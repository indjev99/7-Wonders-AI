#include "player_state.h"
#include <algorithm>

PlayerState::PlayerState(int coins, int producing)
{
    std::fill(state, state + NUM_PROPS, 0);
    state[COINS] = coins;
    if (producing) state[producing] = 1;
}

void PlayerState::buildCard(const Card& card)
{
    built.insert(card.cardId);
    for (const CardEffect& effect : card.effects)
    {
        if (effect.counts)
        {
            if (effect.gives == SCORE)
            {
                applyAtEndOfGame.push_back(effect);
            }
            else
            {
                applyAtEndOfTurn.push_back(effect);
            }
        }
        else
        {
            applyEffect(effect);
        }
    }
}

void PlayerState::applyEffect(const CardEffect& effect)
{
    if (effect.counts)
    {
        int cnt = 0;
        if (effect.self)
        {
            cnt += state[effect.counts];
        }
        if (effect.neighbours)
        {
            /// TO-DO: COUNT NEIGHBOURS
        }
        state[effect.gives] += cnt * effect.base;
    }
    else
    {
        state[effect.gives] += effect.base;
    }
}

void PlayerState::finishTurn()
{
    for (const CardEffect& effect : applyAtEndOfTurn)
    {
        applyEffect(effect);
    }
    applyAtEndOfTurn.clear();
}

void PlayerState::finishGame()
{
    for (const CardEffect& effect : applyAtEndOfGame)
    {
        applyEffect(effect);
    }
    applyAtEndOfGame.clear();
}
