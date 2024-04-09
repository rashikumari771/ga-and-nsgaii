#include "crowding_distance.h"
#include <iostream>
#include <limits>
#include <algorithm>

std::vector<double> CalculateCrowdingDistance(CPopulation& cur, CNondominatedSort::TFronts& fronts)
{
    const size_t num_objs = cur[0].objs().size();
    const size_t num_individuals = cur.size();
    const size_t num_fronts = fronts.size();

    std::vector<double> crowding_distance(num_individuals, 0.0);

    for (size_t f = 0; f < num_objs; ++f)
    {
        for (size_t i = 0; i < num_fronts; ++i)
        {
            const size_t front_size = fronts[i].size();
            if (front_size <= 2)
            {
                // Skip fronts with 2 or fewer individuals as their crowding distance will be infinity
                continue;
            }

            std::sort(fronts[i].begin(), fronts[i].end(), [&](size_t a, size_t b) {
                return cur[a].objs()[f] < cur[b].objs()[f];
                });

            crowding_distance[fronts[i][0]] = crowding_distance[fronts[i][front_size - 1]] = std::numeric_limits<double>::infinity();
            const double obj_range = cur[fronts[i][front_size - 1]].objs()[f] - cur[fronts[i][0]].objs()[f];

            for (size_t j = 1; j < front_size - 1; ++j)
            {
                const size_t indv_index = fronts[i][j];
                crowding_distance[indv_index] += (cur[fronts[i][j + 1]].objs()[f] - cur[fronts[i][j - 1]].objs()[f]) / obj_range;
            }
        }
    }

    return crowding_distance;
}

void SortBasedOnCrowdingDistance(CPopulation& cur, CNondominatedSort::TFronts& fronts)
{
    std::vector<double> crowding_distance = CalculateCrowdingDistance(cur, fronts);

    // Sort individuals within each front based on crowding distance
    for (size_t i = 0; i < fronts.size(); ++i)
    {
        CNondominatedSort::TFrontMembers& front = fronts[i];
        std::sort(front.begin(), front.end(), [&](size_t a, size_t b) {
         return crowding_distance[a] > crowding_distance[b]; // Sort in descending order of crowding distance
         });
    }
  
}
