#include "ClassicMode.h"

using namespace std;
ClassicMode::ClassicMode() : GenericGame::GenericGame(){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}

ClassicMode::ClassicMode(unsigned int numRows, unsigned int numColumns, double popDensity) : GenericGame::GenericGame(numRows, numColumns, popDensity){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}
ClassicMode::ClassicMode(string fileName) : GenericGame::GenericGame(fileName){
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
    createNextGen(mGenThree,mGenFour);
}
ClassicMode::~ClassicMode(){
    delete mGenOne;
    delete mGenTwo;
    delete mGenThree;
    delete mGenFour;
    delete bufferGrid;
}

void ClassicMode::generateBufferedGrid(Map*& smallerGrid) const{
    bufferGrid->makeEmptyMap();
    for (int i = 0; i < smallerGrid->getNumRows(); i++) {
        for (int j = 0; j < smallerGrid->getNumColumns(); j++) {
            bufferGrid->updateGrid(i+1,j+1,smallerGrid->getGridElement(i,j));
        }
    }
}
