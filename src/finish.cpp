#include "finish.h"
#include "QDebug"
finish::finish(QGraphicsItem *parent):piece(parent)
{
    setImage();
}
void finish::setImage()
{
    setPixmap(QPixmap(":/img/images/horse.png").scaled(30,30,Qt::KeepAspectRatio));
}
