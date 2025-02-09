#include "mainwindow.h"
#include "ui_for_rasb_stend.h"
#include "ui_form_help.h"
#include "ui_form_conf_speed.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Создаем экземпляры окон
    //form_conf_speed = new QWidget();
    //form_help = new QWidget();
    form_conf_speed = new QDialog(this);  // Используем QDialog вместо QWidget
    Ui::Form_conf_speed ui_conf_speed;
    ui_conf_speed.setupUi(form_conf_speed);
    // Настраиваем UI для окон
    //Ui::Form_conf_speed ui_conf_speed;
    //ui_conf_speed.setupUi(form_conf_speed);

    form_help = new QWidget();
    Ui::Form_help ui_help;
    ui_help.setupUi(form_help);

    // Загружаем изображения из ресурсов
    QPixmap moveDownImage(":/move_dwn.png");  // Загрузка изображения для label_updw
    ui->label_updw->setPixmap(moveDownImage);
    QPixmap closeDoorImage(":/close_door.png");  // Загрузка изображения для label_opcl
    ui->label_opcl->setPixmap(closeDoorImage);
    ui->label_updw->setScaledContents(true);
    //ui->label_updw->setVisible(true);
    ui->label_opcl->setScaledContents(true);
    // Устанавливаем изображения в соответствующие QLabel
   // Связываем кнопку "Exit" в Form_conf_speed с закрытием окна
    //QObject::connect(ui_conf_speed.pushButton_cancel, &QPushButton::clicked, form_conf_speed, &QWidget::close);
    QObject::connect(ui_conf_speed.pushButton_cancel, &QPushButton::clicked, form_conf_speed, &QDialog::close);
    // Связываем кнопку "Exit" в Form_help с закрытием окна
    QObject::connect(ui_help.pushButton_h_exit, &QPushButton::clicked, form_help, &QWidget::close);
    QObject::connect(ui->pushButton_conf, &QPushButton::clicked, this, &MainWindow::on_pushButton_conf_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete form_conf_speed;
    delete form_help;
}


void MainWindow::on_action_Help_triggered()
{
    //Form_help.show();
    // Открываем окно помощи
    form_help->show();
   // this->hide();
   
    //this->showNormal();


}


void MainWindow::on_actionconfig_triggered()
{
    //Form_conf_speed.show();
    // Открываем окно конфигурации скорости
    form_conf_speed->exec();
    //form_conf_speed->show();
}
void MainWindow::on_pushButton_conf_clicked()
{
    form_conf_speed->exec();
}
