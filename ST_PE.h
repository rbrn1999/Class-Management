//
// Created by 劉學逸 on 2019-05-20.
//

#ifndef CLASS_MANAGEMENT_ST_PE_H
#define CLASS_MANAGEMENT_ST_PE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <sstream>
#include "ST.h"

using namespace std;

class ST_PE : public ST {
protected:
    int pe;
    ST_PE *nextSTU;
public:
    ST_PE();

    void init(int, string, int);

    int getPE();

    int getTotal();

    void setNext(ST_PE *);

    ST_PE *getNext();

    void print();
};

ST_PE::ST_PE() {
    name = "";
    number = 0;
    pe = 0;
    nextSTU = NULL;
}

void ST_PE::init(int number, string name, int pe) {
    this->number = number;
    this->name = name;
    this->pe = pe;
}

int ST_PE::getPE() {
    return pe;
}

int ST_PE::getTotal() {
    return pe;
}

void ST_PE::setNext(ST_PE *stu) {
    nextSTU = stu;
}

ST_PE *ST_PE::getNext() {
    return nextSTU;
}

void ST_PE::print() {
    cout << "Number: " << setw(3) << number << " Name: " << setw(10) << name;
    cout << "PE score: " << pe << "total: " << setw(3) << pe << endl;
}


#endif //CLASS_MANAGEMENT_ST_PE_H
