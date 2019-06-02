#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <sstream>
#include "ST.h"
#include "ST_CMPS.h"
#include "ST_PE.h"
#include "CL.h"

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

using namespace std;


int safeInput() {
    int num;
    cin >> num;
    while (cin.fail() || num <= 0) {
        cout << "Invalid input, please re-enter a number larger than 0." << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> num;
    }
    return num;
}

int safeScrInput() {
    int num;
    cin >> num;
    while (cin.fail() || num < 0 || num > 100) {
        cout << "Invalid input, please re-enter a number between 0 and 100." << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> num;
    }
    return num;
}


int MENU() {
    cout << "\nSelect a function:" << endl;
    cout << "1. Add student data" << endl;
    cout << "2. Find student" << endl;
    cout << "3. Delete student data" << endl;
    cout << "4. Print ranking list" << endl;
    cout << "5. Leave" << endl;
    int input = safeInput();
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        return 0;
    } else {
        return input;
    }
}

int menuF() {
    cout << "search by: 1.name 2.number" << endl;
    int input = safeInput();
    if (cin.fail()) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return 0;
    } else {
        return input;
    }
}

int classOption() {
    cout << "Choose a class: 1.CS 2.PE" << endl;
    return safeInput();
}

int main() {
    CL<ST_PE> PEclass = CL<ST_PE>();
    CL<ST_CMPS> CSclass = CL<ST_CMPS>();
    PEclass.loadPE();
    CSclass.loadCS();

    bool leave = false;
    while (!leave) {
        PEclass.savePE();
        CSclass.saveCS();
        switch (MENU()) {
            case 1: {
                switch (classOption()) {
                    case 1: {
                        if (CSclass.getCount() > 50) {
                            cout << "The class can't have over 50 students." << endl;
                            break;
                        }
                        int number;
                        cout << "Enter the number:" << endl;
                        number = safeInput();
                        if (!CSclass.findNum(number)) {
                            cout << "Enter the name:" << endl;
                            string name;
                            cin.ignore(INT_MAX, '\n'); //cin.ignore(numeric_limits<std::streamsize>::max(),'/n')
                            getline(cin, name);
                            while (name.length() > 10) {
                                cout << "Too long, re-enter: " << endl;
                                getline(cin, name);
                            }
                            int prg, math;
                            cout << "Enter computer science score: " << endl;
                            prg = safeScrInput();
                            cout << "Enter math score: " << endl;
                            math = safeScrInput();
                            ST_CMPS *nStudent = new ST_CMPS;
                            nStudent->init(number, name, prg, math);
                            CSclass.insert(nStudent);
                            cout << "Added: ";
                            nStudent->print();
                        } else {
                            cout << "Number had already been used, returning to main menu" << endl;
                        }
                        break;
                    }
                    case 2: {
                        if (PEclass.getCount() > 50) {
                            cout << "The class can't have over 50 students." << endl;
                            break;
                        }
                        int number;
                        cout << "Enter the number:" << endl;
                        number = safeInput();
                        if (!PEclass.findNum(number)) {
                            cout << "Enter the name:" << endl;
                            string name;
                            cin.ignore(INT_MAX, '\n'); //cin.ignore(numeric_limits<std::streamsize>::max(),'/n')
                            getline(cin, name);
                            while (name.length() > 10) {
                                cout << "Too long, re-enter: " << endl;
                                getline(cin, name);
                            }
                            int pe;
                            cout << "Enter PE score: " << endl;
                            pe = safeScrInput();
                            ST_PE *nStudent = new ST_PE;
                            nStudent->init(number, name, pe);
                            PEclass.insert(nStudent);
                            cout << "Added: ";
                            nStudent->print();
                        } else {
                            cout << "Number had already been used, returning to main menu" << endl;
                        }
                        break;
                    }
                    default:
                        cout << "index error" << endl;
                        break;
                }
                break;
            }
            case 2: {
                switch (classOption()) {
                    case 1: {
                        switch (menuF()) {
                            case 1: {
                                string name;
                                cout << "Enter the name:" << endl;
                                cin.ignore(INT_MAX, '\n');
                                getline(cin, name);
                                CSclass.findAndPrintName(name);
                                break;
                            }
                            case 2: {
                                cout << "Enter the number:" << endl;
                                int num = safeInput();
                                ST_CMPS *stu = CSclass.findNum(num);
                                if (stu) {
                                    stu->print();
                                } else {
                                    cout << num << " doesn't exist." << endl;
                                }
                                break;
                            }
                            default: {
                                cout << "Invalid Input, returning to main menu" << endl;
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        switch (menuF()) {
                            case 1: {
                                string name;
                                cout << "Enter the name:" << endl;
                                cin.ignore(INT_MAX, '\n');
                                getline(cin, name);
                                PEclass.findAndPrintName(name);
                                break;
                            }
                            case 2: {
                                cout << "Enter the number:" << endl;
                                int num = safeInput();
                                ST_PE *stu = PEclass.findNum(num);
                                if (stu) {
                                    stu->print();
                                } else {
                                    cout << num << " doesn't exist." << endl;
                                }
                                break;
                            }
                            default: {
                                cout << "Invalid Input, returning to main menu" << endl;
                                break;
                            }
                        }
                        break;
                    }
                    default:
                        cout << "Index error" << endl;
                        break;
                }
                break;

            }

            case 3: {
                switch (classOption()) {
                    case 1: {
                        int number;
                        cout << "Enter the number:" << endl;
                        cin >> number;
                        CSclass.deleteStu(number);
                        break;
                    }
                    case 2: {
                        int number;
                        cout << "Enter the number:" << endl;
                        cin >> number;
                        PEclass.deleteStu(number);
                        break;
                    }
                    default:
                        cout << "Index error" << endl;
                        break;
                }
                break;
            }
            case 4: {
                switch (classOption()) {
                    case 1:
                        cout << "#   Number    Name        CS MATH TOTAL" << endl;
                        CSclass.ranking();
                        break;
                    case 2:
                        cout << "#   Number    Name        PE TOTAL" << endl;
                        PEclass.ranking();
                        break;
                    default:
                        cout << "Index error" << endl;
                        break;
                }
                break;
            }
            case 5: {
                leave = true;
                break;
            }
            default: {
                cout << "Type 1~5 to start a function" << endl;
                break;
            }
        }
    }
    cout << "Thank you for using our service, bye :)" << endl;
    return 0;
}

