#ifndef SPOCK_H
#define SPOCK_H

#include "move.h"

class Spock : public Move {
public:
    std::string getName() const override { return "Spock"; }
    bool defeats(const Move& opponentMove) const override;
};

#endif
