#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include "node.cpp"
using namespace std;

class Graph{
private:
    unsigned int vertices, edges;
    unsigned int counterID;
    vector<Node *> *adj;
    
    void setVertices(unsigned int v);
    void setEdges(unsigned int e);
public:
    Graph(unsigned int v, unsigned int e);
    ~Graph() {}
    void addNode(Node *w);
    void addEdge(unsigned int u, unsigned int v);
    void DFS(Node *u, Node *parent, unsigned int cost, unsigned int &MaximumCost, vector<Node *> &maximumPath, vector<Node *> &temporaryVector);
    unsigned int getVertices();
    unsigned int getEdges();
    Node *getNode(unsigned int v);
    vector<Node*> *getAdj(); 
};
#endif /* GRAPH_H */