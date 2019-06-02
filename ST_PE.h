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

    void printScore();

    string data();
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
    cout << "Number: " << setw(3) << number << " Name: " << left << setw(10) << name << right;
    cout << "PE score: " << setw(4) << pe << "total: " << setw(4) << pe << endl;
}

void ST_PE::printScore() {
    cout << setw(3) << number << "      " << left << setw(10) << name << right;
    cout << setw(4) << pe << setw(4) << pe << endl;
}

string ST_PE::data() {
    string num, pe;
    stringstream ss;
    ss << this->number;
    num = ss.str();
    ss.str("");
    ss.clear();
    ss << this->pe;
    pe = ss.str();
    ss.str("");
    ss.clear();


    return num+"\n"+name+"\n"+pe;
}


#endif //CLASS_MANAGEMENT_ST_PE_H
