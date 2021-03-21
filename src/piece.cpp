#include "piece.h"

piece::piece(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{

}

void piece::setCurrentBox(Box1 *box)
{
    currentBox=box;
}

Box1 *piece::getCurrentBox()
{
    return currentBox;
}
