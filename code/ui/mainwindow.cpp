#include "mainwindow.h"
#include "../logic/moves/move.h"
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
#include <iostream>

enum MoveType {
    RockMove,
    PaperMove,
    ScissorsMove,
    LizardMove,
    SpockMove
};

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), game(nullptr)
{
    modeSelector = new QComboBox();
    modeSelector->addItem("Single Match", QVariant::fromValue(MatchMode::SINGLE));
    modeSelector->addItem("Best of 3", QVariant::fromValue(MatchMode::BEST_OF_THREE));

    startButton = new QPushButton("Start Game");

    QHBoxLayout *modeLayout = new QHBoxLayout();
    modeLayout->addWidget(new QLabel("Select Mode:", this));
    modeLayout->addWidget(modeSelector);
    modeLayout->addWidget(startButton);

    moveSelector = new QComboBox(this);

    moveSelector->addItem("Rock", QVariant::fromValue(static_cast<int>(MoveType::RockMove)));
    moveSelector->addItem("Paper", QVariant::fromValue(static_cast<int>(MoveType::PaperMove)));
    moveSelector->addItem("Scissors", QVariant::fromValue(static_cast<int>(MoveType::ScissorsMove)));
    moveSelector->addItem("Lizard", QVariant::fromValue(static_cast<int>(MoveType::LizardMove)));
    moveSelector->addItem("Spock", QVariant::fromValue(static_cast<int>(MoveType::SpockMove)));

    playButton = new QPushButton("Play Move", this);
    resetButton = new QPushButton("Reset Game", this);

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
    mainLayout->addWidget(resetButton);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(playButton, &QPushButton::clicked, this, &MainWindow::makeMove);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetGame);
}

Move* MainWindow::createMove(int moveType) {
    std::cout << "moveType: " << moveType << std::endl;

    switch (moveType) {
    case MoveType::RockMove:
        return new Rock();
    case MoveType::PaperMove:
        return new Paper();
    case MoveType::ScissorsMove:
        return new Scissors();
    case MoveType::LizardMove:
        return new Lizard();
    case MoveType::SpockMove:
        return new Spock();
    default:
        return nullptr;
    }
}

void MainWindow::startGame()
{
    // if a previous game exists, delete it
    if (game) {
        delete game;
        game = nullptr;
    }

    int modeInt = modeSelector->currentData().toInt();
    std::cout << "modeInt: " << modeInt << std::endl;

    MatchMode mode = static_cast<MatchMode>(modeInt);

    game = new Game(mode, this);

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

    int computerMoveType = std::rand() % 5;

    Move* computerMove = createMove(computerMoveType);

    std::string resultText = game->playRound(*playerMove, *computerMove);

    QString text = QString::fromStdString(resultText);
    roundResultLabel->setText(text);

    delete playerMove;
    delete computerMove;

    if (game->isFinished()) {

        QString finalText = QString::fromStdString(game->getFinalResult());
        finalResultLabel->setText("<b>" + finalText + "</b>");
    }
}

void MainWindow::resetGame()
{
    if (game) {
        game->resetGame();
    }

    roundResultLabel->setText("Round results:");
    finalResultLabel->clear();

    modeSelector->setCurrentIndex(0);
    moveSelector->setCurrentIndex(0);
}


