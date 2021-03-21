#include <QGraphicsScene>
#include <QPixmap>
#include <QDebug>
#include <QComboBox>

#include "game.h"
#include "Button.h"
#include "Board.h"
#include "ComboBox.h"

extern Dikstra *dikstra;
Game::Game(QWidget *parent ):QGraphicsView(parent)
{


    //Making the Scene
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1400,900);

    //Making the view
//    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
//    QBrush brush;
//    brush.setStyle(Qt::Sol);
//    brush.setColor(Qt::white);
//    setBackgroundBrush(brush);
}


void Game::addToScene(QGraphicsItem *item)
{
    gameScene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item)
{
    gameScene->removeItem(item);

}


void Game::drawBoard()
{
    board = new Board();

}

void Game::displayMainMenu()
{
    drawBoard();
    int V = 625;
    dikstra=new Dikstra(V);
    this->board->list.at(0)->complementStart();
    this->board->list.at(V-1)->complementFinish();
    this->board->list.at(0)->setColor(Qt::green);
    this->board->list.at(V-1)->setColor(Qt::red);

    //create start Button
    Button * startDikstra = new Button("Start Dikstra");
    int pxPos = width()/2 - startDikstra->boundingRect().width()/2+200;
    int pyPos = 0;
    startDikstra->setPos(pxPos,pyPos);
    connect(startDikstra,SIGNAL(clicked()) , this , SLOT(shortestPathBetweenTwoGame()));
    this->addToScene(startDikstra);

    //create clear Button
    Button * clearBoard = new Button("Clear Board");
    int pxPos2 = width()/2 - clearBoard->boundingRect().width()/2+500;
    int pyPos2 = 0;
    clearBoard->setPos(pxPos2,pyPos2);
    connect(clearBoard,SIGNAL(clicked()) , this , SLOT(clearBoardGame()));
    this->addToScene(clearBoard);

    //create combo box
    QComboBox *comboBox= new QComboBox();
//    QStringList list=(QStringList()<<"red"<<"yellow"<<"blue");
//    ComboBox *comboBox = new ComboBox("cf");
//    int pxPos3 = width()/2 - comboBox->boundingRect().width()/2+0;
//    int pyPos3 = 200;
//    comboBox->setPos(pxPos3,pyPos3);
//    this->addToScene(comboBox);
//    comboBox->addItems(list);

}


void Game::shortestPathBetweenTwoGame()
{
    dikstra->shortestPathBetweenTwo();
}

void Game::clearBoardGame()
{
    dikstra->clearBoard();
}
