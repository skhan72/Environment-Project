
int temperaturePin= 0;

void setup()

{

Serial.begin(9600);
}

Void loop()

{

float temperature = getVoltage(temperaturePin);

temperature = (temperature - .5)*100;

Serial.println(temperature);

delay(2000);

}

float getVoltage(int Pin){

return (analogRead(Pin)*.004882814);

}