//
// Created by manuel on 05.06.2020.
//

//TODO Logic Konstruktor leer
// Neue Berechnungen übegeben in public funktion

#include "Logic.h"
#include "Calculation.h"
#include <string.h>
#include <iostream>
#include <sstream>
using namespace std;

Logic::Logic() {
}

void Logic::calculate(char rest[]) {
    int i = -1;
    result = 0;
    string input = rest;
    string restAsString = rest;

    //TODO Erstes Zeichen überprüfen, ob Klammer, Vorzeichen (-), Operator (für rechnen mit letztem Ergebnis oder Zahl

    //TODO in Methode auslagern ?????

     while (!restAsString.empty()) {
         char digit = rest[0];

         if (digit >= '0' && digit <= '9' || digit == '-') {
             //if input[0] != number or - -> operator or ( or wrong input.
             if(i >= 0) {
                 numbers[i] = strtod(rest, &rest);

                 cout << "Number: " << i << " Value: " << numbers[i] << endl;
                 cout << "Rest: " << rest << endl;
             } else {
                 result = strtod(rest, &rest);
                 cout << "Number: " << i << " Value: " << result << endl;
             }

             restAsString = rest;
             if(!restAsString.empty()) {
                 operand[i + 1] = rest[0];
                 rest++;
             }

             //TODO Regeln beachten, wann was berechnet wird (Punkt vor Strich)
             if(i >= 0) {
                 Calculation calc(operand[i], result, numbers[i]);
                 try {
                     result = calc.getResult();
                 } catch(...) {
                     /*TODO Exception weiterreichen oder abfangen und dann Rechnung stoppen oder so.
                      * Siehe Vorlesung 4
                      * Invalid Argmunent Exception.
                      */
                 }
                 cout << "Result " << result << endl;
             }

             cout << "Rest nach Abschnitt: " << rest << endl;

             i++;
             cout << "-------------------------------------------------------------------------------" << endl;

         } else if (digit == '^' || digit == '*' || digit == '/' || digit == ':' || digit == '+') {
             //TODO History mit Operator mit folgender Zahl berechnen
             // falls history leer dann fehler

         } else if (digit == '-') {
             //TODO Falls History leer dann minuszahl
             // sonst mit Operator mit folgender Zahl berechnen

         } else {
             //TODO Error keine valide Eingabe
         }
     }
     // History: "<Input> = <Ergebnis>"
    // Convert result from double to string
     std::ostringstream resultStream;
     resultStream << result;
     std::string resultAsString = resultStream.str();

     history = input;
     history.append(" = ");
     history.append(resultAsString);

     //  cout << "History Entry: " << historyEntry << endl;

     restAsString = rest;
}

string Logic::getHistory() {
    return history;
}


/*
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
    cout << "Rest: " << rest << endl;*/




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



/*int test_size = sizeof(input) / sizeof(input[0]);
cout << "Size OFF: " <<  test_size << endl;
int size = sizeof(input);
cout << "Size : " <<  size << endl;

int y = 5;
for(int x = 0; x < y; x++) {
    cout << "X : " <<  x << endl;
    cout << "Y : " <<  y << endl;
    y = 3;
}*/