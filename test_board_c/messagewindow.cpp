/*
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

*/

#include "messagewindow.h"

MessageWindow::MessageWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Сообщения");
    setFixedSize(400, 300);  // Фиксированный размер окна

    // Создаем модель данных
    model = new QStandardItemModel(this);
    model->setColumnCount(2);  // Два столбца: ID и сообщение
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Сообщение");


    // Создаем таблицу и связываем её с моделью
    tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->setGeometry(0, 0, 400, 300);  // Размер таблицы
   //tableView->resizeColumnsToContents();

    tableView->setColumnWidth(1, 260);
   // tableView->resizeRowsToContents();
}

/*

void MessageWindow::appendMessage(const QByteArray &data) {
    // Дешифруем сообщение
    QString decodedMessage = decoder.decodeMessage(data);

    // Добавляем новую строку в таблицу
    QList<QStandardItem*> rowItems;
    rowItems << new QStandardItem(decodedMessage);  // Дешифрованное сообщение
    model->appendRow(rowItems);




*/
void MessageWindow::appendMessage(const QString &id, const QString &data) {
    // Дешифруем сообщение
    QString decodedMessage = decoder.decodeMessage(id, data);

    // Добавляем новую строку в таблицу
    QList<QStandardItem*> rowItems;
    rowItems << new QStandardItem(id);            // ID сообщения
    rowItems << new QStandardItem(decodedMessage);  // Дешифрованное сообщение
    model->appendRow(rowItems);

    // Прокручиваем таблицу к последней строке
    tableView->scrollToBottom();
}
