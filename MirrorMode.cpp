#include "MirrorMode.h"

using namespace std;

MirrorMode::MirrorMode() : GenericGame::GenericGame(){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}

MirrorMode::MirrorMode(unsigned int numRows, unsigned int numColumns, double popDensity) : GenericGame::GenericGame(numRows, numColumns, popDensity){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}
MirrorMode::MirrorMode(string fileName) : GenericGame::GenericGame(fileName){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}
MirrorMode::~MirrorMode(){
    delete mGenOne;
    delete mGenTwo;
    delete mGenThree;
    delete mGenFour;
    delete bufferGrid;
}

void MirrorMode::generateBufferedGrid(Map*& smallerGrid) const{
    bufferGrid->makeEmptyMap();
    for (int i = 0; i < smallerGrid->getNumRows(); ++i) {
        for (int j = 0; j < smallerGrid->getNumColumns(); ++j) {
            bufferGrid->updateGrid(i+1, j+1, smallerGrid->getGridElement(i,j));
        }
    }

    for (int i = 0; i < bufferGrid->getNumRows(); ++i) {
        bufferGrid->updateGrid(i, 0, bufferGrid->getGridElement(i, 1));
        bufferGrid->updateGrid(i, bufferGrid->getNumColumns() - 1, bufferGrid->getGridElement(i, bufferGrid->getNumColumns() - 2));
    }

    for (int i = 0; i < bufferGrid->getNumColumns(); ++i) {
        bufferGrid->updateGrid(0, i, bufferGrid->getGridElement(1, i));
        bufferGrid->updateGrid(bufferGrid->getNumRows() - 1, i, bufferGrid->getGridElement(bufferGrid->getNumRows() - 2, i));
    }
}
