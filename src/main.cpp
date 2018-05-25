#include <QtWidgets/QApplication>
#include "BasicMotion.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    BasicMotion basicmotion;
    basicmotion.show();
    return app.exec();
}
