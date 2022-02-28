#include "node.h"
using namespace std;

Node::Node(unsigned int PIL){
    colorNode = WHITE;
    p = nullptr;
    cost = 0;
    adj = new list<Node *>;
    this->PIL = PIL;
}

void Node::setID(unsigned int value) {
    id = value;
}

void Node::setPIL(int value) {
    PIL = value;
}

void Node::setCost(int cost) {
    this->cost = cost;
}

void Node::setP(Node *x) {
    this->p = x;
}

void Node::setColor(color c) {
    colorNode = c;
}

unsigned int Node::getID() {
    return id; 
}

unsigned int Node::getPIL() {
    return PIL; 
}

unsigned int Node::getCost(){
    return cost;
}

Node *Node::getP() {
    return p;
}

list<Node *> *Node::getAdj() {
    return adj;
}

color Node::getColor() {
    return colorNode;
}


