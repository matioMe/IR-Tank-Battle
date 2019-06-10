#include "w_mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    W_MainWindow w;
    w.show();

    return a.exec();
}

