/*
#include "mainwindow.h"
#include "ui_for_rasb_stend.h"
#include "ui_form_help.h"
#include <QPixmap>
#include <QPropertyAnimation>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QGraphicsOpacityEffect>
//#include <wiringPi.h>
//#include <wiringPiI2C.h>
#include <QTimer>
//#include <QModbus>
//#include <libmodbus.h>
//#include <QModbusRtuSerialMaster>
#include <QModbusDataUnit>
#include <QModbusReply>
#include <QVariant>
#include <QSerialPort>



//const int PULSES_PER_REVOLUTION = 2048;
//const double PULLEY_DIAMETER_1 = 320.0;
//const double PULLEY_DIAMETER_2 = 200.0;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , form_conf_speed(new QDialog(this))  // Создаём QDialog для формы
    , ui_conf_speed(new Ui::Form_conf_speed())  // Создаём объект UI
    , form_help(new QWidget())  // Инициализируем форму помощи
    , animation(new QPropertyAnimation(this))
    , isMoving(false)
    , messageWindow(new MessageWindow(this))
    , isMessageWindowVisible(false)

{
    ui->setupUi(this);
    // Инициализация таймера
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateSpeed);
    // Связываем кнопку для включения/выключения окна сообщений
    connect(ui->checkBox_bus, &QPushButton::toggled, this, &MainWindow::toggleMessageWindow);
    // Инициализация значений по умолчанию
    gearRatio = 2;               // Первая строка в listWidget_ratio
    PULLEY_DIAMETER = 320.0;     // Первая строка в listWidget_shave
    PULSES_PER_REVOLUTION = 2048; // Первая строка в listWidget_enc

    // Подключаем сигнал от формы конфигурации updateSettings
    //connect(form_conf_speed, &ui_conf_speed::pushButton_Ok, this, &MainWindow::updateSettings);
    //connect(ui_conf_speed->pushButton_Ok, &QPushButton::clicked, this, &MainWindow::on_pushButton_Ok_clicked);
    // Таймер для чтения данных с шины
    //QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::readDataFromBus);
    //timer->start(1000);  // Чтение данных каждую секунду

    timer->start(1000);  // Обновление каждую секунду

    // Настраиваем UI для формы конфигурации скорости

    // Заполняем listWidget_ratio
    QListWidgetItem *item1 = new QListWidgetItem("1 : 2");
    item1->setData(Qt::UserRole, 2);
    ui_conf_speed->listWidget_ratio->addItem(item1);

    QListWidgetItem *item2 = new QListWidgetItem("1 : 1");
    item2->setData(Qt::UserRole, 1);
    ui_conf_speed->listWidget_ratio->addItem(item2);

    // Устанавливаем первую строку как выбранную
    ui_conf_speed->listWidget_ratio->setCurrentRow(0);

     // listWidget_shave
    QListWidgetItem *item3 = new QListWidgetItem(" 320 мм");
    item3->setData(Qt::UserRole, 320.0);
    ui_conf_speed->listWidget_shave->addItem(item3);

    QListWidgetItem *item4 = new QListWidgetItem(" 200 мм");
    item4->setData(Qt::UserRole, 200.0);
    ui_conf_speed->listWidget_shave->addItem(item4);

    ui_conf_speed->listWidget_shave->setCurrentRow(0);

    // listWidget_enc
    QListWidgetItem *item5 = new QListWidgetItem("Pulses 2048");
    item5->setData(Qt::UserRole, 2048);
    ui_conf_speed->listWidget_enc->addItem(item5);

    QListWidgetItem *item6 = new QListWidgetItem("Pulses 1024");
    item6->setData(Qt::UserRole, 1024);
    ui_conf_speed->listWidget_enc->addItem(item6);

    QListWidgetItem *item7 = new QListWidgetItem("Pulses 500");
    item7->setData(Qt::UserRole, 500);
    ui_conf_speed->listWidget_enc->addItem(item7);

    ui_conf_speed->listWidget_enc->setCurrentRow(0);

    ui_conf_speed->setupUi(form_conf_speed);

    // Подключаем сигналы и слоты для кнопок формы
    connect(ui_conf_speed->pushButton_Ok, &QPushButton::clicked, this, &MainWindow::on_pushButton_Ok_clicked);
    connect(ui_conf_speed->pushButton_cancel, &QPushButton::clicked, this, &MainWindow::on_pushButton_cancel_clicked);

    // Инициализация формы помощи
    Ui::Form_help ui_help;
    ui_help.setupUi(form_help);

    readSettings();

    // Загружаем изображения из ресурсов
    //ui->label_updw->setPixmap(QPixmap(":/pic/move_dwn.png"));
    QPixmap moveDownImage(":/pic/move_dwn.png");
    if (moveDownImage.isNull()) {
        qDebug() << "Ошибка: Не удалось загрузить move_dwn.png!";
    } else {
        qDebug() << "Изображение move_dwn.png успешно загружено!";
        ui->label_updw->setPixmap(moveDownImage);
        ui->label_updw->setScaledContents(true);
    }
    QPixmap closeDoorImage(":/pic/close_door.png");
    ui->label_opcl->setPixmap(closeDoorImage);
    ui->label_updw->setScaledContents(true);
    ui->label_opcl->setScaledContents(true);

    // Настройка анимации
    ui->label_move->setPixmap(QPixmap(":/pic/lift_cab_128.png"));
    ui->label_move->setScaledContents(true);
    ui->label_move->raise();
    animation->setTargetObject(ui->label_move);
    animation->setPropertyName("pos");
    animation->setDuration(3000);
    animation->setLoopCount(-1);

    // Связываем завершение анимации с слотом
    connect(animation, &QPropertyAnimation::finished, this, &MainWindow::on_animation_finished);

    // Связываем кнопки с слотами
    connect(ui->pushButton_start, &QPushButton::clicked, this, &MainWindow::on_pushButton_start_clicked);
    connect(ui->pushButton_stop, &QPushButton::clicked, this, &MainWindow::on_pushButton_stop_clicked);
    connect(ui->radioButton_opcl, &QPushButton::clicked, this, &MainWindow::on_radioButton_opcl_clicked);
    connect(ui->radioButton_500, &QPushButton::clicked, this, &MainWindow::on_radioButton_500_clicked);
    connect(ui->radioButton_501, &QPushButton::clicked, this, &MainWindow::on_radioButton_501_clicked);
    connect(ui->radioButton_light, &QPushButton::clicked, this, &MainWindow::on_radioButton_light_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete form_conf_speed;
    delete ui_conf_speed;
    delete form_help;
    delete animation;
}


void MainWindow::on_action_Help_triggered()
{
    form_help->show();
}
void MainWindow::toggleMessageWindow(bool checked) {
    if (checked) {
        messageWindow->show();  // Показать окно
        isMessageWindowVisible = true;
    } else {
        messageWindow->hide();  // Скрыть окно
        isMessageWindowVisible = false;
    }
}

void MainWindow::readDataFromBus() {
    // Здесь будет код для чтения данных с CAN или ModBus
    // Пример:
    QString message = "Пример сообщения с шины";
    if (isMessageWindowVisible) {
        messageWindow->appendMessage(message);  // Вывод сообщения в окно
    }
}

    /*

    void MainWindow::readDataFromBus() {

    QModbusRtuSerialMaster *modbusDevice = new QModbusRtuSerialMaster(this);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter, "/dev/ttyUSB0");
    modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, QSerialPort::Baud9600);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter, QSerialPort::NoParity);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, QSerialPort::OneStop);

    if (!modbusDevice->connectDevice()) {
        qDebug() << "Ошибка подключения к ModBus устройству!";
        return;
    }

    // Чтение данных
    QModbusDataUnit request(QModbusDataUnit::InputRegisters, 0, 10);  // Чтение 10 регистров
    if (auto *reply = modbusDevice->sendReadRequest(request, 1)) {
        if (!reply->isFinished()) {
            connect(reply, &QModbusReply::finished, this, [this, reply]() {
                if (reply->error() == QModbusDevice::NoError) {
                    const QModbusDataUnit unit = reply->result();
                    QString message = "Данные: ";
                    for (uint i = 0; i < unit.valueCount(); ++i) {
                        message += QString::number(unit.value(i)) + " ";
                    }
                    if (isMessageWindowVisible) {
                        messageWindow->appendMessage(message);  // Вывод сообщения в окно
                    }
                } else {
                    qDebug() << "Ошибка чтения данных: " << reply->errorString();
                }
                reply->deleteLater();
            });
        } else {
            delete reply;
        }
    } else {
        qDebug() << "Ошибка отправки запроса!";
    }
}
*/
/*
void MainWindow::on_radioButton_opcl_clicked()
{
    if (ui->radioButton_opcl->isChecked()) {
        ui->label_opcl->setPixmap(QPixmap(":/pic/close_door.png"));
    } else {
        ui->label_opcl->setPixmap(QPixmap(":/pic/open_door.png"));
    }
    repaint();
}

void MainWindow::updateSpeed() {
    //int fd = initI2C();
    int fd =20;
    if (fd == -1) return;

    //int pulsesPerSecond = readI2CData(fd);
    int pulsesPerSecond = 500;
    //double pulleyDiameter = 320;
    //int gearRatio = 2;
   //updateSettings;
   // double speed = calculateLiftSpeed(pulsesPerSecond, PULSES_PER_REVOLUTION, PULLEY_DIAMETER, gearRatio);
    double speed = calculateLiftSpeed(pulsesPerSecond);
    ui->label_speed_mc->setText(QString::number(speed, 'f', 2) + " м/с");
}


void MainWindow::updateSettings(int gearRatio, double PULLEY_DIAMETER, int PULSES_PER_REVOLUTION) {
    // Обновляем переменные
    this->gearRatio = gearRatio;
    this->PULLEY_DIAMETER = PULLEY_DIAMETER;
    this->PULSES_PER_REVOLUTION = PULSES_PER_REVOLUTION;

    // Выводим отладочную информацию
    qDebug() << "Настройки обновлены:";
    qDebug() << "Gear Ratio:" << gearRatio;
    qDebug() << "Pulley Diameter:" << PULLEY_DIAMETER;
    qDebug() << "Pulses per Revolution:" << PULSES_PER_REVOLUTION;
}
//void MainWindow::calculateSpeed() {
    // Пример формулы для вычисления скорости
   // double speed = (someValue * gearRatio * PULLEY_DIAMETER) / PULSES_PER_REVOLUTION;

    // Отображаем скорость в интерфейсе
  //  ui->label_speed->setText(QString::number(speed, 'f', 2));
//}

 //speed
//double calculateLiftSpeed(int pulsesPerSecond, int PULSES_PER_REVOLUTION, double pulleyDiameter, int gearRatio) {
double MainWindow::calculateLiftSpeed(int pulsesPerSecond)
{
double pulleyDiameterMeters = PULLEY_DIAMETER / 1000.0;
    double circumference = M_PI * pulleyDiameterMeters;
    double speed = (circumference * pulsesPerSecond) / (PULSES_PER_REVOLUTION * gearRatio);
    speed = round(speed * 100) / 100;
   // ui_conf_speed->label_speed->setText(QString::number(speed, 'f', 2));
    return speed;
}
*/
/*
// Инициализация I2C
int initI2C() {
    int fd = wiringPiI2CSetup(PCF8574_ADDRESS);
    if (fd == -1) {
        qDebug() << "Ошибка инициализации I2C!";
    }
    return fd;
}

// Чтение данных с PCF8574
int readI2CData(int fd) {
    return wiringPiI2CRead(fd);
}
*/
// Обновление скорости
/*

void MainWindow::on_actionconfig_triggered()
{
    form_conf_speed->exec();
}

void MainWindow::on_pushButton_conf_clicked()
{
    form_conf_speed->exec();
}

void MainWindow::on_pushButton_start_clicked()
{
    if (isMoving) return;
    ui->pushButton_stop->setChecked(false);

    bool is501Selected = ui->radioButton_501->isChecked();
    bool is500Selected = ui->radioButton_500->isChecked();

    if (is501Selected && is500Selected) { qDebug() << "Ошибка: Выбраны обе радиокнопки!"; return;}
    if (!is501Selected && !is500Selected) return;

    if (is501Selected) {
        ui->label_updw->setPixmap(QPixmap(":/pic/move_up.png"));
        qDebug() << "Выбрана радиокнопка 501: Движение вверх";
        animation->setStartValue(QPoint(100, 400));
        animation->setEndValue(QPoint(100, 10));
    } else if (is500Selected) {
        ui->label_updw->setPixmap(QPixmap(":/pic/move_dwn.png"));
        qDebug() << "Выбрана радиокнопка 500: Движение вниз";
        animation->setStartValue(QPoint(100, 10));
        animation->setEndValue(QPoint(100, 400));
    }

    animation->start();
    isMoving = true;
}

void MainWindow::on_pushButton_stop_clicked()
{
    animation->stop();
    isMoving = false;  // Сбрасываем флаг движения

    // Перемещаем картинку на уровень Floor2
    ui->label_move->move(QPoint(100, 200));

    // Сбрасываем состояние кнопки Start
    ui->pushButton_start->setChecked(false);
    // Плавное возвращение кнопки Stop в ненажатое состояние
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(ui->pushButton_stop);
    ui->pushButton_stop->setGraphicsEffect(opacityEffect);

    QPropertyAnimation *buttonAnimation = new QPropertyAnimation(opacityEffect, "opacity");
    buttonAnimation->setDuration(3000);  // Длительность анимации (500 мс)
    buttonAnimation->setStartValue(0.1); // Начальная прозрачность (полупрозрачная)
    buttonAnimation->setEndValue(1.0);   // Конечная прозрачность (полностью непрозрачная)
    buttonAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    // Возвращаем кнопку в ненажатое состояние
    ui->pushButton_stop->setChecked(false);
}

void MainWindow::on_animation_finished()
{
    if (isMoving) {
        animation->start();
    }
}

void MainWindow::on_radioButton_500_clicked()
{
    if (!ui->radioButton_501->isChecked())
        ui->label_updw->setPixmap(QPixmap(":/pic/move_dwn.png"));
}

void MainWindow::on_radioButton_501_clicked()
{
    if (!ui->radioButton_500->isChecked())
        ui->label_updw->setPixmap(QPixmap(":/pic/move_up.png"));
}

void MainWindow::on_pushButton_Ok_clicked()
{
     qDebug() << "Кнопка 'ОК' нажата!";
    writeSettings();
     if (ui_conf_speed->label_saved) {
        qDebug() << "label_saved существует, устанавливаем текст...";
        ui_conf_speed->label_saved->setText("Saved");
        ui_conf_speed->label_saved->setVisible(true);  // Убедимся, что виджет видим
        ui_conf_speed->label_saved->repaint();        // Принудительное обновление виджета
        ui_conf_speed->label_saved->update();  // Принудительное обновление виджета
     } else {
        qDebug() << "Ошибка: label_saved не существует!";
     }
 */
     /*

     // Получаем выбранные значения
     QListWidgetItem *selectedRatioItem = ui_conf_speed->listWidget_ratio->currentItem();
     int gearRatio = selectedRatioItem->data(Qt::UserRole).toInt();

     QListWidgetItem *selectedPulleyItem = ui_conf_speed->listWidget_shave->currentItem();
     double PULLEY_DIAMETER = selectedPulleyItem->data(Qt::UserRole).toDouble();

     QListWidgetItem *selectedPulsesItem = ui_conf_speed->listWidget_enc->currentItem();
     int PULSES_PER_REVOLUTION = selectedPulsesItem->data(Qt::UserRole).toInt();
*/
     // Отправляем сигнал с выбранными значениями
      //updateSettings(gearRatio, PULLEY_DIAMETER, PULSES_PER_REVOLUTION);
