// Biblioteca  - Ultrasonic  HR-SC04.
// 28 - 08 - 2022.
// Elismar. S ( https://github.com/ElismarSilva )


#include <SensorUltrasonico.h>

SensorUltrasonico ultrasonico(9,8); // (pin Trig,pino Echo)

void setup() {
  Serial.begin(9600); 
}

void loop()
{
  Serial.print(ultrasonico.distanciaPol()); // Distancia em polegadas
  Serial.println(" pol" );
  delay(100);
}
