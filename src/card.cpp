#include "card.h"

Card::Card(int id, const std::string& name, const std::vector<CardEffect>& effects, const std::vector<std::pair<int, int>>& costPairs, const std::vector<int>& freeChains):
    id(id),
    name(name),
    effects(effects),
    cost(costPairs, freeChains) {}
