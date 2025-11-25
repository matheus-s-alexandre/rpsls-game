#include "game.h"

Game::Game(MatchMode mode)
    : mode(mode), playerWins(0), computerWins(0), roundsPlayed(0) {}

void Game::resetGame() {
    playerWins = 0;
    computerWins = 0;
    roundsPlayed = 0;
}

std::string Game::playRound(const Move& player, const Move& computer) {
    roundsPlayed++;

    std::string result = "";

    std::string text = "You chose " + player.getName() +
                       ", Computer chose " + computer.getName() + ". ";

    // Emit event to QT

    if (player.defeats(computer)) {
        playerWins++;
        std::string resultText = "You win this round!";
        // Emit event to QT
    } else if (computer.defeats(player)) {
        computerWins++;
        std::string resultText = "Computer wins this round!";
        // Emit event to QT
    } else {
        std::string resultText = "It's a tie";
        // Emit event to QT
    }

    if (mode == MatchMode::SINGLE) {
        result += getFinalResult();
        // Emit event to QT
    }
    else if (mode == MatchMode::BEST_OF_THREE) {
        if (playerWins == 2 || computerWins == 2) {
            result += getFinalResult();
        } else {
            // Emit event to QT
        }
    }

    return result;
}

bool Game::isFinished() const {
    if (mode == MatchMode::SINGLE) {
        return roundsPlayed >= 1;
    }
    if (mode == MatchMode::BEST_OF_THREE) {
        return (playerWins == 2 || computerWins == 2);
    }
    return false;
}

std::string Game::getFinalResult() const {
    if (playerWins > computerWins) {
        // Emit event to QT
        std::string text = "Game Result: You win the match!";
    } else if (computerWins > playerWins) {
        // Emit event to QT
        std::string text = "Game Result: Computer wins the match!";
    } else {
        // Emit event to QT
        std::string text = "Game Result: It's a draw!";
    }
}
