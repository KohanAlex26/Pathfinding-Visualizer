#ifndef START_H
#define START_H

#include "piece.h"

class start:public piece
{
public:
    start(QGraphicsItem *parent = 0);
    void setImage();
};

#endif // START_H
