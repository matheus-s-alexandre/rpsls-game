#include "rpsls.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RPSLS w;
    w.show();
    return a.exec();
}
