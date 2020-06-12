//
// Created by manuel on 05.06.2020.
//

#include "Logic.h"
#include <string.h>
#include <iostream>
using namespace std;

Logic::Logic(char term[]) {
    string rule;

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

/*
 * ()
 * Potenz
 * Wurzel
 * Mal / Geteilt
 * Plus / Minus
 */

