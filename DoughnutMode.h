/**
 * Header File: DoughnutMode.h
 *
 * Full Name: Rahul Sura
 * Student ID: 2371308
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Assignment: Assignment 3
 */

#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H

#include "GenericGame.h"

class DoughnutMode : public GenericGame{
    public:
        DoughnutMode();
        DoughnutMode(unsigned int numRows, unsigned int numColumns, double popDensity);
        DoughnutMode(string fileName);
        ~DoughnutMode();
    private:
        void generateBufferedGrid(Map*& smallerGrid) const;
};

#endif
