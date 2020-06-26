//
// Created by marius on 6/5/20.
//

#ifndef CALCULATOR_TINF19B3_CALCULATION_H
#define CALCULATOR_TINF19B3_CALCULATION_H

#include <iostream>

class Calculation {
public:
    Calculation(std::string operand, double pX, double pY);
    Calculation(std::string operand, double pX);
    ~Calculation();

    double getResult();
private:
    double sqrt();
    double addition();
    double subtraction();
    double multiply();
    double division();
    double pow();
    void checkAndCalculate(std::string operand);

    double _result;
    double _x;
    double _y;
};


#endif //CALCULATOR_TINF19B3_CALCULATION_H