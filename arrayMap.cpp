//
// Created by Matthew Lourenco on 01/01/2020.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <regex>

#include "arrayMap.h"

using namespace std;

arrayMap::arrayMap() {
    grid = nullptr;
    source = "";
    width = 0;
    height = 0;
    loaded = false;
}

arrayMap::arrayMap(const string & src) {
    grid = nullptr;
    source = "";
    width = 0;
    height = 0;
    if(!loadMap(src)) loaded = false;
}

arrayMap::arrayMap(const arrayMap & src) {
    loaded = src.loaded;
    width = src.width;
    height = src.height;
    source = src.source;
    grid = new char*[height];
    for(int i = 0; i < height; ++i) {
        grid[i] = new char[width + 1];
        strcpy(grid[i], src.grid[i]);
    }
}

arrayMap::~arrayMap() {
    if(grid) {
        for(int i = 0; i < height; ++i) delete [] grid[i];
        delete [] grid;
    }
}

bool arrayMap::getLoaded() {return loaded;}
int arrayMap::getWidth() {return width;}
int arrayMap::getHeight() {return height;}
string arrayMap::getSource() {return source;}
char arrayMap::getTile(int x, int y) {
    if(0 <= x && x < width && 0 <= y && y < height) {
        return grid[y][x];
    }
}

void arrayMap::getNextLine(ifstream & file, string & line) {
    getline(file, line);
    if(line.length() > 0) {
        if(line[line.length() - 1] == '\r') {
            line.pop_back();
        }
    }
}

bool arrayMap::loadMap(const string & src) {
    ifstream f(src); //open map file
    if(!f.is_open()) return false;

    int tmpWidth = 0;
    int tmpHeight = 0;
    string nextLine;

    if(!f.eof()) {
        //check first line of map for width
        getNextLine(f, nextLine);
        tmpWidth = nextLine.length();
        if(tmpWidth == 0 || tmpWidth > MAX_X) {
            f.close();
            return false;
        }
        if(regex_match(nextLine, regex("\t"))) {
            f.close();
            return false;
        }
        tmpHeight++;
    } else {
        f.close();
        return false;
    }

    while(!f.eof()) {
        getNextLine(f, nextLine);
        tmpHeight++;
        if(nextLine.length() != tmpWidth) {
            f.close();
            return false;
        }
        if(regex_match(nextLine, regex("\t"))) {
            f.close();
            return false;
        }
    }

    if(tmpHeight > MAX_Y) {
        f.close();
        return false;
    }

    //After these tests, the map is valid
    //Return the file stream to the beginning
    f.clear();
    f.seekg(0, ios::beg);

    //new map is valid so delete old map and replace it
    if(grid) {
        for(int i = 0; i < height; ++i) delete [] grid[i];
        delete [] grid;
    }

    width = tmpWidth;
    height = tmpHeight;

    grid = new char*[height];
    for(int i = 0; i < height; ++i) {
        grid[i] = new char[width + 1];
    }

    for(int i = 0; i < height; ++i) { //copy map contents
        getNextLine(f, nextLine);
        strcpy(grid[i], nextLine.c_str());
    }

    f.clear();
    f.close();
    source = src;
    loaded = true;
    return true;
}

void arrayMap::print() {
    if(!loaded) cout << "Map is not loaded" << endl;
    cout << "Width: " << width << ", Height: " << height << endl
         << "Source: " << source << endl;
    for(int i = 0; i < height; ++i) {
        printf("%s\n", grid[i]);
    }
}

arrayMap & arrayMap::operator=(const arrayMap & rhs) {
    if(this == &rhs) return *this;
    if(grid) {
        for(int i = 0; i < height; ++i) delete [] grid[i];
        delete [] grid;
    }
    width = rhs.width;
    height = rhs.height;
    source = rhs.source;
    grid = new char*[height];
    for(int i = 0; i < height; ++i) {
        grid[i] = new char[width + 1];
        strcpy(grid[i], rhs.grid[i]);
    }
    return *this;
}
