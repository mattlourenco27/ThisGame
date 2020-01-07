//
// Created by Matthew Lourenco on 03/01/2020.
//

#ifndef THISGAME_MAPPAINTER_H
#define THISGAME_MAPPAINTER_H

#include "linkedMap.h"

class mapPainter: public linkedMap {
protected:
    string destination;
public:
    //Constructors & Destructor
    mapPainter();
    explicit mapPainter(string src);
    mapPainter(const mapPainter & src);
    virtual ~mapPainter();

    //Accessors and Mutators
    string getDest();
    void setDest(string dest);
    bool setWidth(unsigned short _width);
    bool setHeight(unsigned short _height);

    //Utility methods
    bool drawRect(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2,
                  char fill, bool hollow = false);
    bool drawLine(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, char fill);
    bool drawPoint(unsigned short x, unsigned short y, char fill);

    void newMap();
    bool save(string dest);
    bool save();

    //Operator overloads
    mapPainter & operator=(const mapPainter & rhs);
};


#endif //THISGAME_MAPPAINTER_H
