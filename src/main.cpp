#include <Arduino.h>
#include <Wire.h>
#include "simplelamp.h"
#include "RTClib.h"
#include <SPI.h>

SimpleLamp *lamp;
int data = 0;
int watt;
char logString[20];
RTC_DS3231 rtc;
DateTime now;
DateTime lastOn;
TimeSpan span;


void requestEvent(){

    span = now - lastOn;
    watt = span.days()*24 + span.hours() * 5;
    sprintf(logString, "%04d-%02d-%02d %02d:%02d:%02d", now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second());
    Wire.write(watt);
    Wire.write(logString);
    

}

void receiveEvent(int howmany) {
  
  data = Wire.read();
  lamp->setState(data);
  if(data == 1){
    lastOn = now;
  }
}


void setup() {
  Serial.begin(115200);
  lamp = new SimpleLamp(8);
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  rtc.begin();  // Initialize the RTC module
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Optionally set the current time
}

void loop() {
  // put your main code here, to run repeatedly:
  now = rtc.now();
  delay(1000);
}
