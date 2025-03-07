/*
  #pragma once

#include <QMainWindow>
#include <QDialog>
#include "ui_form_conf_speed.h"
//#include "ui_form_help.h"
#include <QPropertyAnimation>
#include "messagewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_Help_triggered();
    void on_pushButton_conf_clicked();
    void on_actionconfig_triggered();
    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
    void on_animation_finished();
    void on_radioButton_opcl_clicked();
    void on_radioButton_500_clicked();
    void on_radioButton_501_clicked();
    void on_pushButton_Ok_clicked();
    void on_pushButton_cancel_clicked();
    void readSettings();
    void writeSettings();
    void on_radioButton_light_clicked();
    void toggleMessageWindow(bool checked);  // Включение/выключение окна сообщений
    void readDataFromBus();  // Чтение данных с шины
    void updateSpeed();  // Слот для обновления скорости


private:
    Ui::MainWindow *ui;
    QDialog *form_conf_speed;  // Окно конфигурации скорости
    Ui::Form_conf_speed *ui_conf_speed;  // Указатель на UI формы
    QWidget *form_help;  // Окно помощи
    QPropertyAnimation *animation;  // Анимация для перемещения картинки
    bool isMoving;  // Флаг для отслеживания движения
    MessageWindow *messageWindow;  // Окно для отображения сообщений
    bool isMessageWindowVisible;   // Флаг видимости окна
    int gearRatio;               // Переменная для Gear Ratio
    double PULLEY_DIAMETER;      // Переменная для Pulley Diameter
    int PULSES_PER_REVOLUTION;   // Переменная для Encoder Pulses
    void updateSettings(int gearRatio, double PULLEY_DIAMETER, int PULSES_PER_REVOLUTION);
    //double calculateLiftSpeed(int pulsesPerSecond, int PULSES_PER_REVOLUTION, double pulleyDiameter, int gearRatio);
    double calculateLiftSpeed(int pulsesPerSecond);


};
*/
#pragma once

#include <QMainWindow>
#include <QDialog>
#include "ui_form_conf_speed.h"
#include <QPropertyAnimation>
#include "messagewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_Help_triggered();
    void on_pushButton_conf_clicked();
    void on_actionconfig_triggered();
    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
    void on_animation_finished();
    void on_radioButton_opcl_clicked();
    void on_radioButton_500_clicked();
    void on_radioButton_501_clicked();
    void on_pushButton_Ok_clicked();
    void on_pushButton_cancel_clicked();
    void readSettings();
    void writeSettings();
    void on_radioButton_light_clicked();
    void toggleMessageWindow(bool checked);  // Включение/выключение окна сообщений
    void readDataFromBus();  // Чтение данных с шины
    void updateSpeed();  // Слот для обновления скорости
    void onRatioChanged(int row);  // Слот для изменения строки в listWidget_ratio
    void onPulleyChanged(int row); // Слот для изменения строки в listWidget_shave
    void onPulsesChanged(int row); // Слот для изменения строки в listWidget_enc

private:
    Ui::MainWindow *ui;
    QDialog *form_conf_speed;  // Окно конфигурации скорости
    Ui::Form_conf_speed *ui_conf_speed;  // Указатель на UI формы
    QWidget *form_help;  // Окно помощи
    QPropertyAnimation *animation;  // Анимация для перемещения картинки
    bool isMoving;  // Флаг для отслеживания движения
    MessageWindow *messageWindow;  // Окно для отображения сообщений
    bool isMessageWindowVisible;   // Флаг видимости окна
    int gearRatio;               // Переменная для Gear Ratio
    double PULLEY_DIAMETER;      // Переменная для Pulley Diameter
    int PULSES_PER_REVOLUTION;   // Переменная для Encoder Pulses
    void updateSettings(int gearRatio, double PULLEY_DIAMETER, int PULSES_PER_REVOLUTION);
    double calculateLiftSpeed(int pulsesPerSecond);
    QTimer *closeTimer;  // Таймер для задержки закрытия формы

};
