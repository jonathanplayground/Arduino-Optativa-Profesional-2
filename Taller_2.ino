/*
 * Taller 2 
 * control de iluminación de led con sensor fotoresistivo.
 */

const int sensorPin = A0;       //pin analogo para entrada de sensor
const int ledPin = 9;           //pin para salida, conexión a led

//variables del sensor  --> cuando el sensor esta tapado completamente la resistencia es máxima
int sensorValue = 0;      //valor de inicio de sensor
int sensorMin = 1023;      //valor mínimo del sensor --> 10 bits
int sensorMax = 0;        //valor máximo del sensor

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(13,HIGH);      //INDICADOR DE INICIO

  //CALIBRAR SENSOR DURANTE LOS PRIMEROS 10 SEGUNDOS --> modificado para mas segundos
  while(millis()<10000){
    sensorValue =analogRead(sensorPin);

    //grabar valor maximo del sensor
    if(sensorValue>sensorMax){
      sensorMax =sensorValue;
    }

    //Registrar valor minimo del sensor
    if(sensorValue<sensorMin){
      sensorMin=sensorValue;
    }
    analogWrite(ledPin,sensorValue);
    Serial.println(sensorValue);
  }
  //Señala el fin del periodo de calibración
    digitalWrite(13,LOW);
  Serial.println("Final!!!!!!!!!!!!!!!!!!!!!!!llllllllllllllllllllllllll");
}

void loop() {
  // Lectura de sensor
  sensorValue = analogRead(sensorPin);

  //aplica calibración a la lectura del sensor con comando map(mapeo) --> consultar comando map
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0,255);

  //si el sensor esta fuera de rango visto durante la calibración --> se restringe el valor del sensor a 0,255
  sensorValue = constrain(sensorValue,0,255);

  //atenuar led usando el valor calibrado  --> escribimos en la salida del pin 13 el "voltaje" suministrado al led
  analogWrite(ledPin,sensorValue);
  Serial.println(sensorValue);

}
