//
// Created by Matthew Lourenco on 03/01/2020.
//

#include "mapPainter.h"

//Constructors & Destructor
mapPainter::mapPainter():linkedMap() {
    destination = "";
}

mapPainter::mapPainter(string src): linkedMap(src) {
    destination = "";
}

mapPainter::mapPainter(const mapPainter & src): linkedMap(src) {
    destination = src.destination;
}

mapPainter::~mapPainter() {
    return;
}

string mapPainter::getDest() {return destination;}

void mapPainter::setDest(string dest) {
    destination = dest;
}

bool mapPainter::setWidth(unsigned short _width){
    if(_width > 4095) return false;
    char** tmpGrid = new char*[height];
    for(int i = 0; i < height; ++i) {

    }

    if(_width > width) {

        for(int i = width; i < _width, ++i) {

        }
    }
}

bool mapPainter::setHeight(unsigned short _height) {

}

bool mapPainter::drawRect(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2,
                          char fill, bool hollow = false);
bool mapPainter::drawLine(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, char fill);
bool mapPainter::drawPoint(unsigned short x, unsigned short y, char fill);

void mapPainter::newMap();
bool mapPainter::save(string dest);
bool mapPainter::save();