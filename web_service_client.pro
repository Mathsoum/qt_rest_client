QT += core network
QT -= gui

CONFIG += c++11

TARGET = web_service_client
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myclient.cpp

HEADERS += \
    myclient.h
