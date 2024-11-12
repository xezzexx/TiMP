#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "transport.h"

class Airplane : public Transport {
    private:
        int weight_transport;

    public:
       Airplane(const string& n, const string& b, int y, int weight);
       void show() const override; // переопределение виртуальной функции
       void setWeight(int weight); 
};

#endif