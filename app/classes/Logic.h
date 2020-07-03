//
// Created by manuel on 05.06.2020.
//

#ifndef CALCULATOR_TINF19B3_LOGIC_H
#define CALCULATOR_TINF19B3_LOGIC_H
#include <string>
using namespace std;

class Logic {

public:
    Logic(char term[]);

protected:

private:
    std::string history[10];
};


class Term {

public:
    Term(char input[]);
    //void divideInput(char* input);
    double checkNumber(Term*);

private:
    char* input;
    int position = 0;
    string rule;
    int braceCounter = 0;
    double firstNumber;
    double secondNumber;
};


#endif //CALCULATOR_TINF19B3_LOGIC_H