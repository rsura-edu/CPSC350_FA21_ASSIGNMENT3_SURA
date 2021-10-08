#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include <iostream>
#include <fstream>
// #include <stdlib.h>
#include <unistd.h>
#include "GenericGame.h"

class ClassicMode : public GenericGame{
    public:
        ClassicMode();
        ClassicMode(unsigned int numRows, unsigned int numColumns, double popDensity);
        ClassicMode(string fileName);
        ~ClassicMode();
        void play() ;
    // private:
        bool isStable() const;
        void createNextGen(Map*& oldGen, Map*& newGen) const;
        void consoleWithPause();
        void consoleWithEnter() ;
        void fileOutput() ;
        void generateBufferedGrid(Map*& smallerGrid) const;
        int countNeighbors(int rowNum, int columnNum) const;
        /*
        unsigned int currGen;

        // There are 3 maps so that if it stabilizes, we can end the game
        Map* mGenOne;
        Map* mGenTwo;
        Map* mGenThree;
        // Map* tempMap;
        Map* bufferGrid;
        */
};

#endif
