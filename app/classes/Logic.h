//
// Created by manuel on 05.06.2020.
//

#ifndef CALCULATOR_TINF19B3_LOGIC_H
#define CALCULATOR_TINF19B3_LOGIC_H
#include <string>
using namespace std;

class Logic {

public:
    Logic();
    //void divideInput(char* input);
    void calculate(char* rest);
    string getHistory();
    double getResult();

private:
    string operand[10];
    double numbers[20];
    double result = 0;
    string history;

    int braceCounter = 0;


};


#endif //CALCULATOR_TINF19B3_LOGIC_H