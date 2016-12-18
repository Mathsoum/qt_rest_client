#include <QCoreApplication>

#include "myclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClient myClient;
    myClient.sendRequest("1.2.0");

    return a.exec();
}
