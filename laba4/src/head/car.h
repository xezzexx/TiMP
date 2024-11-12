#ifndef CAR_H
#define CAR_H

#include "transport.h"

class Car : public Transport {
    private:
        int max_speed;

    public:
       Car(const string& n, const string& b, int y, int speed);
       void show() const override; // переопределение виртуальной функции
       void setSpeed(int speed); 
};

#endif