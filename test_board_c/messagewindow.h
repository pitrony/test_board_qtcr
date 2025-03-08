/*
#pragma once
#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QDialog>
#include <QPlainTextEdit>

class MessageWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MessageWindow(QWidget *parent = nullptr);
    void appendMessage(const QString &message);  // Добавление сообщения в окно
private:
    QPlainTextEdit *textEdit;  // Виджет для отображения текста
};

#endif // MESSAGEWINDOW_H
*/

#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include <QTableView>
#include "messdecoder.h"

class MessageWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MessageWindow(QWidget *parent = nullptr);
    void appendMessage(const QString &id, const QString &data);  // Добавление сообщения в таблицу
/*
void appendMessage(const QByteArray &data);  // Добавление сообщения в таблицу



*/
private:
    QTableView *tableView;         // Виджет для отображения таблицы
    QStandardItemModel *model;     // Модель данных для таблицы
    MessageDecoder decoder;        // Дешифровщик сообщений
};

#endif // MESSAGEWINDOW_H
