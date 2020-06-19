//
// Created by marius on 6/5/20.
//

#include "Calculation.h"
#include <cmath>

Calculation::Calculation(std::string operand, double pX, double pY) : _x(pX), _y(pY){
   Calculation::checkAndCalculate(operand);
}

Calculation::Calculation(std::string operand, double pX) : _x(pX){
    Calculation::checkAndCalculate(operand);
}

Calculation::~Calculation() {}

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
void Calculation::checkAndCalculate(std::string operand) {
    if (operand == "/" || operand == ":"){
        if (_y == 0){
            throw std::invalid_argument("Division by Zero is not defined.");
        }
        _result = Calculation::division();
    }
    if (operand == "^"){
        if (_y < 0){
            //operand = "/";
            //_result = Calculation::division();
        }
        _result = Calculation::pow();
    }
    if (operand == "R"){
        if (_x < 0) {
            throw std::invalid_argument("Sqrt < 0 is not defined.");
        }
        _result = Calculation::sqrt();
    }
    if(operand == "+"){
        _result = Calculation::addition();
    }
    if(operand == "-"){
        _result = Calculation::subtraction();
    }
    if(operand == "*"){
        _result = Calculation::multiply();
    }
}

double Calculation::getResult() {
    return _result;
}