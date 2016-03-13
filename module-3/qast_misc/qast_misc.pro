QT += core network
QT -= gui

CONFIG += c++11

TARGET = qast_misc
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    qast.cpp

HEADERS += \
    qast.h
