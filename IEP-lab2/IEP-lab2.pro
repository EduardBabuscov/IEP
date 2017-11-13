#-------------------------------------------------
#
# Project created by QtCreator 2017-10-16T16:21:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IEP-lab2
TEMPLATE = app
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

SOURCES += main.cpp\
        mainwindow.cpp \
    bcm2835.c \
    pwm.cpp \
    pin.cpp \
    spi.cpp \
    serial.cpp

HEADERS  += mainwindow.h \
    bcm2835.h \
    pin.hpp \
    pwm.hpp \
    serial.hpp \
    spi.hpp

FORMS    += mainwindow.ui
