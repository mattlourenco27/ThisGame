//
// Created by Matthew Lourenco on 01/01/2020.
//

#include <iostream>
#include <fstream>
#include "map.h"
using namespace std;

#define TESTMAP1 "../maps/testmap1.txt"
#define TESTMAP2 "../maps/testmap2.txt"
#define TESTMAP3 "../maps/testmap3.txt"
#define TESTMAP4 "../maps/testmap4.txt"
#define TESTMAP5 "../maps/testmap5.txt"
#define TESTMAP6 "../maps/testmap6.txt"
#define EMPTYMAP "../maps/emptymap.txt"

int main() {
    cout << "Testing first constructor" << endl;
    map a;
    a.print();

    cout << endl << "Testing load function" << endl;
    cout << "loading map (testmap1)" << endl;
    a.loadMap(TESTMAP1);
    a.print();

    cout << endl << "Testing load function" << endl;
    cout << "loading map with error (testmap3)" << endl;
    a.loadMap(TESTMAP3);
    a.print();

    cout << endl << "Testing load function" << endl;
    cout << "loading map with error (testmap4)" << endl;
    a.loadMap(TESTMAP4);
    a.print();

    cout << endl << "Testing load function" << endl;
    cout << "loading map with error (testmap5)" << endl;
    a.loadMap(TESTMAP5);
    a.print();

    cout << endl << "Testing load function" << endl;
    cout << "loading map with error (testmap6)" << endl;
    a.loadMap(TESTMAP6);
    a.print();

    cout << endl << "Testing load function" << endl;
    cout << "loading map with error (emptymap)" << endl;
    a.loadMap(EMPTYMAP);
    a.print();

    cout << endl << "Testing load function" << endl;
    cout << "loading map (testmap2)" << endl;
    a.loadMap(TESTMAP2);
    a.print();

    cout << endl << "Testing accessors" << endl;
    cout << "Loaded: " << (a.getLoaded()? "true": "false") << endl
         << "Width: " << a.getWidth() << ", Height: " << a.getHeight() << endl
         << "Source: " << a.getSource() << endl;
    cout << "Tile [0][0]: " << a.getTile(0, 0) << endl;
    cout << "Tile [6][1]: " << a.getTile(6, 1) << endl;

    cout << endl << "Testing second constructor (testmap1)" << endl;
    map b(TESTMAP1);
    b.print();

    cout << endl << "Testing copy constructor" << endl;
    map c(b);
    c.print();

    cout << endl << "Testing operator=" << endl;
    a = b;
    a.print();

    cout << endl << "End of tests" << endl;

    return 0;
}