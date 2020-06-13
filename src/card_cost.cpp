#include "card_cost.h"

CardCost::CardCost() {}

CardCost::CardCost(const std::vector<std::pair<int, int>>& costPairs, const std::vector<int>& freeChains):
    freeChains(freeChains)
{
    for (const std::pair<int, int>& costPair : costPairs)
    {
        costs[costPair.first] += costPair.second;
    }
}
