//
// Created by Matthew Lourenco on 01/01/2020.
//
// Editted by Matthew Lourenco on 03/01/2020
// Changed to a linked map type structure and changed name
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

#include "linkedMap.h"

using namespace std;

linkedMap::linkedMap() {
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
    source = "";
    loaded = false;
}

linkedMap::linkedMap(const string & src) {
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
    source = "";
    if(!loadMap(src)) loaded = false;
}

linkedMap::linkedMap(const linkedMap & src) {
    source = src.source;
    if(!src.loaded) {
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
        source = "";
        loaded = false;
    }

    tileNode *curL = nullptr;
    tileNode *prevRow = nullptr;
    tileNode *p = src.topLeft;
    tileNode *row = src.topLeft;

    curL = new tileNode(*p);
    p = p->getRight();
    topLeft = curL;
    prevRow = curL;
    while(p) {
        curL->connectRight(new tileNode(*p));
        p = p->getRight();
        curL = curL->getRight();
    }
    topRight = curL;

    row = row->getBottom();
    p = row;
    while(row) {
        prevRow->connectBottom(new tileNode(*p));
        p = p->getRight();
        prevRow = prevRow->getBottom();
        curL = prevRow;
        while(p) {
            curL->connectRight(new tileNode(*p));
            p = p->getRight();
            curL->getTop()->getRight()->connectBottom(curL->getRight());
            curL = curL->getRight();
        }
        row = row->getBottom();
        p = row;
    }
    bottomLeft = prevRow;
    bottomRight = curL;

    loaded = true;
}

linkedMap::~linkedMap() {
    unloadMap();
}

bool linkedMap::getLoaded() {return loaded;}
string linkedMap::getSource() {return source;}
int linkedMap::getWidth() {
    return (topRight->getX() - topLeft->getX() + 1);
}

int linkedMap::getHeight() {
    return (bottomLeft->getY() - topLeft->getY() + 1);
}
char linkedMap::getTile(int x, int y) {
    if(x < 0 || x > (getWidth() - 1) || y < 0 || y > (getHeight() - 1)) return '\0';

    tileNode *p = nullptr;

    if((topRight->getX() - x) < x) {
        if((bottomLeft->getY() - y) < y) {
            p = bottomRight;
        } else {
            p = topRight;
        }
    } else {
        if((bottomLeft->getY() - y) < y) {
            p = bottomLeft;
        } else {
            p = topLeft;
        }
    }

    while(p->getX() != x && p->getY() != y) {
        if(p->getX() > x) p = p->getLeft();
        else if(p->getX() < x) p = p->getRight();
        if(p->getY() > y) p = p->getTop();
        else if(p->getY() < y) p = p->getBottom();
    }

    return p->getTile();
}

void linkedMap::getNextLine(ifstream & file, string & line) {
    getline(file, line);
    if(line.length() > 0) {
        if(line[line.length() - 1] == '\r') {
            line.pop_back();
        }
    }
}

bool linkedMap::loadMap(const string & src) {
    ifstream f(src); //open map file
    if(!f.is_open()) return false;

    unsigned short width = 0;
    unsigned short height = 0;
    string nextLine;

    if(f.eof()) { // Check if map has a height of 1 or more
        f.close();
        return false;
    }

    //Check that new map is rectangular and without '\t' characters
    getNextLine(f, nextLine);
    height++;
    width = nextLine.length();
    if(width == 0 || width > MAX_X) {
        f.close();
        return false;
    }
    if(regex_match(nextLine, regex("\t"))) {
        f.close();
        return false;
    }

    while(!f.eof()) {
        getNextLine(f, nextLine);
        height++;
        if(nextLine.length() != width) {
            f.close();
            return false;
        }
        if(regex_match(nextLine, regex("\t"))) {
            f.close();
            return false;
        }
    }

    if(height > MAX_Y) {
        f.close();
        return false;
    }

    //At this point the map is rectangular and all characters are 'valid'
    //Return the file stream to the beginning
    f.clear();
    f.seekg(0, ios::beg);

    unloadMap();

    tileNode *prevRow = nullptr; //Previous row;
    tileNode *curL = nullptr; //Left node of current position
    unsigned short x = 0;
    unsigned short y = 0;
    char tile;

    //First set up top row of map
    getNextLine(f, nextLine);
    stringstream dataStream(nextLine);
    dataStream >> tile;
    topLeft = new tileNode(x++, y, tile);
    curL = topLeft;
    while(x != width) {
        dataStream >> tile;
        curL->connectRight(new tileNode(x++, y, tile));
        curL = curL->getRight();
    }
    prevRow = topLeft;
    topRight = curL;

    //then set up the rest of the rows
    while(!f.eof()) {
        getNextLine(f, nextLine);
        dataStream.clear();
        //dataStream.ignore(1000, '\n');
        dataStream.str(nextLine);

        dataStream >> tile;
        x = 0;
        y++;
        prevRow->connectBottom(new tileNode(x++, y, tile));
        prevRow = prevRow->getBottom();
        curL = prevRow;
        while(x != width) {
            dataStream >> tile;
            curL->connectRight(new tileNode(x++, y, tile));
            curL->getTop()->getRight()->connectBottom(curL->getRight());
            curL = curL->getRight();
        }
    }
    bottomLeft = prevRow;
    bottomRight = curL;

    source = src;
    loaded = true;
    f.close();
    return true;
}

void linkedMap::unloadMap() {
    tileNode *t = nullptr;
    tileNode *p = topLeft;
    tileNode *row = topLeft;
    while(row) {
        row = row->getBottom();
        while(p) {
            t = p->getRight();
            delete p;
            p = t;
        }
        p = row;
    }

    loaded = false;
    source = "";
}

void linkedMap::print() {
    if(!loaded) cout << "Map is not loaded" << endl;
    cout << "Source: " << source << endl;

    tileNode *p = topLeft;
    tileNode *row = topLeft;
    while(row) {
        row = row->getBottom();
        while(p) {
            cout << *p;
            p = p->getRight();
        }
        cout << endl;
        p = row;
    }
}

linkedMap & linkedMap::operator=(const linkedMap & rhs) {
    if(this == &rhs) return *this;
    source = rhs.source;
    unloadMap();

    if(!rhs.loaded) return *this;

    tileNode *curL = nullptr;
    tileNode *prevRow = nullptr;
    tileNode *p = rhs.topLeft;
    tileNode *row = rhs.topLeft;

    curL = new tileNode(*p);
    p = p->getRight();
    topLeft = curL;
    prevRow = curL;
    while(p) {
        curL->connectRight(new tileNode(*p));
        p = p->getRight();
        curL = curL->getRight();
    }
    topRight = curL;

    row = row->getBottom();
    p = row;
    while(row) {
        prevRow->connectBottom(new tileNode(*p));
        p = p->getRight();
        prevRow = prevRow->getBottom();
        curL = prevRow;
        while(p) {
            curL->connectRight(new tileNode(*p));
            p = p->getRight();
            curL->getTop()->getRight()->connectBottom(curL->getRight());
            curL = curL->getRight();
        }
        row = row->getBottom();
        p = row;
    }
    bottomLeft = prevRow;
    bottomRight = curL;

    loaded = true;
    return *this;
}
