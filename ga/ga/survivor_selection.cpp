#include "survivor_selection.h"
#include "population.h"
#include "math_aux.h"

#include <limits>
#include <algorithm>
#include<iostream>

using namespace std;

// ----------------------------------------------------------------------
// SurvivorSelection():
// ----------------------------------------------------------------------
void SurvivorSelection(CPopulation *pnext, CPopulation *pcur,  size_t PopSize)
{
	CPopulation &cur = *pcur, &next = *pnext;
	next.clear();
	std::vector<size_t> index; 
	//std :: cout << "next gen:\n";
	//system("pause");
	for (int i = 0; i < cur.size(); i++) {
		index.push_back(i);
	}
	

	std::sort(index.begin(), index.end(), [&](size_t a, size_t b) {
		return cur[a].objs()[0]+ cur[a].objs()[1] < cur[b].objs()[0]+ cur[b].objs()[1];
		});
	

	for (size_t t = 0; t < PopSize ; t += 1)
	{
		 next.push_back(cur[index[t]]);
		 
	}

}
// ----------------------------------------------------------------------