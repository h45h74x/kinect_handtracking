#-------------------------------------------------
#
# Project created by QtCreator 2019-08-14T12:06:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kinect_Handtracking
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        kinect.cpp \
        main.cpp \
        mainwindow.cpp \
        myframe.cpp \
        tracker.cpp \
        viewport.cpp

HEADERS += \
        kinect.h \
        mainwindow.h \
        myframe.h \
        tracker.h \
        viewport.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../lib/release/ -lfreenect2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../lib/debug/ -lfreenect2
else:unix: LIBS += -L$$PWD/../../../../../../../../../lib/ -lfreenect2

INCLUDEPATH += $$PWD/../../lib/libfreenect2
DEPENDPATH += $$PWD/../../lib/libfreenect2

INCLUDEPATH += -I/usr/local/include/opencv4
LIBS += -L/usr/local/lib

DISTFILES +=
