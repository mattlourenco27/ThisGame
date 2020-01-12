//
// Created by Matthew Lourenco on 03/01/2020.
//

#include "tileNode.h"

tileNode::tileNode() {
    tile = DEFAULT_TILE;
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    x = 0;
    y = 0;
}

tileNode::tileNode(char _tile) {
    if(_tile != '\t' && _tile != '\n' && _tile != '\0') {
        tile = _tile;
    } else {
        tile = DEFAULT_TILE;
    }
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    x = 0;
    y = 0;
}

tileNode::tileNode(unsigned short _x, unsigned short _y) {
    tile = DEFAULT_TILE;
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    x = _x;
    y = _y;
}

tileNode::tileNode(unsigned short _x, unsigned short _y, char _tile) {
    if(_tile != '\t' && _tile != '\n' && _tile != '\0') {
        tile = _tile;
    } else {
        tile = DEFAULT_TILE;
    }
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    x = _x;
    y = _y;
}

tileNode::tileNode(const tileNode & src) {
    tile = src.tile;
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    x = src.x;
    y = src.y;
}

tileNode::~tileNode() {
    if(top) top->bottom = nullptr;
    if(bottom) bottom->top = nullptr;
    if(left) left->right = nullptr;
    if(right) right->left = nullptr;
}

char tileNode::getTile() {return tile;}
tileNode *tileNode::getTop() {return top;}
tileNode *tileNode::getBottom() {return bottom;}
tileNode *tileNode::getLeft() {return left;}
tileNode *tileNode::getRight() {return right;}
unsigned short tileNode::getX() {return x;}
unsigned short tileNode::getY() {return y;}

void tileNode::setTile(char _tile) {
    if(_tile != '\t' && _tile != '\n' && _tile != '\0') {
        tile = _tile;
    }
}

tileNode *tileNode::setTop(tileNode *ptr) {
    tileNode *tmp = top;
    top = ptr;
    return tmp;
}

tileNode *tileNode::setBottom(tileNode *ptr) {
    tileNode *tmp = bottom;
    bottom = ptr;
    return tmp;
}

tileNode *tileNode::setLeft(tileNode *ptr) {
    tileNode *tmp = left;
    left = ptr;
    return tmp;
}

tileNode *tileNode::setRight(tileNode *ptr) {
    tileNode *tmp = right;
    right = ptr;
    return tmp;
}

void tileNode::setX(unsigned short _x) {
    x = _x;
}

void tileNode::setY(unsigned short _y) {
    y =_y;
}

void tileNode::connectTop(tileNode *ptr) {
    top = ptr;
    if(ptr) ptr->bottom = this;
}

void tileNode::connectBottom(tileNode *ptr) {
    bottom = ptr;
    if(ptr) ptr->top = this;
}

void tileNode::connectLeft(tileNode *ptr) {
    left = ptr;
    if(ptr) ptr->right = this;
}

void tileNode::connectRight(tileNode *ptr) {
    right = ptr;
    if(ptr) ptr->left = this;
}

void tileNode::disconnect() {
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
}

void tileNode::print() {
    cout << "Symbol: " << tile << endl
         << "x: " << x << ", y: " << y << endl;
}

ostream & operator<<(ostream & out, const tileNode & rhs) {
    out << rhs.tile;
    return out;
}