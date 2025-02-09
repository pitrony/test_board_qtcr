/********************************************************************************
** Form generated from reading UI file 'form_helpZbMEyH.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FORM_HELPZBMEYH_H
#define FORM_HELPZBMEYH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_help
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_h_exit;
    QLabel *label_for_text;
    QListView *listView;

    void setupUi(QWidget *Form_help)
    {
        if (Form_help->objectName().isEmpty())
            Form_help->setObjectName("Form_help");
        Form_help->resize(661, 562);
        Form_help->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 127)"));
        gridLayoutWidget = new QWidget(Form_help);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 500, 641, 61));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton_h_exit = new QPushButton(gridLayoutWidget);
        pushButton_h_exit->setObjectName("pushButton_h_exit");

        gridLayout->addWidget(pushButton_h_exit, 0, 1, 1, 1);

        label_for_text = new QLabel(Form_help);
        label_for_text->setObjectName("label_for_text");
        label_for_text->setGeometry(QRect(20, 70, 601, 431));
        label_for_text->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 127)"));
        listView = new QListView(Form_help);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(20, 20, 256, 31));

        retranslateUi(Form_help);
        QObject::connect(pushButton_h_exit, &QPushButton::clicked, Form_help, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Form_help);
    } // setupUi

    void retranslateUi(QWidget *Form_help)
    {
        Form_help->setWindowTitle(QCoreApplication::translate("Form_help", "Form", nullptr));
        pushButton_h_exit->setText(QCoreApplication::translate("Form_help", "&Exit", nullptr));
        label_for_text->setText(QCoreApplication::translate("Form_help", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\321\213\321\205 \321\202\320\276\321\207\320\265\320\272 \320\272 \321\201\320\270\321\201\321\202\320\265\320\274\320\265 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \321\207\320\265\321\200\320\265\320\267\n"
"\320\277\320\273\320\260\321\202\321\203 \320\263\320\260\320\273\321\214\320\262\320\260\320\275\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \321\200\320\260\320\267\320\262\321\217\320\267\320\272\320\270\n"
"\320\237\320\273\320\260\321\202\320\260 1\n"
"(\320\260\320\264\321\200\320\265\321\201 20h)		\320\237\320\273\320\260\321\202\320\260 2\n"
"(\320\260\320\264\321\200\320\265\321\201 24h)		\320\237\320\273\320\260\321\202\320\260 3\n"
"(\320\260\320\264\321\200\320\265\321\201 22h)\n"
"RY	1		INS	1		RGK	1\n"
"RH	2		UP	2		FRI	2\n"
"RF	3		DOWN	3		PPP	3\n"
"RU1	4		ML1	4		SAFE"
                        "(120)	4\n"
"RU2	5		ML2	5		DSH(130)	5\n"
"KRC	6		DOOR	6		DCAB(140)	6\n"
"FRN	7		TOP	7		LIGHT	7\n"
"PTC	8		BOT	8		REZ1	8\n"
"\n"
"\320\244\320\276\321\200\320\274\320\260 conf_speed \320\264\320\273\321\217 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270. \n"
"\320\222\321\213\320\261\320\276\321\200 \320\276\321\201\321\203\321\211\320\265\321\201\321\202\320\262\320\273\321\217\320\265\321\202\321\201\321\217 3-\320\274\321\217 \321\201\320\270\320\263\320\275\320\260\320\273\320\260\320\274\320\270 RY RH RF, \320\272\320\276\321\202\320\276\321\200\321\213\320\265 \321\204\320\276\321\200\320\274\320\270\321\200\321\203\321\216\321\202 \n"
"\320\262\321\213\320\261\320\276\321\200 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270 \320\262 \321\207"
                        "\320\260\321\201\321\202\320\276\321\202\320\275\320\276\320\274 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265.\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_help: public Ui_Form_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORM_HELPZBMEYH_H
