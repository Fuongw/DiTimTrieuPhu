QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Cấu hình chuẩn cho ứng dụng giao diện (GUI) trên Windows
win32 {
    CONFIG += windows
}

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/GameController.cpp

HEADERS += \
    include/mainwindow.h \
    include/GameController.h \
    include/Question.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += $$PWD/include

DISTFILES += \
    data/pixel_font.ttf \
    data/questions_easy.txt \
    data/questions_hard.txt \
    images/cat.gif \
    images/cat_hoi.gif \
    images/cat_mc.gif