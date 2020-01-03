//
// Created by Matthew Lourenco on 03/01/2020.
//

#ifndef THISGAME_MAPPAINTER_H
#define THISGAME_MAPPAINTER_H

#include "map.h"

class mapPainter: public map {
public:
    //Constructors & Destructor
    mapPainter();
    mapPainter(string src);
    mapPainter(map src);
    ~mapPainter();

    //Utility methods
    bool drawRect(int x1, int y1, int x2, int y2);
    bool drawLine(int x1, int y1, int x2, int y2);
    bool drawPoint(int x, int y);
};


#endif //THISGAME_MAPPAINTER_H
