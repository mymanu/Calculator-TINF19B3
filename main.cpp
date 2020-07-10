//
// Created by manuel on 15.05.2020.
//

#include <string>
#include <iostream>
#include "app/classes/Logic.h"
#include "app/classes/CalculatorGUI.h"
#include <QApplication>

using namespace std;

int main (int argc, char *argv[]) {
    QApplication app(argc, argv);

    CalculatorGUI myCalcGUI;
    myCalcGUI.show();

    return app.exec();


    bool calculation = true;
    while(calculation) {
        double result;
        char input[200];

        cout << "Hello User" << endl;
        cout << "We welcome you to the MaMa Calculator." << endl;
        cout << "To start your first calculation you can enter your characters after you read the short explanation"
             << endl;
        cout << "Please enter a calculation like this: a+b | a-b | a*b | a/b | a:b | a^b | \"R\"a (for root (a))"
             << endl;


        cin.getline(input, 200);

        Logic logic(input);

        cout << "Your input was: " << input << " Thank you for calculating with the MaMa Calculator" << endl;

        cout << "To turn off the MaMa Calculator, please enter \"off\" otherwise press ENTER" << endl;
        cin.getline(input, 200);

        cout << "" << endl;

        string inputString(input);

        if(inputString.compare("off") == 0) {
            calculation = false;
        }
    }
}