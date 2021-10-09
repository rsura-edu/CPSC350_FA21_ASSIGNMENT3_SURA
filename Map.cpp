#include "Map.h"

using namespace std;

Map::Map(){
    mNumRows = 7;
    mNumColumns = 7;
    grid = new char*[mNumRows];
    for (int i = 0; i < mNumRows; ++i){
        grid[i] = new char[mNumColumns];
    }
    makeEmptyMap();
    populateMap(0.5);
}

Map::Map(unsigned int numRows, unsigned int numColumns){
    mNumRows = numRows;
    mNumColumns = numColumns;
    grid = new char*[mNumRows];
    for (int i = 0; i < mNumRows; ++i){
        grid[i] = new char[mNumColumns];
    }
    makeEmptyMap();
}

Map::Map(string fileName){
    try{
        ifstream fileReader;
        fileReader.open(fileName);

        if(!fileReader.is_open()){
            cout << "\nOops! No file found with the name of \"" << fileName << "\"" << endl;
            cout << "Please check if the file is in the wrong directory, has the proper reading permissions or if you have provided the extension for the file name" << endl;
        } else {
            string fileLine;
            getline(fileReader, fileLine);
            mNumRows = stoi(fileLine);
            getline(fileReader, fileLine);
            mNumColumns = stoi(fileLine);

            grid = new char*[mNumRows];
            for (int i = 0; i < mNumRows; ++i){
                grid[i] = new char[mNumColumns];
            }

            int currRow = 0;
            while (getline (fileReader,fileLine)) {
                for (int i = 0; i < mNumColumns; ++i) {
                    if (fileLine[i] == '-' || toupper(fileLine[i]) == 'X') {
                        grid[currRow][i] = toupper(fileLine[i]);
                    } else {
                        throw runtime_error("ERROR: INVALID FILE INPUT");
                    }
                }
                ++currRow;
            }
            if (!fileReader.eof()) { // if for some reason the file reader doesn't reach the endl of the file
                cout << "There was an input failure before reaching the end of file." << endl;
            }

        }
        fileReader.close();
    } catch (runtime_error &exception){
        cerr << exception.what() << endl;
        cerr << "The file had invalid inputs. Please make sure that the following are true:" << endl;
        cerr << "1. The first line is a single positive integer representing the length of the row" << endl;
        cerr << "2. The second line is a single positive integer representing the length of the column" << endl;
        cerr << "3. The grid has the same dimensions as stated in lines 1 and 2 and contains ONLY a \'X\' or a \'-\' for each character" << endl;
    }
}

Map::~Map(){
    for (int i = 0; i < mNumRows; ++i){ // deletes each sub array in the 2d arrat
        delete [] grid[i];
    }
    delete [] grid; // deletes overall array
}

string Map::getMapString(){
    string mapStr = "";
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < mNumColumns; ++j) {
            mapStr += grid[i][j];
        }
        mapStr += "\n";
    }
    mapStr = mapStr.substr(0, mapStr.length() - 1); // removes last '\n' character
    return mapStr;
}

void Map::print(){
    cout << getMapString() << endl;
}

void Map::makeEmptyMap(){
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < mNumColumns; ++j) {
            grid[i][j] = '-';
        }
    }
}

void Map::populateMap(double popDensity){
    makeEmptyMap();
    int totCells = round((popDensity * mNumRows) * mNumColumns);
    int currentlyFilled = 0;
    int randomRow;
    int randomColumn;
    while (currentlyFilled < totCells) {
        randomRow = floor(rand() % mNumRows);
        randomColumn = floor(rand() % mNumColumns);
        if (grid[randomRow][randomColumn] == '-') {
            grid[randomRow][randomColumn] = 'X';
            ++currentlyFilled;
        }
    }
}

void Map::updateGrid(int rowNum, int columnNum, char val){
    if ((rowNum > -1 && rowNum < mNumRows) && (columnNum > -1 && columnNum < mNumColumns) && (val == '-' || toupper(val) == 'X')) {
        grid[rowNum][columnNum] = toupper(val);
    } else {
        cerr << "Not a valid way to update the grid" << endl;
    }
}

char Map::getGridElement(int rowNum, int columnNum){
    return grid[rowNum][columnNum];
}

unsigned int Map::getNumRows(){
    return mNumRows;
}

unsigned int Map::getNumColumns(){
    return mNumColumns;
}
