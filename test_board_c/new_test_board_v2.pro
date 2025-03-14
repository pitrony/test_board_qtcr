QT += core gui serialbus serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Подключение Paho MQTT
#LIBS += -lpaho-mqttpp3 -lpaho-mqtt3a
#INCLUDEPATH += "C:/Qt/pahomqttcpp-master/include/mqtt" # Укажите путь к заголовочным файлам Paho MQTT

# Подключение CAN (SocketCAN для Linux или PCAN для Windows)
#unix: LIBS += -lsocketcan  # Для Linux
#win32: LIBS += -L"C:/path/to/pcan/lib" -lPCANBasic  # Для Windows
#unix: INCLUDEPATH += /usr/include  # Для Linux
#win32: INCLUDEPATH += "C:/path/to/pcan/include"  # Для Windows

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    messagewindow.cpp \
    messdecoder.cpp

HEADERS += \
    mainwindow.h \
    messagewindow.h \
    messdecoder.h

TRANSLATIONS += \
    new_test_board_v2_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += C:/Qt/6.5.2/Src/qtserialbus/src/serialbus

RESOURCES += \
    resurce.qrc
