TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    mystacks.cpp \
    tests.cpp

HEADERS += \
    mystacks.h \
    catch.hpp

win32 {
    QMAKE_CXXFLAGS += -Wa,-mbig-obj
}
