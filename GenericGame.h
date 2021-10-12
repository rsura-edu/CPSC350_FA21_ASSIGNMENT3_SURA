/**
 * Header File: GenericGame.h
 *
 * Full Name: Rahul Sura
 * Student ID: 2371308
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Assignment: Assignment 3
 */

#ifndef GENERICGAME_H
#define GENERICGAME_H

#include "Map.h"
using namespace std;

class GenericGame{
    public:
        GenericGame();
        GenericGame(unsigned int numRows, unsigned int numColumns, double popDensity);
        GenericGame(string fileName);
        virtual ~GenericGame(){}
        void play(); // starts the game
    protected:
        bool isStable() const; // checks if the map has stabilized
        void createNextGen(Map*& oldGen, Map*& newGen) ; // Creates next generation
        void consoleWithPause();
        void consoleWithEnter();
        void fileOutput();
        virtual void generateBufferedGrid(Map*& smallerGrid) const = 0;
        int countNeighbors(int rowNum, int columnNum) const;
        unsigned int currGen;
        // There are 4 maps so that if it stabilizes, we can end the game
        Map* mGenOne;
        Map* mGenTwo;
        Map* mGenThree;
        Map* mGenFour;
        // Map for the buffered grid
        Map* bufferGrid;



};

#endif
