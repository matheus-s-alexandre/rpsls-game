#ifndef LIZARD_H
#define LIZARD_H

#include "move.h"

class Lizard : public Move {
public:
    std::string getName() const override { return "Lizard"; }
    bool defeats(const Move& opponentMove) const override;
};

#endif
