// Allocates memory for adjacency list
#include <QtDebug>
#include <QVector>
#include <Queue>
#include <vector>

#include "Dikstra.h"
#include "Board.h"
#include "Button.h"
#include "game.h"

extern Game *game;
extern piece *piece1;
extern piece *piece2;
Dikstra::Dikstra(int V,QWidget *parent):QGraphicsView(parent)
{
    this->V = V;
    s=0;
    f=V-1;
    adj = new list<iPair>[V];
    createEdges();
}

void Dikstra::createEdges()
{
    for (int i = 0; i < V; i++)
    {
        std::vector<int> list = neighbours(i);
        for (int j = 0; j < list.size(); j++)
        {
            addEdge(i, list[j],1);
        }
    }
}

void Dikstra::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Dikstra::shortestPath(int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair>, greater<iPair> > pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;

    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
        std::cout << "---------------------------"<<endl;
        std::cout << "u = "<<u << endl;
        std::cout << "---------------------------"<<endl;
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
            std::cout << "node = " << v << endl << "weight = " << weight<<endl;
            std::cout << endl;
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

std::vector<int> Dikstra::neighbours(int x)
{
    std::vector<int> listN;
    int nr = sqrt(this->getNodes());
    //std::cout <<"nr: "<< nr << "\n";
    if (x % nr != 0)
    {
       /* std::cout << 1 << "\n";*/
        listN.push_back(x - 1);
    }

    if ((x + 1) % nr != 0)
    {
        /*std::cout << 2 << "\n";*/
        listN.push_back(x + 1);
    }
    if (x >= nr)
    {
       /* std::cout << 3 << "\n";*/
        listN.push_back(x - nr);
    }
    if (x + nr < nr * nr)
    {
      /*  std::cout << 4 << "\n";*/
        listN.push_back(x + nr);
    }
    return listN;
}

int Dikstra::getNodes()
{
    return this->V;
}


void Dikstra::showDikstra()
{
    for (int i = 0;i <= 24;i++)
    {
        std::cout <<"-----------"<< i << endl;
        list< pair<int, int> >::iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); it++)
            std::cout << it->first << " " << it->second << endl;
    }
}
void Dikstra::addWall(int x)
{
    //std::cout << "-----------------------------------"<<endl;
    std::vector<int> adjunct = neighbours(x);
    list< pair<int, int> >::iterator it;
    //std::cout << "-----------------------------------"<< x<<endl;
    //for (it = adj[x].begin(); it != adj[x].end(); it++)
    //    std::cout << it->first << " " << it->second << endl;
    adj[x].clear();
    //for (int j = 0;j < adjunct.size(); j++)
    //    std::cout << adjunct[j]<<" ";
    //std::cout << endl;
    for (int i = 0; i < adjunct.size(); i++)
    {
        list< pair<int, int> >::iterator it;
        it = adj[adjunct[i]].begin();
        while (it != adj[adjunct[i]].end())
            //for (it = adj[adjunct[i]].begin(); it != adj[adjunct[i]].end(); it++)
        {
            if (it->first == x)
            {
                it = adj[adjunct[i]].erase(it);
            }
            else
                it++;
        }
    }
    //std::cout << "-----------------------------------"<<endl;
}


void Dikstra::shortestPathBetweenTwo()
{
    list<int>* elems= new list<int>[V];
    for (int i = 0;i < V;i++)
        elems[i].push_back(0);
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.

    priority_queue< iPair, vector <iPair>, greater<iPair> > pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, s));
    dist[s] = 0;

    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {

            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                //insert a list to another
                elems[v].clear();
                elems[v].insert(elems[v].end(), elems[u].begin(), elems[u].end());
                elems[v].push_back(v);
            }
        }


    }


    for (int i = 0; i < game->board->list.size(); i++)
    {
        if(game->board->list[i]->isStart!=true && game->board->list[i]->isFinish!=true &&  game->board->list[i]->brush!=Qt::blue)
        {
            game->board->list[i]->setColor(Qt::lightGray);
        }
    }

    list<int>::iterator iter;
    for (iter = elems[f].begin(); iter != elems[f].end(); iter++)
    {
         if(iter != elems[f].begin() && iter != --elems[f].end())
         game->board->list.at(*iter)->setColor(QColor(255, 0, 0, 127));
    }

}


void Dikstra::addEdgesForNode(int x)
{
        std::vector<int> list = neighbours(x);
        for (int j = 0; j < list.size(); j++)
        {
            addEdge(x, list[j],1);
        }
}

void Dikstra::clearBoard()
{
    s=0;
    f=624;
           for (int i=1;i<game->board->list.size()-1;i++)
           {
               game->board->list.at(i)->setColor(Qt::lightGray);
           }
           game->board->list.at(0)->setColor(Qt::green);
           game->board->list.at(624)->setColor(Qt::red);
           adj = new list<iPair>[V];
           createEdges();
   game->board->list.at(s)->currentPiece->setCurrentBox(NULL);
   game->board->list.at(f)->currentPiece->setCurrentBox(NULL);
   game->board->list.at(s)->placePiece(piece1);
   game->board->list.at(f)->placePiece(piece2);
}

