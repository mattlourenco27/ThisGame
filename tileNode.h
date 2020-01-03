//
// Created by Matthew Lourenco on 03/01/2020.
//

#ifndef THISGAME_TILENODE_H
#define THISGAME_TILENODE_H

#include <iostream>
using namespace std;

class tileNode {
private:
    char tile;
    tileNode *top, *bottom, *left, *right;
public:
    //Constructors & destructor
    tileNode();
    tileNode(char _tile);
    tileNode(const tileNode & src);
    ~tileNode();

    //Accessors
    char getTile();
    tileNode *getTop();
    tileNode *getBottom();
    tileNode *getLeft();
    tileNode *getRight();

    //Mutators
    void setTile(char _tile);
    tileNode *setTop(tileNode *ptr);
    tileNode *setBottom(tileNode *ptr);
    tileNode *setLeft(tileNode *ptr);
    tileNode *setRight(tileNode *ptr);

    //Utility methods
    void disconnect();
    void print();
};


#endif //THISGAME_TILENODE_H
