#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include "card.h"
#include "game_constants.h"
#include <vector>
#include <unordered_map>

struct Deck
{
    std::vector<Card> cardList;
    std::unordered_map<std::string, int> nameMap;
    std::vector<int> ageCards[NUM_AGES];
    std::vector<int> guildCards[NUM_AGES];
};

#endif // DECK_H_INCLUDED
