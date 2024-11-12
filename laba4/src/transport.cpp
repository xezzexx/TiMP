#include "head/transport.h"

void Transport::show() const {
    cout << "Наименование транспорта: " << name << endl;
    cout << "Марка: " << brand << endl;
    cout << "Год выпуска: " << year << endl;
}

void Transport::setName(const string& n) {
    name = n;
}

void Transport::setBrand(const string& b) {
    brand = b;
}

int Transport::getYear() const {
    return year;
}