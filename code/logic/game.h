#ifndef GAME_H
#define GAME_H

#include "move.h"
#include <string>

enum class MatchMode {
    SINGLE,
    BEST_OF_THREE
};

class Game {
public:
    MatchMode mode = MatchMode::SINGLE;

    Game(MatchMode mode);

    std::string playRound(const Move& player, const Move& computer);

    bool isFinished() const;
    std::string getFinalResult() const;

    void resetGame();
private:
    int playerWins;
    int computerWins;
    int roundsPlayed;
};

#endif // GAME_H
