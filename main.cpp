#include "tsclient.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    TSClient w;
    w.show();

    return a.exec();
}
