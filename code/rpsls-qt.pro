QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logic/game.cpp \
    logic/moves/lizard.cpp \
    logic/moves/paper.cpp \
    logic/moves/rock.cpp \
    logic/moves/scissors.cpp \
    logic/moves/spock.cpp \
    logic/rock.cpp \
    main.cpp \
    rpsls.cpp \
    ui/mainwindow.cpp

HEADERS += \
    logic/game.h \
    logic/move.h \
    logic/moves/lizard.h \
    logic/moves/paper.h \
    logic/moves/rock.h \
    logic/moves/scissors.h \
    logic/moves/spock.h \
    logic/rock.h \
    rpsls.h \
    ui/mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
