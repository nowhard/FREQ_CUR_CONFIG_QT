#-------------------------------------------------
#
# Project created by QtCreator 2011-04-14T20:35:49
#
#-------------------------------------------------

QT       += core gui

TARGET = Threading
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    input_thread.cpp \
    output_thread.cpp \
    dialog_com.cpp \
    delegate.cpp \
    proto_uso.cpp


HEADERS  += mainwindow.h \
    input_thread.h \
    output_thread.h \
    dialog_com.h \
    delegate.h \
    proto_uso.h

FORMS    += mainwindow.ui \
    dialog_com.ui

INCLUDEPATH += ./serial_src/qserialdevice
INCLUDEPATH += ./serial_src/qserialdeviceenumerator

QMAKE_LIBDIR += ./libs
LIBS += -lqserialdevice\
        -lqserialdeviceenumerator
