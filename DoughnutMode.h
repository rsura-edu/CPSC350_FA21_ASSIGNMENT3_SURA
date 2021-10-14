/**
 * Header File: DoughnutMode.h
 *
 * Full Name: Rahul Sura
 * Student ID: 2371308
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Assignment: Assignment 3
 */

#ifndef DOUGHNUTMODE_H // header guards
#define DOUGHNUTMODE_H

#include "GenericGame.h"

class DoughnutMode : public GenericGame{ // DoughnutMode inheriting from abstract GenericGame
    public:
        DoughnutMode(); // default constructor - shouldn't be used in general
        DoughnutMode(unsigned int numRows, unsigned int numColumns, double popDensity); // new DoughnutMode based on number of rows and columns and population density
        DoughnutMode(string fileName); // new DoughnutMode based on file name
        ~DoughnutMode(); // destructor implemented here, in the sub class, instead of the abstract class, GenericGame

    private:
        // implemented here, in the sub class, instead of the abstract class, GenericGame
        // creates the bufferGrid based on the rules of DoughnutMode
        void generateBufferedGrid(Map*& smallerGrid) const;
};

#endif
