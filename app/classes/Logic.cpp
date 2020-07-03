//
// Created by manuel on 05.06.2020.
//

#include "Logic.h"
#include <string.h>
#include <iostream>
using namespace std;

Logic::Logic(char term[]) {
    string rule = "No rule detected !!";

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
Term::Term(char input[]) {

    //TODO Erstes Zeichen überprüfen, ob Klammer, Vorzeichen (-), Operator (für rechnen mit letztem Ergebnis oder Zahl

    //to split input in numbers.
    //--------------------------------
    //if input[0] != number or - -> operator or ( or wrong input.
    // negative number works
    firstNumber = strtod(input, &rest);

    cout << "Value: " << firstNumber << endl;
    cout << "Value * 11: " << firstNumber * 11 << endl;
    cout << "Rest: " << rest << endl;

    firstOperand = rest[0];
    rest++;
    cout << "Rest nach Abschnitt: " << rest << endl;

    secondNumber = strtod(rest, &rest);
    secondOperand = rest[0];
    rest++;

    cout << "Value: " << secondNumber << endl;
    cout << "Value * 11: " << secondNumber * 11 << endl;
    cout << "Rest: " << rest << endl;

    thirdNumber = strtod(rest, &rest);
    thirdOperand = rest[0];
    rest++;

    cout << "Value: " << thirdNumber << endl;
    cout << "Value * 11: " << thirdNumber * 11 << endl;
    cout << "Rest: " << rest << endl;

    fourthNumber = strtod(rest, &rest);

    cout << "Value: " << fourthNumber << endl;
    cout << "Value * 11: " << fourthNumber * 11 << endl;
    cout << "Rest: " << rest << endl;
}


  /*  if (rest.compare(0,1,".")!= 0) {
        operand = rest[0];
        cout << "Rest vor kuerzen: " << rest << endl;
        rest = rest.substr(1);
        cout << "Rest nach kuerzen: " << rest << endl;
    } else {
        rest = rest.substr(1);
        int restOfNumber = stoi(rest,&restSize);
        firstNumber = firstNumber + .500;
        cout << "Value: " << firstNumber << endl;
    }*/

   // secondNumber = stoi(newRest,&restSize);

   // cout << "Value: " << secondNumber << endl;
   // cout << "Rest: " << newRest.substr(rest) << endl;


    //---------------------------------
    //receive the first number (everything before the point) and the rest as a String.

     /*while(!input.substr(rest).empty()) {
        break;
    }*/



 /*   for (position = 0; position < sizeof(input); position++) {
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
}*/

/*double Term::checkNumber(Term*) {
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



    for (int i = position; i < input.size(); i++) {
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
}*/
/*
 * ()
 * Potenz "^"
 * Wurzel "R"
 * Mal "*"
 * Geteilt "/" ":"
 * Plus "+"
 * Minus "-"
 */