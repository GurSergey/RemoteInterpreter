#-------------------------------------------------
#
# Project created by QtCreator 2016-02-01T20:59:44
#
#-------------------------------------------------

QT       += core gui script serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    keyboardcontrol.cpp \
    messagescr.cpp \
    signals.cpp \
    mousecontrol.cpp \
    screen.cpp \
    processsnapshot.cpp \
    serialport.cpp \
    controlprogram.cpp \
    timerscript.cpp

HEADERS  += mainwindow.h \
    keyboardcontrol.h \
    messagescr.h \
    signals.h \
    mousecontrol.h \
    screen.h \
    processsnapshot.h \
    serialport.h \
    controlprogram.h \
    timerscript.h

FORMS    += mainwindow.ui


LIBS     += libgdi32 -lpsapi

RESOURCES += \
    images.qrc
