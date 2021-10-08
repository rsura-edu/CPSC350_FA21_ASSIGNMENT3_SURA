#include "ClassicMode.h"

using namespace std;
ClassicMode::ClassicMode(){
    currGen = 3;
    mGenOne = new Map();
    bufferGrid = new Map(mGenOne->getNumRows() + 2, mGenOne->getNumColumns() + 2);
    mGenTwo = new Map();
    mGenThree = new Map();
    generateBufferedGrid(mGenOne);
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
}
ClassicMode::ClassicMode(unsigned int numRows, unsigned int numColumns, double popDensity){
    currGen = 3;
    mGenOne = new Map(numRows, numColumns);
    mGenOne->populateMap(popDensity);
    bufferGrid = new Map(mGenOne->getNumRows() + 2, mGenOne->getNumColumns() + 2);
    mGenTwo = new Map(numRows, numColumns);
    mGenThree = new Map(numRows, numColumns);
    generateBufferedGrid(mGenOne);
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
}
ClassicMode::ClassicMode(string fileName){
    currGen = 3;
    mGenOne = new Map(fileName);
    bufferGrid = new Map(mGenOne->getNumRows() + 2, mGenOne->getNumColumns() + 2);
    mGenTwo = new Map(fileName);
    mGenThree = new Map(fileName);
    generateBufferedGrid(mGenOne);
    createNextGen(mGenOne, mGenTwo);
    createNextGen(mGenTwo,mGenThree);
}
ClassicMode::~ClassicMode(){
    delete mGenOne;
    delete mGenTwo;
    delete mGenThree;
    delete bufferGrid;
}

void ClassicMode::play() {
    string options = "";
    while (!(options == "pauses" || options == "enters" || options == "file")) {
        cout << "Would you like a brief pause between generations, press the enter key for each generation, or have the simulation output to a file?" << endl;
        cout << "If you want a brief pause between generations outputted on the console, please type \"pauses\" into the prompt and hit enter on your keyboard." << endl;
        cout << "If you want to just hit enter between generations outputted on the console, please type \"enters\" into the prompt and hit enter on your keyboard." << endl;
        cout << "If you want the simulation outputted in a file, please type \"file\" into the prompt and hit enter on your keyboard." << endl;
        cout << "---->\t";
        getline (cin, options);
        for (int i = 0; i < options.length(); ++i) {
            options[i] = tolower(options[i]);
        }
        if (!(options == "pauses" || options == "enters" || options == "file")) {
            cout << "Sorry, that wasn't one of the options. Instructions will be repeated again." << endl;
        }
    }
    if (options == "pauses") {
        consoleWithPause();
    } else if (options == "enters"){
        consoleWithEnter();
    } else if (options == "file"){
        fileOutput();
    }
}

bool ClassicMode::isStable() const{
    if (mGenOne != NULL && mGenTwo != NULL && mGenThree != NULL) {
        if (mGenOne->getMapString() == mGenThree->getMapString() || mGenTwo->getMapString() == mGenThree->getMapString() || mGenOne->getMapString() == mGenTwo->getMapString()) {
            return true;
        }
    } else if (mGenTwo != NULL && mGenThree != NULL){
        if (mGenTwo->getMapString() == mGenThree->getMapString()) {
            return true;
        }
    }
    return false;
}

void ClassicMode::createNextGen(Map*& oldGen, Map*& newGen) const{
    generateBufferedGrid(oldGen);
    int currCellNeighbors = 0;
    for (int i = 0; i < newGen->getNumRows(); i++) {
        for (int j = 0; j < newGen->getNumColumns(); j++) {
            currCellNeighbors = countNeighbors(i + 1, j + 1);
            if (currCellNeighbors == 0 || currCellNeighbors == 1) {
                newGen->updateGrid(i,j,'-');
            } else if (currCellNeighbors == 2) {
                newGen->updateGrid(i,j,oldGen->getGridElement(i,j));
            } else if (currCellNeighbors == 3) {
                newGen->updateGrid(i,j,'X');
            } else if (currCellNeighbors >= 4 || currCellNeighbors <= 8) {
                newGen->updateGrid(i,j,'-');
            } else {
                cout << "Something went wrong with calculating number of number of neighbors" << endl;
            }
        }
    }

}

void ClassicMode::generateBufferedGrid(Map*& smallerGrid) const{
    bufferGrid->makeEmptyMap();
    for (int i = 0; i < smallerGrid->getNumRows(); i++) {
        for (int j = 0; j < smallerGrid->getNumColumns(); j++) {
            bufferGrid->updateGrid(i+1,j+1,smallerGrid->getGridElement(i,j));
        }
    }
}

// helper function
int ClassicMode::countNeighbors(int rowNum, int columnNum) const{
    int numNeighbors = 0;
    if (bufferGrid->getGridElement(rowNum - 1, columnNum - 1) == 'X') {++numNeighbors;}
    if (bufferGrid->getGridElement(rowNum - 1, columnNum) == 'X') {++numNeighbors;}
    if (bufferGrid->getGridElement(rowNum - 1, columnNum + 1) == 'X') {++numNeighbors;}
    if (bufferGrid->getGridElement(rowNum, columnNum - 1) == 'X') {++numNeighbors;}
    if (bufferGrid->getGridElement(rowNum, columnNum + 1) == 'X') {++numNeighbors;}
    if (bufferGrid->getGridElement(rowNum + 1, columnNum - 1) == 'X') {++numNeighbors;}
    if (bufferGrid->getGridElement(rowNum + 1, columnNum) == 'X') {++numNeighbors;}
    if (bufferGrid->getGridElement(rowNum + 1, columnNum + 1) == 'X') {++numNeighbors;}
    return numNeighbors;
}


void ClassicMode::consoleWithPause() {
    double numSeconds = 0.5;
    cout << "Generation 0:" << endl;
    mGenOne->print();
    usleep((long)(numSeconds * 1000000));
    cout << "\nGeneration 1:" << endl;
    mGenTwo->print();
    usleep((long)(numSeconds * 1000000));
    cout << "\nGeneration 2:" << endl;
    mGenThree->print();
    usleep((long)(numSeconds * 1000000));
    while(!isStable()){
        Map* tempMap = mGenOne;
        mGenOne = mGenTwo;
        mGenTwo = mGenThree;
        mGenThree = new Map(mGenTwo->getNumRows(), mGenTwo->getNumColumns());
        createNextGen(mGenTwo, mGenThree);
        delete tempMap;
        cout << "\nGeneration " << currGen << ":" << endl;
        mGenThree->print();
        ++currGen;
        usleep((long)(numSeconds * 1000000)); // program waits for 2 seconds
    }
}

void ClassicMode::consoleWithEnter() {

}

void ClassicMode::fileOutput() {

}
