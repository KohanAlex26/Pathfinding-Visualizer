#include <QGraphicsItemGroup>
#include <QGraphicsView>
#include <QDebug>

#include "Board.h"
#include "Box.h"
#include "game.h"
#include "end.h"
#include "finish.h"

extern Game *game;
piece *piece1;
piece *piece2;
Board::Board()
{
    int SHIFT = 30;
    int x=30;
    int y=30;
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 25; j++)
        {
             Box1 *box = new Box1();
             box->setNumber(25*i+j);
             box->setPos(x+SHIFT*j+100,y+SHIFT*i+100);
             box->setOriginalColor(Qt::lightGray);
             game->addToScene(box);
             list.push_back(box);
             if(i==0 && j==0)
             {
                  piece1=new start();
                  box->placePiece(piece1);
                  game->addToScene(piece1);
             }
             else
             if(i==24 && j==24)
             {
                  piece2=new finish();
                  box->placePiece(piece2);
                  game->addToScene(piece2);
             }
         }
     }
}

