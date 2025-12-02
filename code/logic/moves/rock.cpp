#include "rock.h"

bool Rock::defeats(const Move& opponentMove) const {
    // const std::string o = opponentMove.getName();
    // return (o == "Scissors" || o == "Lizard");
    return (opponentMove.getName() == "Scissors" || opponentMove.getName() == "Lizard");
}
