#include "card.h"

Card::Card() {}

Card::Card(int cardId, const std::vector<CardEffect>& effects, const std::vector<std::pair<int, int>>& costPairs, const std::vector<int>& freeChains):
    cardId(cardId),
    effects(effects),
    cost(costPairs, freeChains) {}
