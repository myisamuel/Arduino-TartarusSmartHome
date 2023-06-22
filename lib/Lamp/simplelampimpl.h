SimpleLamp::SimpleLamp(int pin)
{
    this->pin = pin;
}

SimpleLamp::~SimpleLamp()
{
    
}

bool SimpleLamp::getState(){
    return this->state;
}

void SimpleLamp::setState(bool state){
    this->state = state;
    pinMode(this->pin,this->state);
}

void SimpleLamp::setPin(int pin){
    this->pin = pin;
}