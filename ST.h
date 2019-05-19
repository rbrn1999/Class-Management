//
// Created by 劉學逸 on 2019-05-20.
//

#ifndef CLASS_MANAGEMENT_ST_H
#define CLASS_MANAGEMENT_ST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <sstream>

using namespace std;

class ST {
protected:
    int number;
    string name;

public:
    ST();

    int getNumber();

    string getName();
};

ST::ST() {
    name = "";
    number = 0;
}

int ST::getNumber() {
    return number;
}

string ST::getName() {
    return name;
}

#endif //CLASS_MANAGEMENT_ST_H
