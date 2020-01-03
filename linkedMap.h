//
// Created by Matthew Lourenco on 01/01/2020.
//
// This class loads a valid txt file into a linkedMap
//
// Editted by Matthew Lourenco on 03/01/2020
// Changed to a linked map type structure and changed name
//

#ifndef THISGAME_MAP_H
#define THISGAME_MAP_H

#include "tileNode.h"
#define MAX_X 4095
#define MAX_Y 4095

class linkedMap {
private:
    string source;
    bool loaded;

protected:
    tileNode *topLeft;
    tileNode *topRight;
    tileNode *bottomLeft;
    tileNode* bottomRight;

public:
    //Constructors
    linkedMap();
    explicit linkedMap(const string & src);
    linkedMap(const linkedMap & src);

    //Destructor
    virtual ~linkedMap();

    //Accessors
    bool getLoaded();
    string getSource();

    //Utility methods
    bool loadMap(const string & src);
    void unloadMap();
    virtual void print();

    //Operator overloads
    linkedMap & operator=(const linkedMap & rhs);
};


#endif //THISGAME_MAP_H
