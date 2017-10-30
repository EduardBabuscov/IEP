#-------------------------------------------------
#
# Project created by QtCreator 2017-10-16T16:21:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IEP-lab2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bcm2835.c \
    Pin.cpp \
    pwm.cpp

HEADERS  += mainwindow.h \
    bcm2835.h \
    pin.hpp \
    pwm.hpp

FORMS    += mainwindow.ui
