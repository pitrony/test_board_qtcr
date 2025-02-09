/********************************************************************************
** Form generated from reading UI file 'form_confOrTvOw.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FORM_CONFORTVOW_H
#define FORM_CONFORTVOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_conf
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *Form_conf)
    {
        if (Form_conf->objectName().isEmpty())
            Form_conf->setObjectName("Form_conf");
        Form_conf->resize(640, 480);
        Form_conf->setStyleSheet(QString::fromUtf8("background:rgb(85, 255, 127)"));
        buttonBox = new QDialogButtonBox(Form_conf);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(230, 420, 176, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Form_conf);

        QMetaObject::connectSlotsByName(Form_conf);
    } // setupUi

    void retranslateUi(QWidget *Form_conf)
    {
        Form_conf->setWindowTitle(QCoreApplication::translate("Form_conf", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_conf: public Ui_Form_conf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORM_CONFORTVOW_H
