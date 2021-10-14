/**
 * Implementation File: Map.cpp
 *
 * Full Name: Rahul Sura
 * Student ID: 2371308
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Assignment: Assignment 3
 */
#include "Map.h"

using namespace std;

Map::Map(){
    mNumRows = 7;
    mNumColumns = 7;
    mFileName = "";
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
    mFileName = "";
    grid = new char*[mNumRows];
    for (int i = 0; i < mNumRows; ++i){
        grid[i] = new char[mNumColumns];
    }
    makeEmptyMap();
}

Map::Map(string fileName){
    ifstream fileReader;
    fileReader.open(fileName);

    if(!fileReader.is_open()){
        string runtimeMessage = "ERROR: No file found with the name of \"" + fileName + "\"\n";
        runtimeMessage += "Please check if the file is in the wrong directory, has the proper reading permissions or if you have provided the extension for the file name";
        throw runtime_error(runtimeMessage);
    } else {
        mFileName = fileName;
        if (!isValidFile(fileName)) {
            string runtimeMessage = "ERROR: INVALID FILE INPUT";
            runtimeMessage += "\nThe file had invalid inputs. Please make sure that the following are true:";
            runtimeMessage += "\n\t1. The first line is a single positive integer representing the length of the row";
            runtimeMessage += "\n\t2. The second line is a single positive integer representing the length of the column";
            runtimeMessage += "\n\t3. The grid has the same dimensions as stated in lines 1 and 2 and contains ONLY a \'X\' or a \'-\' for each character";
            throw runtime_error(runtimeMessage);
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
                    grid[currRow][i] = toupper(fileLine[i]);
                }
                ++currRow;
            }
            if (!fileReader.eof()) { // if for some reason the file reader doesn't reach the endl of the file
                throw runtime_error("File wasn't able to be read until the end");
            }
        }
    }
    fileReader.close();

}

Map::~Map(){
    if ((mNumRows > 0 && mNumColumns > 0 && grid != NULL) || (mFileName != "" && isValidFile(mFileName))) {
        for (int i = 0; i < mNumRows; ++i){ // deletes each sub array in the 2d array
            if (grid[i] != NULL) {
                delete [] grid[i];
            }
        }
        delete [] grid; // deletes overall array
    }
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
        randomRow = rand() % mNumRows;
        randomColumn = rand() % mNumColumns;
        if (grid[randomRow][randomColumn] == '-') {
            grid[randomRow][randomColumn] = 'X';
            ++currentlyFilled;
        }
    }
}

bool Map::isValidLine(string fileLine){
    if (fileLine.length() != mNumColumns) {
        return false;
    }
    for (int i = 0; i < fileLine.length(); ++i) {
        if (fileLine[i] != '-' && toupper(fileLine[i]) != 'X') {
            return false;
        }
    }
    return true;
}

bool Map::isValidFile(string fileName){
    ifstream fileReader;
    fileReader.open(fileName);
    string fileLine;

    int numRows;
    getline(fileReader, fileLine);
    if (fileLine.empty()) {
        fileReader.close();
        return false;
    }
    for (int i = 0; i < fileLine.length(); ++i) {
        if (!isdigit(fileLine[i])){
            fileReader.close();
            return false;
        }
    }

    try{ // even if the line is a number, it should be an integer (not larger than the integer limit)
        numRows = stoi(fileLine);
    } catch(invalid_argument &exception) {
        return false;
    }

    mNumRows = numRows;

    getline(fileReader, fileLine);
    if (fileLine.empty()) {
        fileReader.close();
        return false;
    }
    for (int i = 0; i < fileLine.length(); ++i) {
        if (!isdigit(fileLine[i])){
            fileReader.close();
            return false;
        }
    }

    try{ // even if the line is a number, it should be an integer (not larger than the integer limit)
        mNumColumns = stoi(fileLine);
    } catch(invalid_argument &exception) {
        return false;
    }


    int currRow = 0;
    while (getline (fileReader,fileLine)) {
        if (!isValidLine(fileLine)) {
            fileReader.close();
            return false;
        }
        ++currRow;
    }
    if (currRow != numRows) {
        fileReader.close();
        return false;
    }
    fileReader.close();
    return true;

}

void Map::updateGrid(int rowNum, int columnNum, char val){
    if ((rowNum > -1 && rowNum < mNumRows) && (columnNum > -1 && columnNum < mNumColumns) && (val == '-' || toupper(val) == 'X')) {
        grid[rowNum][columnNum] = toupper(val);
    } else {
        throw runtime_error("Not a valid way to update the grid");
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
