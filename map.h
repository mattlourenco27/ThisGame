//
// Created by Matthew Lourenco on 01/01/2020.
//
// This class loads a valid map file
//

#ifndef THISGAME_MAP_H
#define THISGAME_MAP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

class map {
private:
    string source;
    bool loaded;

protected:
    char** grid;
    unsigned short width, height;

public:
    //Constructors
    map();
    explicit map(const string & src);
    map(const map & src);

    //Destructor
    virtual ~map();

    //Accessors
    bool getLoaded();
    int getWidth();
    int getHeight();
    string getSource();
    char getTile(unsigned short x, unsigned short y);

    //Utility methods
    bool loadMap(const string & src);
    virtual void print();

    //Operator overloads
    map & operator=(const map & rhs);
};


#endif //THISGAME_MAP_H
