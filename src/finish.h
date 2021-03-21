#ifndef FINISH_H
#define FINISH_H

#include "piece.h"
class finish:public piece
{
public:
    finish(QGraphicsItem *parent = 0);
    void setImage();
};


#endif // FINISH_H
