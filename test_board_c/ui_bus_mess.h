/********************************************************************************
** Form generated from reading UI file 'bus_messXdlGPL.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef BUS_MESSXDLGPL_H
#define BUS_MESSXDLGPL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_messages
{
public:
    QLabel *label;

    void setupUi(QWidget *Form_messages)
    {
        if (Form_messages->objectName().isEmpty())
            Form_messages->setObjectName("Form_messages");
        Form_messages->resize(642, 494);
        Form_messages->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 127)"));
        label = new QLabel(Form_messages);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 80, 531, 351));

        retranslateUi(Form_messages);

        QMetaObject::connectSlotsByName(Form_messages);
    } // setupUi

    void retranslateUi(QWidget *Form_messages)
    {
        Form_messages->setWindowTitle(QCoreApplication::translate("Form_messages", "Messages Bus", nullptr));
        label->setText(QCoreApplication::translate("Form_messages", "Bus messages", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_messages: public Ui_Form_messages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BUS_MESSXDLGPL_H
