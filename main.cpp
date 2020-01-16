//
// Created by Matthew Lourenco on 01/01/2020.
//

#include <iostream>
#include "linkedMap.h"
#include "arrayMap.h"
#include "mapPainter.h"

using namespace std;

#define TESTMAP "../maps/testmap1.1.txt"
#define TESTLOADMAP "../maps/testmap1.txt"

int main() {
    cout << "Creating a few test maps..." << endl;
    mapPainter painter;
    painter.setDest(TESTMAP);

    cout << "Creating testmap1.1 (50x50)" << endl;
    painter.setWidth(50);
    painter.setHeight(50);
    cout << (painter.save()? "Saved": "Save unsuccessful") << endl;

    cout << "Editing and saving to testmap1.2 (40x20)" << endl;
    painter.setWidth(40);
    painter.setHeight(20);
    cout << (painter.save("../maps/testmap1.2.txt")? "Saved": "Save unsuccessful") << endl;

    cout << "Drawing Rectangles and saving to testmap1.3 (40x20)" << endl;
    painter.drawRect(0,0,9,9,'H');
    painter.drawRect(10, 10, 20, 19, 'S', true);
    cout << (painter.save("../maps/testmap1.3.txt")? "Saved": "Save unsuccessful") << endl;

    cout << "Testing width and height constructor and saving to testmap1.4 (10x10)" << endl;
    mapPainter p0(10, 10);
    cout << (p0.save("../maps/testmap1.4.txt")? "Saved": "Save unsuccessful") << endl;
    cout << "Testing saving without defining destination" << endl;
    cout << (p0.save()? "Saved": "Save unsuccessful") << endl;

    cout << "Testing source file constructor, making an edit, and saving to testmap1.5" << endl;
    mapPainter p1(TESTLOADMAP);
    p1.setDest("../maps/testmap1.5.txt");
    p1.drawRect(1, 1, p1.getWidth() - 2, 1, 'A');
    cout << (p1.save()? "Saved": "Save unsuccessful") << endl;

    cout << "Creating a new map with the same painter" << endl;
    p1.newMap();
    p1.setDest("../maps/testmap1.6.txt");
    cout << (p1.save()? "Saved": "Save unsuccessful") << endl;

    cout << "Loading previous map, drawing lines, and saving to testmap1.6" << endl;
    p1.loadMap("../maps/testmap1.2.txt");
    p1.drawLine(1,1,6,6,'A');
    p1.drawLine(18,18,13,13, 'B');
    p1.drawLine(38,1,33,6, 'C');
    p1.drawLine(1,18,6,13, 'D');
    cout << (p1.save()? "Saved": "Save unsuccessful") << endl;

    cout << "Drawing points and saving to testmap1.7" << endl;
    p1.drawPoint(1,1,'X');
    p1.drawPoint(18,18, 'Y');
    cout << (p1.save("../maps/testmap1.7.txt")? "Saved": "Save unsuccessful") << endl;

    return 0;
}