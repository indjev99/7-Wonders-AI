#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include "card_effect.h"
#include "card_cost.h"
#include <vector>
#include <string>

struct Card
{
    int id;
    std::string name;
    std::vector<CardEffect> effects;
    CardCost cost;

    Card(int id, const std::string& name, const std::vector<CardEffect>& effects, const std::vector<std::pair<int, int>>& costPairs, const std::vector<int>& freeChains);
};

#endif // CARD_H_INCLUDED
