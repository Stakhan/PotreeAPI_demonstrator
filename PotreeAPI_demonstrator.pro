######################################################################
# Automatically generated by qmake (3.1) Wed Feb 24 09:41:17 2021
######################################################################

TEMPLATE = app
TARGET = demo
INCLUDEPATH += .

QT += widgets
QT += webenginewidgets
QT += core websockets

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += mainwidget.h APIWebsockets.h
SOURCES += main.cpp mainwidget.cpp APIWebsockets.cpp
