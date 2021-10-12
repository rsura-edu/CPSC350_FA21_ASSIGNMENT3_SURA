/**
 * Header File: ClassicMode.h
 *
 * Full Name: Rahul Sura
 * Student ID: 2371308
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Assignment: Assignment 3
 */

#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include "GenericGame.h"

class ClassicMode : public GenericGame{
    public:
        ClassicMode();
        ClassicMode(unsigned int numRows, unsigned int numColumns, double popDensity);
        ClassicMode(string fileName);
        ~ClassicMode();
    private:
        void generateBufferedGrid(Map*& smallerGrid) const;
};

#endif
