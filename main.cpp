#include "metasysteam.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    metasysteam w;
    w.show();
    return a.exec();
}
