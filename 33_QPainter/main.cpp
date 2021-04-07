#include "painterdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PainterDialog w;
    w.show();
    return a.exec();
}
