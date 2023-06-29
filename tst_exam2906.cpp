#include <QtTest>
#include "singleton_metr.h"

// add necessary includes here

class exam2906 : public QObject
{
    Q_OBJECT

public:
    exam2906();
    ~exam2906();

private slots:
    //void test_add_metr();
    void test_coutn_cometr();

};

exam2906::exam2906()
{

}

exam2906::~exam2906()
{

}

//void exam2906::test_add_metr()
//{
//    QCOMPARE(true,MeticRegister::getInstance()->add_metr(105,5));
//}

void exam2906::test_coutn_cometr()
{
    QString filename = "C:/temp/metricFile.txt";
    MeticRegister::getInstance()->init(filename);

    QCOMPARE(25,MeticRegister::getInstance()->coutn_cometr(2));
    QCOMPARE(27,MeticRegister::getInstance()->coutn_cometr(3));
    QCOMPARE(29,MeticRegister::getInstance()->coutn_cometr(5));
    QCOMPARE(26,MeticRegister::getInstance()->coutn_cometr(4));
    QCOMPARE(25,MeticRegister::getInstance()->coutn_cometr(1));
    QCOMPARE(35,MeticRegister::getInstance()->coutn_cometr(6));
    QCOMPARE(42,MeticRegister::getInstance()->coutn_cometr(7));
    QCOMPARE(35,MeticRegister::getInstance()->coutn_cometr(8));
    QCOMPARE(31,MeticRegister::getInstance()->coutn_cometr(9));
    QCOMPARE(40,MeticRegister::getInstance()->coutn_cometr(9));
}


QTEST_APPLESS_MAIN(exam2906)

#include "tst_exam2906.moc"
