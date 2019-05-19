//
// Created by 劉學逸 on 2019-05-20.
//

#ifndef CLASS_MANAGEMENT_CL_H
#define CLASS_MANAGEMENT_CL_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <sstream>
#include "ST.h"
#include "ST_CMPS.h"

using namespace std;

template<typename T>
class CL {
private:
    T *head;

public:
    CL();

    void insert(T *);

    int getCount();

    int findName(string name);

    bool findAndPrintName(string name);

    T *findNum(int);

    void deleteStu(string);

    void deleteStu(int);

    void ranking();

    void saveCS();
};

template<typename T>
CL<T>::CL() {
    head = NULL;
}

template<typename T>
void CL<T>::insert(T *stu) {
    if (head == NULL) {
        head = stu;
        stu->setNext(NULL);
    } else if (stu->getNumber() <= head->getNumber()) {
        stu->setNext(head);
        head = stu;
    } else {
        T *largerPtr = head->getNext();
        T *smallerPtr = head;
        while (largerPtr && stu->getNumber() > largerPtr->getNumber()) {
            smallerPtr = largerPtr;
            largerPtr = largerPtr->getNext();
        }
        smallerPtr->setNext(stu);
        stu->setNext(largerPtr);
    }
}

template<typename T>
int CL<T>::getCount() {
    int counter = 0;

    T *cur = head;
    while (cur) {
        cur = cur->getNext();
        counter++;
    }
    return counter;
}

template<typename T>
T *CL<T>::findNum(int num) {
    T *detector = head;
    while (detector) {
        if (detector->getNumber() == num) {
            return detector;
        } else {
            detector = detector->getNext();
        }
    }
    return NULL;
}

template<typename T>
bool CL<T>::findAndPrintName(string name) {
    bool flag = false;
    T *detector = head;
    while (detector) {
        if (detector->getName() == name) {
            detector->print();
            flag = true;
        }
        detector = detector->getNext();
    }

    if (flag) {
        return true;
    } else {
        cout << name << " doesn't exist." << endl;
        return false;
    }
}

template<typename T>
void CL<T>::deleteStu(int number) {
    T *stu = head;
    T *prev = new T;
    if (stu && stu->getNumber() == number) {  //delete the head object
        head = stu->getNext();
        cout << "Delete operation done!" << endl;
    } else {                          //delete a latter object
        while (stu && stu->getNumber() != number) {
            prev = stu;
            stu = stu->getNext();
        }
        if (stu) {
            prev->setNext(stu->getNext());
            cout << "Delete operation done!" << endl;
        } else {
            cout << "The student doesn't exist, can't delete" << endl;
        }
    }

}

template<typename T>
void CL<T>::ranking() {
    int length = getCount();

    T students[length];
    //make a copy of all student objects to an array
    T *curStu = head;
    for (int i = 0; i < length; i++) {
        students[i] = *curStu;
        curStu = curStu->getNext();
    }
    //sort by total score
    for (int i = 0; i < length - 1; i++) {
        for (int j = i; j < length; j++) {
            if (students[j].getTotal() > students[i].getTotal()) {
                swap(students[i], students[j]);
            } else if (students[j].getTotal() == students[i].getTotal()) {
                if (students[j].getNumber() < students[i].getNumber()) {
                    swap(students[i], students[j]);
                }
            }

        }
    }
    //output results
    for (int i = 0; i < getCount(); i++) {
        students[i].print();
    }
}

template <typename T>
void CL<T>::saveCS() {
    fstream file;
    file.open("CSclass.txt", fstream::trunc);
    file.open("CSclass.txt",fstream::out);
    T *curStu = head;
    for (int i=0; i< getCount(); i++) {
        file << curStu->data() << "\n";
        curStu = curStu->getNext();
    }
    file.close();
}

#endif //CLASS_MANAGEMENT_CL_H
