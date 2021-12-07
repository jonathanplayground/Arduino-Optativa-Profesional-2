/*
 * 
 */

#include <SoftwareSerial.h>         //libreria necesaria para utilizar pines diferentes al 0 y 1 como TX y RX

//pines de RX y TX 
SoftwareSerial miBT(10 , 11);      //pin 10 ->RX; pin 11->TX 

//variables bluetooth
int power = 12;

char rxChar = 0;                                  // Variable para recibir datos del puerto serie
int ledpin1 = 9;                              // Pin donde se encuentra conectado el led (pin 9)
int ledpin2 = 8;
int ledpin3 = 7;
int ledpin4 = 6;
int ledpin5 = 5;
int ledpin6 = 4;

 
// variavles sensor temperatura 
String indices[5] = {"Muy caliente", "Caliente", "Agradable", "Frio", "Muy Frio"};

float dato;
int c;
String t;
int valor = 0;


void setup() {
  
  for(int i = 9; i>4; i--)
  {
    pinMode(i,OUTPUT);            //Pines declarados como salida
  }
  
  Serial.begin(9600);
  
  pinMode(power,OUTPUT);
  digitalWrite(power,HIGH);
  delay(100);
  miBT.begin(9600);
  Serial.begin(9600);  
  Serial.println("Temperatura");
}

void loop() {

  leerGrados();
  int prueba = (c,DEC);
  Serial.write(prueba);
  if(Serial.available())
  {
    miBT.write(Serial.read());
  }
  
  if(miBT.available())
  {
    leerGrados();
    Serial.println(c);
    delay(1000);
    temperaturaC(c);
  }
}


int leerGrados()
{
  dato = analogRead(A0);
  c = dato*0.49;        //conversión --> ((5000mV * Sensor)/1023)/(10mV) --> obtenemos un valor en mV se divide todo entre 10mV para obtener los grados
  delay(10);

   if(c<0)
   {
    c = 0;
   }
  return c;
}

void temperaturaC(int valor)
{
  
  if(valor>=30)
  {
    t = indices[0];
    digitalWrite(ledpin6,HIGH); 
    digitalWrite(ledpin5,HIGH);  
    digitalWrite(ledpin4,HIGH);
    digitalWrite(ledpin3,HIGH);
    digitalWrite(ledpin2,HIGH);
    digitalWrite(ledpin1,HIGH);
  }
  else if(valor>=24)
  {
    t = indices[1];
    digitalWrite(ledpin6,HIGH); 
    digitalWrite(ledpin5,HIGH);  
    digitalWrite(ledpin4,HIGH);
    digitalWrite(ledpin3,HIGH);
    digitalWrite(ledpin2,HIGH);
    digitalWrite(ledpin1,LOW);
  }
  else if(valor>=18)
  {
    t = indices[2];
    digitalWrite(ledpin6,HIGH); 
    digitalWrite(ledpin5,HIGH);  
    digitalWrite(ledpin4,HIGH);
    digitalWrite(ledpin3,HIGH);
    digitalWrite(ledpin2,LOW);
    digitalWrite(ledpin1,LOW);
  }
  else if(valor>=10)
  {
    t = indices[3];
    digitalWrite(ledpin6,HIGH); 
    digitalWrite(ledpin5,HIGH);  
    digitalWrite(ledpin4,HIGH);
    digitalWrite(ledpin3,LOW);
    digitalWrite(ledpin2,LOW);
    digitalWrite(ledpin1,LOW);
  }
  else if(valor>=4)
  {
    t = indices[4]; 
    digitalWrite(ledpin6,HIGH); 
    digitalWrite(ledpin5,HIGH);  
    digitalWrite(ledpin4,LOW);
    digitalWrite(ledpin3,LOW);
    digitalWrite(ledpin2,LOW);
    digitalWrite(ledpin1,LOW);
  }
}
