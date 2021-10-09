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
