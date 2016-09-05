#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T14:57:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dbmsmidsem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    newwindow.cpp \
    database.cpp \
    dialog1.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    newwindow.h \
    database.h \
    common.h \
    dialog1.h

FORMS    += mainwindow.ui \
    dialog.ui \
    newwindow.ui \
    dialog1.ui
QT += sql
