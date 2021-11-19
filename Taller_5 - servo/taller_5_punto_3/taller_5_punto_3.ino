/*
 * Control servo con libreria
 * red     -> 5V
 * brown   -> GND
 * orange  -> PWM
 */

#include<Servo.h>

Servo servo1;
int angulo = 0;
int pot = A0;
int lectura;
int regulador;

void setup() {
  servo1.attach(9);             // Conectar servo1 al pin 9 (además del Vcc y GND)
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(pot);
  //angulo = lectura*180/1024;                          //presenta fallas, entrega valores negativos y el servo no responde              
  angulo = map(analogRead(pot), 0, 1024, 90, 180);       //map(dato, valormínimo entrada, valor maximo entrada, valor minimo enviado, valor maximo enviado)
  Serial.println(angulo);                               //verificación de grados por monitor serial
  servo1.write(angulo);
  delay(100);

}
