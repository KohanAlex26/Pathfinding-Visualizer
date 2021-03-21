#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>

#include "Box.h"

class Box1;
class piece:public QGraphicsPixmapItem
{
public:
    piece(QGraphicsItem *parent = 0);
    void setCurrentBox(Box1 *box);
    Box1 *getCurrentBox() ;
    virtual void setImage() = 0;
protected:
    Box1 *currentBox;
};

#endif // PIECE_H
