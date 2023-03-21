#ifndef SENSORULTRASONICO_H_INCLUDED
#define SENSORULTRASONICO_H_INCLUDED

class SensorUltrasonico
{

public:
  SensorUltrasonico(int trigger, int echo);
  double distanciaCM();
  double distanciaM();
  double distanciaPol();
  double distancia(char op);
  double config();

private:
  int _trigger;
  int _echo;
};

#endif // SENSORULTRASONICO_H_INCLUDED
