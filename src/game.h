#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>

#include "Board.h"
#include "Box.h"
#include "piece.h"

class Game:public QGraphicsView
{
    Q_OBJECT
public:
    //constructor
    Game(QWidget *parent = 0);

    //methods
    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);
    void drawBoard();
    void displayMainMenu();


    //atributes
    QGraphicsScene *gameScene;
    Board *board;
    int src=0,f=624;

public slots:
    void shortestPathBetweenTwoGame();
    void clearBoardGame();
};

#endif // GAME_H
