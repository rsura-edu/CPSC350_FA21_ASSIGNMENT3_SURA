/**
 * Header File: Map.h
 *
 * Full Name: Rahul Sura
 * Student ID: 2371308
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Assignment: Assignment 3
 */

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <exception>
#include <stdexcept>

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
        bool isValidFile(string fileName);
    private:

        bool isValidLine(string fileLine);

        char** grid;
        unsigned int mNumRows;
        unsigned int mNumColumns;
        string mFileName;

};

#endif
