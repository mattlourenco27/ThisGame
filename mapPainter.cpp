//
// Created by Matthew Lourenco on 03/01/2020.
//

#include <cmath>
#include "mapPainter.h"

//Constructors & Destructor
mapPainter::mapPainter():linkedMap() {
    destination = "";
}

mapPainter::mapPainter(const string & src): linkedMap(src) {
    destination = "";
}

mapPainter::mapPainter(const mapPainter & src): linkedMap(src) {
    destination = src.destination;
}

mapPainter::~mapPainter() = default;

string mapPainter::getDest() {return destination;}

void mapPainter::setDest(const string & dest) {
    destination = dest;
}

//Deletes or adds columns from the right
bool mapPainter::setWidth(unsigned short _width) {
    if(_width > MAX_X) return false;
    if(_width < 1) return false;

    //Determine if columns must be added or subtracted
    int diff = _width - getWidth();
    if(diff > 0) { //Add columns
        tileNode *p;
        int x, y;
        while(_width - getWidth() > 0) {
            x = topRight->getX() + 1;
            y = 0;
            topRight->connectRight(new tileNode(x, y++));
            topRight = topRight->getRight();
            p = topRight;
            while(p->getLeft()->getBottom()) {
                p->connectBottom(new tileNode(x, y++));
                p->getLeft()->getBottom()->connectRight(p->getBottom());
                p = p->getBottom();
            }
            bottomRight = p;
        }
    } else if(diff < 0) { //Remove columns
        tileNode *p;
        while(_width - getWidth() < 0) {
            p = topRight;
            topRight = topRight->getLeft();
            while(p->getBottom()) {
                p = p->getBottom();
                delete p->getTop();
            }
            bottomRight = p->getLeft();
            delete p;
        }
    }
    return true;
}

//Deletes or adds rows from the bottom
bool mapPainter::setHeight(unsigned short _height) {
    if(_height > MAX_Y) return false;
    if(_height < 1) return false;

    //Determine if rows must be added or subtracted
    int diff = _height - getHeight();
    if(diff > 0) { //Add rows
        tileNode *p;
        int x, y;
        while(_height - getHeight() > 0) {
            x = 0;
            y = bottomLeft->getY() + 1;
            bottomLeft->connectBottom(new tileNode(x++, y));
            bottomLeft = bottomLeft->getBottom();
            p = bottomLeft;
            while(p->getTop()->getRight()) {
                p->connectRight(new tileNode(x++, y));
                p->getTop()->getRight()->connectBottom(p->getRight());
                p = p->getRight();
            }
            bottomRight = p;
        }
    } else if(diff < 0) { //Remove rows
        tileNode *p;
        while(_height - getHeight() < 0) {
            p = bottomLeft;
            bottomLeft = bottomLeft->getTop();
            while(p->getRight()) {
                p = p->getRight();
                delete p->getLeft();
            }
            bottomRight = p->getTop();
            delete p;
        }
    }
    return true;
}

bool mapPainter::drawRect(unsigned short x1, unsigned short y1,
                          unsigned short x2, unsigned short y2,
                          char fill, bool hollow) {

    if(x1 >= getWidth() || y1 >= getHeight() ||
       x2 >= getWidth() || y2 >= getHeight() ||
       x1 > x2 || y1 > y2) return false;

    //Find the starting point
    tileNode *p = getNode(x1, y1);
    if(!p) return false;

    if(hollow) { //Travel in a loop
        while(p->getY() < y2) {
            p = p->getBottom();
            p->setTile(fill);
        }
        while(p->getX() < x2) {
            p = p->getRight();
            p->setTile(fill);
        }
        while(p->getY() > y1) {
            p = p->getTop();
            p->setTile(fill);
        }
        while(p->getY() > x1) {
            p = p->getLeft();
            p->setTile(fill);
        }
    } else { //travel column by column
        tileNode *topC; //Top of current column
        while(p->getX() <= x2) {
            topC = p;
            while(p->getY() <= y2) {
                p->setTile(fill);
                p = p->getBottom();
            }
            p = topC->getRight();
        }
    }
    return true;
}

bool mapPainter::drawLine(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, char fill) {
    if(x1 >= getWidth() || y1 >= getHeight() ||
       x2 >= getWidth() || y2 >= getHeight()) return false;

    //Find the starting point
    tileNode *p = getNode(x1, y1);
    if(!p) return false;
    p->setTile(fill);

    if(x1 == x2 && y2 == y1) return true;

    if(abs(y2 - y1) < abs(x2 - x1)) { //Use X as independent variable
        double slope = (double) (y2 - y1) / (double) (x2 - x1);

        if(x1 > x2) { //Case where starting point is further right than ending point
            for(int i = x2; i <= x1; i++) {
                p = getNodefrom(i, round(y2 + slope*(i - x2)), p);
                p->setTile(fill);
            }
        } else {
            for(int i = x1; i <= x2; i++) {
                p = getNodefrom(i, round(y1 + slope*(i - x1)), p);
                p->setTile(fill);
            }
        }
    } else { //Use Y as independent variable
        double slope = (double) (x2 - x1) / (double) (y2 - y1);

        if(y1 > y2) { //Case where starting point is further down than ending point
            for(int i = y2; i <= y1; i++) {
                p = getNodefrom(round(x2 + slope*(i - y2)), i, p);
                p->setTile(fill);
            }
        } else {
            for(int i = y1; i <= y2; i++) {
                p = getNodefrom(round(x1 + slope*(i - y1)), i, p);
                p->setTile(fill);
            }
        }
    }
    return true;
}

bool mapPainter::drawPoint(unsigned short x, unsigned short y, char fill) {
    if(x >= getWidth() || y >= getHeight()) return false;
    tileNode *p = getNode(x, y);
    if(!p) return false;
    p->setTile(fill);
    return true;
}

void mapPainter::newMap();
bool mapPainter::save(string dest);
bool mapPainter::save();