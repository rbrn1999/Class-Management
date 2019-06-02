//
// Created by 劉學逸 on 2019-05-20.
//

#ifndef CLASS_MANAGEMENT_ST_CMPS_H
#define CLASS_MANAGEMENT_ST_CMPS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <sstream>
#include "ST.h"

using namespace std;

class ST_CMPS : public ST {
protected:
    int prgScr; // computer science
    int mathScr;
    ST_CMPS *nextStu;
public:
    ST_CMPS();

    void init(int, string, int, int);

    int getTotal();

    void setNext(ST_CMPS *);

    ST_CMPS *getNext();

    void print();

    void printScore();

    string data();

};

ST_CMPS::ST_CMPS() {
    name = "";
    number = 0;
    prgScr = 0;
    mathScr = 0;
    nextStu = NULL;
}

void ST_CMPS::init(int number, string name, int prg, int math) {
    this->number = number;
    this->name = name;
    this->prgScr = prg;
    this->mathScr = math;
}

int ST_CMPS::getTotal() {
    return mathScr + prgScr;
}

void ST_CMPS::setNext(ST_CMPS *ptr) {
    nextStu = ptr;
}

ST_CMPS *ST_CMPS::getNext() {
    return nextStu;
}

void ST_CMPS::print() {
    cout << "Number: " << setw(3) << number << " Name: " << left << setw(10) << name << right;
    cout << " CS score: " << setw(3) << prgScr << " math score: " << setw(3) << mathScr << " total score: " << setw(3)
         << prgScr + mathScr
         << endl;
}

void ST_CMPS::printScore() {
    cout << setw(3) << number << "      " << left << setw(10) << name << right;
    cout << setw(4) << prgScr << setw(4) << mathScr << setw(5)
         << prgScr + mathScr
         << endl;
}

string ST_CMPS::data() {
    string num, prg, math;
    stringstream ss;
    ss << this->number;
    num = ss.str();
    ss.str("");
    ss.clear();
    ss << this->prgScr;
    prg = ss.str();
    ss.str("");
    ss.clear();
    ss << this->mathScr;
    math = ss.str();

    return num+"\n"+name+"\n"+prg+" "+math;
}


#endif //CLASS_MANAGEMENT_ST_CMPS_H
