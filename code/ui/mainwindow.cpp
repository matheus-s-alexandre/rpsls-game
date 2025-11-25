#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), game(nullptr)
{
    modeSelector = new QComboBox(this);
    modeSelector->addItem("Single Match", MatchMode::SINGLE);
    modeSelector->addItem("Best of 3", MatchMode::BEST_OF_THREE);

    startButton = new QPushButton("Start Game", this);

    QHBoxLayout *modeLayout = new QHBoxLayout();
    modeLayout->addWidget(new QLabel("Select Mode:", this));
    modeLayout->addWidget(modeSelector);
    modeLayout->addWidget(startButton);

    moveSelector = new QComboBox(this);
    moveSelector->addItem("Rock", (int)MoveType::Rock);
    moveSelector->addItem("Paper", (int)MoveType::Paper);
    moveSelector->addItem("Scissors", (int)MoveType::Scissors);
    moveSelector->addItem("Lizard", (int)MoveType::Lizard);
    moveSelector->addItem("Spock", (int)MoveType::Spock);

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

    // connect(moveSelector,
    //         QOverload<int>::of(&QComboBox::currentIndexChanged),
    //         this,
    //         &MainWindow::onMoveSelected);
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
    Move playerMove = static_cast<Move>(moveSelector->currentData().toInt());

    RoundResult result = game->playRound(playerMove);

    QString text = QString("You played: %1\nComputer played: %2\nResult: %3")
                       .arg(result.playerMove)
                       .arg(result.computerMove)
                       .arg(result.resultText);

    roundResultLabel->setText(text);

    updateAfterRound();
}

void MainWindow::updateAfterRound()
{
    if (game->isFinished())
    {
        QString finalText = QString("Final Result: %1")
        .arg(game->getFinalResult());

        finalResultLabel->setText("<b>" + finalText + "</b>");
    }
}
