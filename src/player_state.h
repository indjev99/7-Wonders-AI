#ifndef PLAYER_STATE_H_INCLUDED
#define PLAYER_STATE_H_INCLUDED

#include "card_effect.h"
#include <set>

struct PlayerState
{
    char state[NUM_PROPS];
    std::set built;
};

#endif // PLAYER_STATE_H_INCLUDED
