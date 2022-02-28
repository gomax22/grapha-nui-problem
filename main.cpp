#include <iostream>
#include <string>
#include "gnp.h"
#include "gnp.cpp"
using namespace std;

int main() {
    unsigned int source = 0;
    string inputString;

    cout << "----------GRAPHA-NUI PROBLEM-------------" << endl;
    cout << "Insert TextFile Name: " << endl;
    getline(cin, inputString);
    GNP instance(inputString);

    cout << "Select a source from Node 0 to Node " << instance.getIslands() -1 << endl; 
    cin >> source; fflush(stdin);

    while (source < 0 || source >= instance.getIslands()) {
        cout << "Error: source not valid!" << endl;
        cout << "Insert a valid input! (0 <= source <= " << instance.getIslands() -1 << ")" << endl;
        cin >> source; fflush(stdin);
        system("cls");
    }
    //system("cls");

    instance.MaximumCostPath(source);
    
    system("pause");
    return 0;
}