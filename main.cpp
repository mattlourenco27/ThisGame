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

    return 0;
}