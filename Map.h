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
        char** getMap(); // gets map in string form
        void print(); // prints the map
        void populateMap(double popDensity);
        unsigned int getNumRows();
        unsigned int getNumColumns();
        // // ADD MORE FUNCTIONS MAYBE
        bool operator==(Map secondMap); // checks if two maps are equal


    private:
        void makeEmptyMap();
        char** grid; // had to make this public to check if two maps are equal
        unsigned int mNumRows;
        unsigned int mNumColumns;

};

#endif
