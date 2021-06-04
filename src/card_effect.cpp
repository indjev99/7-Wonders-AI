#include "card_effect.h"

CardEffect::CardEffect():
    gives(0),
    base(0),
    counts(0),
    self(false),
    neighbours(false) {}

CardEffect::CardEffect(int gives, int base):
    gives(gives),
    base(base),
    counts(0),
    self(false),
    neighbours(false) {}

CardEffect::CardEffect(int gives, int mult, int counts, bool self, bool neighbours):
    gives(gives),
    base(mult),
    counts(counts),
    self(self),
    neighbours(neighbours) {}
