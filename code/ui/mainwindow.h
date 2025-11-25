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
    ~MainWindow();

private slots:
    void startGame();
    void makeMove();
    void updateAfterRound();

private:
    QComboBox *modeSelector;
    QComboBox *moveSelector;
    QPushButton *startButton;
    QPushButton *playButton;
    QLabel *roundResultLabel;
    QLabel *finalResultLabel;

    Game *game;
};

#endif // MAINWINDOW_H
