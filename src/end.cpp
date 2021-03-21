#include "end.h"
#include "QDebug"

end::end(QGraphicsItem *parent):piece(parent)
{
    setImage();
}
void end::setImage()
{
    setPixmap(QPixmap(":/img/images/horse.png").scaled(30,30,Qt::KeepAspectRatio));
}
