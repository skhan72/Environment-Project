#include <LiquidCrystal.h>

 int LED3 = 9;
 int LED2= 13;
 int LED1 = 10;
int ThermistorPin = 0;
int Vo;
int brightness = 100;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
Serial.begin(9600);
pinMode (LED3, OUTPUT);
pinMode (LED2, OUTPUT);
pinMode (LED1, OUTPUT);

}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 

  lcd.print("Temp = ");
  lcd.print(T);   
  lcd.print(" F");
  
  if (T < 32) {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED3, HIGH);
  } 
   if (T >= 32 && T < 80){
    digitalWrite (LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);

  }
  else {
    digitalWrite (LED3, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);
  }
  
  delay(500);            
  lcd.clear();

}


