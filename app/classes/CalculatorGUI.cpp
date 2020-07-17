//
// Created by marius on 7/3/20.
//

#include "CalculatorGUI.h"
#include "Logic.h"
#include <QtWidgets>
#include <QDebug>
#include <QMessageBox>
#include <iostream>

CalculatorGUI::CalculatorGUI(QWidget *parent) : QWidget(parent), ui(new Ui::Form)
{
    // Setting up UI and connecting the slots
    ui->setupUi(this);
    m_Logic = new Logic();

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
// When an button for textinput is clicked, get the char and append it to the string
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
    // convert the input-field to an an *c array
    QString inputStr = ui->textEdit->toPlainText();
    QByteArray inputBa = inputStr.toLocal8Bit();
    char *c_InputStr = inputBa.data();

    // try to calculate the string, set the result as input and insert calculation into the history
    try {
        m_Logic.startNewCalculation(c_InputStr);

        ui->textEdit->setText(QString::number(m_Logic.getResult()));

        ui->listHistory->addItem(QString::fromStdString(m_Logic.getHistory()));
        ui->listHistory->scrollToBottom();
    } catch (std::invalid_argument exception) {
        ui->textEdit->setText("NOPE");
        QMessageBox messageBox;
        messageBox.critical(0,"invalid argument", exception.what());
        messageBox.setFixedSize(400,200);
    }

    m_equated = true;
}
// clear the input field
void CalculatorGUI::clearClicked() {
    ui->textEdit->setText("");
}
// change the prefix of the whole input
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
