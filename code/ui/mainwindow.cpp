#include "mainwindow.h"
#include "../logic/moves/rock.h"
#include "../logic/moves/paper.h"
#include "../logic/moves/scissors.h"
#include "../logic/moves/lizard.h"
#include "../logic/moves/spock.h"
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVariant>
#include <QDebug>

enum MoveType {
    Rock,
    Paper,
    Scissors,
    Lizard,
    Spock
};

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), game(nullptr)
{
    modeSelector = new QComboBox(this);
    modeSelector->addItem("Single Match", QVariant::fromValue(MatchMode::SINGLE));
    modeSelector->addItem("Best of 3", QVariant::fromValue(MatchMode::BEST_OF_THREE));

    startButton = new QPushButton("Start Game", this);

    QHBoxLayout *modeLayout = new QHBoxLayout();
    modeLayout->addWidget(new QLabel("Select Mode:", this));
    modeLayout->addWidget(modeSelector);
    modeLayout->addWidget(startButton);

    moveSelector = new QComboBox(this);

    moveSelector->addItem("Rock", QVariant::fromValue((int)MoveType::Rock));
    moveSelector->addItem("Paper", QVariant::fromValue((int)MoveType::Paper));
    moveSelector->addItem("Scissors", QVariant::fromValue((int)MoveType::Scissors));
    moveSelector->addItem("Lizard", QVariant::fromValue((int)MoveType::Lizard));
    moveSelector->addItem("Spock", QVariant::fromValue((int)MoveType::Spock));

    playButton = new QPushButton("Play Move", this);

    QHBoxLayout *playLayout = new QHBoxLayout();
    playLayout->addWidget(moveSelector);
    playLayout->addWidget(playButton);

    roundResultLabel = new QLabel("Round results:", this);
    finalResultLabel = new QLabel("", this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(modeLayout);
    mainLayout->addLayout(playLayout);
    mainLayout->addWidget(roundResultLabel);
    mainLayout->addWidget(finalResultLabel);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(playButton, &QPushButton::clicked, this, &MainWindow::makeMove);
}

Move* MainWindow::createMove(int moveType) {
    switch (moveType) {
    case MoveType::Rock:
        return new Rock();
    case MoveType::Paper:
        return new Paper();
    case MoveType::Scissors:
        return new Scissors();
    case MoveType::Lizard:
        return new Lizard();
    case MoveType::Spock:
        return new Spock();
    default:
        return nullptr;
    }
}

void MainWindow::startGame()
{
    MatchMode mode = static_cast<MatchMode>(modeSelector->currentData().toInt());
    game = new Game(mode);
    finalResultLabel->clear();
    roundResultLabel->setText("Choose your move:");
}

void MainWindow::makeMove()
{
    int selectedMoveType = moveSelector->currentData().toInt();
    Move* playerMove = createMove(selectedMoveType);
    if (!playerMove) {
        qWarning() << "Invalid move selected!";
        return;
    }

    RoundResult result = game->playRound(playerMove, "Rock");

    QString text = QString("You played: %1\nComputer played: %2\nResult: %3")
                       .arg(QString::fromStdString(result.playerMove))
                       .arg(QString::fromStdString(result.computerMove))
                       .arg(result.resultText);

    roundResultLabel->setText(text);
    updateAfterRound();
}

// Update the UI after a round
void MainWindow::updateAfterRound()
{
    if (game->isFinished()) {
        QString finalText = QString("Final Result: %1")
        .arg(game->getFinalResult());

        finalResultLabel->setText("<b>" + finalText + "</b>");
    }
}
