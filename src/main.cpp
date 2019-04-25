#include <QtWidgets/QApplication>
#include "BasicMotion.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    if (argc == 1)
    {
      BasicMotion basicmotion;
      basicmotion.show();
      return app.exec();
    }
    else
    {
      printf("Error: Incorrect number of parameters\nUsage: ./basicmotion\n");
      return 1;
    }
}
