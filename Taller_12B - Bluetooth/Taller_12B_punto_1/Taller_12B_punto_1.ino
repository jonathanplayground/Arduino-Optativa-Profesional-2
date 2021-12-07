/*
 * Uso módulo bluetooth HC06, comandado por monitor serial
 * Encendido y apagado de diodos led según la tecla ingresada
 * También se puede conectar a otro dispositivo bluetooth y enviar letra para control de encendido y apagado de diodos
 */

#include <SoftwareSerial.h>                       //libreria necesaria para utilizar pines diferentes al 0 y 1 como TX y RX

//pines de RX y TX 
SoftwareSerial miBT(10 , 11);                     //pin 10 ->RX; pin 11->TX 


char rxChar = 0;                                  // Variable para recibir datos del puerto serie
int ledpin = 9;                                   // Pin donde se encuentra conectado el led (pin 13)
int power = 12;


void setup(){
  pinMode(power,OUTPUT);
  digitalWrite(power,HIGH);
  delay(100);
  miBT.begin(9600);
  Serial.begin(9600);  
}


void loop(){
  
  if(Serial.available())
  {
    Serial.println("Dato ingresado");
    rxChar = Serial.read();
    if( rxChar == 'A' )                         // Procesar comando de un solo byte, verificar si el dato ingresado es igual al requerido
    {
      digitalWrite(ledpin, HIGH);
      Serial.println("Diodo encendido");
    }
    else if ( rxChar == 'a' )
    {
      digitalWrite(ledpin, LOW);
      Serial.println("Diodo apagado");
    }
    //miBT.write(Serial.read());
  }

  // Si hay datos disponibles en el buffer   -> lee arduino y envia a BT
  if(miBT.available())                         // available -> devuelve verdadero cuando hay datos disponibles en el monitor serial.
  {
    rxChar = miBT.read();                     // Leer un byte y colocarlo en variable.
    if( rxChar == 'A' )                         // Procesar comando de un solo byte, verificar si el dato ingresado es igual al requerido
    {
      digitalWrite(ledpin, HIGH);
      Serial.println("Diodo encendido");
    }
    else if ( rxChar == 'a' )
    {
      digitalWrite(ledpin, LOW);
      Serial.println("Diodo apagado");
    }
  }
  // Podemos hacer otras cosas aquí
  delay(100);
 
}

  
