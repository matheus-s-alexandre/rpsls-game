#ifndef PAPER_H
#define PAPER_H

#include "move.h"

class Paper : public Move {
public:
    std::string getName() const override { return "Paper"; }
    bool defeats(const Move& opponentMove) const override;
};

#endif
