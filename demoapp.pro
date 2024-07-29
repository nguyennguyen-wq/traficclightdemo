TEMPLATE = app
TARGET = Demoapp

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    circlelabel.h \
    mainwindow.h
