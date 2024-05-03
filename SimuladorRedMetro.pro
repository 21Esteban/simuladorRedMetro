TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        estacion.cpp \
        linea.cpp \
        main.cpp \
        menu.cpp \
        red.cpp

HEADERS += \
    ArrayDinamico.h \
    estacion.h \
    linea.h \
    menu.h \
    red.h
