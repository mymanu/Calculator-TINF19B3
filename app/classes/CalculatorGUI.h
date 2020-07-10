//
// Created by suppe on 7/3/20.
//
#include <QtWidgets>
#include "../ui/calculator.h"

#ifndef CALCULATOR_TINF19B3_CALCULATORGUI_H
#define CALCULATOR_TINF19B3_CALCULATORGUI_H


class CalculatorGUI : public QWidget {
    Q_OBJECT

public:
    CalculatorGUI(QWidget *parent = nullptr);
    ~CalculatorGUI();

protected:
    //void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::Form *ui;
    bool m_equated = false;

private slots:
    void stringButtonClicked();
    void equalClicked();
    void clearClicked();
    void prefixChange();
};


#endif //CALCULATOR_TINF19B3_CALCULATORGUI_H
