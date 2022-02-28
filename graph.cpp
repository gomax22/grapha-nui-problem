#include "graph.h"
#include <iostream>
using namespace std;


Graph::Graph(unsigned int v, unsigned int e) {
    setVertices(v);
    setEdges(e);
    adj = new vector<Node*>;
    counterID = 0; 
}

void Graph::setVertices(unsigned int v) {
    this->vertices = v;
}
void Graph::setEdges(unsigned int e) {
    this->edges = e;
}
/*
Il costruttore con parametro prende in input la stringa corrispondente al nome del file di testo e 
si occupa di inizializzare gli attributi del grafo e successivamente leggere il contenuto del file di testo a meno di errori causati
dal mancato soddisfacimento dei vincoli imposti dal quesito.
*/

//La procedura addNode() prende in input il puntatore ad un nodo e inserisce il nodo all'interno del grafo.
void Graph::addNode(Node *w) {
    w->setID(counterID); this->counterID += 1; adj->push_back(w); 
}

//La procedura addEdge() prende in input l'ID dei nodi collegati da un arco ed aggiunge questo all'interno del grafo.
void Graph::addEdge(unsigned int u, unsigned int v){
        getNode(u)->getAdj()->push_back(getNode(v));
        getNode(v)->getAdj()->push_back(getNode(u));
}

//La funzione getNode() prende in input l'ID di un nodo e resituisce il suo puntatore.
Node *Graph::getNode(unsigned int v){
    return adj->at(v);
}

//La funzione getVertices() restituisce il numero di vertici del grafo.
unsigned int Graph::getVertices() {
    return vertices;
}

//La funzione getVertices() restituisce il numero di archi del grafo.
unsigned int Graph::getEdges() {
    return edges;
}

vector<Node*> *Graph::getAdj() {
    return adj;
}

/*
La procedura Wrapper_DFS() è una procedura ausiliaria ricorsiva che permette di trovare il percorso di costo massimo corrispondente 
ad un vertice indicato come sorgente.
Questa procedura prende in input:
  - un puntatore al nodo che stiamo visitando
  - un puntatore al nodo da cui proveniamo
  - il costo accumulato fino al nodo che stiamo visitando
  - un vettore di puntatore a nodo che contiene il percorso aggiornato chiamata per chiamata

Il percorso di costo massimo viene memorizzato nell'attributo MaximumPath.
*/
void Graph::DFS(Node *u, Node *parent, unsigned int cost, unsigned int &MaximumCost, vector<Node *> &maximumPath, vector<Node *> &temporaryVector) {
    if (u->getColor() == BLACK) {
        return;
    }

    if (u->getColor() == LIGHTGRAY) {                           // se il nodo è già stato visitato in precedenza, tutti i nodi del ciclo
        Node *cur = parent;                                     //vengono impostati a DARKGRAY
        cur->setColor(DARKGRAY);
        cur->setCost(cost);

        while (cur != u) {
            cur = cur->getP();
            cur->setColor(DARKGRAY);
            cur->setCost(cost);
        }
        return;
    }

    if (u->getColor() == DARKGRAY) u->setColor(BLACK);              //i nodi di un ciclo, quando vengono ispezionati una seconda volta, vengono impostati a nero

    if (u->getColor() == WHITE) {                                   //i nodi appena visitati vengono impostati a LIGHTGRAY
        u->setColor(LIGHTGRAY);
        u->setCost(cost + u->getPIL());
    }

    u->setP(parent);
    temporaryVector.push_back(u);                                    //vettore/stack per tenere traccia del percorso
    
    for (auto v: *u->getAdj()) {
        if (v == u->getP()) continue;                                
        if (u->getColor() == BLACK && v->getColor() == LIGHTGRAY) continue;         //i nodi che fanno parte di un ciclo non possono visitare i nodi già visitati ma non appartenenti al ciclo poichè percorreremmo due volte lo stesso arco
        DFS(v, u, u->getCost(), MaximumCost, maximumPath, temporaryVector);
    }
 
    
    if (u->getCost() > MaximumCost)  {
        MaximumCost = u->getCost();
        maximumPath = temporaryVector;
    } else if (u->getCost() == MaximumCost && temporaryVector.size() > maximumPath.size()) {     //a parità di costo, viene preso il percorso
        maximumPath = temporaryVector;                                                           //la cui lunghezza è maggiore
    }

    if(u->getColor() == LIGHTGRAY)              //imposto il colore delle foglie a bianco per esaminare tutti i percorsi
        u->setColor(WHITE);

    temporaryVector.pop_back();
}
