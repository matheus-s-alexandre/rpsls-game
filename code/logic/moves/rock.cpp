#include "rock.h"

bool Rock::defeats(const Move& opponentMove) const {
    return (opponentMove.getName() == "Scissors" || opponentMove.getName() == "Lizard");
}
