QT += core
QT -= gui

CONFIG += c++11

TARGET = chkenv_qt
CONFIG += console
CONFIG -= app_bundle

LIBS += -lmagic

TEMPLATE = app

SOURCES += main.cpp \
    qast.cpp

HEADERS += \
    qast.h
