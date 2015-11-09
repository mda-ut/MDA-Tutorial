#-------------------------------------------------
#
# Project created by QtCreator 2015-11-09T14:52:16
#
#-------------------------------------------------

#QT       += core

#QT       -= gui

TARGET = VisionTut1

LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_video \
-lopencv_videoio \
-lopencv_imgcodecs

#CONFIG   += console
#CONFIG   -= app_bundle

#TEMPLATE = app


SOURCES += main.cpp