//emit
    //form_conf_speed->close();
/*
  }

void MainWindow::on_radioButton_light_clicked()
{
    if (ui->radioButton_light->isChecked())
        ui->label_ligth->setPixmap(QPixmap(":/pic/lift_cab_512_ligh2.png"));
    else
        ui->label_ligth->setPixmap(QPixmap(":/pic/lift_cab_512.png"));
ui->label_ligth->setScaledContents(true);
}

void MainWindow::on_pushButton_cancel_clicked()
{
    form_conf_speed->close();
}

void MainWindow::readSettings()
{
    QFile file("D:/alexey/QT/new_test_board_v2/speed_settings.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        writeSettings();
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("=");
        if (parts.size() == 2) {
            QString key = parts[0].trimmed();
            bool value = (parts[1].trimmed() == "1");

            // Устанавливаем состояния радиокнопок

             //levelling speed
            if (key == "rh_l") ui_conf_speed->radioButton_rh_l->setChecked(value);
            if (key == "rf_l") ui_conf_speed->radioButton_rf_l->setChecked(value);
            if (key == "ry_l") ui_conf_speed->radioButton_ry_l->setChecked(value);
            //floar aproach speed
            if (key == "rh_f") ui_conf_speed->radioButton_rh_f->setChecked(value);
            if (key == "rf_f") ui_conf_speed->radioButton_rf_f->setChecked(value);
            if (key == "ry_f") ui_conf_speed->radioButton_ry_f->setChecked(value);
            //retern speed
            if (key == "rh_ret") ui_conf_speed->radioButton_rh_ret->setChecked(value);
            if (key == "rf_ret") ui_conf_speed->radioButton_rf_ret->setChecked(value);
            if (key == "ry_ret") ui_conf_speed->radioButton_ry_ret->setChecked(value);
            //card insp speed
            if (key == "rh_c") ui_conf_speed->radioButton_rh_c->setChecked(value);
            if (key == "rf_c") ui_conf_speed->radioButton_rf_c->setChecked(value);
            if (key == "ry_c") ui_conf_speed->radioButton_ry_c->setChecked(value);
            //inspection shaft speed
            if (key == "rh_sh") ui_conf_speed->radioButton_rh_sh->setChecked(value);
            if (key == "rf_sh") ui_conf_speed->radioButton_rf_sh->setChecked(value);
            if (key == "ry_sh") ui_conf_speed->radioButton_ry_sh->setChecked(value);
            //normal speed
            if (key == "rh_n") ui_conf_speed->radioButton_rh_n->setChecked(value);
            if (key == "rf_n") ui_conf_speed->radioButton_rf_n->setChecked(value);
            if (key == "ry_n") ui_conf_speed->radioButton_ry_n->setChecked(value);
            // high speed
            if (key == "rh_h") ui_conf_speed->radioButton_rh_h->setChecked(value);
            if (key == "rf_h") ui_conf_speed->radioButton_rf_h->setChecked(value);
            if (key == "ry_h") ui_conf_speed->radioButton_ry_h->setChecked(value);
            // max speed
            if (key == "rh_m") ui_conf_speed->radioButton_rh_m->setChecked(value);
            if (key == "rf_m") ui_conf_speed->radioButton_rf_m->setChecked(value);
            if (key == "ry_m") ui_conf_speed->radioButton_ry_m->setChecked(value);
            //reading shaft
            if (key == "rh_read") ui_conf_speed->radioButton_rh_read->setChecked(value);
            if (key == "rf_read") ui_conf_speed->radioButton_rf_read->setChecked(value);
            if (key == "ry_read") ui_conf_speed->radioButton_ry_read->setChecked(value);
        }
    }

    file.close();
}

void MainWindow::writeSettings()
{
    QFile file("D:/alexey/QT/new_test_board_v2/speed_settings.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить настройки!");
        return;
    }

    QTextStream out(&file);

    // Сохраняем состояния радиокнопок

    out << "rh_l=" << (ui_conf_speed->radioButton_rh_l->isChecked() ? "1" : "0") << "\n";
    out << "rf_l=" << (ui_conf_speed->radioButton_rf_l->isChecked() ? "1" : "0") << "\n";
    out << "ry_l=" << (ui_conf_speed->radioButton_ry_l->isChecked() ? "1" : "0") << "\n";

    out << "rh_f=" << (ui_conf_speed->radioButton_rh_f->isChecked() ? "1" : "0") << "\n";
    out << "rf_f=" << (ui_conf_speed->radioButton_rf_f->isChecked() ? "1" : "0") << "\n";
    out << "ry_f=" << (ui_conf_speed->radioButton_ry_f->isChecked() ? "1" : "0") << "\n";

    out << "rh_ret=" << (ui_conf_speed->radioButton_rh_ret->isChecked() ? "1" : "0") << "\n";
    out << "rf_ret=" << (ui_conf_speed->radioButton_rf_ret->isChecked() ? "1" : "0") << "\n";
    out << "ry_ret=" << (ui_conf_speed->radioButton_ry_ret->isChecked() ? "1" : "0") << "\n";

    out << "rh_c=" << (ui_conf_speed->radioButton_rh_c->isChecked() ? "1" : "0") << "\n";
    out << "rf_c=" << (ui_conf_speed->radioButton_rf_c->isChecked() ? "1" : "0") << "\n";
    out << "ry_c=" << (ui_conf_speed->radioButton_ry_c->isChecked() ? "1" : "0") << "\n";

    out << "rh_sh=" << (ui_conf_speed->radioButton_rh_sh->isChecked() ? "1" : "0") << "\n";
    out << "rf_sh=" << (ui_conf_speed->radioButton_rf_sh->isChecked() ? "1" : "0") << "\n";
    out << "ry_sh=" << (ui_conf_speed->radioButton_ry_sh->isChecked() ? "1" : "0") << "\n";

    out << "rh_n=" << (ui_conf_speed->radioButton_rh_n->isChecked() ? "1" : "0") << "\n";
    out << "rf_n=" << (ui_conf_speed->radioButton_rf_n->isChecked() ? "1" : "0") << "\n";
    out << "ry_n=" << (ui_conf_speed->radioButton_ry_n->isChecked() ? "1" : "0") << "\n";

    out << "rh_h=" << (ui_conf_speed->radioButton_rh_h->isChecked() ? "1" : "0") << "\n";
    out << "rf_h=" << (ui_conf_speed->radioButton_rf_h->isChecked() ? "1" : "0") << "\n";
    out << "ry_h=" << (ui_conf_speed->radioButton_ry_h->isChecked() ? "1" : "0") << "\n";

    out << "rh_m=" << (ui_conf_speed->radioButton_rh_m->isChecked() ? "1" : "0") << "\n";
    out << "rf_m=" << (ui_conf_speed->radioButton_rf_m->isChecked() ? "1" : "0") << "\n";
    out << "ry_m=" << (ui_conf_speed->radioButton_ry_m->isChecked() ? "1" : "0") << "\n";

    out << "rh_read=" << (ui_conf_speed->radioButton_rh_read->isChecked() ? "1" : "0") << "\n";
    out << "rf_read=" << (ui_conf_speed->radioButton_rf_read->isChecked() ? "1" : "0") << "\n";
    out << "ry_read=" << (ui_conf_speed->radioButton_ry_read->isChecked() ? "1" : "0") << "\n";

    file.close();
}
*/
#include "mainwindow.h"
#include "ui_for_rasb_stend.h"
#include "ui_form_help.h"
#include <QPixmap>
#include <QPropertyAnimation>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QGraphicsOpacityEffect>
#include <QTimer>
#include <QModbusDataUnit>
#include <QModbusReply>
#include <QVariant>
#include <QSerialPort>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      form_conf_speed(new QDialog(this)),
      ui_conf_speed(new Ui::Form_conf_speed()),
      form_help(new QWidget()),
      animation(new QPropertyAnimation(this)),
      isMoving(false),
      messageWindow(new MessageWindow(this)),
      isMessageWindowVisible(false),
      gearRatio(2),
      PULLEY_DIAMETER(320.0),
      PULSES_PER_REVOLUTION(2048),
      closeTimer(new QTimer(this))   // Инициализация таймера
{
    ui->setupUi(this);
    // Настройка таймера
    closeTimer->setSingleShot(true);  // Таймер сработает только один раз
    connect(closeTimer, &QTimer::timeout, this, [this]() {
        form_conf_speed->close();
        ui_conf_speed->label_saved->setText("Not saved"); // Закрытие формы после задержки
    });
    // Проверка инициализации ui_conf_speed
    if (!ui_conf_speed) {
        qDebug() << "Ошибка: ui_conf_speed не инициализирован!";
        return;
    }


    // Инициализация таймера
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateSpeed);
    connect(ui->checkBox_bus, &QPushButton::toggled, this, &MainWindow::toggleMessageWindow);
    connect(timer, &QTimer::timeout, this, &MainWindow::readDataFromBus);
    //timer->start(1000);  // Чтение данных каждую секунду

    timer->start(1000);  // Обновление каждую секунду

    // Настраиваем UI для формы конфигурации скорости
    // Настройка формы conf_speed
    ui_conf_speed->setupUi(form_conf_speed);
    // Очистка списков перед добавлением элементов
    ui_conf_speed->listWidget_ratio->clear();
    ui_conf_speed->listWidget_shave->clear();
    ui_conf_speed->listWidget_enc->clear();
    // Заполняем listWidget_ratio
    QListWidgetItem *item1 = new QListWidgetItem("1 : 2");
    item1->setData(Qt::UserRole, 2);
    ui_conf_speed->listWidget_ratio->addItem(item1);

    QListWidgetItem *item2 = new QListWidgetItem("1 : 1");
    item2->setData(Qt::UserRole, 1);
    ui_conf_speed->listWidget_ratio->addItem(item2);
    ui_conf_speed->listWidget_ratio->setCurrentRow(0);

    // listWidget_shave
    QListWidgetItem *item3 = new QListWidgetItem(" 320 мм");
    item3->setData(Qt::UserRole, 320.0);
    ui_conf_speed->listWidget_shave->addItem(item3);

    QListWidgetItem *item4 = new QListWidgetItem(" 200 мм");
    item4->setData(Qt::UserRole, 200.0);
    ui_conf_speed->listWidget_shave->addItem(item4);
    ui_conf_speed->listWidget_shave->setCurrentRow(0);

    // listWidget_enc
    QListWidgetItem *item5 = new QListWidgetItem(" 2048");
    item5->setData(Qt::UserRole, 2048);
    ui_conf_speed->listWidget_enc->addItem(item5);

    QListWidgetItem *item6 = new QListWidgetItem(" 1024");
    item6->setData(Qt::UserRole, 1024);
    ui_conf_speed->listWidget_enc->addItem(item6);

    QListWidgetItem *item7 = new QListWidgetItem(" 500");
    item7->setData(Qt::UserRole, 500);
    ui_conf_speed->listWidget_enc->addItem(item7);
    ui_conf_speed->listWidget_enc->setCurrentRow(0);

    // Подключаем сигналы и слоты для кнопок формы
    connect(ui_conf_speed->pushButton_Ok, &QPushButton::clicked, this, &MainWindow::on_pushButton_Ok_clicked);
    connect(ui_conf_speed->pushButton_cancel, &QPushButton::clicked, this, &MainWindow::on_pushButton_cancel_clicked);
    // Подключаем сигналы currentRowChanged к слотам
    connect(ui_conf_speed->listWidget_ratio, &QListWidget::currentRowChanged, this, &MainWindow::onRatioChanged);
    connect(ui_conf_speed->listWidget_shave, &QListWidget::currentRowChanged, this, &MainWindow::onPulleyChanged);
    connect(ui_conf_speed->listWidget_enc, &QListWidget::currentRowChanged, this, &MainWindow::onPulsesChanged);

    // Подключаем сигналы и слоты для кнопок формы
    connect(ui_conf_speed->pushButton_Ok, &QPushButton::clicked, this, &MainWindow::on_pushButton_Ok_clicked);
    connect(ui_conf_speed->pushButton_cancel, &QPushButton::clicked, this, &MainWindow::on_pushButton_cancel_clicked);

    // Инициализация формы помощи
    Ui::Form_help ui_help;
    ui_help.setupUi(form_help);

    readSettings();

    // Загружаем изображения из ресурсов
    QPixmap moveDownImage(":/pic/move_dwn.png");
    if (moveDownImage.isNull()) {
        qDebug() << "Ошибка: Не удалось загрузить move_dwn.png!";
    } else {
        ui->label_updw->setPixmap(moveDownImage);
        ui->label_updw->setScaledContents(true);
    }

    QPixmap closeDoorImage(":/pic/close_door.png");
    ui->label_opcl->setPixmap(closeDoorImage);
    ui->label_opcl->setScaledContents(true);

    // Настройка анимации
    ui->label_move->setPixmap(QPixmap(":/pic/lift_cab_128.png"));
    ui->label_move->setScaledContents(true);
    ui->label_move->raise();
    animation->setTargetObject(ui->label_move);
    animation->setPropertyName("pos");
    animation->setDuration(3000);
    animation->setLoopCount(-1);

    // Связываем завершение анимации с слотом
    connect(animation, &QPropertyAnimation::finished, this, &MainWindow::on_animation_finished);

    // Связываем кнопки с слотами
    connect(ui->pushButton_start, &QPushButton::clicked, this, &MainWindow::on_pushButton_start_clicked);
    connect(ui->pushButton_stop, &QPushButton::clicked, this, &MainWindow::on_pushButton_stop_clicked);
    connect(ui->radioButton_opcl, &QPushButton::clicked, this, &MainWindow::on_radioButton_opcl_clicked);
    connect(ui->radioButton_500, &QPushButton::clicked, this, &MainWindow::on_radioButton_500_clicked);
    connect(ui->radioButton_501, &QPushButton::clicked, this, &MainWindow::on_radioButton_501_clicked);
    connect(ui->radioButton_light, &QPushButton::clicked, this, &MainWindow::on_radioButton_light_clicked);

    timer->start(1000);  // Запуск таймера
}

