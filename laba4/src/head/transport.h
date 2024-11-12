#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transport {
    protected:
        string name; // название транспорта = свойство
        string brand; // марка = свойство
        int year; // год выпуска = свойство

    public:
        Transport(const string& n, const string& b, int y) : name(n), brand(b), year(y) {} // конструктор класса = метод
        virtual void show() const; // виртуальная функция (полиморфизм) + метод show()
        void setName(const string& n); // установка нового имени транспорта = метод
        void setBrand(const string& b); // установка бренда = метод
        int getYear() const; // возвращение года выпуска = метод
        virtual ~Transport() {}
};

#endif