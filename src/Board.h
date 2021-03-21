#ifndef BOARD_H
#define BOARD_H
#include "Box.h"
#include "start.h"
#include "piece.h"

#include <vector>
#include <QPushButton>
#include "piece.h"
#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
class Board
{
public:
    Board();
    std::vector <Box1 *> list;
private:
    Box1 *start1;
    Box1 *end1;
};

#endif // BOARD_H
