#-------------------------------------------------
#
# Project created by QtCreator 2019-05-27T14:28:32
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI_Tank
TEMPLATE = app

LIBS += -L/opt/qt5pi/sysroot/usr/lib/ -lwiringPi



# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        c_tcpserver.cpp \
        main.cpp \
        w_mainwindow.cpp \
        w_menudejeu.cpp \
        w_options.cpp

HEADERS += \
        c_tcpserver.h \
        w_mainwindow.h \
        w_menudejeu.h \
        w_options.h

FORMS += \
        w_mainwindow.ui \
        w_menudejeu.ui \
        w_options.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
