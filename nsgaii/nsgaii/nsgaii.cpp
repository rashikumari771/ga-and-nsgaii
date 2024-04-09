#include "nsgaii.h"
#include "base_problem.h"
#include "individual.h"
#include "population.h"

#include "initialization.h"
#include "crossover.h"
#include "mutation.h"
#include "survivor_selection.h"

#include "gnuplot_interface.h"
#include "log.h"
#include "windows.h" // for Sleep()

#include <vector>
#include <fstream>
#include<iostream>

using namespace std;

CNSGAII::CNSGAII(const string& inifile_name) :
	name_("NSGAII"),
	obj_division_p_(12),
	gen_num_(1000),
	pc_(1.0), // default setting in NSGA-II
	eta_c_(30), // default setting
	eta_m_(20) // default setting
{
	if (inifile_name == "") return;

	ifstream inifile(inifile_name);
	if (!inifile) return;

	string dummy;
	inifile >> dummy >> dummy >> name_;
	inifile >> dummy >> dummy >> obj_division_p_;
	inifile >> dummy >> dummy >> gen_num_;
	inifile >> dummy >> dummy >> pc_;
	inifile >> dummy >> dummy >> eta_c_;
	inifile >> dummy >> dummy >> eta_m_;
}
// ----------------------------------------------------------------------
void CNSGAII::Solve(CPopulation* solutions, const BProblem& problem)
{
	CIndividual::SetTargetProblem(problem);


	size_t PopSize = 50;
	while (PopSize % 4) PopSize += 1;

	//CPopulation pop[2] = { CPopulation(PopSize) };
	std::vector<CPopulation> pop(2, CPopulation(PopSize));
	CSimulatedBinaryCrossover SBX(pc_, eta_c_);
	CPolynomialMutation PolyMut(1.0 / problem.num_variables(), eta_m_);

	Gnuplot gplot;

	int cur = 0, next = 1;

	//std::cout << problem.lower_bounds()[0] << '\n';
	RandomInitialization(&pop[cur], problem);
	for (size_t i = 0; i < PopSize; i += 1)
	{
		problem.Evaluate(&pop[cur][i]);
	}

	for (size_t t = 0; t < gen_num_; t += 1)
	{
		pop[cur].resize(PopSize * 2);

		for (size_t i = 0; i < PopSize; i += 2)
		{
			int father = rand() % PopSize,
				mother = rand() % PopSize;

			SBX(&pop[cur][PopSize + i], &pop[cur][PopSize + i + 1], pop[cur][father], pop[cur][mother]);

			PolyMut(&pop[cur][PopSize + i]);
			PolyMut(&pop[cur][PopSize + i + 1]);

			problem.Evaluate(&pop[cur][PopSize + i]);
			problem.Evaluate(&pop[cur][PopSize + i + 1]);
		}

		SurvivorSelection(&pop[next], &pop[cur], PopSize);

		//ShowPopulation(gplot, pop[next], "pop"); Sleep(10);

		std::swap(cur, next);
	}

	*solutions = pop[cur];
}