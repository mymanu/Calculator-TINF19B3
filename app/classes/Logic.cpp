//
// Created by manuel on 05.06.2020.
//

#include "Logic.h"
#include <string.h>
#include <iostream>
using namespace std;

Logic::Logic(char* term) {
    string rule = "No rule detected !!";

    int size = 10;
    int numberToParse[size] {-1,-1,-1,-1,-1};

    int arrayLength = 0;
    for (int x = 0; x < size; x++) {
        if(numberToParse[x] != -1) {
        arrayLength++;
        }
    }
    cout << "Length: " << arrayLength << endl;

    if(strstr(term, "(")) {
        rule = "brace";
    } else if(strstr(term, "^")) {
        rule = "square";
    } else if(strstr(term, "R")) {
        rule = "root";
    } else if(strstr(term, "*")) {
        rule = "multiply";
    } else if(strstr(term, "/")) {
        rule = "division";
    } else if(strstr(term, ":")) {
        rule = "division";
    } else if(strstr(term, "+")) {
        rule = "addition";
    } else if(strstr(term, "-")) {
        rule = "subtraction";
    }

    cout << "Recognized rule is: " << rule << endl;
}

class Term {
    char* input;
    int position = 0;
    string rule;
    int braceCounter = 0;
    double firstNumber;
    double secondNumber;

public:
    void divideInput(char* term);
    Term& checkNumber(Term);
};

void Term::divideInput(char* term) {
    Term calc;
    calc.input = term;
    for (calc.position = 0; calc.position < sizeof(calc.input); calc.position++) {
        char digit = calc.input[calc.position];
        if (digit == '(') {
            braceCounter++;
        } else if (digit == ')') {
            braceCounter--;
        } else if (digit == '^') {
            rule = "power";
        } else if (digit == 'R') {
            rule = "root";
        } else if (digit == '*') {
            rule = "multiplication";
        } else if (digit == '/') {
            rule = "division";
        } else if (digit == ':') {
            rule = "division";
        } else if (digit == '+') {
            rule = "addition";
        } else if (digit == '-') {
            rule = "subtraction";
        } else if (digit >= '0' && digit <= '9') {
            checkNumber(calc);
        }
    }
}

Term & Term::checkNumber(Term calc) {
    //getting in by first "number" digit to save the Numbers into the number variables in Term Class
    // while (number) add to firstNumber if not "" else add to secondNumber
    int numberToParse[50];
    int positionInNumber = 0;

    int commaPosition = 0;

    for (int i = calc.position; i < sizeof(calc.input); i++) {
        char digit = calc.input[i];

        if (digit >= '0' && digit <= '9') {
            numberToParse[positionInNumber] = digit;
            positionInNumber++;
        } else if (digit == ',') {
            commaPosition = positionInNumber;
        }
        calc.position = i;
    }
    return calc;
}
/*
 * ()
 * Potenz "^"
 * Wurzel "R"
 * Mal "*"
 * Geteilt "/" ":"
 * Plus "+"
 * Minus "-"
 */