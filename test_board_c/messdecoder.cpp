#include "messdecoder.h"

MessageDecoder::MessageDecoder() {
    // Заполняем таблицу значений (пример для модели лифта 1)
    messageTable["0x100:0x100"] = "Лифт на этаже: 1";
    messageTable["0x100:0x101"] = "Лифт на этаже: 2";
    messageTable["0x100:0x102"] = "Лифт на этаже: 3";
    messageTable["0x100:0x200"] = "Нажата кнопка: Вверх";
    messageTable["0x100:0x201"] = "Нажата кнопка: Вниз";
    // Добавьте другие значения в зависимости от модели лифта
}

QString MessageDecoder::decodeMessage(const QString &id, const QString &data) const {
    // Дешифруем сообщение на основе ID и данных
    QString key = id + ":" + data;  // Пример ключа: "0x100:0x100"
    if (messageTable.contains(key)) {
        return messageTable[key];  // Возвращаем дешифрованное сообщение
    }
    return "Неизвестное сообщение: ID=" + id + ", Data=" + data;  // Если сообщение не найдено в таблице
}

/*
#include "messagedecoder.h"

MessageDecoder::MessageDecoder() {
    // Заполняем таблицу для дешифровки этажей
    floorMap[2] = "Car is at 3rd floor";

    // Заполняем таблицу для дешифровки направления
    directionMap[0x19] = "Next stop direction is UP, current travelling direction is DOWN";

    // Заполняем таблицу для дешифровки состояния дверей
    doorMap[0x12] = "Front door is closing";
}

QString MessageDecoder::decodeMessage(const QByteArray &data) const {
    QString message;

    // Дешифровка этажа (первый байт)
    int floorValue = static_cast<unsigned char>(data[0]);
    if (floorMap.contains(floorValue)) {
        message += floorMap[floorValue] + "\n";
    }

    // Дешифровка состояния дверей (первый байт)
    if (doorMap.contains(floorValue)) {
        message += doorMap[floorValue] + "\n";
    }

    // Дешифровка направления (четвертый байт)
    int directionValue = static_cast<unsigned char>(data[4]);
    if (directionMap.contains(directionValue)) {
        message += directionMap[directionValue] + "\n";
    }

    // Дешифровка текста на дисплее (второй и третий байты)
    QString displayText = QString("%1%2").arg(char(data[2])).arg(char(data[3]));
    message += "Display is showing: " + displayText + "\n";

    return message;
}

*/