MainWindow::~MainWindow() {
    delete ui;
    delete form_conf_speed;
    delete ui_conf_speed;
    delete form_help;
    delete animation;
}

void MainWindow::on_action_Help_triggered() {
    form_help->show();
}

void MainWindow::toggleMessageWindow(bool checked) {
    if (checked) {
        messageWindow->show();  // Показать окно
        isMessageWindowVisible = true;
    } else {
        messageWindow->hide();  // Скрыть окно
        isMessageWindowVisible = false;
    }
}

void MainWindow::readDataFromBus() {
    QString message = "Пример сообщения с шины";
    if (isMessageWindowVisible && messageWindow) {
        messageWindow->appendMessage(message);  // Вывод сообщения в окно
    } else {
        qDebug() << "Окно сообщений скрыто или не инициализировано!";
    }
}


void MainWindow::on_radioButton_opcl_clicked() {
    if (ui->radioButton_opcl->isChecked()) {
        ui->label_opcl->setPixmap(QPixmap(":/pic/close_door.png"));
    } else {
        ui->label_opcl->setPixmap(QPixmap(":/pic/open_door.png"));
    }
    repaint();
}

void MainWindow::updateSpeed() {
    int pulsesPerSecond = 500;  // Пример значения
    double speed = calculateLiftSpeed(pulsesPerSecond);
    if (ui->label_speed_mc) {
        ui->label_speed_mc->setText(QString::number(speed, 'f', 2) + " м/с");
    } else {
        qDebug() << "Ошибка: label_speed_mc не инициализирован!";
    }
}

