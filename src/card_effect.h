#ifndef CARD_EFFECT_H_INCLUDED
#define CARD_EFFECT_H_INCLUDED

#include <initializer_list>

#define SCORE 0
#define COINS 1
#define M_POWER 2
#define M_WINS 3
#define M_LOSSES 4
#define S_MATH 5
#define S_ENG 6
#define S_HIST 7
#define S_WILD 8
#define R_WOOD 9
#define R_STONE 10
#define R_CLAY 11
#define R_IRON 12
#define R2_WS 13
#define R2_WC 14
#define R2_WI 15
#define R2_SC 16
#define R2_SI 17
#define R2_CI 18
#define P_CLOTH 19
#define P_GLASS 20
#define P_PAPER 21
#define C_EAST 22
#define C_WEST 23
#define C_MARK 24
#define C_CARAV 25
#define C_FORUM 26
#define W_FREE 27
#define W_LAST 28
#define W_FREEUSED 29
#define W_GUILDCOPY 30
#define K_WONDER 31
#define K_BROWN 32
#define K_GRAY 33
#define K_BLUE 34
#define K_RED 35
#define K_YELLOW 36
#define K_GREEN 37
#define NUM_PROPS 38

#include <vector>

struct SingleEffect
{
    int gives;
    int base;
    int counts;
    bool self, neighbours;
    SingleEffect();
    SingleEffect(int gives, int base);
    SingleEffect(int gives, int counts, bool self, bool neighbours);
    SingleEffect(int gives, int base, int counts, bool self, bool neighbours);
};

struct CardEffect
{
    int cardId;
    std::vector<SingleEffect> singEffs;
    CardEffect(int cardId, std::initializer_list<SingleEffect> singEffs);
};

#endif // CARD_EFFECT_H_INCLUDED
