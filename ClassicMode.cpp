/**
 * Implementation File: ClassicMode.cpp
 *
 * Full Name: Rahul Sura
 * Student ID: 2371308
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Assignment: Assignment 3
 */
#include "ClassicMode.h"

using namespace std;

/**
 * Default constructor:
 * Creates a classic mode simulation where the starting Map is a default 7 x 7 Map with a population density of 0.5
 */
ClassicMode::ClassicMode() : GenericGame::GenericGame(){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}

/**
 * Overloaded constructor:
 * Creates a classic mode simulation where the starting Map is a Map with given dimensions and a given population density
 *
 * @param an unsigned int representing number of rows
 * @param an unsigned int representing number of columns
 * @param a double representing population density
 */
ClassicMode::ClassicMode(unsigned int numRows, unsigned int numColumns, double popDensity) : GenericGame::GenericGame(numRows, numColumns, popDensity){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}

/**
 * Overloaded constructor:
 * Creates a classic mode simulation from a file that represents the starting Map of generation 0
 *
 * @param a string representing the file name
 */
ClassicMode::ClassicMode(string fileName) : GenericGame::GenericGame(fileName){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}

/**
 * Destructor - deleting all the Maps of the last four generations and the buffered grid
 */
ClassicMode::~ClassicMode(){
    delete mGenOne;
    delete mGenTwo;
    delete mGenThree;
    delete mGenFour;
    delete bufferGrid;
}

/**
 * Creates the buffered grid of a Map based on the rules of classic mode
 *
 * @param a Map
 */
void ClassicMode::generateBufferedGrid(Map*& smallerGrid) const{
    bufferGrid->makeEmptyMap();
    for (int i = 0; i < smallerGrid->getNumRows(); ++i) {
        for (int j = 0; j < smallerGrid->getNumColumns(); ++j) {
            bufferGrid->updateGrid(i+1, j+1, smallerGrid->getGridElement(i,j));
        }
    }
}
