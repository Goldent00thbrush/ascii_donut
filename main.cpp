#include "mainwindow.h"
#include "donut.cpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    donut d; //our object
    QApplication a(argc, argv); //actual UI window
    MainWindow w;
    w.show();
    return a.exec();
}

