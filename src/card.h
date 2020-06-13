#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include "card_effect.h"
#include "card_cost.h"
#include <vector>

struct Card
{
    int cardId;
    std::vector<CardEffect> effects;
    CardCost cost;

    Card();
    Card(int cardId, const std::vector<CardEffect>& effects, const std::vector<std::pair<int, int>>& costPairs, const std::vector<int>& freeChains);
};

#endif // CARD_H_INCLUDED
