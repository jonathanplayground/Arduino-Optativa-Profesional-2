/*
 * Uso módulo bluetooth HC06, comandado por monitor serial
 * 
 * Encendido y apagado de diodos led según la tecla ingresada
 */

#include <SoftwareSerial.h>         //libreria necesaria para utilizar pines diferentes al 0 y 1 como TX y RX

//pines de RX y TX 
SoftwareSerial miBT(10 , 11);      //pin 10 ->RX; pin 11->TX 

int power = 12;

char rxChar = 0;                                  // Variable para recibir datos del puerto serie
int ledpin1 = 9;                              // Pin donde se encuentra conectado el led (pin 9)
int ledpin2 = 8;
int ledpin3 = 7;
int ledpin4 = 6;
int ledpin5 = 5;


void setup(){
  for(int i = 9; i>4; i--)
  {
    pinMode(i,OUTPUT);            //Pines declarados como salida
  }
  pinMode(power,OUTPUT);
  digitalWrite(power,HIGH);
  delay(100);
  miBT.begin(9600);
  Serial.begin(9600);                      // Comunicación serie a 9600 baudios
}



void loop(){

if(miBT.available())
{
  rxChar = miBT.read();
  if( rxChar == 'A' )                         // Procesar comando de un solo byte, verificar si el dato ingresado es igual al requerido
    {
      digitalWrite(ledpin1, HIGH);
      Serial.println("Salida 1 encendido");
    }
    else if ( rxChar == 'a' )
    {
      digitalWrite(ledpin1, LOW);
      Serial.println("Salida 1 apagado");
    }
  ////////////////  led2
  if( rxChar == 'B' )                          
  {
    digitalWrite(ledpin2, HIGH);
    Serial.println("Salida 2 encendida");
  }
  else if ( rxChar == 'b' )
  {
    digitalWrite(ledpin2, LOW);
    Serial.println("Salida 2 apagada");
  }
  ////////////////  led3
  if( rxChar == 'C' )                          
  {
    digitalWrite(ledpin3, HIGH);
    Serial.println("Salida 3 encendida");
  }
  else if ( rxChar == 'c' )
  {
    digitalWrite(ledpin3, LOW);
    Serial.println("Salida 3 apagada");
  }
    ////////////////  led4
  if( rxChar == 'D' )                          
  {
    digitalWrite(ledpin4, HIGH);
    Serial.println("Salida 4 encendida");
  }
  else if ( rxChar == 'd' )
  {
    digitalWrite(ledpin4, LOW);
    Serial.println("Salida 4 apagada");
  }
  delay(100);
}
}

  
