#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H

class DoughnutMode : public GenericGame{
    public:
        DoughnutMode();
        DoughnutMode(unsigned int rowLength, unsigned int columnLength, unsigned double popDensity);
        DoughnutMode(string fileName);
        ~DoughnutMode();
    private:
        char** bufferGrid;
};

#endif
