
#include "assignment_problem.h"
#include "nsgaii.h"
#include "population.h"
#include "gnuplot_interface.h"
#include "log.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "individual.h"
#include "math_aux.h"

using namespace std;

int main()
{
	CNSGAII nsgaii("nsgaii.ini");
	CPopulation solutions;
	Gnuplot gplot;

	const size_t NumRuns = 10;

	BProblem* problem3 = new CProblemAssignment3(2, 3,-4, 4);
	BProblem* problem4 = new CProblemAssignment4(2, 2,-7, 4);

	BProblem* problem = problem4;


	for (size_t r = 0; r < NumRuns; r += 1)
	{
		srand(r); cout << "Run Number: " << r << endl;

		nsgaii.Solve(&solutions, *problem);

		SaveToFile(nsgaii.name() + "-" + problem->name() + ".txt", solutions);
		ShowPopulation(gplot, solutions, "pop"); //system("pause");
	}
	delete problem;

	return 0;
}
