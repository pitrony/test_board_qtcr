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
