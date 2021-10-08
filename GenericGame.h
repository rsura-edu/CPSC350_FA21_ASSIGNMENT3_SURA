#ifndef GENERICGAME_H
#define GENERICGAME_H

#include <iostream>
#include "Map.h"
using namespace std;

class GenericGame{
    public:
        virtual ~GenericGame(){}
        virtual void play() = 0; // starts the game
    // protected:
        virtual bool isStable() const = 0; // checks if the map has stabilized
        virtual void createNextGen(Map*& oldGen, Map*& newGen) const = 0; // Creates next generation
        virtual void consoleWithPause() = 0;
        virtual void consoleWithEnter()  = 0;
        virtual void fileOutput()  = 0;
        virtual void generateBufferedGrid(Map*& smallerGrid) const = 0;
        virtual int countNeighbors(int rowNum, int columnNum) const = 0;
        unsigned int currGen;

        // There are 3 maps so that if it stabilizes, we can end the game
        Map* mGenOne;
        Map* mGenTwo;
        Map* mGenThree;
        // Map* tempMap;
        Map* bufferGrid;



};

#endif
