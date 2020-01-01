//
// Created by Matthew Lourenco on 01/01/2020.
//
// This class loads a valid map file
//

#ifndef THISGAME_MAP_H
#define THISGAME_MAP_H

#include <iostream>
#include <fstream>
using namespace std;

class map {
private:
    char** grid;
    string source;

public:
    map();
    map(const map & src);
    virtual ~map();
    bool loadMap(char* src);
    virtual void print();
};


#endif //THISGAME_MAP_H
