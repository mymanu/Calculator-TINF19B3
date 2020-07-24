//
// Created by marius on 6/5/20.
//

#include "Calculation.h"
#include <cmath>
// save the numbers in the private vars and start the calculation
Calculation::Calculation(std::string operand, double pX, double pY) : _x(pX), _y(pY){
   Calculation::checkAndCalculate(operand);
}
// save the number in the private var and start the calculation
Calculation::Calculation(std::string operand, double pX) : _x(pX){
    Calculation::checkAndCalculate(operand);
}

Calculation::~Calculation() {}

//basic calculations
double Calculation::sqrt(){
    return ::std::sqrt(_x);
}
double Calculation::addition(){
    return (_x + _y);
};
double Calculation::subtraction(){
    return (_x - _y);
}
double Calculation::multiply(){
    return (_x * _y);
}
double Calculation::division(){
    return (_x / _y);
}
double Calculation::pow(){
    return ::std::pow(_x, _y);
}

// check if there are invalid inputs -> if not: calculate
void Calculation::checkAndCalculate(std::string operand) {
    // check for division by zero
    if (operand == "/" || operand == ":"){
        if (_y == 0){
            _result = NAN;
            throw std::invalid_argument("Division by Zero is not defined.");
        } else{
            _result = Calculation::division();
        }
    }
    // check if exponent is < 0
    else if (operand == "^"){
        if (_y < 0){
            _result = NAN;
            throw std::invalid_argument("^y with y < 0 is not defined.");
        } else{
            _result = Calculation::pow();
        }
    }
    // check if you try to get a Sqrt of a number < 0
    else if (operand == "R"){
        if (_x < 0) {
            _result = NAN;
            throw std::invalid_argument("Sqrt < 0 is not defined.");
        } else{
            _result = Calculation::sqrt();
        }
    }
    else if(operand == "+"){
        _result = Calculation::addition();
    }
    else if(operand == "-"){
        _result = Calculation::subtraction();
    }
    else if(operand == "*"){
        _result = Calculation::multiply();
    } else{
        _result = NAN;
        throw std::invalid_argument("Invalid Input.");
    }
}

// returns the result value
double Calculation::getResult() {
    return _result;
}