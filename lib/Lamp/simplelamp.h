#include<Arduino.h>

#ifndef simplelamp
#define simplelamp

class SimpleLamp
{
private:
    bool state;
    int pin;
    /* data */
public:
    SimpleLamp(int pin);
    ~SimpleLamp();
    bool getState();
    void setState(bool state);
    void setPin(int pin);
};

#include "simplelampimpl.h"
#endif
