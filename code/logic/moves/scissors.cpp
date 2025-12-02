#include "scissors.h"
#include "paper.h"
#include "lizard.h"

bool Scissors::defeats(const Move& opponentMove) const {
    return (opponentMove.getName() == "Paper" || opponentMove.getName() == "Lizard");
}
