#include "gnp.h"
using namespace std;


GNP::GNP(string inputString) {
    MaximumCost = 0;
    if (!readText(inputString)) return;
}

/*
La funzione getMaximumPath() restituisce un vettore contentente i puntatori dei nodi che compongono il percorso di costo massimo, che non attraversa
due volte lo stesso arco, che fa capo all'ultima sorgente passata alla funzione MaximumCostPath().
*/
vector<Node *> GNP::getMaximumPath() {
    return maximumPath;
}

//La funzione getMaximumCost() restituisce il costo del percorso di costo massimo.
unsigned int GNP::getMaximumCost() {
    return MaximumCost;
}

unsigned int GNP::getIslands() {
    return GraphaNui->getVertices();
}
/*
La funzione checkInput() prende in input una stringa corrispondente al nome del file di testo e restituisce un valore booleano, 
TRUE se l'apertura è avvenuta con successo, altrimenti FALSE.
*/
bool GNP::checkInput(string inputString) {
    file.open(inputString.c_str());

    if(!file.fail()){
        cout << "FILE: " << inputString << "\nStatus: Successfully opened!\n" << endl;
        return true;
    }else cout << "Error: cannot open input file!" << endl;
    return false;
}

/*
La funzione readText() prende in input una stringa corrispondente al nome del file di testo e restituisce un valore booleano, 
TRUE se la lettura è avvenuta con successo, altrimenti FALSE.
Inoltre, controlla se il contenuto del file di testo rispetta i vincoli imposti dal quesito.
*/
bool GNP::readText(string inputString) {
    if (!checkInput(inputString)) return false;

    unsigned int PIL, vertices, edges, u, v;
    file >> vertices >> edges;

    cout << "V: " << vertices << "\tE: " << edges << endl << endl;
    GraphaNui = new Graph(vertices, edges);

    for (unsigned int i = 0; i < vertices; ++i) {  //Node added /PIL: x
        file >> PIL;

        GraphaNui->addNode(new Node(PIL));
        cout << "Node " << GraphaNui->getAdj()->at(i)->getID() << ": added! /PIL: " << GraphaNui->getAdj()->at(i)->getPIL() << endl;
    }
    cout << endl;

    for (unsigned int i = 0; i < edges; ++i) {   //Edge: (u,v) added!
        file >> u >> v;

        GraphaNui->addEdge(u,v);
        cout << "Edge (" << u << "," << v <<"): added!" << endl;
    }
    cout << endl;

    file.close();
    return true;
}

/*
La procedura MaximumCostPath() prende in input un puntatore ad un vertice del grafo, corrispondente ad una sorgente, e stampa a video
il costo del percorso di costo massimo e i nodi che lo compongono.
*/
void GNP::MaximumCostPath(unsigned int source) {
    vector<Node *> temporaryVector;
    Node *s = GraphaNui->getNode(source);
    GraphaNui->DFS(s, nullptr, 0, MaximumCost, maximumPath, temporaryVector);
    
    cout << "Source: " << s->getID() << endl;
    cout << "MaximumCost: " << this->MaximumCost << endl;

    for (auto x: this->maximumPath)
        cout << x->getID() << " -> ";
    cout << endl;
}
