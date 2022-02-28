#ifndef GNP_H
#define GNP_H

#include "graph.h"
#include "graph.cpp"
#include <fstream>
using namespace std;

//Grapha-Nui Problem
class GNP {
private:
    unsigned int MaximumCost;
    vector<Node *> maximumPath;
    Graph *GraphaNui;
    ifstream file;

    bool checkInput(string inputString);
    bool readText(string inputString);
public:
    GNP(string inputString);
    ~GNP() {}
    void MaximumCostPath(unsigned int source);
    unsigned int getMaximumCost();
    unsigned int getIslands();
    vector<Node *> getMaximumPath();
};


#endif /* GNP_H */