void MainWindow::updateSettings(int gearRatio, double PULLEY_DIAMETER, int PULSES_PER_REVOLUTION) {
    this->gearRatio = gearRatio;
    this->PULLEY_DIAMETER = PULLEY_DIAMETER;
    this->PULSES_PER_REVOLUTION = PULSES_PER_REVOLUTION;

    qDebug() << "Настройки обновлены:";
    qDebug() << "Gear Ratio:" << gearRatio;
    qDebug() << "Pulley Diameter:" << PULLEY_DIAMETER;
    qDebug() << "Pulses per Revolution:" << PULSES_PER_REVOLUTION;
}

double MainWindow::calculateLiftSpeed(int pulsesPerSecond) {
    if (PULLEY_DIAMETER <= 0 || PULSES_PER_REVOLUTION <= 0 || gearRatio <= 0) {
        qDebug() << "Ошибка: Некорректные значения параметров для расчёта скорости!";
        return 0.0;
    }

    double pulleyDiameterMeters = PULLEY_DIAMETER / 1000.0;
    double circumference = M_PI * pulleyDiameterMeters;
    double speed = (circumference * pulsesPerSecond) / (PULSES_PER_REVOLUTION * gearRatio);
    speed = round(speed * 100) / 100;
    return speed;
}

void MainWindow::on_actionconfig_triggered() {
    form_conf_speed->exec();
}

