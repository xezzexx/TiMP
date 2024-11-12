#include "head/airplane.h"

Airplane::Airplane(const string& n, const string& b, int y, int weight) : Transport(n, b, y), weight_transport(weight) {}

void Airplane::show() const {
    Transport::show(); //вызов метода базового класса
    cout << "Вес транспорта: " << weight_transport << " (тн)" << endl;
    cout << " " << endl;
}

void Airplane::setWeight(int weight) {
    weight_transport = weight;
}