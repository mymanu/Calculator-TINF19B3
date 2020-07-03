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
    string input;
    char operand;
    string::size_type restSize;
    double firstNumber;
    double secondNumber;


    int position = 0;
    string rule;
    int braceCounter = 0;


};


#endif //CALCULATOR_TINF19B3_LOGIC_H