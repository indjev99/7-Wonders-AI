#ifndef CARD_EFFECT_H_INCLUDED
#define CARD_EFFECT_H_INCLUDED

#include <initializer_list>

#define SCORE 0
#define COINS 1
#define M_POWER 2
#define M_LOSSES 3
#define S_MATH 4
#define S_ENG 5
#define S_HIST 6
#define S_WILD 7
#define R_WOOD 8
#define R_STONE 9
#define R_CLAY 10
#define R_IRON 11
#define R2_WS 12
#define R2_WC 13
#define R2_WI 14
#define R2_SC 15
#define R2_SI 16
#define R2_CI 17
#define P_CLOTH 18
#define P_GLASS 19
#define P_PAPER 20
#define C_EAST 21
#define C_WEST 22
#define C_MARK 23
#define C_CARAV 24
#define C_FORUM 25
#define W_FREE 26
#define W_LAST 27
#define W_FREEUSED 28
#define W_GUILDCOPY 29
#define K_WONDER 30
#define K_BROWN 31
#define K_GRAY 32
#define K_BLUE 33
#define K_RED 34
#define K_YELLOW 35
#define K_GREEN 36
#define NUM_PROPS 37

struct CardEffect
{
    int gives;
    int base;
    int counts;
    bool self, neighbours;

    CardEffect();
    CardEffect(int gives, int base);
    CardEffect(int gives, int counts, bool self, bool neighbours);
    CardEffect(int gives, int base, int counts, bool self, bool neighbours);
};

#endif // CARD_EFFECT_H_INCLUDED