void MainWindow::on_pushButton_conf_clicked() {
    form_conf_speed->exec();
}

void MainWindow::on_pushButton_start_clicked() {
    if (isMoving) return;
    ui->pushButton_stop->setChecked(false);

    bool is501Selected = ui->radioButton_501->isChecked();
    bool is500Selected = ui->radioButton_500->isChecked();

    if (is501Selected && is500Selected) {
        qDebug() << "Ошибка: Выбраны обе радиокнопки!";
        return;
    }
    if (!is501Selected && !is500Selected) return;

    if (is501Selected) {
        ui->label_updw->setPixmap(QPixmap(":/pic/move_up.png"));
        qDebug() << "Выбрана радиокнопка 501: Движение вверх";
        animation->setStartValue(QPoint(100, 400));
        animation->setEndValue(QPoint(100, 10));
    } else if (is500Selected) {
        ui->label_updw->setPixmap(QPixmap(":/pic/move_dwn.png"));
        qDebug() << "Выбрана радиокнопка 500: Движение вниз";
        animation->setStartValue(QPoint(100, 10));
        animation->setEndValue(QPoint(100, 400));
    }

    animation->start();
    isMoving = true;
}

void MainWindow::on_animation_finished() {
    if (isMoving) {
        animation->start();
    }
}

