#ifndef DIKSTRA_H
#define DIKSTRA_H
#pragma once
// Program to find Dijkstra's shortest path using
// priority_queue in STL


#include<iostream>
#include <list>
#include <vector>
#include <QGraphicsView>
#include <QGraphicsItemGroup>
#include <QPointF>



using namespace std;
# define INF 0x3f3f3f3f

// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed Dikstra using
// adjacency list representation
class Board;
class Dikstra:public QGraphicsView
{
Q_OBJECT
    // No. of vertices
    int V;

    // In a weighted Dikstra, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;

public:
    int s,f;

    // Constructor
    Dikstra(int V,QWidget *parent = 0);

    void createEdges();
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
    void addWall(int x);
    int getNodes();
    void showDikstra();
    void addEdgesForNode(int x);
    void clearBoard();
    //  void shortestPathBetweenTwo(int s, int f);

    //
    bool down;
    QPointF m_last_pos;
    QGraphicsItemGroup * m_group;
    std::vector<int> neighbours(int x);
public slots:
    void shortestPathBetweenTwo();

//
//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
};



#endif // DIKSTRA_H
