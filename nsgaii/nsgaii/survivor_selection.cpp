#include "survivor_selection.h"
#include "population.h"
#include "math_aux.h"
#include "nondominated_sort.h"
#include "crowding_distance.h"

#include <limits>
#include <algorithm>

using namespace std;

// ----------------------------------------------------------------------
// SurvivorSelection():
// ----------------------------------------------------------------------
void SurvivorSelection(CPopulation *pnext, CPopulation *pcur,  size_t PopSize)
{
	CPopulation &cur = *pcur, &next = *pnext;
	next.clear();

	// ---------- Step 4 in Algorithm 1: non-dominated sorting ----------
	CNondominatedSort::TFronts fronts = NondominatedSort(cur).second;
	SortBasedOnCrowdingDistance(cur, fronts);


	for (size_t t = 0; t < fronts.size() - 1; t += 1)
	{
		for (size_t i = 0; i < fronts[t].size() - 1; i += 1) {
		   if (next.size() >= PopSize) break;
		   next.push_back(cur[fronts[t][i]]);
		}
	}

}
// ----------------------------------------------------------------------