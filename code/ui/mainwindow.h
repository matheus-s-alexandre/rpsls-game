#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../logic/game.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private slots:
    void startGame();
    void makeMove();
    void resetGame();

private:
    QComboBox *modeSelector;
    QComboBox *moveSelector;
    QPushButton *startButton;
    QPushButton *playButton;
    QPushButton *resetButton;
    QLabel *roundResultLabel;
    QLabel *finalResultLabel;

    Game *game;
    Move* createMove(int moveType);
};

#endif // MAINWINDOW_H
