#ifndef GENERICGAME_H
#define GENERICGAME_H

#include <iostream>
using namespace std;

class GenericGame{
    public:
        virtual ~GenericGame(){}
        virtual void play() const = 0; // starts the game
        virtual bool isStable() const = 0; // checks if the map has stabilized
        virtual void createNextGen() const = 0; // Creates next generation
        virtual void generateMap() const = 0;
    protected:
        // There are 3 maps so that if it stabilizes, we can end the game
        Map mGenOne;
        Map mGenTwo;
        Map mGenThree;



};

#endif
