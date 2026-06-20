#include "mainwindow.h"

#include <QApplication>

// Workaround for __imp___argc linking issue with Qt6EntryPoint
//extern "C" void* __imp___argc;
//extern "C" void* __imp___argv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
