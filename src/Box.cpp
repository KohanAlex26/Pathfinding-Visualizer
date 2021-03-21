#include <QDebug>
#include <QLabel>
#include <QDrag>
#include <QMimeData>
#include <QApplication>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>

#include "Box.h"
#include "game.h"
#include "start.h"
#include "piece.h"

extern Game *game;
extern Dikstra *dikstra;
extern piece *piece1;
extern piece *piece2;
bool Box1::dragFromStart=false;
bool Box1::dragFromFinish=false;
bool Box1::st=false;
bool Box1::fn=false;
int Box1::nr=-1;
Box1::Box1(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    hasWall=0;
    dragFromFinish=false;
    dragFromStart=false;
    isStart=false;
    isFinish=false;
    setRect(0,0,30,30);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    currentPiece = NULL;
    setAcceptDrops(true);
    setAcceptedMouseButtons(Qt::LeftButton);

}

Box1::~Box1()
{
    delete this;
}


void Box1::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}


void Box1::resetOriginalColor()
{
    setColor(originalColor);
}


void Box1::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}

int Box1::getNumber()
{
    return number;
}

void Box1::setNumber(int n)
{
    this->number=n;
}

void Box1::placePiece(piece* piece)
{
    piece->setPos(x()+15- piece->pixmap().width()/2  ,y()+15-piece->pixmap().width()/2);
    piece->setCurrentBox(this);
    currentPiece = piece;
}



void Box1::complementStart()
{
    if(isStart==true)
        isStart=false;
    else
    {
        isStart=true;
//        setAcceptDrops(false);
    }
}

void Box1::complementFinish()
{
    if(isFinish==true)
        isFinish=false;
    else
    {
        isFinish=true;
//        setAcceptDrops(false);
    }
}

void Box1::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->board->list.at(dikstra->s)->setAcceptDrops(true);
    game->board->list.at(dikstra->f)->setAcceptDrops(true);

    if(isFinish!=true && isStart!=true)
    {
        setCursor(Qt::ClosedHandCursor);
        if(brush==Qt::blue)
        {
            hasWall=true;
            this->setColor(Qt::lightGray);
            dikstra->addEdgesForNode(this->getNumber());
            nr=this->getNumber();
        }
            else
        {
            this->setColor(Qt::blue);
            dikstra->addWall(this->getNumber());
            nr=this->getNumber();
        }
    }
    if(isStart==true)
    {
         dragFromStart=true;
         game->board->list.at(dikstra->f)->setAcceptDrops(false);
    }
    if(isFinish==true)
    {
        dragFromFinish=true;
        game->board->list.at(dikstra->s)->setAcceptDrops(false);
    }
//    qDebug()<<"start";
//    qDebug()<<g->board->list.at(g->src)->acceptDrops();
//    qDebug()<<"finish";
//    qDebug()<<g->board->list.at(g->f)->acceptDrops();
//    qDebug()<<"";
}


void Box1::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    qDebug()<<"Mouse move Event";
//    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
//              .length() < QApplication::startDragDistance()) {
////              QGraphicsRectItem::mouseMoveEvent(event);
//               return;
//          }
          QDrag *drag = new QDrag(event->widget());
          QMimeData *mime = new QMimeData;
          drag->setMimeData(mime);
//          drag->setHotSpot(QPoint(30,30));
          drag->exec();
}

void Box1::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{

        qDebug()<<"Drag Enter";
    if(isStart!=true && isFinish!=true && dragFromStart!=true && dragFromFinish!=true)
        if(brush==Qt::lightGray)
        {
            hasWall=true;
            this->setColor(Qt::blue);
            dikstra->addWall(this->getNumber());
        }
        else
        {
            this->setColor(Qt::lightGray);
            dikstra->addEdgesForNode(this->getNumber());
        }
    if(dragFromStart == true && isFinish!=true && isStart!=true)
    {
//        currentPiece->setPos(x()+115- currentPiece->pixmap().width()/2  ,y()+115-currentPiece->pixmap().width()/2);
//        piece *piece2;
//        piece2=new start();
//        currentPiece->setCurrentBox(piece2);
        isStart=true;
        this->setColor(Qt::green);
        this->placePiece(piece1);

    }
    if(dragFromFinish == true && isFinish!=true && isStart!=true)
    {
//        currentPiece->setPos(x()+75- currentPiece->pixmap().width()/2  ,y()+75-currentPiece->pixmap().width()/2);
//        currentPiece->setCurrentBox(this);
        isFinish=true;
        this->setColor(Qt::red);
        this->placePiece(piece2);
    }
    if(isStart==true)
        st=true;
    else
        st=false;
    if(isFinish==true)
        fn=true;
    else
        fn=false;
}

void Box1::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
nr=-1;
    qDebug()<<"Drag leave";
    if(dragFromStart == true && fn==false)
     {
        if(this->hasWall==true)
            this->setColor(Qt::blue);
        else
        this->setColor(Qt::lightGray);
        isStart=false;
     }
    if(dragFromFinish == true && st==false)
     {
        if(this->hasWall==true)
            this->setColor(Qt::blue);
        else
            this->setColor(Qt::lightGray);
        isFinish=false;
     }
}

void Box1::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug()<<"Drop";
    qDebug()<<"";
    if(dragFromStart==true)
    {
        dikstra->s=this->getNumber();
    }
    if(dragFromFinish==true)
    {
        dikstra->f=this->getNumber();
    }
    dragFromStart=false;
    dragFromFinish=false;
}

void Box1::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::OpenHandCursor);
}

void Box1::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug()<<"drag Move Event";
}
