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
#include <QStandardItemModel>

//#include <mqtt/async_client.h>
//#include <mqtt/client.h>
//#include <wiringPiI2C.h>
//#include <unistd.h>

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
    //timer2 = new QTimer(this);
    //QTimer *timer2 = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::readI2CData);
    //timer2->start(50); // 50 мс = 0.05 секунд

    //connect(timer, &QTimer::timeout, this, &MainWindow::readI2CData);

    connect(ui->checkBox_bus, &QPushButton::toggled, this, &MainWindow::toggleMessageWindow);
    connect(timer, &QTimer::timeout, this, &MainWindow::readDataFromBus);
    //timer->start(1000);  // Чтение данных каждую секунду

    timer->start(5000);  // Обновление каждую 5 секунду
    QStandardItemModel *model = new QStandardItemModel(this);
    ui->listView_alarms->setModel(model);
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



void MainWindow::readI2CData() {
//    int fd1 = wiringPiI2CSetup(0x20); // Адрес первого устройства
  //  int fd2 = wiringPiI2CSetup(0x24); // Адрес второго устройства
    //int fd3 = wiringPiI2CSetup(0x22); // Адрес третьего устройства

    //int data1 = wiringPiI2CRead(fd1);
    //int data2 = wiringPiI2CRead(fd2);
    //int data3 = wiringPiI2CRead(fd3);
   // data1=255;
    //data2=255;
    // data3=255;
    // Декодирование данных
//if(data1!=_data1 || data2!=_data2 || data3!=_data3) {
    //decode(data1, data2, data3);

    // Обновление интерфейса
    updateUI(data1, data2, data3);
   // updateUI(255, 255, 255);

    // Отправка изменений по MQTT
    //sendMQTT(data1, data2, data3);
//}
_data1=data1;
_data2=data2;
_data3=data3;
}

/*
void MainWindow::send_mqtt(const std::string& topic, int data) {
    mqtt::client client("tcp://localhost:1883", "client_id");
    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);

    try {
        client.connect(connOpts);
        mqtt::message_ptr pubmsg = mqtt::make_message(topic, std::to_string(data));
        client.publish(pubmsg);
        client.disconnect();
    } catch (const mqtt::exception& exc) {
        std::cerr << "Ошибка MQTT: " << exc.what() << std::endl;
    }
}
void MainWindow::sendMQTT(int data1, int data2, int data3) {
    static int prev_data1 = 0, prev_data2 = 0, prev_data3 = 0;

    if (data1 != prev_data1) {
        send_mqtt("/orange/data1", data1);
        prev_data1 = data1;
    }
    if (data2 != prev_data2) {
        send_mqtt("/orange/data2", data2);
        prev_data2 = data2;
    }
    if (data3 != prev_data3) {
        send_mqtt("/orange/data3", data3);
        prev_data3 = data3;
    }
}
*/

void MainWindow::updateUI(int data1, int data2, int data3) {
    // Обновление радиобоксов
    if (data1 & 0x08) ui->radioButton_ru1->setChecked(true);
    if (data1 & 0x10) ui->radioButton_ru2->setChecked(true);
    if (data1 & 0x20) ui->radioButton_krc->setChecked(true);
    if (data1 & 0x40) ui->radioButton_frn->setChecked(true);
    if (data1 & 0x80) ui->radioButton_ptc->setChecked(true);

    if (data2 & 0x01) ui->radioButton_ins->setChecked(true);
    if (data2 & 0x02) ui->radioButton_500->setChecked(true);
    if (data2 & 0x04) ui->radioButton_501->setChecked(true);
    if (data2 & 0x08) ui->radioButton_ml1->setChecked(true);
    if (data2 & 0x10) ui->radioButton_ml2->setChecked(true);
    if (data2 & 0x20) ui->radioButton_opcl->setChecked(true);
    if (data2 & 0x40) ui->radioButton_818->setChecked(true);
    if (data2 & 0x80) ui->radioButton_817->setChecked(true);

    if (data3 & 0x01) ui->radioButton_rgk->setChecked(true);
    if (data3 & 0x02) ui->radioButton_fri->setChecked(true);
    if (data3 & 0x04) ui->radioButton_ppp->setChecked(true);
    if (data3 & 0x08) ui->radioButton_120->setChecked(true);
    if (data3 & 0x10) ui->radioButton_130->setChecked(true);
    if (data3 & 0x20) ui->radioButton_140->setChecked(true);
    if (data3 & 0x40) ui->radioButton_light->setChecked(true);
    if (data3 & 0x80) ui->radioButton_rez1->setChecked(true);

    // Обновление alarm
    if (data1 & 0x80) {
        QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->listView_alarms->model());
        if (model) {
            QStandardItem *item = new QStandardItem("Ошибка ptc!");
            model->appendRow(item); // Добавляем новый элемент в список
        }
    }

    //if ((data1 & 0x80)==true) {
       //ui->listView_alarms->model()->insertRow(ui->listView_alarms->model()->rowCount()); // Добавляем новую строку
        //QModelIndex index = ui->listView_alarms->model()->index(ui->listView_alarms->model()->rowCount() - 1, 0); // Получаем индекс новой строки
       //ui->listView_alarms->model()->setData(index, "Ptc hight temp"); // Устанавливаем текст в новую строку
    //}


    // if (data3 & 0x04) ui->listView_alarms->setText("Ошибка!");
  //model->insertRow(model->rowCount());
    //QModelIndex index = model->index(model->rowCount()-1)
                        //model->setData(index, str);

    //else ui->listView_alarms->setText("Нет ошибок");
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
  /*  QString message = "Пример сообщения с шины";
    if (isMessageWindowVisible && messageWindow) {
        messageWindow->appendMessage(message);  // Вывод сообщения в окно

    } else {
        qDebug() << "Окно сообщений скрыто или не инициализировано!";
    }

#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <unistd.h>

void MainWindow::readDataFromBus() {
    int sock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (sock < 0) {
        qDebug() << "Ошибка создания сокета CAN!";
        return;
    }

    struct can_frame frame;
    int nbytes = read(sock, &frame, sizeof(struct can_frame));
    if (nbytes < 0) {
        qDebug() << "Ошибка чтения данных с CAN!";
        close(sock);
        return;
    }

    QString id = QString("0x%1").arg(frame.can_id, 0, 16);  // ID сообщения
    QString data = QString("0x%1").arg(frame.data[0], 0, 16);  // Данные сообщения (первый байт)

    if (isMessageWindowVisible) {
        messageWindow->appendMessage(id, data);  // Вывод сообщения в таблицу
    }

    close(sock);
}


*/
    // Здесь будет код для чтения данных с CAN или ModBus
    // Пример:

    /*
    // Пример данных с шины)
    QByteArray data;
    data.append(0x12);  // Первый байт: этаж и состояние дверей
    data.append(0x00);  // Второй байт: null
    data.append(0x31);  // Третий байт: "E"
    data.append(0x34);  // Четвертый байт: "G"
    data.append(0x19);  // Пятый байт: направление
    data.append(0x00);  // Шестой байт: null
    data.append(0x00);  // Седьмой байт: null
    data.append(0x00);  // Восьмой байт: null

    if (isMessageWindowVisible) {
        messageWindow->appendMessage(data);  // Вывод сообщения в таблицу
    }
}



    */
    QString id = "0x100";       // ID сообщения
    QString data = "0x100";      // Данные сообщения

    if (isMessageWindowVisible) {
        messageWindow->appendMessage(id, data);  // Вывод сообщения в таблицу
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
