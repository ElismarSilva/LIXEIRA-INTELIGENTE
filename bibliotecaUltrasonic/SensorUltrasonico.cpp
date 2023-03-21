#include <SensorUltrasonico.h>
#include <Arduino.h>

SensorUltrasonico::SensorUltrasonico(int trigger, int echo)
{
  _echo = echo;
  _trigger = trigger;
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
}
double SensorUltrasonico::config()
{
  digitalWrite(_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigger, LOW);
}

double SensorUltrasonico::distanciaCM()
{
  config();
  double distancia;
  distancia = pulseIn(_echo, HIGH) / 58.2;

  return distancia;
}
double SensorUltrasonico::distanciaM()
{
  config();
  double _distancia = pulseIn(_echo, HIGH) / 58.2;
  double _distanciaM = _distancia / 100;

  return _distanciaM;
}

double SensorUltrasonico::distanciaPol()
{
  config();
  double _distanciaP = pulseIn(_echo, HIGH) / 58.2 / 2.540;
  return _distanciaP;
}
double SensorUltrasonico::distancia(char op)
{
  config();

  switch (op)
  {
  case 'c':
  case 'C':
    return distanciaCM();
    break;
  case 'm':
  case 'M':
    return distanciaM();
    break;
  case 'p':
  case 'P':
    return distanciaPol();
    break;
  default:
    return Serial.println("Opção invalida");
  }
}