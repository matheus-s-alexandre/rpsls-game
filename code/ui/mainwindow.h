#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>
#include "../logic/game.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

private slots:
    void onStartGame();
    void onMatchModeClicked();
    void onResetGameClicked();
    //TODO: Substituir para uma unica funcao de onMoveClicked
    void onRockClicked();
    void onPaperClicked();
    void onScissorsClicked();
    void onLizardClicked();
    void onSpockClicked();

private:
    Ui::MainWindow *ui;
    Game *game;

    void playRound(Move& playerMove, Move& ComputerMove);
    void isFinished();
    void getFinalResult();
    void resetGame();
};

#endif // MAINWINDOW_HPP
