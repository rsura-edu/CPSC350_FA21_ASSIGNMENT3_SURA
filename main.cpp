/**
 * Main Implementation File: main.cpp
 *
 * Full Name: Rahul Sura
 * Student ID: 2371308
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Assignment: Assignment 3
 */
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"

using namespace std;

int main(int argc, char** argv) {
    cout << "Hello! Welcome to the Game of Life!" << endl;
    cout << "-----------------------------------" << endl;

    string randOrFile = "";
    string fileName = "";
    string boundaryMode = "";
    int numRows = 0;
    int numColumns = 0;
    double popDensity = 2;


    while (!(randOrFile == "random" || randOrFile == "file")) {
        cout << "Would you like to start with a random configuration or flat-file configuration?" << endl;
        cout << "If you want a random configuration, please type \"random\" into the prompt and hit enter on your keyboard." << endl;
        cout << "If you want a flat-file configuration, please type \"file\" into the prompt and hit enter on your keyboard." << endl;
        cout << "---->\t";
        getline (cin, randOrFile);
        for (int i = 0; i < randOrFile.length(); i++) {
            randOrFile[i] = tolower(randOrFile[i]);
        }
        if (!(randOrFile == "random" || randOrFile == "file")) {
            cout << "Sorry, that wasn't one of the options. Instructions will be repeated again." << endl;
        }
    }

    if (randOrFile == "random") {
        string temp;
        while (numRows < 1) {
            cout << "Input a number representing the number of rows in the grid (a positive integer greater than 0)" << endl;
            cout << "---->\t";
            getline (cin, temp);
            try{
                numRows = stoi(temp);
            } catch (invalid_argument &exception) {
                cerr << "ERROR: Please put a valid positive integer value for the number of rows" << endl;
            }
            if (numRows < 1) {
                cout << "Sorry, that wasn't a valid dimension. Instructions will be repeated again." << endl;
            }
        }
        while (numColumns < 1) {
            cout << "Input a number representing the number of columns in the grid (a positive integer greater than 0)" << endl;
            cout << "---->\t";
            getline (cin, temp);
            try{
                numColumns = stoi(temp);
            } catch (invalid_argument &exception) {
                cerr << "ERROR: Please put a valid positive integer value for the number of columns" << endl;
            }
            if (numColumns < 1) {
                cout << "Sorry, that wasn't a valid dimension. Instructions will be repeated again." << endl;
            }
        }
        while (popDensity < 0 || popDensity > 1) {
            cout << "Input a decimal number between 0 and 1 representing the population density of this grid" << endl;
            cout << "---->\t";
            getline (cin, temp);
            try{
                popDensity = stod(temp);
            } catch (invalid_argument &exception) {
                cerr << "ERROR: Please put a valid positive double value between 0 and 1 representing the population density of the grid" << endl;
            }
            if (popDensity < 0 || popDensity > 1) {
                cout << "Sorry, that wasn't a valid population. Instructions will be repeated again." << endl;
            }
        }
    } else if (randOrFile == "file") {
        while (fileName == "") {
            cout << "Please input the name of the file (or the file path of the file, if it's in a different folder)" << endl;
            cout << "---->\t";
            getline(cin, fileName);
            if (fileName == "") {
                cout << "Sorry, you didn't enter a file name. Instructions will be repeated again." << endl;
            }
        }
    }

    while (!(boundaryMode == "classic" || boundaryMode == "doughnut" || boundaryMode == "mirror")) {
        cout << "What boundary mode would you like?" << endl;
        cout << "If you want classic mode, please type \"classic\" into the prompt and hit enter on your keyboard." << endl;
        cout << "If you want doughnut mode, please type \"doughnut\" into the prompt and hit enter on your keyboard." << endl;
        cout << "If you want mirror mode, please type \"mirror\" into the prompt and hit enter on your keyboard." << endl;
        cout << "---->\t";
        getline (cin, boundaryMode);
        for (int i = 0; i < boundaryMode.length(); i++) {
            boundaryMode[i] = tolower(boundaryMode[i]);
        }
        if (!(boundaryMode == "classic" || boundaryMode == "doughnut" || boundaryMode == "mirror")) {
            cout << "Sorry, that wasn't one of the options. Instructions will be repeated again." << endl;
        }
    }

    if (boundaryMode == "classic") {
        if (numRows > 0) {
            ClassicMode* cm = new ClassicMode(numRows, numColumns, popDensity);
            cm->play();
            delete cm;
        } else if (fileName != ""){
            try {
                ClassicMode* cm = new ClassicMode(fileName);
                cm->play();
                delete cm;
            } catch (runtime_error &exception){
                cerr << exception.what() << endl;
            }
        } else {
            ClassicMode* cm = new ClassicMode();
            cm->play();
            delete cm;
        }
    } else if (boundaryMode == "doughnut") {
        if (numRows > 0) {
            DoughnutMode* dm = new DoughnutMode(numRows, numColumns, popDensity);
            dm->play();
            delete dm;
        } else if (fileName != ""){
            try {
                DoughnutMode* dm = new DoughnutMode(fileName);
                dm->play();
                delete dm;
            } catch (runtime_error &exception){
                cerr << exception.what() << endl;
            }
        } else {
            DoughnutMode* dm = new DoughnutMode();
            dm->play();
            delete dm;
        }
    } else if (boundaryMode == "mirror") {
        if (numRows > 0) {
            MirrorMode* mm = new MirrorMode(numRows, numColumns, popDensity);
            mm->play();
            delete mm;
        } else if (fileName != ""){
            try {
                MirrorMode* mm = new MirrorMode(fileName);
                mm->play();
                delete mm;
            } catch (runtime_error &exception){
                cerr << exception.what() << endl;
            }
        } else {
            MirrorMode* mm = new MirrorMode();
            mm->play();
            delete mm;
        }
    }

    return 0;
}
