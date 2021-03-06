//
// Created by Matthew Lourenco on 03/01/2020.
//

#ifndef THISGAME_MAPPAINTER_H
#define THISGAME_MAPPAINTER_H

#include "linkedMap.h"
#include "arrayMap.h"
#define DEFAULT_FILE_NAME "out_file.txt"

class mapPainter: public linkedMap {
protected:
    string destination;
public:
    //Constructors & Destructor
    mapPainter();
    explicit mapPainter(const string & src);
    mapPainter(unsigned short _width, unsigned short _height);
    mapPainter(const mapPainter & src);
    ~mapPainter() override;

    //Accessors and Mutators
    string getDest();
    void setDest(const string & dest);
    bool setWidth(unsigned short _width);
    bool setHeight(unsigned short _height);

    //Utility methods
    //Draws a rectangle across (x1, y1) and (x2, y2)
    //The following must be true (x1 <= x2 AND y1 <= y2)
    bool drawRect(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2,
                  char fill, bool hollow = false);
    bool drawLine(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, char fill);
    bool drawPoint(unsigned short x, unsigned short y, char fill);

    void newMap();
    bool save(const string & dest);
    bool save();
    void print() override;

    //Conversion
    arrayMap toArrayMap();

    //Operator overloads
    mapPainter & operator=(const mapPainter & rhs);
};


#endif //THISGAME_MAPPAINTER_H
