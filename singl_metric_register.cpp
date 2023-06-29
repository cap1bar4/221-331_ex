#include "singleton_metr.h"

MeticRegister::MeticRegister()
{

}


MeticRegister::~MeticRegister()
{

}


bool MeticRegister::add_metr(int resp_t, int wait_t)
{
    massiv_map.insert(massiv_map.size() + 1, qMakePair(resp_t,wait_t));
    return 1;
}

bool MeticRegister::show_mert() //вывести на экран все значения, упорядоченные по ключу
{
    bool flag;
    for (QMap<int, QPair<int,int>>::iterator iterator = massiv_map.begin(); iterator != massiv_map.end(); ++iterator)
    {
        qDebug() << "Key:" << iterator.key() << "Values:" << iterator.value().first << iterator.value().second;
    }
}

int MeticRegister::coutn_cometr(int key) //вычислить вспомогательную метрику
{
    if (massiv_map.contains(key))
    {
        QPair<int,int> values_map = massiv_map.value(key);
        int number1 = values_map.first;
        int number2 = values_map.second;
        int sum = number1 + number2;
        return sum;
    }
    else
    {
        qDebug() << "Key is not in QMap";
        return 0;
    }
}

void MeticRegister::init(QString filename) //загрузить метрики из файла
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error open file";
    }
    QTextStream in(&file); //поток для работы с файлом

    while (!in.atEnd()) {
        QString stroka = in.readLine();
        QStringList split_line = stroka.split(',');
        int key = split_line[0].toInt();

        int number1 = split_line[1].toInt();
        int number2 = split_line[2].toInt();
        massiv_map.insert(key, qMakePair(number1, number2)); //созданный QMap
    }
    qDebug() << massiv_map;
}

MeticRegister* MeticRegister::p_instance;
MeticRegister_Destroyer MeticRegister::destroyer;
