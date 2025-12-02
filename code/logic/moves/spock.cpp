#include "spock.h"
#include "scissors.h"
#include "rock.h"

bool Spock::defeats(const Move& opponentMove) const {
    return (opponentMove.getName() == "Scissors" || opponentMove.getName() == "Rock");
}
