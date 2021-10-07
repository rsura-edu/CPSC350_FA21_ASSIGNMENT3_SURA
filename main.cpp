#include "Map.h"
#include <exception>


using namespace std;

void toLowerCase(string &s){
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
}

int main(int argc, char** argv) {

/*
    cout << "Hello! Welcome to the Game of Life!" << endl;
    cout << "-----------------------------------" << endl;

    string randOrFile = "";
    string fileName = "";
    string boundaryMode = "";
    unsigned int rowLength = 0;
    unsigned int columnLength = 0;
    unsigned double popDensity = 2;


    while (!(randOrFile == "random" || randOrFile == "file")) {
        cout << "Would you like to start with a random configuration or flat-file configuration?" << endl;
        cout << "If you want a random configuration, please type \"random\" into the prompt" << endl;
        cout << "If you want a flat-file configuration, please type \"file\" into the prompt" << endl;
        getline (cin, randOrFile);
        toLowerCase(randOrFile);
        if (!(randOrFile == "random" || randOrFile == "file")) {
            cout << "Sorry, that wasn't one of the options. Instructions will be repeated again." << endl;
        }
    }

    if (randOrFile == "random") {
        try{
            string temp;
            while (rowLength > 0) {
                cout << "Input a number representing the length of the row of the grid (a positive integer greater than 0)" << endl;
                getline (cin, temp);
                rowLength = stoi(temp);
                if (rowLength < 1) {
                    cout << "Sorry, that wasn't a valid dimension. Instructions will be repeated again." << endl;
                }
            }
            while (columnLength > 0) {
                cout << "Input a number representing the length of the column of the grid (a positive integer greater than 0)" << endl;
                getline (cin, temp);
                columnLength = stoi(temp);
                if (columnLength < 1) {
                    cout << "Sorry, that wasn't a valid dimension. Instructions will be repeated again." << endl;
                }
            }
            while (popDensity >= 0 && popDensity <= 1) {
                cout << "Input a decimal number between 0 and 1 representing the population density of this grid" << endl;
                getline (cin, temp);
                popDensity = stod(temp);
                if (popDensity < 0 || popDensity > 1) {
                    cout << "Sorry, that wasn't a valid population. Instructions will be repeated again." << endl;
                }
            }
        } catch (runtime_error &exception){
            cout << "Please put valid, positive integer values for the dimensions of the grid and ";
            cout << "a valid positive double value between 0 and 1 representing the population density of the grid" << endl;
        }
    } else if (randOrFile == "file") {
        while (!fileName == "") {
            cout << "Please input the name of the file (or the file path of the file, if it's in a different folder)" << endl;
            getline(cin, fileName);
            if (fileName == "") {
                cout << "Sorry, you didn't enter a file name. Instructions will be repeated again." << endl;
            }
        }
    }

    while (!(boundaryMode == "classic" || boundaryMode == "doughnut" || boundaryMode == "mirror")) {
        cout << "What boundary mode would you like?" << endl;
        cout << "If you want classic mode, please type \"classic\" into the prompt" << endl;
        cout << "If you want doughnut mode, please type \"doughnut\" into the prompt" << endl;
        cout << "If you want mirror mode, please type \"mirror\" into the prompt" << endl;
        getline (cin, boundaryMode);
        toLowerCase(boundaryMode);
        if (!(boundaryMode == "classic" || boundaryMode == "doughnut" || boundaryMode == "mirror")) {
            cout << "Sorry, that wasn't one of the options. Instructions will be repeated again." << endl;
        }
    }

    if (boundaryMode == "classic") {
        ClassicMode *cm
        if (rowLength > 0) {
            cm = new ClassicMode(rowLength, columnLength, popDensity);
        } else if (fileName != ""){
            cm = new ClassicMode(fileName);
        } else {
            cm = new ClassicMode(5, 5, 0.5);
        }
        cm->play();
        delete cm;
    } else if (boundaryMode == "doughnut"){
        DoughnutMode *dm
        if (rowLength > 0) {
            dm = new DoughnutMode(rowLength, columnLength, popDensity);
        } else if (fileName != ""){
            dm = new DoughnutMode(fileName);
        } else {
            dm = new DoughnutMode(5, 5, 0.5);
        }
        dm->play();
        delete dm;
    } else if (boundaryMode == "mirror"){
        MirrorMode *mm
        if (rowLength > 0) {
            mm = new ClassicMode(rowLength, columnLength, popDensity);
        } else if (fileName != ""){
            mm = new ClassicMode(fileName);
        } else {
            mm = new ClassicMode(5, 5, 0.5);
        }
        mm->play();
        delete mm;
    }
*/

    return 0;
}
