#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumSize(400, 200);
    w.setWindowFlags(Qt::Window | Qt::WindowFullscreenButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint);
    w.show();
    return a.exec();
}
