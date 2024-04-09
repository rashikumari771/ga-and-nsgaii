#ifndef CROWDING_DISTANCE_H
#define CROWDING_DISTANCE_H

#include "nondominated_sort.h"
#include "population.h"
#include <vector>

std:: vector<double> CalculateCrowdingDistance(CPopulation& cur, CNondominatedSort::TFronts& fronts);
void SortBasedOnCrowdingDistance(CPopulation& cur, CNondominatedSort::TFronts& fronts);

#endif
