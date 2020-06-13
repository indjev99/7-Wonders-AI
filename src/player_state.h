#ifndef PLAYER_STATE_H_INCLUDED
#define PLAYER_STATE_H_INCLUDED

#include "card_effect.h"
#include <unordered_set>

struct PlayerState
{
    int state[NUM_PROPS];
    std::unordered_set<int> built;
    std::vector<SingleEffect> applyAtEndOfTurn;
    std::vector<SingleEffect> applyAtEndOfGame;

    PlayerState(int coins, int producing);

    void applySingle(const SingleEffect& singEff);
    void apply(const CardEffect& effect);
    void finishTurn();
    void finishGame();
};

#endif // PLAYER_STATE_H_INCLUDED
