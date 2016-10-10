QT += core
QT -= gui

TARGET = DoublyLinkedList
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Node.cpp \
    List.cpp

HEADERS += \
    node.h \
    list.h

