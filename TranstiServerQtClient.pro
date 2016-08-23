#-------------------------------------------------
#
# Project created by QtCreator 2015-04-20T14:58:35
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TranstiServerQtClient
TEMPLATE = app


SOURCES += main.cpp\
        tsclient.cpp \
    waypointpassageparser.cpp \
    tablepassagemodel.cpp

HEADERS  += tsclient.h \
    waypointpassageparser.h \
    tablepassagemodel.h
