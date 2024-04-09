#include <vector>
#include "math_aux.h"

using namespace std;

namespace MathAux
{

// ----------------------------------------------------------------------
// ASF: Achivement Scalarization Function
// ----------------------------------------------------------------------
double ASF(const vector<double> &objs, const vector<double> &weight)
{
	double max_ratio = -numeric_limits<double>::max();
	for (size_t f=0; f<objs.size(); f+=1)
	{
		double w = weight[f]?weight[f]:0.00001;
		max_ratio = std::max(max_ratio, objs[f]/w);
	}
	return max_ratio;
}
// ---------------------------------------------------------------------




}// namespace MathAux