#include "paper.h"
#include "rock.h"
#include "spock.h"

bool Paper::defeats(const Move& opponentMove) const {
    return (opponentMove.getName() == "Rock" || opponentMove.getName() == "Spock");
}
