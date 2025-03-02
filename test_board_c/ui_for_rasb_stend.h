/********************************************************************************
** Form generated from reading UI file 'for_rasb_stendmdsaoV.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FOR_RASB_STENDMDSAOV_H
#define FOR_RASB_STENDMDSAOV_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionconfig;
    QAction *actionexit;
    QAction *actionStart;
    QAction *actionStop;
    QAction *action_Help;
    QAction *actionSim_ulator;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_817;
    QRadioButton *radioButton_818;
    QRadioButton *radioButton_rez1;
    QRadioButton *radioButton_ru1;
    QRadioButton *radioButton_ru2;
    QRadioButton *radioButton_krc;
    QRadioButton *radioButton_ml1;
    QRadioButton *radioButton_ml2;
    QRadioButton *radioButton_opcl;
    QRadioButton *radioButton_frn;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_fri;
    QRadioButton *radioButton_120;
    QRadioButton *radioButton_140;
    QRadioButton *radioButton_ppp;
    QRadioButton *radioButton_501;
    QRadioButton *radioButton_light;
    QRadioButton *radioButton_ins;
    QRadioButton *radioButton_ptc;
    QRadioButton *radioButton_130;
    QRadioButton *radioButton_rgk;
    QRadioButton *radioButton_500;
    QLabel *label_speed;
    QLabel *label_alkarm;
    QListView *listView_alarms;
    QFrame *frame_for_mov;
    QLabel *label_move;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_fl1;
    QLabel *label_fl2;
    QLabel *label_fl3;
    QLabel *label_updw;
    QLabel *label_opcl;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_conf;
    QLabel *label_inf;
    QLabel *label_hdx;
    QLabel *label_ligth;
    QLabel *label_speed_mc;
    QCheckBox *checkBox_bus;
    QMenuBar *menubar;
    QMenu *menumenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1065, 784);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 127)"));
        actionconfig = new QAction(MainWindow);
        actionconfig->setObjectName("actionconfig");
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName("actionexit");
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName("actionStart");
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName("actionStop");
        action_Help = new QAction(MainWindow);
        action_Help->setObjectName("action_Help");
        actionSim_ulator = new QAction(MainWindow);
        actionSim_ulator->setObjectName("actionSim_ulator");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(-1, 120, 161, 461));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gridLayoutWidget->sizePolicy().hasHeightForWidth());
        gridLayoutWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        gridLayoutWidget->setFont(font);
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_817 = new QRadioButton(gridLayoutWidget);
        radioButton_817->setObjectName("radioButton_817");
        sizePolicy.setHeightForWidth(radioButton_817->sizePolicy().hasHeightForWidth());
        radioButton_817->setSizePolicy(sizePolicy);
        radioButton_817->setFont(font);
        radioButton_817->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_817, 14, 0, 1, 1);

        radioButton_818 = new QRadioButton(gridLayoutWidget);
        radioButton_818->setObjectName("radioButton_818");
        sizePolicy.setHeightForWidth(radioButton_818->sizePolicy().hasHeightForWidth());
        radioButton_818->setSizePolicy(sizePolicy);
        radioButton_818->setFont(font);
        radioButton_818->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_818, 15, 0, 1, 1);

        radioButton_rez1 = new QRadioButton(gridLayoutWidget);
        radioButton_rez1->setObjectName("radioButton_rez1");
        sizePolicy.setHeightForWidth(radioButton_rez1->sizePolicy().hasHeightForWidth());
        radioButton_rez1->setSizePolicy(sizePolicy);
        radioButton_rez1->setFont(font);
        radioButton_rez1->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_rez1, 16, 0, 1, 1);

        radioButton_ru1 = new QRadioButton(gridLayoutWidget);
        radioButton_ru1->setObjectName("radioButton_ru1");
        sizePolicy.setHeightForWidth(radioButton_ru1->sizePolicy().hasHeightForWidth());
        radioButton_ru1->setSizePolicy(sizePolicy);
        radioButton_ru1->setFont(font);
        radioButton_ru1->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ru1, 5, 0, 1, 1);

        radioButton_ru2 = new QRadioButton(gridLayoutWidget);
        radioButton_ru2->setObjectName("radioButton_ru2");
        sizePolicy.setHeightForWidth(radioButton_ru2->sizePolicy().hasHeightForWidth());
        radioButton_ru2->setSizePolicy(sizePolicy);
        radioButton_ru2->setFont(font);
        radioButton_ru2->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ru2, 8, 0, 1, 1);

        radioButton_krc = new QRadioButton(gridLayoutWidget);
        radioButton_krc->setObjectName("radioButton_krc");
        sizePolicy.setHeightForWidth(radioButton_krc->sizePolicy().hasHeightForWidth());
        radioButton_krc->setSizePolicy(sizePolicy);
        radioButton_krc->setFont(font);
        radioButton_krc->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_krc, 10, 0, 1, 1);

        radioButton_ml1 = new QRadioButton(gridLayoutWidget);
        radioButton_ml1->setObjectName("radioButton_ml1");
        sizePolicy.setHeightForWidth(radioButton_ml1->sizePolicy().hasHeightForWidth());
        radioButton_ml1->setSizePolicy(sizePolicy);
        radioButton_ml1->setFont(font);
        radioButton_ml1->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ml1, 12, 0, 1, 1);

        radioButton_ml2 = new QRadioButton(gridLayoutWidget);
        radioButton_ml2->setObjectName("radioButton_ml2");
        sizePolicy.setHeightForWidth(radioButton_ml2->sizePolicy().hasHeightForWidth());
        radioButton_ml2->setSizePolicy(sizePolicy);
        radioButton_ml2->setFont(font);
        radioButton_ml2->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_ml2, 13, 0, 1, 1);

        radioButton_opcl = new QRadioButton(gridLayoutWidget);
        radioButton_opcl->setObjectName("radioButton_opcl");
        sizePolicy.setHeightForWidth(radioButton_opcl->sizePolicy().hasHeightForWidth());
        radioButton_opcl->setSizePolicy(sizePolicy);
        radioButton_opcl->setFont(font);
        radioButton_opcl->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_opcl, 11, 0, 1, 1);

        radioButton_frn = new QRadioButton(gridLayoutWidget);
        radioButton_frn->setObjectName("radioButton_frn");
        sizePolicy.setHeightForWidth(radioButton_frn->sizePolicy().hasHeightForWidth());
        radioButton_frn->setSizePolicy(sizePolicy);
        radioButton_frn->setFont(font);
        radioButton_frn->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_frn, 4, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(160, 110, 161, 521));
        sizePolicy.setHeightForWidth(gridLayoutWidget_2->sizePolicy().hasHeightForWidth());
        gridLayoutWidget_2->setSizePolicy(sizePolicy);
        gridLayoutWidget_2->setFont(font);
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_fri = new QRadioButton(gridLayoutWidget_2);
        radioButton_fri->setObjectName("radioButton_fri");
        sizePolicy.setHeightForWidth(radioButton_fri->sizePolicy().hasHeightForWidth());
        radioButton_fri->setSizePolicy(sizePolicy);
        radioButton_fri->setFont(font);
        radioButton_fri->setAutoExclusive(false);

        gridLayout_2->addWidget(radioButton_fri, 11, 0, 1, 1);

        radioButton_120 = new QRadioButton(gridLayoutWidget_2);
        radioButton_120->setObjectName("radioButton_120");
        sizePolicy.setHeightForWidth(radioButton_120->sizePolicy().hasHeightForWidth());
        radioButton_120->setSizePolicy(sizePolicy);
        radioButton_120->setFont(font);
        radioButton_120->setAutoExclusive(false);

        gridLayout_2->addWidget(radioButton_120, 16, 0, 1, 1);

        radioButton_140 = new QRadioButton(gridLayoutWidget_2);
        radioButton_140->setObjectName("radioButton_140");
        sizePolicy.setHeightForWidth(radioButton_140->sizePolicy().hasHeightForWidth());
        radioButton_140->setSizePolicy(sizePolicy);
        radioButton_140->setFont(font);
        radioButton_140->setAutoExclusive(false);

        gridLayout_2->addWidget(radioButton_140, 18, 0, 1, 1);

        radioButton_ppp = new QRadioButton(gridLayoutWidget_2);
        radioButton_ppp->setObjectName("radioButton_ppp");
        sizePolicy.setHeightForWidth(radioButton_ppp->sizePolicy().hasHeightForWidth());
        radioButton_ppp->setSizePolicy(sizePolicy);
        radioButton_ppp->setFont(font);
        radioButton_ppp->setAutoExclusive(false);

        gridLayout_2->addWidget(radioButton_ppp, 12, 0, 1, 1);

        radioButton_501 = new QRadioButton(gridLayoutWidget_2);
        radioButton_501->setObjectName("radioButton_501");
        sizePolicy.setHeightForWidth(radioButton_501->sizePolicy().hasHeightForWidth());
        radioButton_501->setSizePolicy(sizePolicy);
        radioButton_501->setFont(font);
        radioButton_501->setAutoExclusive(false);

        gridLayout_2->addWidget(radioButton_501, 4, 0, 1, 1);

        radioButton_light = new QRadioButton(gridLayoutWidget_2);
        radioButton_light->setObjectName("radioButton_light");
        sizePolicy.setHeightForWidth(radioButton_light->sizePolicy().hasHeightForWidth());
        radioButton_light->setSizePolicy(sizePolicy);
        radioButton_light->setFont(font);
        radioButton_light->setAutoExclusive(false);

        gridLayout_2->addWidget(radioButton_light, 15, 0, 1, 1);

        radioButton_ins = new QRadioButton(gridLayoutWidget_2);
        radioButton_ins->setObjectName("radioButton_ins");
        sizePolicy.setHeightForWidth(radioButton_ins->sizePolicy().hasHeightForWidth());
        radioButton_ins->setSizePolicy(sizePolicy);
        radioButton_ins->setFont(font);
        radioButton_ins->setAutoExclusive(false);

        gridLayout_2->addWidget(radioButton_ins, 2, 0, 1, 1);

        radioButton_ptc = new QRadioButton(gridLayoutWidget_2);
        radioButton_ptc->setObjectName("radioButton_ptc");
        sizePolicy.setHeightForWidth(radioButton_ptc->sizePolicy().hasHeightForWidth());
        radioButton_ptc->setSizePolicy(sizePolicy);
        radioButton_ptc->setFont(font);
        radioButton_ptc->setAutoExclusive(false);

        gridLayout_2->addWidget(radioButton_ptc, 14, 0, 1, 1);

        radioButton_130 = new QRadioButton(gridLayoutWidget_2);
        radioButton_130->setObjectName("radioButton_130");
        sizePolicy.setHeightForWidth(radioButton_130->sizePolicy().hasHeightForWidth());
        radioButton_130->setSizePolicy(sizePolicy);
        radioButton_130->setFont(font);
        radioButton_130->setAutoExclusive(false);

        gridLayout_2->addWidget(radioButton_130, 17, 0, 1, 1);

        radioButton_rgk = new QRadioButton(gridLayoutWidget_2);
        radioButton_rgk->setObjectName("radioButton_rgk");
        sizePolicy.setHeightForWidth(radioButton_rgk->sizePolicy().hasHeightForWidth());
        radioButton_rgk->setSizePolicy(sizePolicy);
        radioButton_rgk->setFont(font);
        radioButton_rgk->setAutoExclusive(false);

        gridLayout_2->addWidget(radioButton_rgk, 13, 0, 1, 1);

        radioButton_500 = new QRadioButton(gridLayoutWidget_2);
        radioButton_500->setObjectName("radioButton_500");
        sizePolicy.setHeightForWidth(radioButton_500->sizePolicy().hasHeightForWidth());
        radioButton_500->setSizePolicy(sizePolicy);
        radioButton_500->setFont(font);
        radioButton_500->setAutoExclusive(false);

        gridLayout_2->addWidget(radioButton_500, 5, 0, 1, 1);

        label_speed = new QLabel(centralwidget);
        label_speed->setObjectName("label_speed");
        label_speed->setGeometry(QRect(310, -10, 461, 41));
        sizePolicy.setHeightForWidth(label_speed->sizePolicy().hasHeightForWidth());
        label_speed->setSizePolicy(sizePolicy);
        label_speed->setFont(font);
        label_alkarm = new QLabel(centralwidget);
        label_alkarm->setObjectName("label_alkarm");
        label_alkarm->setGeometry(QRect(350, 100, 131, 61));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(true);
        label_alkarm->setFont(font1);
        listView_alarms = new QListView(centralwidget);
        listView_alarms->setObjectName("listView_alarms");
        listView_alarms->setGeometry(QRect(330, 170, 451, 311));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView_alarms->sizePolicy().hasHeightForWidth());
        listView_alarms->setSizePolicy(sizePolicy1);
        listView_alarms->setFont(font);
        listView_alarms->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 127)"));
        listView_alarms->setMovement(QListView::Free);
        listView_alarms->setResizeMode(QListView::Fixed);
        listView_alarms->setModelColumn(0);
        listView_alarms->setUniformItemSizes(true);
        listView_alarms->setItemAlignment(Qt::AlignLeading);
        frame_for_mov = new QFrame(centralwidget);
        frame_for_mov->setObjectName("frame_for_mov");
        frame_for_mov->setGeometry(QRect(790, 0, 256, 480));
        frame_for_mov->setStyleSheet(QString::fromUtf8("background:rgb(255, 170, 127)"));
        frame_for_mov->setFrameShape(QFrame::StyledPanel);
        frame_for_mov->setFrameShadow(QFrame::Raised);
        label_move = new QLabel(frame_for_mov);
        label_move->setObjectName("label_move");
        label_move->setGeometry(QRect(100, 208, 64, 64));
        label_move->setPixmap(QPixmap(QString::fromUtf8("../PycharmProjects/py_rasp_test_stend/lift_cab_64.png")));
        line = new QFrame(frame_for_mov);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 450, 61, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(frame_for_mov);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(10, 260, 61, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(frame_for_mov);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(10, 70, 61, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_fl1 = new QLabel(frame_for_mov);
        label_fl1->setObjectName("label_fl1");
        label_fl1->setGeometry(QRect(10, 430, 58, 16));
        label_fl2 = new QLabel(frame_for_mov);
        label_fl2->setObjectName("label_fl2");
        label_fl2->setGeometry(QRect(10, 240, 58, 16));
        label_fl3 = new QLabel(frame_for_mov);
        label_fl3->setObjectName("label_fl3");
        label_fl3->setGeometry(QRect(10, 50, 58, 16));
        label_updw = new QLabel(centralwidget);
        label_updw->setObjectName("label_updw");
        label_updw->setGeometry(QRect(670, 490, 128, 128));
        label_opcl = new QLabel(centralwidget);
        label_opcl->setObjectName("label_opcl");
        label_opcl->setGeometry(QRect(830, 490, 128, 128));
        pushButton_start = new QPushButton(centralwidget);
        pushButton_start->setObjectName("pushButton_start");
        pushButton_start->setGeometry(QRect(40, 670, 90, 28));
        pushButton_start->setCheckable(true);
        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName("pushButton_stop");
        pushButton_stop->setGeometry(QRect(160, 670, 90, 28));
        pushButton_stop->setCheckable(true);
        pushButton_exit = new QPushButton(centralwidget);
        pushButton_exit->setObjectName("pushButton_exit");
        pushButton_exit->setGeometry(QRect(860, 660, 90, 28));
        pushButton_conf = new QPushButton(centralwidget);
        pushButton_conf->setObjectName("pushButton_conf");
        pushButton_conf->setGeometry(QRect(290, 670, 90, 28));
        label_inf = new QLabel(centralwidget);
        label_inf->setObjectName("label_inf");
        label_inf->setGeometry(QRect(550, 40, 221, 61));
        sizePolicy.setHeightForWidth(label_inf->sizePolicy().hasHeightForWidth());
        label_inf->setSizePolicy(sizePolicy);
        label_inf->setFont(font);
        label_hdx = new QLabel(centralwidget);
        label_hdx->setObjectName("label_hdx");
        label_hdx->setGeometry(QRect(10, 30, 201, 31));
        label_hdx->setFont(font1);
        label_ligth = new QLabel(centralwidget);
        label_ligth->setObjectName("label_ligth");
        label_ligth->setGeometry(QRect(520, 490, 128, 128));
        label_speed_mc = new QLabel(centralwidget);
        label_speed_mc->setObjectName("label_speed_mc");
        label_speed_mc->setGeometry(QRect(310, 50, 101, 31));
        sizePolicy.setHeightForWidth(label_speed_mc->sizePolicy().hasHeightForWidth());
        label_speed_mc->setSizePolicy(sizePolicy);
        label_speed_mc->setFont(font);
        checkBox_bus = new QCheckBox(centralwidget);
        checkBox_bus->setObjectName("checkBox_bus");
        checkBox_bus->setGeometry(QRect(20, 70, 171, 27));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1065, 29));
        menumenu = new QMenu(menubar);
        menumenu->setObjectName("menumenu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menumenu->menuAction());
        menumenu->addAction(action_Help);
        menumenu->addAction(actionconfig);
        menumenu->addAction(actionStart);
        menumenu->addAction(actionStop);
        menumenu->addAction(actionSim_ulator);
        menumenu->addAction(actionexit);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_exit, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionconfig->setText(QCoreApplication::translate("MainWindow", "&Config", nullptr));
        actionexit->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
        actionStart->setText(QCoreApplication::translate("MainWindow", "&Start", nullptr));
        actionStop->setText(QCoreApplication::translate("MainWindow", "S&top", nullptr));
        action_Help->setText(QCoreApplication::translate("MainWindow", "&Help", nullptr));
        actionSim_ulator->setText(QCoreApplication::translate("MainWindow", "Sim&ulator", nullptr));
        radioButton_817->setText(QCoreApplication::translate("MainWindow", " 817", nullptr));
        radioButton_818->setText(QCoreApplication::translate("MainWindow", " 818", nullptr));
        radioButton_rez1->setText(QCoreApplication::translate("MainWindow", " rez1", nullptr));
        radioButton_ru1->setText(QCoreApplication::translate("MainWindow", " RU1", nullptr));
        radioButton_ru2->setText(QCoreApplication::translate("MainWindow", " RU2", nullptr));
        radioButton_krc->setText(QCoreApplication::translate("MainWindow", " KRC", nullptr));
        radioButton_ml1->setText(QCoreApplication::translate("MainWindow", " ML1", nullptr));
        radioButton_ml2->setText(QCoreApplication::translate("MainWindow", " ML2", nullptr));
        radioButton_opcl->setText(QCoreApplication::translate("MainWindow", " OP /CL", nullptr));
        radioButton_frn->setText(QCoreApplication::translate("MainWindow", " FRN", nullptr));
        radioButton_fri->setText(QCoreApplication::translate("MainWindow", " FRI", nullptr));
        radioButton_120->setText(QCoreApplication::translate("MainWindow", " 120", nullptr));
        radioButton_140->setText(QCoreApplication::translate("MainWindow", " 140", nullptr));
        radioButton_ppp->setText(QCoreApplication::translate("MainWindow", " Key fr", nullptr));
        radioButton_501->setText(QCoreApplication::translate("MainWindow", " 501", nullptr));
        radioButton_light->setText(QCoreApplication::translate("MainWindow", " Light", nullptr));
        radioButton_ins->setText(QCoreApplication::translate("MainWindow", " INS", nullptr));
        radioButton_ptc->setText(QCoreApplication::translate("MainWindow", " PTC", nullptr));
        radioButton_130->setText(QCoreApplication::translate("MainWindow", " 130", nullptr));
        radioButton_rgk->setText(QCoreApplication::translate("MainWindow", " RGK", nullptr));
        radioButton_500->setText(QCoreApplication::translate("MainWindow", " 500", nullptr));
        label_speed->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        label_alkarm->setText(QCoreApplication::translate("MainWindow", "Alarms", nullptr));
        label_move->setText(QString());
        label_fl1->setText(QCoreApplication::translate("MainWindow", "Floor 1", nullptr));
        label_fl2->setText(QCoreApplication::translate("MainWindow", "Floor 2", nullptr));
        label_fl3->setText(QCoreApplication::translate("MainWindow", "Floor 3", nullptr));
        label_updw->setText(QCoreApplication::translate("MainWindow", "UP / Down", nullptr));
        label_opcl->setText(QCoreApplication::translate("MainWindow", "Open / Close", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "&Start", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "S&top", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
        pushButton_conf->setText(QCoreApplication::translate("MainWindow", "&Configure", nullptr));
        label_inf->setText(QString());
        label_hdx->setText(QCoreApplication::translate("MainWindow", "Hedefsan HD X one", nullptr));
        label_ligth->setText(QCoreApplication::translate("MainWindow", "ligth", nullptr));
        label_speed_mc->setText(QCoreApplication::translate("MainWindow", "\320\274/\321\201", nullptr));
        checkBox_bus->setText(QCoreApplication::translate("MainWindow", "View bus messages", nullptr));
        menumenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FOR_RASB_STENDMDSAOV_H
