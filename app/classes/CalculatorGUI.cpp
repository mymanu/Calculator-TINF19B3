//
// Created by suppe on 7/3/20.
//

#include "CalculatorGUI.h"
#include <QtWidgets>
#include <QDebug>
#include <iostream>

CalculatorGUI::CalculatorGUI(QWidget *parent) : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->button0, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->button2, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->button3, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->button4, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->button5, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->button6, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->button7, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->button8, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->button9, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->buttonSQRT, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->buttonEXP, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->buttonDivision, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->buttonMultiply, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->buttonSubtract, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->buttonAdd, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->buttonBracketOpen, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->buttonBracketClose, SIGNAL(released()), this, SLOT(stringButtonClicked()));
    connect(ui->buttonDecimal, SIGNAL(released()), this, SLOT(stringButtonClicked()));

    connect(ui->buttonPrefix, SIGNAL(released()), this, SLOT(prefixChange()));

    connect(ui->buttonClear, SIGNAL(released()), this, SLOT(clearClicked()));

    connect(ui->buttonResult, SIGNAL(released()), this, SLOT(equalClicked()));
}

CalculatorGUI::~CalculatorGUI() {
    delete ui;
}

void CalculatorGUI::stringButtonClicked() {
    QPushButton * button = (QPushButton*)sender();
    QString textEditString = ui->textEdit->toPlainText();
    QString buttonString = button->text();
    bool ok;
    buttonString.toDouble(&ok);

    if (m_equated && ok){
        textEditString = "";
    }
    m_equated = false;

    buttonString = buttonString == "×" ? "*" : buttonString;
    buttonString = buttonString == "÷" ? "/" : buttonString;
    buttonString = buttonString == "√" ? "R" : buttonString;

    textEditString = textEditString + buttonString;

    ui->textEdit->setText(textEditString);
}

void CalculatorGUI::equalClicked() {
    QString inputStr = ui->textEdit->toPlainText();
    QByteArray inputBa = inputStr.toLocal8Bit();
    char *c_InputStr = inputBa.data();

    try {

    } catch (std::invalid_argument exception) {

    }

    m_equated = true;
}

void CalculatorGUI::clearClicked() {
    ui->textEdit->setText("");
}

void CalculatorGUI::prefixChange() {
    QString textEditString = ui->textEdit->toPlainText();

    if (textEditString != "") {
        if (textEditString.at(0) == '-') {
            textEditString.remove(0, 1);
        } else {
            textEditString.prepend('-');
        }

        ui->textEdit->setText(textEditString);
    }
}