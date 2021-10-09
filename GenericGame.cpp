#include "GenericGame.h"

using namespace std;

GenericGame::GenericGame(){
    currGen = 4;
    mGenOne = new Map();
    bufferGrid = new Map(mGenOne->getNumRows() + 2, mGenOne->getNumColumns() + 2);
    mGenTwo = new Map();
    mGenThree = new Map();
    mGenFour = new Map();
}

GenericGame::GenericGame(unsigned int numRows, unsigned int numColumns, double popDensity){
    currGen = 4;
    mGenOne = new Map(numRows, numColumns);
    mGenOne->populateMap(popDensity);
    bufferGrid = new Map(mGenOne->getNumRows() + 2, mGenOne->getNumColumns() + 2);
    mGenTwo = new Map(numRows, numColumns);
    mGenThree = new Map(numRows, numColumns);
    mGenFour = new Map(numRows, numColumns);
}

GenericGame::GenericGame(string fileName){
    currGen = 4;
    mGenOne = new Map(fileName);
    mGenOne->print();
    bufferGrid = new Map(mGenOne->getNumRows() + 2, mGenOne->getNumColumns() + 2);
    mGenTwo = new Map(mGenOne->getNumRows(), mGenOne->getNumColumns());
    mGenThree = new Map(mGenOne->getNumRows(), mGenOne->getNumColumns());
    mGenFour = new Map(mGenOne->getNumRows(), mGenOne->getNumColumns());
}

void GenericGame::play() {
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

bool GenericGame::isStable() const{

    if(mGenOne != NULL && mGenTwo != NULL && mGenThree != NULL && mGenFour != NULL){
        if (mGenOne->getMapString() == mGenFour->getMapString() ||
            mGenTwo->getMapString() == mGenFour->getMapString() ||
            mGenThree->getMapString() == mGenFour->getMapString()){
            return true;
        }
    } else if (mGenTwo != NULL && mGenThree != NULL && mGenFour != NULL){
        if (mGenTwo->getMapString() == mGenFour->getMapString() ||
            mGenThree->getMapString() == mGenFour->getMapString()){
            return true;
        }
    } else if (mGenThree != NULL && mGenFour != NULL) {
        if (mGenThree->getMapString() == mGenFour->getMapString()){
            return true;
        }
    }
    return false;
}

void GenericGame::createNextGen(Map*& oldGen, Map*& newGen) const{
    generateBufferedGrid(oldGen);
    int currCellNeighbors = 0;
    for (int i = 0; i < newGen->getNumRows(); ++i) {
        for (int j = 0; j < newGen->getNumColumns(); ++j) {
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


int GenericGame::countNeighbors(int rowNum, int columnNum) const{
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

void GenericGame::consoleWithPause() {
    double numSeconds = 0.1;

    cout << "Generation 0:" << endl;
    mGenOne->print();
    usleep((long)(numSeconds * 1000000));

    cout << "\nGeneration 1:" << endl;
    mGenTwo->print();
    usleep((long)(numSeconds * 1000000));

    cout << "\nGeneration 2:" << endl;
    mGenThree->print();
    usleep((long)(numSeconds * 1000000));

    cout << "\nGeneration 3:" << endl;
    mGenFour->print();
    usleep((long)(numSeconds * 1000000));

    while(!isStable()){
        Map* tempMap = mGenOne;
        mGenOne = mGenTwo;
        mGenTwo = mGenThree;
        mGenThree = mGenFour;
        mGenFour = new Map(mGenTwo->getNumRows(), mGenTwo->getNumColumns());
        createNextGen(mGenThree, mGenFour);
        delete tempMap;
        cout << "\nGeneration " << currGen << ":" << endl;
        mGenFour->print();
        ++currGen;
        usleep((long)(numSeconds * 1000000));
    }
}

void GenericGame::consoleWithEnter() {
    cout << "Generation 0:" << endl;
    mGenOne->print();
    cin.ignore();

    cout << "\nGeneration 1:" << endl;
    mGenTwo->print();
    cin.ignore();

    cout << "\nGeneration 2:" << endl;
    mGenThree->print();
    cin.ignore();

    cout << "\nGeneration 3:" << endl;
    mGenFour->print();
    cin.ignore();

    while(!isStable()){
        Map* tempMap = mGenOne;
        mGenOne = mGenTwo;
        mGenTwo = mGenThree;
        mGenThree = mGenFour;
        mGenFour = new Map(mGenTwo->getNumRows(), mGenTwo->getNumColumns());
        createNextGen(mGenThree, mGenFour);
        delete tempMap;
        cout << "\nGeneration " << currGen << ":" << endl;
        mGenFour->print();
        ++currGen;
        cin.ignore();
    }
}

void GenericGame::fileOutput() {
    string fileName;
    cout << "What is the name of the file you would like your output to be in?" << endl;
    cout << "---->\t";
    getline(cin, fileName);

    ofstream fileWriter;
    fileWriter.open(fileName);

    fileWriter << "Generation 0:" << endl;
    fileWriter << mGenOne->getMapString() << endl;

    fileWriter << "\nGeneration 1:" << endl;
    fileWriter << mGenTwo->getMapString() << endl;

    fileWriter << "\nGeneration 2:" << endl;
    fileWriter << mGenThree->getMapString() << endl;

    fileWriter << "\nGeneration 3:" << endl;
    fileWriter << mGenFour->getMapString() << endl;

    while(!isStable()){
        Map* tempMap = mGenOne;
        mGenOne = mGenTwo;
        mGenTwo = mGenThree;
        mGenThree = mGenFour;
        mGenFour = new Map(mGenTwo->getNumRows(), mGenTwo->getNumColumns());
        createNextGen(mGenTwo, mGenThree);
        delete tempMap;
        fileWriter << "\nGeneration " << currGen << ":" << endl;
        fileWriter << mGenFour->getMapString() << endl;
        ++currGen;
    }

    cout << "Successfully created file!" << endl;
    cout << "Please check the folder where the executable was located to find the text file: \"" << fileName << "\"" << endl;
}
