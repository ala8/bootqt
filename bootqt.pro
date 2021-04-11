QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/BForm/bform.cpp \
    src/BLineEdit/blineedit.cpp \
    src/BNav/bnav.cpp \
    src/BPushButton/bpushbutton.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/BForm/bform.h \
    src/BLineEdit/blineedit.h \
    src/BNav/bnav.h \
    src/BPushButton/bpushbutton.h \
    src/mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
