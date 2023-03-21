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
  Serial.print(ultrasonico.distancia('c')); // Escolha ->> 'c'('C')centimetros: 'm'('M'): metros: 'p'('P'): polegadas.
  Serial.println(" cm" );
  delay(100);
}