void MainWindow::on_radioButton_500_clicked() {
    if (!ui->radioButton_501->isChecked())
        ui->label_updw->setPixmap(QPixmap(":/pic/move_dwn.png"));
}

void MainWindow::on_radioButton_501_clicked() {
    if (!ui->radioButton_500->isChecked())
        ui->label_updw->setPixmap(QPixmap(":/pic/move_up.png"));
}

void MainWindow::on_pushButton_stop_clicked() {
    animation->stop();
    isMoving = false;

    ui->label_move->move(QPoint(100, 200));
    ui->pushButton_start->setChecked(false);

    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(ui->pushButton_stop);
    ui->pushButton_stop->setGraphicsEffect(opacityEffect);

    QPropertyAnimation *buttonAnimation = new QPropertyAnimation(opacityEffect, "opacity");
    buttonAnimation->setDuration(3000);
    buttonAnimation->setStartValue(0.1);
    buttonAnimation->setEndValue(1.0);
    buttonAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    ui_conf_speed->label_saved->setText("Not saved");
    ui->pushButton_stop->setChecked(false);
}

void MainWindow::on_pushButton_Ok_clicked() {
    qDebug() << "Кнопка 'ОК' нажата!";
    writeSettings();

    if (ui_conf_speed && ui_conf_speed->label_saved) {
        ui_conf_speed->label_saved->setText("Saved");
        ui_conf_speed->label_saved->setVisible(true);
        ui_conf_speed->label_saved->repaint();
        ui_conf_speed->label_saved->update();
    } else {
        qDebug() << "Ошибка: label_saved не существует!";
    }

    if (ui_conf_speed) {
        QListWidgetItem *selectedRatioItem = ui_conf_speed->listWidget_ratio->currentItem();
        int gearRatio = selectedRatioItem ? selectedRatioItem->data(Qt::UserRole).toInt() : 2;

        QListWidgetItem *selectedPulleyItem = ui_conf_speed->listWidget_shave->currentItem();
        double PULLEY_DIAMETER = selectedPulleyItem ? selectedPulleyItem->data(Qt::UserRole).toDouble() : 320.0;

        QListWidgetItem *selectedPulsesItem = ui_conf_speed->listWidget_enc->currentItem();
        int PULSES_PER_REVOLUTION = selectedPulsesItem ? selectedPulsesItem->data(Qt::UserRole).toInt() : 2048;

        updateSettings(gearRatio, PULLEY_DIAMETER, PULSES_PER_REVOLUTION);
    } else {
        qDebug() << "Ошибка: ui_conf_speed не инициализирован!";
    }
    closeTimer->start(3000);  // Задержка 1 секунда (1000 мс)
   //form_conf_speed->close();


}

