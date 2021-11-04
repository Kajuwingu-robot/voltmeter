#include <LiquidCrystal.h>

const char sensorPin = A0; // select the input pin for the potentiometer
int ledPin = 13; // select the pin for the LED
float sensorValue = 0; // variable to store the value coming from the sensor
int ii = 0;
float som = 0;
float msom = 0;
class Killi
{
public:
float vl[10] ;
int f_vl = 0;
long tmp = 0;
long delta;
// long get_delta(){ return (this->delta); }
// int set_delta(long x){ this->delta=x; return (0); }
};

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Killi a0;

void setup() {
lcd.begin(16, 2);
pinMode(ledPin, INPUT);
Serial.begin(9600);
a0.tmp = millis();
}


void loop()
{

//a0.tmp = millis();

int sensorValue = analogRead(A0);
float voltage = sensorValue * (5.0 / 1023.0);

for (ii = 10; ii > 0; ii--)
{
a0.vl[ii] = a0.vl[ii - 1];
Serial.println(a0.vl[ii]);
}
Serial.println("............. tablo");

a0.vl[0] = voltage;

for (ii = 0; ii < 10; ii++)
{
som = som + a0.vl[ii];
}
msom = som / 10;
Serial.println(float(msom - voltage));
Serial.println("............. moyenne ");

if (abs(float(msom - voltage)) < .05)
{
Serial.println("--------");
Serial.println(voltage);
Serial.println(float(msom - voltage));
lcd.setCursor(0, 1);
lcd.print("Acquis ........");
lcd.setCursor(0, 0);
lcd.print(double(voltage));
}
else
{
lcd.setCursor(0, 1);
lcd.print("Non acquis ...");
lcd.setCursor(0, 0);
lcd.print(0.0);
}

som=msom=0;
//msom = 0;




// lcd.print("sensorValue");
// lcd.setCursor(16, 1);
// lcd.autoscroll();
// lcd.noAutoscroll();
// lcd.clear();

//delay(100);
}



/*
LiquidCrystal Library - Autoscroll

Demonstrates the use a 16x2 LCD display. The LiquidCrystal
library works with all LCD displays that are compatible with the
Hitachi HD44780 driver. There are many of them out there, and you
can usually tell them by the 16-pin interface.

This sketch demonstrates the use of the autoscroll()
and noAutoscroll() functions to make new text scroll or not.

The circuit:
LCD RS pin to digital pin 12
LCD Enab
le pin to digital pin 11
LCD D4 pin to digital pin 5
LCD D5 pin to digital pin 4
LCD D6 pin to digital pin 3
LCD D7 pin to digital pin 2
LCD R/W pin to ground
10K resistor:
ends to +5V and ground
wiper to LCD VO pin (pin 3)


*/
