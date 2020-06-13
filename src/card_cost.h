#ifndef CARD_COST_H_INCLUDED
#define CARD_COST_H_INCLUDED

#include <vector>

#define COIN_COST 0
#define WOOD_COST 1
#define STONE_COST 2
#define CLAY_COST 3
#define IRON_COST 4
#define CLOTH_COST 5
#define GLASS_COST 6
#define PAPER_COST 7
#define NUM_COSTS 8

struct CardCost
{
    int costs[NUM_COSTS];
    std::vector<int> freeChains;

    CardCost();
    CardCost(const std::vector<std::pair<int, int>>& costPairs, const std::vector<int>& freeChains);
};

#endif // CARD_COST_H_INCLUDED
