#include <QtWidgets/QApplication>
#include "BasicMotion.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    if (argc == 2)
    {
      BasicMotion basicmotion(atoi(argv[1]));
      basicmotion.show();
      return app.exec();
    }
    else
    {
      printf("Error: Incorrect number of parameters\nUsage: ./basicmotion camId\n");
      return 1;
    }
}
