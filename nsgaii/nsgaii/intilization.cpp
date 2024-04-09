#include "initialization.h"
#include "base_problem.h"
#include "individual.h"
#include "population.h"
#include "math_aux.h"

#include <cstddef>
using std::size_t;

CRandomInitialization RandomInitialization;

void CRandomInitialization::operator()(CIndividual* indv, const BProblem& prob) const
{
	CIndividual::TDecVec& x = indv->vars();
	x.resize(prob.num_variables());
	for (size_t i = 0; i < x.size(); i += 1)
	{
		x[i] = MathAux::random(prob.lower_bounds()[i], prob.upper_bounds()[i]);
	}
}
// ----------------------------------------------------------------------
void CRandomInitialization::operator()(CPopulation* pop, const BProblem& prob) const
{
	for (size_t i = 0; i < pop->size(); i += 1)
	{
		(*this)(&(*pop)[i], prob);
	}
}