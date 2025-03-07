#include "messagewindow.h"

MessageWindow::MessageWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Сообщения");
    setFixedSize(400, 250);  // Фиксированный размер окна

    textEdit = new QPlainTextEdit(this);
    textEdit->setReadOnly(true);  // Запрет редактирования
    textEdit->setGeometry(0, 0, 400, 250);  // Размер текстового поля
}

void MessageWindow::appendMessage(const QString &message) {
    textEdit->appendPlainText(message);  // Добавление сообщения
}
//void MessageWindow::appendMessage(const QString &message) {
  //  if (textEdit) {  // Проверка, что textEdit инициализирован
    //    textEdit->append(message);  // Добавление сообщения
    //} else {
      //  qDebug() << "Ошибка: textEdit не инициализирован!";
    //}
//}
