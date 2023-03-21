/*
   *Esse programa faz a com que uma lixeira abra a tampa caso alguem aproxime as maos do sensor ultrasonic.
   *Elismar. S (Cientista da Computação).
   *Github(https://github.com/ElismarSilva).
   *28/08/2022.
*/

#include <SensorUltrasonico.h> // Inclusao das bibliotecas 
#include <Servo.h>

#define echo 8 // Definindo os pinos
#define trigger 9
Servo motor; //nomeando o servo
SensorUltrasonico dist(trigger, echo); // instancia o ojeto e passa os parametros pinos

void setup() {
  Serial.begin(9600);
  motor.attach(2);
  motor.write(70); // inicia o servo na posicao 70 graus
  delay(10);// aguarda dez milisegundos
}

void loop() {
  double distancia_cm =  dist.distanciaCM(); // cria uma variavel para receber a funcao distancia em centimetros
  //double distancia_pol =  dist.distanciaPol();
  Serial.print("CM: ");
  Serial.println(distancia_cm); //leitura do serial
  //Serial.print("  || Polegadas : ");
  //Serial.println(distancia_pol);

  if (distancia_cm <= 10  ) { //  Verifica  se a distancia em centimetros e menor que
    motor.write(125); // Graus do servo em 125 graus
    delay(2000); // Aguarda dois segundos
    motor.write(70); //Servo na posicao 70 graus

  }


}
