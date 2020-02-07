#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(400, 50, 1200, 950);
    QPalette pal = w.palette();
    pal.setColor(QPalette::Window, Qt::black);
    w.setPalette(pal);
    w.show();

    return a.exec();
}
