//
// Created by manue on 15.05.2020.
//

#include <string>
#include <iostream>

using namespace std;

int main () {
    bool calculation = true;
    while(calculation) {

        cout << "Hello User" << endl;
        cout << "We welcome you to the MaMa Calculator." << endl;
        cout << "To start your first calculation you can enter your characters after you read the short explanation"
             << endl;
        cout << "Please enter a calculation like this: a+b | a-b | a*b | a/b | a:b | a^b | \"R\"a (for root (a))"
             << endl;

        double result;
        char input[200];
        cin.getline(input, 200);
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