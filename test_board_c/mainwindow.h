#pragma once

#include <QMainWindow>
#include <QDialog>
#include "ui_form_conf_speed.h"

#include "ui_form_help.h"

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

private:
    Ui::MainWindow *ui;
    QDialog *form_conf_speed;  // Окно конфигурации скорости
    QWidget *form_help;        // Окно помощи
    Ui::Form_conf_speed ui_conf_speed;  // Добавляем UI для Form_conf_speed

};
