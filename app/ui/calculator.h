#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTextEdit *textEdit;
    QPushButton *buttonClear;
    QPushButton *buttonPrefix;
    QPushButton *buttonSQRT;
    QPushButton *buttonDivision;
    QPushButton *buttonMultiply;
    QPushButton *buttonSubtract;
    QPushButton *buttonAdd;
    QPushButton *buttonResult;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;
    QPushButton *button0;
    QPushButton *buttonDecimal;
    QPushButton *buttonEXP;
    QPushButton *buttonBracketOpen;
    QPushButton *buttonBracketClose;
    QListWidget *listHistory;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(262, 355);
        Form->setMinimumSize(QSize(262, 355));
        Form->setMaximumSize(QSize(262, 355));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("SP_FileDialogListView");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        Form->setWindowIcon(icon);
        textEdit = new QTextEdit(Form);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 60, 241, 31));
        buttonClear = new QPushButton(Form);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));
        buttonClear->setGeometry(QRect(10, 100, 41, 41));
        buttonPrefix = new QPushButton(Form);
        buttonPrefix->setObjectName(QString::fromUtf8("buttonPrefix"));
        buttonPrefix->setGeometry(QRect(60, 100, 41, 41));
        buttonSQRT = new QPushButton(Form);
        buttonSQRT->setObjectName(QString::fromUtf8("buttonSQRT"));
        buttonSQRT->setGeometry(QRect(110, 100, 41, 41));
        buttonDivision = new QPushButton(Form);
        buttonDivision->setObjectName(QString::fromUtf8("buttonDivision"));
        buttonDivision->setGeometry(QRect(210, 100, 41, 41));
        buttonMultiply = new QPushButton(Form);
        buttonMultiply->setObjectName(QString::fromUtf8("buttonMultiply"));
        buttonMultiply->setGeometry(QRect(210, 150, 41, 41));
        buttonSubtract = new QPushButton(Form);
        buttonSubtract->setObjectName(QString::fromUtf8("buttonSubtract"));
        buttonSubtract->setGeometry(QRect(210, 200, 41, 41));
        buttonAdd = new QPushButton(Form);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));
        buttonAdd->setGeometry(QRect(210, 250, 41, 41));
        buttonResult = new QPushButton(Form);
        buttonResult->setObjectName(QString::fromUtf8("buttonResult"));
        buttonResult->setGeometry(QRect(210, 300, 41, 41));
        button7 = new QPushButton(Form);
        button7->setObjectName(QString::fromUtf8("button7"));
        button7->setGeometry(QRect(10, 150, 41, 41));
        button8 = new QPushButton(Form);
        button8->setObjectName(QString::fromUtf8("button8"));
        button8->setGeometry(QRect(60, 150, 41, 41));
        button9 = new QPushButton(Form);
        button9->setObjectName(QString::fromUtf8("button9"));
        button9->setGeometry(QRect(110, 150, 41, 41));
        button4 = new QPushButton(Form);
        button4->setObjectName(QString::fromUtf8("button4"));
        button4->setGeometry(QRect(10, 200, 41, 41));
        button5 = new QPushButton(Form);
        button5->setObjectName(QString::fromUtf8("button5"));
        button5->setGeometry(QRect(60, 200, 41, 41));
        button6 = new QPushButton(Form);
        button6->setObjectName(QString::fromUtf8("button6"));
        button6->setGeometry(QRect(110, 200, 41, 41));
        button1 = new QPushButton(Form);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setGeometry(QRect(10, 250, 41, 41));
        button2 = new QPushButton(Form);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setGeometry(QRect(60, 250, 41, 41));
        button3 = new QPushButton(Form);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setGeometry(QRect(110, 250, 41, 41));
        button0 = new QPushButton(Form);
        button0->setObjectName(QString::fromUtf8("button0"));
        button0->setGeometry(QRect(10, 300, 91, 41));
        buttonDecimal = new QPushButton(Form);
        buttonDecimal->setObjectName(QString::fromUtf8("buttonDecimal"));
        buttonDecimal->setGeometry(QRect(110, 300, 41, 41));
        buttonEXP = new QPushButton(Form);
        buttonEXP->setObjectName(QString::fromUtf8("buttonEXP"));
        buttonEXP->setGeometry(QRect(160, 100, 41, 41));
        buttonBracketOpen = new QPushButton(Form);
        buttonBracketOpen->setObjectName(QString::fromUtf8("buttonBracketOpen"));
        buttonBracketOpen->setGeometry(QRect(160, 150, 41, 41));
        buttonBracketClose = new QPushButton(Form);
        buttonBracketClose->setObjectName(QString::fromUtf8("buttonBracketClose"));
        buttonBracketClose->setGeometry(QRect(160, 200, 41, 41));
        listHistory = new QListWidget(Form);
        listHistory->setObjectName(QString::fromUtf8("listHistory"));
        listHistory->setGeometry(QRect(10, 10, 241, 41));
        listHistory->setAcceptDrops(true);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    }

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Calculator", nullptr));
        buttonClear->setText(QCoreApplication::translate("Form", "AC", nullptr));
        buttonPrefix->setText(QCoreApplication::translate("Form", "+/-", nullptr));
        buttonSQRT->setText(QCoreApplication::translate("Form", "\342\210\232", nullptr));
        buttonDivision->setText(QCoreApplication::translate("Form", "\303\267", nullptr));
        buttonMultiply->setText(QCoreApplication::translate("Form", "\303\227", nullptr));
        buttonSubtract->setText(QCoreApplication::translate("Form", "-", nullptr));
        buttonAdd->setText(QCoreApplication::translate("Form", "+", nullptr));
        buttonResult->setText(QCoreApplication::translate("Form", "=", nullptr));
        button7->setText(QCoreApplication::translate("Form", "7", nullptr));
        button8->setText(QCoreApplication::translate("Form", "8", nullptr));
        button9->setText(QCoreApplication::translate("Form", "9", nullptr));
        button4->setText(QCoreApplication::translate("Form", "4", nullptr));
        button5->setText(QCoreApplication::translate("Form", "5", nullptr));
        button6->setText(QCoreApplication::translate("Form", "6", nullptr));
        button1->setText(QCoreApplication::translate("Form", "1", nullptr));
        button2->setText(QCoreApplication::translate("Form", "2", nullptr));
        button3->setText(QCoreApplication::translate("Form", "3", nullptr));
        button0->setText(QCoreApplication::translate("Form", "0", nullptr));
        buttonDecimal->setText(QCoreApplication::translate("Form", ",", nullptr));
        buttonEXP->setText(QCoreApplication::translate("Form", "^", nullptr));
        buttonBracketOpen->setText(QCoreApplication::translate("Form", "(", nullptr));
        buttonBracketClose->setText(QCoreApplication::translate("Form", ")", nullptr));
    }
};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CALCULATOR_H