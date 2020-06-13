#include "card_cost.h"
#include <algorithm>

CardCost::CardCost() {}

CardCost::CardCost(const std::vector<std::pair<int, int>>& costPairs, const std::vector<int>& freeChains):
    freeChains(freeChains)
{
    std::fill(costs, costs + NUM_COSTS, 0);
    for (const std::pair<int, int>& costPair : costPairs)
    {
        costs[costPair.first] += costPair.second;
    }
}
