#include <iostream>
#include <fstream>
using namespace std;

#define TESTMAP "../maps/testmap.txt"

int main() {
    ifstream f;
    f.open(TESTMAP);
    string line;

    if(!f.is_open()) {
        return 0;
    }

    while(!f.eof()) {
        getline(f, line);
        cout << endl << line;
    }

    f.close();
    return 0;
}