void MainWindow::on_radioButton_light_clicked() {
    if (ui->radioButton_light->isChecked())
        ui->label_ligth->setPixmap(QPixmap(":/pic/lift_cab_512_ligh2.png"));
    else
        ui->label_ligth->setPixmap(QPixmap(":/pic/lift_cab_512.png"));
    ui->label_ligth->setScaledContents(true);
}

void MainWindow::on_pushButton_cancel_clicked() {
    form_conf_speed->close();
}

void MainWindow::readSettings() {
    if (!ui_conf_speed) {
        qDebug() << "Ошибка: ui_conf_speed не инициализирован в readSettings!";
        return;
    }

    QFile file("D:/alexey/QT/new_test_board_v2/speed_settings.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        writeSettings();
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("=");
        if (parts.size() == 2) {
            QString key = parts[0].trimmed();
            bool value = (parts[1].trimmed() == "1");

            // Устанавливаем состояния радиокнопок

            //levelling speed
            if (key == "rh_l") ui_conf_speed->radioButton_rh_l->setChecked(value);
            if (key == "rf_l") ui_conf_speed->radioButton_rf_l->setChecked(value);
            if (key == "ry_l") ui_conf_speed->radioButton_ry_l->setChecked(value);
            //floar aproach speed
            if (key == "rh_f") ui_conf_speed->radioButton_rh_f->setChecked(value);
            if (key == "rf_f") ui_conf_speed->radioButton_rf_f->setChecked(value);
            if (key == "ry_f") ui_conf_speed->radioButton_ry_f->setChecked(value);
            //retern speed
            if (key == "rh_ret") ui_conf_speed->radioButton_rh_ret->setChecked(value);
            if (key == "rf_ret") ui_conf_speed->radioButton_rf_ret->setChecked(value);
            if (key == "ry_ret") ui_conf_speed->radioButton_ry_ret->setChecked(value);
            //card insp speed
            if (key == "rh_c") ui_conf_speed->radioButton_rh_c->setChecked(value);
            if (key == "rf_c") ui_conf_speed->radioButton_rf_c->setChecked(value);
            if (key == "ry_c") ui_conf_speed->radioButton_ry_c->setChecked(value);
            //inspection shaft speed
            if (key == "rh_sh") ui_conf_speed->radioButton_rh_sh->setChecked(value);
            if (key == "rf_sh") ui_conf_speed->radioButton_rf_sh->setChecked(value);
            if (key == "ry_sh") ui_conf_speed->radioButton_ry_sh->setChecked(value);
            //normal speed
            if (key == "rh_n") ui_conf_speed->radioButton_rh_n->setChecked(value);
            if (key == "rf_n") ui_conf_speed->radioButton_rf_n->setChecked(value);
            if (key == "ry_n") ui_conf_speed->radioButton_ry_n->setChecked(value);
            // high speed
            if (key == "rh_h") ui_conf_speed->radioButton_rh_h->setChecked(value);
            if (key == "rf_h") ui_conf_speed->radioButton_rf_h->setChecked(value);
            if (key == "ry_h") ui_conf_speed->radioButton_ry_h->setChecked(value);
            // max speed
            if (key == "rh_m") ui_conf_speed->radioButton_rh_m->setChecked(value);
            if (key == "rf_m") ui_conf_speed->radioButton_rf_m->setChecked(value);
            if (key == "ry_m") ui_conf_speed->radioButton_ry_m->setChecked(value);
            //reading shaft
            if (key == "rh_read") ui_conf_speed->radioButton_rh_read->setChecked(value);
            if (key == "rf_read") ui_conf_speed->radioButton_rf_read->setChecked(value);
            if (key == "ry_read") ui_conf_speed->radioButton_ry_read->setChecked(value);
        }
    }

    file.close();
}

