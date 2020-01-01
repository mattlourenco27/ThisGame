//
// Created by Matthew Lourenco on 01/01/2020.
//

#include "map.h"

map::map() {
    grid = nullptr;
    source = "";
    width = 0;
    height = 0;
    loaded = false;
}

map::map(const string & src) {
    grid = nullptr;
    source = "";
    width = 0;
    height = 0;
    if(!loadMap(src)) loaded = false;
}

map::map(const map & src) {
    loaded = src.loaded;
    width = src.width;
    height = src.height;
    source = src.source;
    grid = new char*[height];
    for(int i = 0; i < height; ++i) {
        grid[i] = new char[width];
        strcpy(grid[i], src.grid[i]);
    }
}

map::~map() {
    if(grid) {
        for(int i = 0; i < height; ++i) delete [] grid[i];
        delete [] grid;
    }
}

bool map::getLoaded() {return loaded;}
int map::getWidth() {return width;}
int map::getHeight() {return height;}
string map::getSource() {return source;}
char map::getTile(int x, int y) {
    if(0 <= x && x < width && 0 <= y && y < height) {
        return grid[y][x];
    }
}

bool map::loadMap(const string & src) {
    ifstream f(src); //open map file
    if(!f.is_open()) return false;

    int tmpWidth = 0;
    int tmpHeight = 0;
    char** tmpGrid;
    string nextLine;

    if(!f.eof()) { //Retrieve data from header and use error checking
        //check first line of map for width and height
        getline(f, nextLine);
        stringstream dataStream(nextLine);
        dataStream >> tmpWidth >> tmpHeight;

        if(dataStream.fail()) {
            f.close();
            return false;
        }
    } else {
        f.close();
        return false;
    }

    //verify that the new map is valid before updating the current map
    tmpGrid = new char*[tmpHeight];
    for(int i = 0; i < tmpHeight; ++i) tmpGrid[i] = new char[tmpWidth];

    bool validMap = true;
    for(int i = 0; i < tmpHeight; ++i) { //copy map contents
        if(f.eof()) { //check if the map is not tall enough
            validMap = false;
            break;
        }

        getline(f, nextLine);

        if(nextLine.length() != tmpWidth) { //check if the map is correct width
            validMap = false;
            break;
        }

        strcpy(tmpGrid[i], nextLine.c_str());
    }

    if(!f.eof()) validMap = false; //if the map has not been saved in its entirety, it is not valid
    f.close();

    if(!validMap) {
        for(int i = 0; i < tmpHeight; ++i) delete [] tmpGrid[i];
        delete [] tmpGrid;
        return false;
    }

    //current map is valid so delete old map and replace it
    if(grid) {
        for(int i = 0; i < height; ++i) delete [] grid[i];
        delete [] grid;
    }
    grid = tmpGrid;
    width = tmpWidth;
    height = tmpHeight;
    source = src;
    loaded = true;
    return true;
}

void map::print() {
    if(!loaded) cout << "Map is not loaded" << endl;
    cout << "Width: " << width << ", Height: " << height << endl
         << "Source: " << source << endl;
    for(int i = 0; i < height; ++i) {
        printf("%s\n", grid[i]);
    }
}

map & map::operator=(const map & rhs) {
    if(this == &rhs) return *this;
    width = rhs.width;
    height = rhs.height;
    source = rhs.source;
    grid = new char*[height];
    for(int i = 0; i < height; ++i) {
        grid[i] = new char[width];
        strcpy(grid[i], rhs.grid[i]);
    }
    return *this;
}
