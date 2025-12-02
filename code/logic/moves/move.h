#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move{
public:
    virtual ~Move() = default;
    virtual std::string getName() const = 0;
    virtual bool defeats(const Move& opponentMove) const = 0;
};

#endif
