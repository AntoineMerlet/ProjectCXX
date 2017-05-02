#-------------------------------------------------
#
# Project created by QtCreator 2017-01-27T13:14:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectCXX
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    baseimage.cpp \
    outputimage.cpp \
    imagedb.cpp

HEADERS  += mainwindow.h \
    baseimage.h \
    outputimage.h \
    imagedb.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    earth.jpg
