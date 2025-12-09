#ifndef ROCK_H
#define ROCK_H

#include "move.h"

class Rock : public Move {
public:
    std::string getName() const override { return "Rock"; }
    bool defeats(const Move& opponentMove) const override;
};

#endif
