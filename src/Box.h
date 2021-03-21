#ifndef Box1_H
#define Box1_H

#include <QPushButton>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include "Dikstra.h"
#include "piece.h"



class piece;
class Dikstra;
class Box1:public QGraphicsRectItem
{
public:

    Box1(QGraphicsItem *parent=0);
    ~Box1();

    //mouseEvents
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void  dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;
    //methods
    void setColor(QColor color);
    void resetOriginalColor();
    void setOriginalColor(QColor value);
    int getNumber();
    void setNumber(int n);
    void placePiece(piece* piece);
    void complementStart();
    void complementFinish();

    piece * currentPiece;
    bool down=false;
    bool isStart;
    bool isFinish;
    bool hasWall;
    static bool dragFromStart;
    static bool dragFromFinish;
    static bool st;
    static bool fn;
    static int nr;
    QBrush brush;
private:
    QColor originalColor;
    int number;
};

#endif // Box1_H
