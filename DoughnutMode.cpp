/**
 * Implementation File: DoughnutMode.cpp
 *
 * Full Name: Rahul Sura
 * Student ID: 2371308
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Assignment: Assignment 3
 */
#include "DoughnutMode.h"

using namespace std;

DoughnutMode::DoughnutMode() : GenericGame::GenericGame(){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}

DoughnutMode::DoughnutMode(unsigned int numRows, unsigned int numColumns, double popDensity) : GenericGame::GenericGame(numRows, numColumns, popDensity){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}
DoughnutMode::DoughnutMode(string fileName) : GenericGame::GenericGame(fileName){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}
DoughnutMode::~DoughnutMode(){
    delete mGenOne;
    delete mGenTwo;
    delete mGenThree;
    delete mGenFour;
    delete bufferGrid;
}

void DoughnutMode::generateBufferedGrid(Map*& smallerGrid) const{
    bufferGrid->makeEmptyMap();
    for (int i = 0; i < smallerGrid->getNumRows(); ++i) {
        for (int j = 0; j < smallerGrid->getNumColumns(); ++j) {
            bufferGrid->updateGrid(i+1, j+1, smallerGrid->getGridElement(i,j));
        }
    }

    // Handle corners
    bufferGrid->updateGrid(0, 0, bufferGrid->getGridElement(bufferGrid->getNumRows() - 2, bufferGrid->getNumColumns() - 2)); // top left corner
    bufferGrid->updateGrid(0, bufferGrid->getNumColumns() - 1, bufferGrid->getGridElement(bufferGrid->getNumRows() - 2, 1)); // top right corner
    bufferGrid->updateGrid(bufferGrid->getNumRows() - 1, 0, bufferGrid->getGridElement(1, bufferGrid->getNumColumns() - 2)); // bottom left corner
    bufferGrid->updateGrid(bufferGrid->getNumRows() - 1, bufferGrid->getNumColumns() - 1, bufferGrid->getGridElement(1, 1)); // bottom right corner

    for (int i = 1; i < bufferGrid->getNumRows() - 1; ++i) {
        bufferGrid->updateGrid(i, 0, bufferGrid->getGridElement(i, bufferGrid->getNumColumns() - 2));
        bufferGrid->updateGrid(i, bufferGrid->getNumColumns() - 1, bufferGrid->getGridElement(i, 1));
    }

    for (int i = 1; i < bufferGrid->getNumColumns() - 1; ++i) {
        bufferGrid->updateGrid(0, i, bufferGrid->getGridElement(bufferGrid->getNumRows() - 2, i));
        bufferGrid->updateGrid(bufferGrid->getNumRows() - 1, i, bufferGrid->getGridElement(1, i));
    }
}
