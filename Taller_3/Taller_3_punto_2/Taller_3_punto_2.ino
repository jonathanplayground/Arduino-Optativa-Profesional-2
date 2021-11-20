/*
 * Sentencia de if Condicional
 * 
 * Se lee el estado de un potenciometro(entrada análoga) y enciende un led conectado en el pin 13
 * Si el valor leido está por encima del umbral, imprime el valor leido sin importarsu nivel
 */

int led = 13;             //LED de salida
int sensorPin = A0;        // entrada de potenciometro
int analogValue = 0;

const int thresHold = 400;      //Nivel arbitrario de comparación en el rango de la seña de entrada

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600); 
  digitalWrite(led, LOW);
}

void loop() {
  analogValue = analogRead(sensorPin);
  if(analogValue>thresHold)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  Serial.println(analogValue);
  delay(1);
}
