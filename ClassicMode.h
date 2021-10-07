#ifndef CLASSICMODE_H
#define CLASSICMODE_H

class ClassicMode : public GenericGame{
    public:
        ClassicMode();
        ClassicMode(unsigned int rowLength, unsigned int columnLength, unsigned double popDensity);
        ClassicMode(string fileName);
        ~ClassicMode();

};

#endif
