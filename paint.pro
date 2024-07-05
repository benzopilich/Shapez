QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    figure.cpp \
    main.cpp \
    mas.cpp \
    oval.cpp \
    paint.cpp \
    paintscene.cpp \
    romb.cpp \
    square.cpp

HEADERS += \
    figure.h \
    mas.h \
    oval.h \
    paint.h \
    paintscene.h \
    romb.h \
    square.h

FORMS += \
    paint.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
