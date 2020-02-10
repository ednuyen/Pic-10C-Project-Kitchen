#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //SecondWindow w2;
    //w2.show();
    w.show();

    return a.exec();
}
