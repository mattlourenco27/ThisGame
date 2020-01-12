//
// Created by Matthew Lourenco on 03/01/2020.
//

#ifndef THISGAME_TILENODE_H
#define THISGAME_TILENODE_H

#include <iostream>

#define DEFAULT_TILE '*'

using namespace std;

class tileNode {
private:
    char tile;
    tileNode *top, *bottom, *left, *right;
    unsigned short x, y; //coordinates
public:
    //Constructors & destructor
    tileNode();
    explicit tileNode(char _tile);
    tileNode(unsigned short _x, unsigned short _y);
    tileNode(unsigned short _x, unsigned short _y, char _tile);
    tileNode(const tileNode & src);
    ~tileNode();

    //Accessors
    char getTile();
    tileNode *getTop();
    tileNode *getBottom();
    tileNode *getLeft();
    tileNode *getRight();
    unsigned short getX();
    unsigned short getY();

    //Mutators
    void setTile(char _tile);
    tileNode *setTop(tileNode *ptr);
    tileNode *setBottom(tileNode *ptr);
    tileNode *setLeft(tileNode *ptr);
    tileNode *setRight(tileNode *ptr);
    void setX(unsigned short _x);
    void setY(unsigned short _y);

    //Utility methods
    void connectTop(tileNode *ptr);
    void connectBottom(tileNode *ptr);
    void connectLeft(tileNode *ptr);
    void connectRight(tileNode *ptr);
    void disconnect();
    void print();

    friend ostream & operator<<(ostream & out, const tileNode & rhs);
};


#endif //THISGAME_TILENODE_H
