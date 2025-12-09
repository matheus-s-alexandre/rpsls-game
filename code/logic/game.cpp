#include "game.h"
#include <iostream>

Game::Game(MatchMode mode, QObject* parent)
    : QObject(parent),
    mode(mode),
    playerWins(0),
    computerWins(0),
    roundsPlayed(0)
{
}

void Game::resetGame() {
    playerWins = 0;
    computerWins = 0;
    roundsPlayed = 0;
}

std::string Game::playRound(const Move& player, const Move& computer) {
    roundsPlayed++;

    std::string resultText =
        "You chose " + player.getName() +
        ", Computer chose " + computer.getName() + ". ";

    if (player.defeats(computer)) {
        playerWins++;
        resultText += "You win this round!";
        emit roundResult("You win this round!");
    } else if (computer.defeats(player)) {
        computerWins++;
        resultText += "Computer wins this round!";
        emit roundResult("Computer wins this round!");
    } else {
        resultText += "It's a tie!";
        emit roundResult("It's a tie!");
    }

    if (isFinished()) {
        std::string finalText = getFinalResult();
        emit matchFinished(QString::fromStdString(finalText));
        return finalText;
    }

    return resultText;
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
    if (mode == MatchMode::SINGLE) {
        if (playerWins > computerWins) return "You win!";
        if (computerWins > playerWins) return "Computer wins!";
        return "It's a tie!";
    }
    else {
        // BEST_OF_THREE Game Mode
        if (playerWins == 2) {
            return "You won the match!";
        } else if (computerWins == 2) {
            return "Computer won the match!";
        }
    }

    return "";
}

