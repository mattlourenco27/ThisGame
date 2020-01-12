//
// Created by Matthew Lourenco on 03/01/2020.
//

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

mapPainter::~mapPainter() {}

string mapPainter::getDest() {return destination;}

void mapPainter::setDest(string dest) {
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

bool mapPainter::drawRect(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2,
                          char fill, bool hollow) {
    if(x1 >= getWidth() || y1 >= getHeight() ||
       x2 >= getWidth() || y2 >= getHeight() || x1 > x2 || y1 > y2) return false;

    //Find the starting point

}
bool mapPainter::drawLine(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, char fill);
bool mapPainter::drawPoint(unsigned short x, unsigned short y, char fill);

void mapPainter::newMap();
bool mapPainter::save(string dest);
bool mapPainter::save();