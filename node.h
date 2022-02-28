#ifndef NODE_H
#define NODE_H

#include <list>
#include <vector>
using namespace std;

typedef enum {WHITE = 0, LIGHTGRAY = 1, DARKGRAY = 2, BLACK = 3}color;
/* 
WHITE = nodo non ancora visitato
LIGHTGRAY = nodo visitato
DARKGRAY = nodo che appartiene ad un ciclo
BLACK = nodo che appartiene ad un ciclo visitato due volte, le adiacenze verso nodi già visitati non possono essere attraversate
*/

class Node{
    unsigned int id;
    unsigned int PIL;
    unsigned int cost;          //memorizza il costo del percorso
    Node *p;
    list<Node* > *adj;
    color colorNode;
public:
    Node(unsigned int PIL);
    void setID(unsigned int value);
    void setPIL(int value);
    void setCost(int cost);
    void setP(Node *x);
    void setColor(color c);
    unsigned int getID();
    unsigned int getPIL();
    unsigned int getCost();
    Node *getP();
    list<Node *> *getAdj();
    color getColor();
};

#endif /* NODE_H */