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