void MainWindow::writeSettings() {
    if (!ui_conf_speed) {
        qDebug() << "Ошибка: ui_conf_speed не инициализирован в writeSettings!";
        return;
    }

    QFile file("D:/alexey/QT/new_test_board_v2/speed_settings.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить настройки!");
        return;
    }

    QTextStream out(&file);

    out << "rh_l=" << (ui_conf_speed->radioButton_rh_l->isChecked() ? "1" : "0") << "\n";
    out << "rf_l=" << (ui_conf_speed->radioButton_rf_l->isChecked() ? "1" : "0") << "\n";
    out << "ry_l=" << (ui_conf_speed->radioButton_ry_l->isChecked() ? "1" : "0") << "\n";

    out << "rh_f=" << (ui_conf_speed->radioButton_rh_f->isChecked() ? "1" : "0") << "\n";
    out << "rf_f=" << (ui_conf_speed->radioButton_rf_f->isChecked() ? "1" : "0") << "\n";
    out << "ry_f=" << (ui_conf_speed->radioButton_ry_f->isChecked() ? "1" : "0") << "\n";

    out << "rh_ret=" << (ui_conf_speed->radioButton_rh_ret->isChecked() ? "1" : "0") << "\n";
    out << "rf_ret=" << (ui_conf_speed->radioButton_rf_ret->isChecked() ? "1" : "0") << "\n";
    out << "ry_ret=" << (ui_conf_speed->radioButton_ry_ret->isChecked() ? "1" : "0") << "\n";

    out << "rh_c=" << (ui_conf_speed->radioButton_rh_c->isChecked() ? "1" : "0") << "\n";
    out << "rf_c=" << (ui_conf_speed->radioButton_rf_c->isChecked() ? "1" : "0") << "\n";
    out << "ry_c=" << (ui_conf_speed->radioButton_ry_c->isChecked() ? "1" : "0") << "\n";

    out << "rh_sh=" << (ui_conf_speed->radioButton_rh_sh->isChecked() ? "1" : "0") << "\n";
    out << "rf_sh=" << (ui_conf_speed->radioButton_rf_sh->isChecked() ? "1" : "0") << "\n";
    out << "ry_sh=" << (ui_conf_speed->radioButton_ry_sh->isChecked() ? "1" : "0") << "\n";

    out << "rh_n=" << (ui_conf_speed->radioButton_rh_n->isChecked() ? "1" : "0") << "\n";
    out << "rf_n=" << (ui_conf_speed->radioButton_rf_n->isChecked() ? "1" : "0") << "\n";
    out << "ry_n=" << (ui_conf_speed->radioButton_ry_n->isChecked() ? "1" : "0") << "\n";

    out << "rh_h=" << (ui_conf_speed->radioButton_rh_h->isChecked() ? "1" : "0") << "\n";
    out << "rf_h=" << (ui_conf_speed->radioButton_rf_h->isChecked() ? "1" : "0") << "\n";
    out << "ry_h=" << (ui_conf_speed->radioButton_ry_h->isChecked() ? "1" : "0") << "\n";

    out << "rh_m=" << (ui_conf_speed->radioButton_rh_m->isChecked() ? "1" : "0") << "\n";
    out << "rf_m=" << (ui_conf_speed->radioButton_rf_m->isChecked() ? "1" : "0") << "\n";
    out << "ry_m=" << (ui_conf_speed->radioButton_ry_m->isChecked() ? "1" : "0") << "\n";

    out << "rh_read=" << (ui_conf_speed->radioButton_rh_read->isChecked() ? "1" : "0") << "\n";
    out << "rf_read=" << (ui_conf_speed->radioButton_rf_read->isChecked() ? "1" : "0") << "\n";
    out << "ry_read=" << (ui_conf_speed->radioButton_ry_read->isChecked() ? "1" : "0") << "\n";
    file.close();
}

void MainWindow::onRatioChanged(int row) {
    if (row < 0) return;  // Проверка на недопустимый индекс

    QListWidgetItem *item = ui_conf_speed->listWidget_ratio->item(row);
    if (item) {
        gearRatio = item->data(Qt::UserRole).toInt();
        qDebug() << "Gear Ratio изменён на:" << gearRatio;
    }
}

void MainWindow::onPulleyChanged(int row) {
    if (row < 0) return;  // Проверка на недопустимый индекс

    QListWidgetItem *item = ui_conf_speed->listWidget_shave->item(row);
    if (item) {
        PULLEY_DIAMETER = item->data(Qt::UserRole).toDouble();
        qDebug() << "Pulley Diameter изменён на:" << PULLEY_DIAMETER;
    }
}

void MainWindow::onPulsesChanged(int row) {
    if (row < 0) return;  // Проверка на недопустимый индекс

    QListWidgetItem *item = ui_conf_speed->listWidget_enc->item(row);
    if (item) {
        PULSES_PER_REVOLUTION = item->data(Qt::UserRole).toInt();
        qDebug() << "Pulses per Revolution изменён на:" << PULSES_PER_REVOLUTION;
    }
}
/*


    void MainWindow::readDataFromBus() {

    QModbusRtuSerialMaster *modbusDevice = new QModbusRtuSerialMaster(this);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter, "/dev/ttyUSB0");
    modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, QSerialPort::Baud9600);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter, QSerialPort::NoParity);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, QSerialPort::OneStop);

    if (!modbusDevice->connectDevice()) {
        qDebug() << "Ошибка подключения к ModBus устройству!";
        return;
    }

    // Чтение данных
    QModbusDataUnit request(QModbusDataUnit::InputRegisters, 0, 10);  // Чтение 10 регистров
    if (auto *reply = modbusDevice->sendReadRequest(request, 1)) {
        if (!reply->isFinished()) {
            connect(reply, &QModbusReply::finished, this, [this, reply]() {
                if (reply->error() == QModbusDevice::NoError) {
                    const QModbusDataUnit unit = reply->result();
                    QString message = "Данные: ";
                    for (uint i = 0; i < unit.valueCount(); ++i) {
                        message += QString::number(unit.value(i)) + " ";
                    }
                    if (isMessageWindowVisible) {
                        messageWindow->appendMessage(message);  // Вывод сообщения в окно
                    }
                } else {
                    qDebug() << "Ошибка чтения данных: " << reply->errorString();
                }
                reply->deleteLater();
            });
        } else {
            delete reply;
        }
    } else {
        qDebug() << "Ошибка отправки запроса!";
    }
}
*/
