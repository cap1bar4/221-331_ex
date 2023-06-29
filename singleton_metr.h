#include <QCoreApplication>
#include <QVariant>

#include <QFile>
#include <QMap>
#include <QDebug>
#include <QTextStream>

class MeticRegister;

class MeticRegister_Destroyer
{
private:
    MeticRegister * p_instance;
public:
    ~MeticRegister_Destroyer() { delete p_instance;}
    void initialize(MeticRegister * p){p_instance = p;}
};


class MeticRegister
{
private:
    static MeticRegister * p_instance; // Статик - память не выделяется классом, единственный экземлпяр
    static MeticRegister_Destroyer destroyer;
protected:
    MeticRegister();
    MeticRegister(const MeticRegister& );
    MeticRegister& operator = (MeticRegister &);
    ~MeticRegister();
    friend class MeticRegister_Destroyer;
public:
    bool add_metr(int resp_t, int wait_t);//добавление метрики
    bool show_mert();//вывести на экран все значения, упорядоченные по ключу
    int coutn_cometr(int key);//вычислить вспомогательную метрику: возвращает сумму времени ожидания и времени отклика для данного ключа.
    void init(QString filename);//загрузить метрики из файла
    QMap <int, QPair<int,int>> massiv_map;

    static MeticRegister *getInstance(){
        if (!p_instance)
        {
            p_instance = new MeticRegister();
            destroyer.initialize(p_instance); // Присваивание ссылки на синглтн в Destroyer
        }
        return p_instance;
    }
};
