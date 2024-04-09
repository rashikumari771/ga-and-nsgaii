#include "assignment_problem.h"
#include "individual.h"
#include "math_aux.h"

#include <cmath>
#include <vector>
#include<iostream>

using std::size_t;
using std::cos;

// ----------------------------------------------------------------------
//		CProblemAssignment
// ----------------------------------------------------------------------

CProblemAssignment::CProblemAssignment(size_t M, size_t k, const std::string& name, double lbs, double ubs) :
	BProblem(name),
	M_(M),
	k_(k)
{
	lbs_.resize( k_, lbs); // lower bound
	ubs_.resize( k_, ubs); // upper bound
}


bool CProblemAssignment3::Evaluate(CIndividual* indv) const
{
	CIndividual::TDecVec& x = indv->vars();
	CIndividual::TObjVec& f = indv->objs();

	if (x.size() != k_) return false; // #variables does not match

	f.resize(M_, 0);
	for (size_t i = 0; i < k_; ++i) {
	   f[0] += MathAux::square(x[i]-1.0/ sqrt(k_));
	}
	f[0] = 1 - exp(-f[0]);
	for (size_t i = 0; i < k_; ++i) {
		f[1] += MathAux::square(x[i] + 1.0/ sqrt(k_));
	}
	f[1] = 1 - exp(-f[1]);
	

	return true;
}


bool CProblemAssignment4::Evaluate(CIndividual* indv) const
{
	CIndividual::TDecVec& x = indv->vars();
	CIndividual::TObjVec& f = indv->objs();
	//std::cout << (x.size() == k_)<<'\n';
	//std::cout << x[0]<<' '<<x[1] << '\n';
	if (x.size() != k_) return false; // #variables does not match
	// constraint 
	double g1 = 6.5 - x[0] / 6 - x[1];
	double g2 = 7.5 - 0.5 * x[0] / 6 - x[1];
	double g3 = 30 - 5 * x[0] / 6 - x[1];

	//penalty
	if (g1 < 0)g1 = g1 * g1;
	if (g2 < 0)g2 = g2 * g2;
	if (g3 < 0)g3 = g3 * g3;

	f.resize(M_, 0);
	f[0] = MathAux::square(x[0]) - x[1] + g1 + g2 + g3;
	f[1] = -0.5 * x[0] - x[1] - 1 + g1 + g2 + g3;

	return true;
}

