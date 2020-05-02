#include "interfaceserie.h"
#include <iostream>
#include <libusb.h>
#include "rs232.h"
#include <QtCharts>
#include <QApplication>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InterfaceSerie w;
    w.show();
    a.setWindowIcon(QIcon("./eltlogo.png"));
    return a.exec();
}
