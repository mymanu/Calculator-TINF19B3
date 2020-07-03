//
// Created by manuel on 05.06.2020.
//

#include "Logic.h"
#include <string.h>
#include <iostream>
using namespace std;

Logic::Logic(char term[]) {
    string rule = "No rule detected !!";
   // string termination = term;
    string::size_type rest;
    double x = stoi(term,&rest);
    cout << "Value: " << x << endl;
   // cout << "Rest: " << termination.substr(rest) << endl;

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

//void Term::divideInput(char* input) {
Term::Term(char term[]) {
    for (position = 0; position < sizeof(input); position++) {
        char digit = input[position];
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
            this->firstNumber = checkNumber(this);
            cout << "First Number: " << firstNumber << endl;
        }
    }
}

double Term::checkNumber(Term*) {
    //getting in by first "number" digit to save the Numbers into the number variables in Term Class
    // while (number) add to firstNumber if not "" else add to secondNumber
    int size = 50;
    int numberToParse[size];
    for (int x = 0; x < size; x++) {
        numberToParse[x] = -1;
        }

    int positionInNumber = 0;
    int potenz = -1;

    int commaPosition = 0;

    /* calc.position position in input string.
     */

    for (int i = position; i < sizeof(input); i++) {
        char digit = input[i];

        if (digit >= '0' && digit <= '9') {
            numberToParse[positionInNumber] = digit;
            positionInNumber++;
        } else if (digit == ',') {
            commaPosition = positionInNumber;
        } else {
            break;
        }
        position = i;
    }
    for (int i = 0; i < size; i++) {
        if (numberToParse[i] != -1) {
            potenz++;
        }
    }
    for (int i = 0; i < size; i++) {
        if (numberToParse[i] != -1) {
           firstNumber = numberToParse[i] ^ potenz;
           potenz--;
        }
    }

    return this->firstNumber;
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