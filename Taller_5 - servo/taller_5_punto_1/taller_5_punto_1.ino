/*
 * Control servo con libreria
 * red     -> 5V
 * brown   -> GND
 * orange  -> PWM
 */

#include<Servo.h>
int angulo = 0;
Servo servo1;

void setup() {
  servo1.attach(9);             // Conectar servo1 al pin 9 (además del Vcc y GND)
}

void loop() {
  for(angulo = 0;angulo<=180; angulo++)
  {
    servo1.write(angulo);
    delay(25);
  }
  for(angulo = 180;angulo >= 0; angulo--)
  {
    servo1.write(angulo);
    delay(25);
  }

}
