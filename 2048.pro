#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T02:15:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    Cube.cpp

HEADERS  += mainwindow.h \
    form.h \
    Cube.h

FORMS    += mainwindow.ui \
    form.ui
