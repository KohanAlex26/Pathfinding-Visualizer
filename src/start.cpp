#include "start.h"
#include "QDebug"
start::start(QGraphicsItem *parent):piece(parent)
{
    setImage();
}
void start::setImage()
{
    setPixmap(QPixmap(":/img/images/bishop.png").scaled(30,30,Qt::KeepAspectRatio));
}
