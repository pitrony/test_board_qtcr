/********************************************************************************
** Form generated from reading UI file 'form_conf_speedrotwbD.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FORM_CONF_SPEEDROTWBD_H
#define FORM_CONF_SPEEDROTWBD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QRadioButton *radioButton_rh_ret;
    QRadioButton *radioButton_ry_h;
    QRadioButton *radioButton_rh_read;
    QRadioButton *radioButton_rf_c;
    QLabel *label_6;
    QRadioButton *radioButton_rf_read;
    QRadioButton *radioButton_rh_m;
    QRadioButton *radioButton_rh_h;
    QRadioButton *radioButton_ry_m;
    QLabel *label_10;
    QRadioButton *radioButton_rf_l;
    QLabel *label_8;
    QRadioButton *radioButton_rf_h;
    QRadioButton *radioButton_ry_read;
    QLabel *label_5;
    QRadioButton *radioButton_ry_n;
    QRadioButton *radioButton_rf_m;
    QRadioButton *radioButton_rf_ret;
    QRadioButton *radioButton_ry_ret;
    QRadioButton *radioButton_rh_n;
    QRadioButton *radioButton_rh_l;
    QRadioButton *radioButton_rh_f;
    QRadioButton *radioButton_ry_l;
    QLabel *label_7;
    QRadioButton *radioButton_rf_sh;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *radioButton_ry_f;
    QRadioButton *radioButton_rf_f;
    QLabel *label_9;
    QLabel *label_3;
    QRadioButton *radioButton_rf_n;
    QRadioButton *radioButton_ry_c;
    QRadioButton *radioButton_ry_sh;
    QLabel *label;
    QRadioButton *radioButton_rh_c;
    QLabel *label_4;
    QLabel *label_2;
    QRadioButton *radioButton_rh_sh;
    QLabel *label_fls;
    QLineEdit *lineEdit_2;
    QLabel *label_speed;
    QListWidget *listWidget_fls;
    QPushButton *pushButton_Ok;
    QPushButton *pushButton_cancel;
    QLabel *label_saved;
    QLabel *label_board;
    QListWidget *listWidget_board;

    void setupUi(QDialog *Form_conf_speed)
    {
        if (Form_conf_speed->objectName().isEmpty())
            Form_conf_speed->setObjectName("Form_conf_speed");
        Form_conf_speed->resize(905, 675);
        Form_conf_speed->setStyleSheet(QString::fromUtf8("background: rgb(85, 170, 127)"));
        gridLayoutWidget = new QWidget(Form_conf_speed);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(40, 40, 531, 401));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_rh_ret = new QRadioButton(gridLayoutWidget);
        radioButton_rh_ret->setObjectName("radioButton_rh_ret");
        radioButton_rh_ret->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_ret, 4, 1, 1, 1);

        radioButton_ry_h = new QRadioButton(gridLayoutWidget);
        radioButton_ry_h->setObjectName("radioButton_ry_h");
        radioButton_ry_h->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_h, 8, 3, 1, 1);

        radioButton_rh_read = new QRadioButton(gridLayoutWidget);
        radioButton_rh_read->setObjectName("radioButton_rh_read");
        radioButton_rh_read->setChecked(true);
        radioButton_rh_read->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_read, 10, 1, 1, 1);

        radioButton_rf_c = new QRadioButton(gridLayoutWidget);
        radioButton_rf_c->setObjectName("radioButton_rf_c");
        radioButton_rf_c->setChecked(true);
        radioButton_rf_c->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_c, 5, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        radioButton_rf_read = new QRadioButton(gridLayoutWidget);
        radioButton_rf_read->setObjectName("radioButton_rf_read");
        radioButton_rf_read->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_read, 10, 2, 1, 1);

        radioButton_rh_m = new QRadioButton(gridLayoutWidget);
        radioButton_rh_m->setObjectName("radioButton_rh_m");
        radioButton_rh_m->setChecked(true);
        radioButton_rh_m->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_m, 9, 1, 1, 1);

        radioButton_rh_h = new QRadioButton(gridLayoutWidget);
        radioButton_rh_h->setObjectName("radioButton_rh_h");
        radioButton_rh_h->setChecked(true);
        radioButton_rh_h->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_h, 8, 1, 1, 1);

        radioButton_ry_m = new QRadioButton(gridLayoutWidget);
        radioButton_ry_m->setObjectName("radioButton_ry_m");
        radioButton_ry_m->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_m, 9, 3, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 6, 0, 1, 1);

        radioButton_rf_l = new QRadioButton(gridLayoutWidget);
        radioButton_rf_l->setObjectName("radioButton_rf_l");
        radioButton_rf_l->setFocusPolicy(Qt::NoFocus);
        radioButton_rf_l->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_l, 2, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 10, 0, 1, 1);

        radioButton_rf_h = new QRadioButton(gridLayoutWidget);
        radioButton_rf_h->setObjectName("radioButton_rf_h");
        radioButton_rf_h->setChecked(true);
        radioButton_rf_h->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_h, 8, 2, 1, 1);

        radioButton_ry_read = new QRadioButton(gridLayoutWidget);
        radioButton_ry_read->setObjectName("radioButton_ry_read");
        radioButton_ry_read->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_read, 10, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        radioButton_ry_n = new QRadioButton(gridLayoutWidget);
        radioButton_ry_n->setObjectName("radioButton_ry_n");
        radioButton_ry_n->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_n, 7, 3, 1, 1);

        radioButton_rf_m = new QRadioButton(gridLayoutWidget);
        radioButton_rf_m->setObjectName("radioButton_rf_m");
        radioButton_rf_m->setChecked(true);
        radioButton_rf_m->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_m, 9, 2, 1, 1);

        radioButton_rf_ret = new QRadioButton(gridLayoutWidget);
        radioButton_rf_ret->setObjectName("radioButton_rf_ret");
        radioButton_rf_ret->setChecked(true);
        radioButton_rf_ret->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_ret, 4, 2, 1, 1);

        radioButton_ry_ret = new QRadioButton(gridLayoutWidget);
        radioButton_ry_ret->setObjectName("radioButton_ry_ret");
        radioButton_ry_ret->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_ret, 4, 3, 1, 1);

        radioButton_rh_n = new QRadioButton(gridLayoutWidget);
        radioButton_rh_n->setObjectName("radioButton_rh_n");
        radioButton_rh_n->setChecked(true);
        radioButton_rh_n->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_n, 7, 1, 1, 1);

        radioButton_rh_l = new QRadioButton(gridLayoutWidget);
        radioButton_rh_l->setObjectName("radioButton_rh_l");
        radioButton_rh_l->setFocusPolicy(Qt::NoFocus);
        radioButton_rh_l->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_l, 2, 1, 1, 1);

        radioButton_rh_f = new QRadioButton(gridLayoutWidget);
        radioButton_rh_f->setObjectName("radioButton_rh_f");
        radioButton_rh_f->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_f, 3, 1, 1, 1);

        radioButton_ry_l = new QRadioButton(gridLayoutWidget);
        radioButton_ry_l->setObjectName("radioButton_ry_l");
        radioButton_ry_l->setFocusPolicy(Qt::NoFocus);
        radioButton_ry_l->setChecked(true);
        radioButton_ry_l->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_l, 2, 3, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        radioButton_rf_sh = new QRadioButton(gridLayoutWidget);
        radioButton_rf_sh->setObjectName("radioButton_rf_sh");
        radioButton_rf_sh->setChecked(true);
        radioButton_rf_sh->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_sh, 6, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        radioButton_ry_f = new QRadioButton(gridLayoutWidget);
        radioButton_ry_f->setObjectName("radioButton_ry_f");
        radioButton_ry_f->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_f, 3, 3, 1, 1);

        radioButton_rf_f = new QRadioButton(gridLayoutWidget);
        radioButton_rf_f->setObjectName("radioButton_rf_f");
        radioButton_rf_f->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_f, 3, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        radioButton_rf_n = new QRadioButton(gridLayoutWidget);
        radioButton_rf_n->setObjectName("radioButton_rf_n");
        radioButton_rf_n->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rf_n, 7, 2, 1, 1);

        radioButton_ry_c = new QRadioButton(gridLayoutWidget);
        radioButton_ry_c->setObjectName("radioButton_ry_c");
        radioButton_ry_c->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_c, 5, 3, 1, 1);

        radioButton_ry_sh = new QRadioButton(gridLayoutWidget);
        radioButton_ry_sh->setObjectName("radioButton_ry_sh");
        radioButton_ry_sh->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ry_sh, 6, 3, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 1);

        radioButton_rh_c = new QRadioButton(gridLayoutWidget);
        radioButton_rh_c->setObjectName("radioButton_rh_c");
        radioButton_rh_c->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_c, 5, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        radioButton_rh_sh = new QRadioButton(gridLayoutWidget);
        radioButton_rh_sh->setObjectName("radioButton_rh_sh");
        radioButton_rh_sh->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rh_sh, 6, 1, 1, 1);

        label_fls = new QLabel(Form_conf_speed);
        label_fls->setObjectName("label_fls");
        label_fls->setGeometry(QRect(610, 150, 58, 16));
        lineEdit_2 = new QLineEdit(Form_conf_speed);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(680, 180, 51, 28));
        label_speed = new QLabel(Form_conf_speed);
        label_speed->setObjectName("label_speed");
        label_speed->setGeometry(QRect(610, 190, 58, 16));
        listWidget_fls = new QListWidget(Form_conf_speed);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        new QListWidgetItem(listWidget_fls);
        listWidget_fls->setObjectName("listWidget_fls");
        listWidget_fls->setGeometry(QRect(680, 140, 51, 31));
        pushButton_Ok = new QPushButton(Form_conf_speed);
        pushButton_Ok->setObjectName("pushButton_Ok");
        pushButton_Ok->setGeometry(QRect(290, 480, 127, 25));
        pushButton_Ok->setFocusPolicy(Qt::NoFocus);
        pushButton_Ok->setStyleSheet(QString::fromUtf8("background: rgb(255, 255, 127);\n"
"border: 1px solid white"));
        pushButton_cancel = new QPushButton(Form_conf_speed);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(430, 480, 128, 25));
        pushButton_cancel->setFocusPolicy(Qt::NoFocus);
        pushButton_cancel->setStyleSheet(QString::fromUtf8("background: rgb(255, 255, 127);\n"
"border: 1px solid white"));
        label_saved = new QLabel(Form_conf_speed);
        label_saved->setObjectName("label_saved");
        label_saved->setGeometry(QRect(800, 20, 128, 23));
        label_board = new QLabel(Form_conf_speed);
        label_board->setObjectName("label_board");
        label_board->setGeometry(QRect(610, 220, 70, 23));
        listWidget_board = new QListWidget(Form_conf_speed);
        new QListWidgetItem(listWidget_board);
        new QListWidgetItem(listWidget_board);
        listWidget_board->setObjectName("listWidget_board");
        listWidget_board->setGeometry(QRect(680, 210, 221, 31));
        gridLayoutWidget->raise();
        label_fls->raise();
        lineEdit_2->raise();
        label_speed->raise();
        listWidget_fls->raise();
        pushButton_cancel->raise();
        label_saved->raise();
        label_board->raise();
        listWidget_board->raise();
        pushButton_Ok->raise();

        retranslateUi(Form_conf_speed);
        QObject::connect(pushButton_Ok, &QPushButton::clicked, label_saved, qOverload<>(&QLabel::hide));

        QMetaObject::connectSlotsByName(Form_conf_speed);
    } // setupUi

    void retranslateUi(QDialog *Form_conf_speed)
    {
        Form_conf_speed->setWindowTitle(QCoreApplication::translate("Form_conf_speed", "Form for configure", nullptr));
        radioButton_rh_ret->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_ry_h->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        radioButton_rh_read->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_rf_c->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        label_6->setText(QCoreApplication::translate("Form_conf_speed", "High speed", nullptr));
        radioButton_rf_read->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_rh_m->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_rh_h->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_ry_m->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        label_10->setText(QCoreApplication::translate("Form_conf_speed", "Shaft revision", nullptr));
        radioButton_rf_l->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        label_8->setText(QCoreApplication::translate("Form_conf_speed", "Reading speed", nullptr));
        radioButton_rf_h->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_ry_read->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        label_5->setText(QCoreApplication::translate("Form_conf_speed", "Normal speed", nullptr));
        radioButton_ry_n->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        radioButton_rf_m->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_rf_ret->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_ry_ret->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        radioButton_rh_n->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_rh_l->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_rh_f->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        radioButton_ry_l->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        label_7->setText(QCoreApplication::translate("Form_conf_speed", "Max speed", nullptr));
        radioButton_rf_sh->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_ry_f->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        radioButton_rf_f->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        label_9->setText(QCoreApplication::translate("Form_conf_speed", "Speed setting", nullptr));
        label_3->setText(QCoreApplication::translate("Form_conf_speed", "Return back", nullptr));
        radioButton_rf_n->setText(QCoreApplication::translate("Form_conf_speed", " RF", nullptr));
        radioButton_ry_c->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        radioButton_ry_sh->setText(QCoreApplication::translate("Form_conf_speed", " RY", nullptr));
        label->setText(QCoreApplication::translate("Form_conf_speed", "Leveling", nullptr));
        radioButton_rh_c->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        label_4->setText(QCoreApplication::translate("Form_conf_speed", "Card revision", nullptr));
        label_2->setText(QCoreApplication::translate("Form_conf_speed", "Floor aproach", nullptr));
        radioButton_rh_sh->setText(QCoreApplication::translate("Form_conf_speed", " RH", nullptr));
        label_fls->setText(QCoreApplication::translate("Form_conf_speed", "Floors", nullptr));
        label_speed->setText(QCoreApplication::translate("Form_conf_speed", "Speed", nullptr));

        const bool __sortingEnabled = listWidget_fls->isSortingEnabled();
        listWidget_fls->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_fls->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Form_conf_speed", "2", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_fls->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Form_conf_speed", "3", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_fls->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Form_conf_speed", "4", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_fls->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("Form_conf_speed", "5", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_fls->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("Form_conf_speed", "6", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_fls->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("Form_conf_speed", "7", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_fls->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("Form_conf_speed", "8", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_fls->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("Form_conf_speed", "9", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_fls->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("Form_conf_speed", "10", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget_fls->item(9);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("Form_conf_speed", "11", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = listWidget_fls->item(10);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("Form_conf_speed", "12", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = listWidget_fls->item(11);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("Form_conf_speed", "13", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = listWidget_fls->item(12);
        ___qlistwidgetitem12->setText(QCoreApplication::translate("Form_conf_speed", "14", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = listWidget_fls->item(13);
        ___qlistwidgetitem13->setText(QCoreApplication::translate("Form_conf_speed", "15", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = listWidget_fls->item(14);
        ___qlistwidgetitem14->setText(QCoreApplication::translate("Form_conf_speed", "16", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = listWidget_fls->item(15);
        ___qlistwidgetitem15->setText(QCoreApplication::translate("Form_conf_speed", "17", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = listWidget_fls->item(16);
        ___qlistwidgetitem16->setText(QCoreApplication::translate("Form_conf_speed", "18", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = listWidget_fls->item(17);
        ___qlistwidgetitem17->setText(QCoreApplication::translate("Form_conf_speed", "19", nullptr));
        QListWidgetItem *___qlistwidgetitem18 = listWidget_fls->item(18);
        ___qlistwidgetitem18->setText(QCoreApplication::translate("Form_conf_speed", "20", nullptr));
        QListWidgetItem *___qlistwidgetitem19 = listWidget_fls->item(19);
        ___qlistwidgetitem19->setText(QCoreApplication::translate("Form_conf_speed", "21", nullptr));
        QListWidgetItem *___qlistwidgetitem20 = listWidget_fls->item(20);
        ___qlistwidgetitem20->setText(QCoreApplication::translate("Form_conf_speed", "22", nullptr));
        QListWidgetItem *___qlistwidgetitem21 = listWidget_fls->item(21);
        ___qlistwidgetitem21->setText(QCoreApplication::translate("Form_conf_speed", "23", nullptr));
        QListWidgetItem *___qlistwidgetitem22 = listWidget_fls->item(22);
        ___qlistwidgetitem22->setText(QCoreApplication::translate("Form_conf_speed", "24", nullptr));
        QListWidgetItem *___qlistwidgetitem23 = listWidget_fls->item(23);
        ___qlistwidgetitem23->setText(QCoreApplication::translate("Form_conf_speed", "25", nullptr));
        QListWidgetItem *___qlistwidgetitem24 = listWidget_fls->item(24);
        ___qlistwidgetitem24->setText(QCoreApplication::translate("Form_conf_speed", "26", nullptr));
        QListWidgetItem *___qlistwidgetitem25 = listWidget_fls->item(25);
        ___qlistwidgetitem25->setText(QCoreApplication::translate("Form_conf_speed", "27", nullptr));
        QListWidgetItem *___qlistwidgetitem26 = listWidget_fls->item(26);
        ___qlistwidgetitem26->setText(QCoreApplication::translate("Form_conf_speed", "28", nullptr));
        QListWidgetItem *___qlistwidgetitem27 = listWidget_fls->item(27);
        ___qlistwidgetitem27->setText(QCoreApplication::translate("Form_conf_speed", "29", nullptr));
        QListWidgetItem *___qlistwidgetitem28 = listWidget_fls->item(28);
        ___qlistwidgetitem28->setText(QCoreApplication::translate("Form_conf_speed", "30", nullptr));
        QListWidgetItem *___qlistwidgetitem29 = listWidget_fls->item(29);
        ___qlistwidgetitem29->setText(QCoreApplication::translate("Form_conf_speed", "31", nullptr));
        QListWidgetItem *___qlistwidgetitem30 = listWidget_fls->item(30);
        ___qlistwidgetitem30->setText(QCoreApplication::translate("Form_conf_speed", "32", nullptr));
        listWidget_fls->setSortingEnabled(__sortingEnabled);

        pushButton_Ok->setText(QCoreApplication::translate("Form_conf_speed", "save", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Form_conf_speed", "cancel", nullptr));
        label_saved->setText(QCoreApplication::translate("Form_conf_speed", "not saved", nullptr));
        label_board->setText(QCoreApplication::translate("Form_conf_speed", "Board", nullptr));

        const bool __sortingEnabled1 = listWidget_board->isSortingEnabled();
        listWidget_board->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem31 = listWidget_board->item(0);
        ___qlistwidgetitem31->setText(QCoreApplication::translate("Form_conf_speed", "HD X ONE", nullptr));
        QListWidgetItem *___qlistwidgetitem32 = listWidget_board->item(1);
        ___qlistwidgetitem32->setText(QCoreApplication::translate("Form_conf_speed", "noname board", nullptr));
        listWidget_board->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class Form_conf_speed: public Ui_Form_conf_speed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORM_CONF_SPEEDROTWBD_H
