#ifndef MIRRORMODE_H
#define MIRRORMODE_H

class MirrorMode : public GenericGame{
    public:
        MirrorMode();
        MirrorMode(unsigned int rowLength, unsigned int columnLength, unsigned double popDensity);
        MirrorMode(string fileName);
        ~MirrorMode();
    private:
        char** bufferGrid;
};

#endif
