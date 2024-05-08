#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "menu.h"
using namespace std;

struct Lvl {
    string word;
    string advice;
    void print();
};

queue<Lvl> loadLevels();

void ejemplo1() {
    cout << "ejemplo 1";
}

void ejemplo2() {
    cout << "ejemplo 2";
}

void ejemplo3() {
    cout << "ejemplo 3";
}

int main() {

    vector<MenuFunction> funcionesDelMenu
    {
        {"Ejm 1", &ejemplo1},
        {"Ejm 2", &ejemplo2},
        {"Ejm 3", &ejemplo3},
    };
    
    MainMenu menu{ "Titulo", funcionesDelMenu };

    menu.run();

    /*

    queue<Lvl> colaxd = loadLevels();

    while (!colaxd.empty()) {
        colaxd.front().print();
        colaxd.pop();
    }

    */

    return 0;
}

void Lvl::print() {
    cout << word << ":" << endl;
    cout << advice << endl;
}

queue<Lvl> loadLevels() {
    srand(time(0));
    vector<Lvl> list;
    queue<Lvl> levelQueue;

    Lvl w1 = { "Entero" , "Sirven para..." };
    Lvl w2 = { "Vector" , ".."};
    Lvl w3 = { "Cola" , "..."};
    Lvl w4 = { "Pila" , "...."};
    Lvl w5 = { "Arreglo" , "....."};

    list.push_back(w1);
    list.push_back(w2);
    list.push_back(w3);
    list.push_back(w4);
    list.push_back(w5);

    
    while(!list.empty()) {
        int index = rand() % list.size();
        levelQueue.push(list[index]);
        list.erase(next(list.begin(),index));
    }

    return levelQueue;
}