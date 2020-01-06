//
// Created by Matthew Lourenco on 01/01/2020.
//
// This class loads a valid map file
//

#ifndef THISGAME_ARRAYMAP_H
#define THISGAME_ARRAYMAP_H

#include <iostream>
#define MAX_X 4095
#define MAX_Y 4095

using namespace std;

class arrayMap {
private:
    char** grid;
    string source;
    int width, height;
    bool loaded;

    void getNextLine(ifstream & file, string & line);

public:
    //Constructors
    arrayMap();
    explicit arrayMap(const string & src);
    arrayMap(const arrayMap & src);

    //Destructor
    virtual ~arrayMap();

    //Accessors
    bool getLoaded();
    int getWidth();
    int getHeight();
    string getSource();
    char getTile(int x, int y);

    //Utility methods
    bool loadMap(const string & src);
    virtual void print();

    //Operator overloads
    arrayMap & operator=(const arrayMap & rhs);
};


#endif //THISGAME_ARRAYMAP_H
