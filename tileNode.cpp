//
// Created by Matthew Lourenco on 03/01/2020.
//

#include "tileNode.h"

tileNode::tileNode() {
    tile = '*';
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
}

tileNode::tileNode(char _tile) {
    if(_tile != ' ' && _tile != '\t' && _tile != '\n') {
        tile = _tile;
    } else {
        tile = '*';
    }
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
}

tileNode::tileNode(const tileNode & src) {
    tile = src.tile;
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
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

void tileNode::setTile(char _tile) {
    if(_tile != ' ' && _tile != '\t' && _tile != '\n') {
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

void tileNode::disconnect() {
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
}

void tileNode::print() {
    cout << tile;
}