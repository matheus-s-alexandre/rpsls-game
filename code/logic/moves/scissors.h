#ifndef SCISSORS_H
#define SCISSORS_H

#include "move.h"

class Scissors : public Move {
public:
    std::string getName() const override { return "Scissors"; }
    bool defeats(const Move& opponentMove) const override;
};

#endif
