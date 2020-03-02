#include "card_effect.h"
#include <algorithm>

SingleEffect::SingleEffect():
    gives(SCORE),
    base(0),
    counts(0),
    self(false),
    neighbours(false) {}

SingleEffect::SingleEffect(char gives, char base):
    gives(gives),
    base(base),
    counts(0),
    self(false),
    neighbours(false) {}

SingleEffect::SingleEffect(char gives, char counts, bool self, bool neighbours):
    gives(gives),
    base(0),
    counts(counts),
    self(self),
    neighbours(neighbours) {}

SingleEffect::SingleEffect(char gives, char base, char counts, bool self, bool neighbours):
    gives(gives),
    base(base),
    counts(counts),
    self(self),
    neighbours(neighbours) {}

CardEffect::CardEffect(char cardId, std::initializer_list<SingleEffect> effects):
    cardId(cardId),
    numEffs(effects.size())
{
    std::copy(effects.begin(), effects.end(), effs);
}
