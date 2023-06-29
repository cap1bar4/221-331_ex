#include <QCoreApplication>
#include "singleton_metr.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "C:/temp/metricFile.txt";
    MeticRegister::getInstance()->init(filename);

    MeticRegister::getInstance()->add_metr(20,25);

    MeticRegister::getInstance()->show_mert();

    int key = 4;
    qDebug() << "Sum for key:" << key << "= "<< MeticRegister::getInstance()->coutn_cometr(key);

    return a.exec();
}
