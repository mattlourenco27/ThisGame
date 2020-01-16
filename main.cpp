//
// Created by Matthew Lourenco on 01/01/2020.
//

#include <iostream>
#include "linkedMap.h"
#include "arrayMap.h"
#include "mapPainter.h"

using namespace std;

#define TESTMAP "../maps/testmap1.1.txt"

int main() {
    cout << "Creating a few test maps..." << endl;
    mapPainter painter;
    painter.setDest(TESTMAP);

    painter.setWidth(50);
    painter.setHeight(50);
    painter.save();

    return 0;
}