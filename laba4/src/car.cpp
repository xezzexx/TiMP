#include "head/car.h"

Car::Car(const string& n, const string& b, int y, int speed) : Transport(n, b, y), max_speed(speed) {}

void Car::show() const {
    Transport::show(); //вызов метода базового класса
    cout << "Максимальная скорость: " << max_speed << " (км/ч)" << endl;
    cout << " " << endl;
}

void Car::setSpeed(int speed) {
    max_speed = speed;
}