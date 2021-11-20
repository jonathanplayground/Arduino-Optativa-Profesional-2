/*
 * Sentencia switch
 * 
 * Permite escoger de un conjunto de valores discretos de una variable, similar a la sentencia utilizada en if
 * Utilizado con fotoresistencia
 */

const int sensorMin = 0;
const int sensorMax = 600;
int sensorLectura = 0;


int sensorPin = A0; 
int led = 12;

void setup() {
  Serial.begin(9600);
  pinMode(12,OUTPUT);
}

void loop() {
  sensorLectura = analogRead(sensorPin);
  int range = map(sensorLectura, sensorMin, sensorMax, 0,3);        //mapea el rango del sensor en 4 opciones --> de 0 a 3 (PERO QUEDA UN RANGO DE 0-5)

  //Dependiendo del valor obtenido en el rango realiza una acción.
  switch(range)
  {
    case 0: 
      Serial.println("Oscuro");
      
      break;
    case 1:
      Serial.println("Dimmer");
      
      break;
    case 2:
      Serial.println("Medio");
    
      break;
    case 3:
      Serial.println("Brillante");
      break;
  }
  analogWrite(led, sensorLectura);            //la salida debe ser analogica, para variar el nivel de intensidad sobre el LED
  Serial.print("Sensor: ");
  Serial.println(sensorLectura);
  Serial.print("Rango: ");
  Serial.println(range);                                                                                                                                                                                                                                                                                                                                                                                                                                                    
  delay(1000);             //retardo para dar estabilidad.

  
}
