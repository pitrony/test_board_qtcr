/********************************************************************************
** Form generated from reading UI file 'form_conf_speedsQzhVl.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FORM_CONF_SPEEDSQZHVL_H
#define FORM_CONF_SPEEDSQZHVL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_conf_speed
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QRadioButton *radioButton_rh_h;
    QRadioButton *radioButton_rh_read;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label;
    QRadioButton *radioButton_rf_n;
    QRadioButton *radioButton_rh_n;
    QRadioButton *radioButton_rf_ret;
    QRadioButton *radioButton_ry_h;
    QRadioButton *radioButton_rf_h;
    QRadioButton *radioButton_rh_ret;
    QRadioButton *radioButton_ry_ret;
    QRadioButton *radioButton_ry_m;
    QLabel *label_6;
    QRadioButton *radioButton_rh_m;
    QRadioButton *radioButton_rf_m;
    QRadioButton *radioButton_ry_c;
    QLabel *label_9;
    QLabel *label_4;
    QRadioButton *radioButton_ry_n;
    QRadioButton *radioButton_rf_c;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *radioButton_rf_f;
    QLabel *label_3;
    QRadioButton *radioButton_rh_l;
    QRadioButton *radioButton_ry_l;
    QRadioButton *radioButton_rf_l;
    QRadioButton *radioButton_rf_read;
    QLabel *label_2;
    QRadioButton *radioButton_ry_f;
    QRadioButton *radioButton_rh_f;
    QRadioButton *radioButton_rh_c;
    QLabel *label_10;
    QRadioButton *radioButton_rh_sh;
    QRadioButton *radioButton_rf_sh;
    QRadioButton *radioButton_ry_sh;
    QRadioButton *radioButton_ry_read;
    QPushButton *pushButtonOk;
    QPushButton *pushButton_cancel;
    QLabel *label_fls;
    QLabel *label_speed;
    QLineEdit *lineEdit_fls;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *Form_conf_speed)
    {
        if (Form_conf_speed->objectName().isEmpty())
            Form_conf_speed->setObjectName("Form_conf_speed");
        Form_conf_speed->resize(996, 739);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form_conf_speed->sizePolicy().hasHeightForWidth());
        Form_conf_speed->setSizePolicy(sizePolicy);
        Form_conf_speed->setAutoFillBackground(false);
        Form_conf_speed->setStyleSheet(QString::fromUtf8("background: rgb(85, 170, 127)"));
        gridLayoutWidget = new QWidget(Form_conf_speed);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(50, 20, 531, 322));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        radioButton_rh_h = new QRadioButton(gridLayoutWidget);
        radioButton_rh_h->setObjectName("radioButton_rh_h");
        radioButton_rh_h->setChecked(true);
        radioButton_rh_h->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_h, 8, 1, 1, 1);

        radioButton_rh_read = new QRadioButton(gridLayoutWidget);
        radioButton_rh_read->setObjectName("radioButton_rh_read");
        radioButton_rh_read->setChecked(true);
        radioButton_rh_read->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_read, 10, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 10, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 1);

        radioButton_rf_n = new QRadioButton(gridLayoutWidget);
        radioButton_rf_n->setObjectName("radioButton_rf_n");
        radioButton_rf_n->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_n, 7, 2, 1, 1);

        radioButton_rh_n = new QRadioButton(gridLayoutWidget);
        radioButton_rh_n->setObjectName("radioButton_rh_n");
        radioButton_rh_n->setChecked(true);
        radioButton_rh_n->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_n, 7, 1, 1, 1);

        radioButton_rf_ret = new QRadioButton(gridLayoutWidget);
        radioButton_rf_ret->setObjectName("radioButton_rf_ret");
        radioButton_rf_ret->setChecked(true);
        radioButton_rf_ret->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_ret, 4, 2, 1, 1);

        radioButton_ry_h = new QRadioButton(gridLayoutWidget);
        radioButton_ry_h->setObjectName("radioButton_ry_h");
        radioButton_ry_h->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_h, 8, 3, 1, 1);

        radioButton_rf_h = new QRadioButton(gridLayoutWidget);
        radioButton_rf_h->setObjectName("radioButton_rf_h");
        radioButton_rf_h->setChecked(true);
        radioButton_rf_h->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_h, 8, 2, 1, 1);

        radioButton_rh_ret = new QRadioButton(gridLayoutWidget);
        radioButton_rh_ret->setObjectName("radioButton_rh_ret");
        radioButton_rh_ret->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_ret, 4, 1, 1, 1);

        radioButton_ry_ret = new QRadioButton(gridLayoutWidget);
        radioButton_ry_ret->setObjectName("radioButton_ry_ret");
        radioButton_ry_ret->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_ret, 4, 3, 1, 1);

        radioButton_ry_m = new QRadioButton(gridLayoutWidget);
        radioButton_ry_m->setObjectName("radioButton_ry_m");
        radioButton_ry_m->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_m, 9, 3, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        radioButton_rh_m = new QRadioButton(gridLayoutWidget);
        radioButton_rh_m->setObjectName("radioButton_rh_m");
        radioButton_rh_m->setChecked(true);
        radioButton_rh_m->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_m, 9, 1, 1, 1);

        radioButton_rf_m = new QRadioButton(gridLayoutWidget);
        radioButton_rf_m->setObjectName("radioButton_rf_m");
        radioButton_rf_m->setChecked(true);
        radioButton_rf_m->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_m, 9, 2, 1, 1);

        radioButton_ry_c = new QRadioButton(gridLayoutWidget);
        radioButton_ry_c->setObjectName("radioButton_ry_c");
        radioButton_ry_c->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_c, 5, 3, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 0, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        radioButton_ry_n = new QRadioButton(gridLayoutWidget);
        radioButton_ry_n->setObjectName("radioButton_ry_n");
        radioButton_ry_n->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_n, 7, 3, 1, 1);

        radioButton_rf_c = new QRadioButton(gridLayoutWidget);
        radioButton_rf_c->setObjectName("radioButton_rf_c");
        radioButton_rf_c->setChecked(true);
        radioButton_rf_c->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_c, 5, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        radioButton_rf_f = new QRadioButton(gridLayoutWidget);
        radioButton_rf_f->setObjectName("radioButton_rf_f");
        radioButton_rf_f->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_f, 3, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        radioButton_rh_l = new QRadioButton(gridLayoutWidget);
        radioButton_rh_l->setObjectName("radioButton_rh_l");
        radioButton_rh_l->setFocusPolicy(Qt::NoFocus);
        radioButton_rh_l->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_l, 2, 1, 1, 1);

        radioButton_ry_l = new QRadioButton(gridLayoutWidget);
        radioButton_ry_l->setObjectName("radioButton_ry_l");
        radioButton_ry_l->setFocusPolicy(Qt::NoFocus);
        radioButton_ry_l->setChecked(true);
        radioButton_ry_l->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_l, 2, 3, 1, 1);

        radioButton_rf_l = new QRadioButton(gridLayoutWidget);
        radioButton_rf_l->setObjectName("radioButton_rf_l");
        radioButton_rf_l->setFocusPolicy(Qt::NoFocus);
        radioButton_rf_l->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_l, 2, 2, 1, 1);

        radioButton_rf_read = new QRadioButton(gridLayoutWidget);
        radioButton_rf_read->setObjectName("radioButton_rf_read");
        radioButton_rf_read->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_read, 10, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        radioButton_ry_f = new QRadioButton(gridLayoutWidget);
        radioButton_ry_f->setObjectName("radioButton_ry_f");
        radioButton_ry_f->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_f, 3, 3, 1, 1);

        radioButton_rh_f = new QRadioButton(gridLayoutWidget);
        radioButton_rh_f->setObjectName("radioButton_rh_f");
        radioButton_rh_f->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_f, 3, 1, 1, 1);

        radioButton_rh_c = new QRadioButton(gridLayoutWidget);
        radioButton_rh_c->setObjectName("radioButton_rh_c");
        radioButton_rh_c->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_c, 5, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 6, 0, 1, 1);

        radioButton_rh_sh = new QRadioButton(gridLayoutWidget);
        radioButton_rh_sh->setObjectName("radioButton_rh_sh");
        radioButton_rh_sh->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_sh, 6, 1, 1, 1);

        radioButton_rf_sh = new QRadioButton(gridLayoutWidget);
        radioButton_rf_sh->setObjectName("radioButton_rf_sh");
        radioButton_rf_sh->setChecked(true);
        radioButton_rf_sh->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_sh, 6, 2, 1, 1);

        radioButton_ry_sh = new QRadioButton(gridLayoutWidget);
        radioButton_ry_sh->setObjectName("radioButton_ry_sh");
        radioButton_ry_sh->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_sh, 6, 3, 1, 1);

        radioButton_ry_read = new QRadioButton(gridLayoutWidget);
        radioButton_ry_read->setObjectName("radioButton_ry_read");
        radioButton_ry_read->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_read, 10, 3, 1, 1);

        pushButtonOk = new QPushButton(Form_conf_speed);
        pushButtonOk->setObjectName("pushButtonOk");
        pushButtonOk->setGeometry(QRect(100, 380, 90, 28));
        pushButtonOk->setStyleSheet(QString::fromUtf8("background: rgb(255, 255, 127);\n"
"border: 1px solid white"));
        pushButton_cancel = new QPushButton(Form_conf_speed);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(210, 380, 90, 28));
        pushButton_cancel->setStyleSheet(QString::fromUtf8("background: rgb(255, 255, 127);\n"
"border: 1px solid white"));
        label_fls = new QLabel(Form_conf_speed);
        label_fls->setObjectName("label_fls");
        label_fls->setGeometry(QRect(650, 40, 58, 16));
        label_speed = new QLabel(Form_conf_speed);
        label_speed->setObjectName("label_speed");
        label_speed->setGeometry(QRect(650, 80, 58, 16));
        lineEdit_fls = new QLineEdit(Form_conf_speed);
        lineEdit_fls->setObjectName("lineEdit_fls");
        lineEdit_fls->setGeometry(QRect(730, 30, 41, 28));
        lineEdit_2 = new QLineEdit(Form_conf_speed);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(730, 70, 41, 28));

        retranslateUi(Form_conf_speed);
        QObject::connect(pushButton_cancel, &QPushButton::clicked, Form_conf_speed, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Form_conf_speed);
    } // setupUi

    void retranslateUi(QWidget *Form_conf_speed)
    {
        Form_conf_speed->setWindowTitle(QCoreApplication::translate("Form_conf_speed", "speed configure", nullptr));
        label_7->setText(QCoreApplication::translate("Form_conf_speed", "Max speed", nullptr));
        radioButton_rh_h->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_rh_read->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        label_5->setText(QCoreApplication::translate("Form_conf_speed", "Normal speed", nullptr));
        label_8->setText(QCoreApplication::translate("Form_conf_speed", "Reading speed", nullptr));
        label->setText(QCoreApplication::translate("Form_conf_speed", "Leveling", nullptr));
        radioButton_rf_n->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_rh_n->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_rf_ret->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_ry_h->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        radioButton_rf_h->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_rh_ret->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_ry_ret->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        radioButton_ry_m->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        label_6->setText(QCoreApplication::translate("Form_conf_speed", "High speed", nullptr));
        radioButton_rh_m->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_rf_m->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_ry_c->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        label_9->setText(QCoreApplication::translate("Form_conf_speed", "Speed setting", nullptr));
        label_4->setText(QCoreApplication::translate("Form_conf_speed", "Card revision", nullptr));
        radioButton_ry_n->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        radioButton_rf_c->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_rf_f->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        label_3->setText(QCoreApplication::translate("Form_conf_speed", "Return back", nullptr));
        radioButton_rh_l->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_ry_l->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        radioButton_rf_l->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_rf_read->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        label_2->setText(QCoreApplication::translate("Form_conf_speed", "Floor aproach", nullptr));
        radioButton_ry_f->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        radioButton_rh_f->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_rh_c->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        label_10->setText(QCoreApplication::translate("Form_conf_speed", "Shaft revision", nullptr));
        radioButton_rh_sh->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_rf_sh->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_ry_sh->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        radioButton_ry_read->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        pushButtonOk->setText(QCoreApplication::translate("Form_conf_speed", "save", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Form_conf_speed", "cancel", nullptr));
        label_fls->setText(QCoreApplication::translate("Form_conf_speed", "Floors", nullptr));
        label_speed->setText(QCoreApplication::translate("Form_conf_speed", "Speed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_conf_speed: public Ui_Form_conf_speed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORM_CONF_SPEEDSQZHVL_H
