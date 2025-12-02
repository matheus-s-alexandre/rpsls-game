#include "lizard.h"
#include "paper.h"
#include "spock.h"

bool Lizard::defeats(const Move& opponentMove) const {
    return (opponentMove.getName() == "Paper" || opponentMove.getName() == "Spock");
}
