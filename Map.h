#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Map{
    public:
        Map();
        Map(unsigned int numRows, unsigned int numColumns);
        Map(string fileName);
        ~Map();
        string getMapString(); // gets map in a string
        void print(); // prints the map
        void populateMap(double popDensity);
        void updateGrid(int rowNum, int columnNum, char val);
        char getGridElement(int rowNum, int columnNum);
        unsigned int getNumRows();
        unsigned int getNumColumns();
        void makeEmptyMap();

    private:
        char** grid;
        unsigned int mNumRows;
        unsigned int mNumColumns;

};

#endif
