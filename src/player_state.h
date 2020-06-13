#ifndef PLAYER_STATE_H_INCLUDED
#define PLAYER_STATE_H_INCLUDED

#include "card.h"
#include <unordered_set>

struct PlayerState
{
    int state[NUM_PROPS];
    std::unordered_set<int> built;
    std::vector<CardEffect> applyAtEndOfTurn;
    std::vector<CardEffect> applyAtEndOfGame;

    PlayerState(int coins, int producing);

    void buildCard(const Card& card);
    void applyEffect(const CardEffect& effect);
    void finishTurn();
    void finishAge(int age);
    void finishGame();
};

#endif // PLAYER_STATE_H_INCLUDED
