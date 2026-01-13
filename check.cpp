#include <string>
#include <iostream>
#include <thread>
#include <iomanip>
#include <math.h>
#include "Check.h"

using namespace std;


bool getValidNumber(int& number) {
    cin >> number;

    if (cin.fail()) {

        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (cin.gcount() > 1) {
        return false;
    }

    return true;
}

int getNumber() {
    int number;

    while (true) {
        cout << "Введите число: ";

        if (getValidNumber(number)) {
            return number;
        }

        cout << "Даю вам последний шанс одуматься..." << endl;
    }
}
