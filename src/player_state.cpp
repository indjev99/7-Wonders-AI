#include "player_state.h"
#include <algorithm>

PlayerState::PlayerState()
{
    std::fill(state, state + NUM_PROPS, 0);
}

void PlayerState::applySingle(const SingleEffect& singEff)
{
    if (singEff.counts)
    {
        int cnt = 0;
        if (singEff.self)
        {
            cnt += state[singEff.counts];
        }
        if (singEff.neighbours)
        {
            /// TO-DO: COUNT NEIGHBOURS
        }
        state[singEff.gives] += cnt * singEff.base;

    }
    else
    {
        state[singEff.gives] += singEff.base;
    }
}

void PlayerState::apply(const CardEffect& effect)
{
    built.insert(effect.cardId);
    for (const SingleEffect& singEff : effect.singEffs)
    {
        if (singEff.counts)
        {
            if (singEff.gives == SCORE)
            {
                applyAtEndOfGame.push_back(singEff);
            }
            else
            {
                applyAtEndOfTurn.push_back(singEff);
            }
        }
        else
        {
            applySingle(singEff);
        }
    }
}

void PlayerState::finishTurn()
{
    for (const SingleEffect& singEff : applyAtEndOfTurn)
    {
        applySingle(singEff);
    }
    applyAtEndOfTurn.clear();
}

void PlayerState::finishGame()
{
    for (const SingleEffect& singEff : applyAtEndOfGame)
    {
        applySingle(singEff);
    }
    applyAtEndOfGame.clear();
}
