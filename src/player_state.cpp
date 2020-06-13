#include "player_state.h"
#include "game_constants.h"
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

void PlayerState::finishAge(int age)
{
    /// TO-DO: MILITARY COMPARISONS WITH NEIGHBOURS
}

int sciScore(int math, int eng, int hist, int wild)
{
    if (wild == 0)
    {
        return std::min(math, std::min(eng, hist)) * SCORE_PER_SCI_COMBO + math * math + eng * eng + hist * hist;
    }
    return std::max(sciScore(math + 1, eng, hist, wild - 1),
           std::max(sciScore(math, eng + 1, hist, wild - 1),
                    sciScore(math, eng, hist + 1, wild - 1)));
}

void PlayerState::finishGame()
{
    for (const CardEffect& effect : applyAtEndOfGame)
    {
        applyEffect(effect);
    }
    state[SCORE] += state[COINS] / COINS_PER_SCORE;
    state[SCORE] += state[M_LOSSES] * SCORE_PER_LOSS;
    state[SCORE] += sciScore(state[S_MATH], state[S_ENG], state[S_HIST], state[S_WILD]);
}
