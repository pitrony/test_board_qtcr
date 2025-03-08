#ifndef MESSAGEDECODER_H
#define MESSAGEDECODER_H

#include <QMap>
#include <QString>

class MessageDecoder
{
public:
    MessageDecoder();

    QString decodeMessage(const QString &id, const QString &data) const;  // Дешифровка сообщения

private:
    QMap<QString, QString> messageTable;  // Таблица значений для дешифровки
};

#endif // MESSAGEDECODER_H

/*

#ifndef MESSAGEDECODER_H
#define MESSAGEDECODER_H

#include <QString>
#include <QMap>

class MessageDecoder
{
public:
    MessageDecoder();

    QString decodeMessage(const QByteArray &data) const;  // Дешифровка сообщения

private:
    QMap<int, QString> floorMap;  // Таблица для дешифровки этажей
    QMap<int, QString> directionMap;  // Таблица для дешифровки направления
    QMap<int, QString> doorMap;  // Таблица для дешифровки состояния дверей
};

#endif // MESSAGEDECODER_H
*/
