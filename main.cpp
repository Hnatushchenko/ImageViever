#include "imageviever.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageViever w;
    w.show();
    return a.exec();
}
