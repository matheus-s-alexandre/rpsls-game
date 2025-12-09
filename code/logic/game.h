#ifndef GAME_H
#define GAME_H

#include <QtWidgets>
#include <string>
#include "./moves/move.h"

enum class MatchMode {
    SINGLE,
    BEST_OF_THREE
};

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(MatchMode mode, QObject* parent = nullptr);

    std::string playRound(const Move& player, const Move& computer);

    bool isFinished() const;
    std::string getFinalResult() const;
    void resetGame();

signals:
    void playerChose(QString move);
    void computerChose(QString move);
    void roundResult(QString text);
    void matchFinished(QString finalResult);
private:
    MatchMode mode;
    int playerWins;
    int computerWins;
    int roundsPlayed;
};

#endif // GAME_H
