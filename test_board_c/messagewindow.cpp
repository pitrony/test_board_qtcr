#include "messagewindow.h"

MessageWindow::MessageWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Сообщения");
    setFixedSize(200, 150);  // Фиксированный размер окна

    textEdit = new QPlainTextEdit(this);
    textEdit->setReadOnly(true);  // Запрет редактирования
    textEdit->setGeometry(0, 0, 200, 150);  // Размер текстового поля
}

void MessageWindow::appendMessage(const QString &message) {
    textEdit->appendPlainText(message);  // Добавление сообщения
}
