/*
 * Taller 25 punto 1
 * Uso maodulo L298N para control de motores DC
 * 
 * EL SISTEMA CONTIENE 4 SENSORES, UNO EN CADA EXTREMO DE UN CARRO
 * 
 * tambien se incluye 4 indicadores led para verificar la dirección del automovil. 
 */


int MotorDer1=2;          //El pin 2 de Arduino se conecta con el pin In1 del L298N
int MotorDer2=3;          //El pin 3 de Arduino se conecta con el pin In2 del L298N

int MotorIzq1=4;          //El pin 7 de Arduino se conecta con el pin In3 del L298N
int MotorIzq2=5;          //El pin 4 de Arduino se conecta con el pin In4 del L298N

int PWM_Derecho=6;        //El pin 5 de Arduino se conecta con el pin EnA del L298N
int PWM_Izquierdo=7;      //El pin 6 de Arduino se conecta con el pin EnB del L298N

int avanzar = 8;          //asignación de pin para indicador led
int retroceder = 9;
int izquierda = 10;
int derecha = 11;

int derAdelante   = A0;             // sensores para evitar choque, son entradas analogicas pero se configuran en el setup() como pines digitales
int derAtras      = A1;
int izqAdelante   = A2;
int izqAtras      = A3;

int dato;                 //variable utilizada para condición switch case.

void setup() {
  Serial.begin(9600);
  
  //Se configuran los pines como salida
  pinMode(MotorDer1, OUTPUT);
  pinMode(MotorDer2, OUTPUT);
  pinMode(MotorIzq1, OUTPUT);
  pinMode(MotorIzq2, OUTPUT);
  pinMode(PWM_Derecho, OUTPUT);
  pinMode(PWM_Izquierdo, OUTPUT);

  //Configuración de indicadores led  
  pinMode(avanzar,OUTPUT);
  pinMode(retroceder,OUTPUT);
  pinMode(izquierda,OUTPUT);
  pinMode(derecha,OUTPUT);

  //Configuración de sensores en pines analógicos -> utilizados como entradas digitales
  pinMode(derAdelante, INPUT);
  pinMode(derAtras, INPUT);
  pinMode(izqAdelante, INPUT);
  pinMode(izqAtras, INPUT);
  
  }

void loop() {

  if(digitalRead(derAdelante) == 0 && digitalRead(izqAdelante) == 0)              //avanzar
  {
    dato = 1;
  }
  else if(digitalRead(derAdelante) == 0 && digitalRead(izqAdelante) == 1)           //giro derecha
  {
    dato = 2;
  }
  else if(digitalRead(derAdelante) == 1 && digitalRead(izqAdelante) == 0)               //giro izquierda 
  { 
    dato = 3;
  }
  else if (digitalRead(derAdelante) == 1 && digitalRead(izqAdelante) == 1 && digitalRead(derAtras) == 0 && digitalRead(izqAtras) == 0)        //retroceder
  {
    dato = 4;
  }
  
  else if (digitalRead(derAdelante) == 1 && digitalRead(izqAdelante) == 1 && digitalRead(derAtras) == 1 && digitalRead(izqAtras) == 0)          //retrocede izquierda
  {
    dato = 5;
  }
  else if (digitalRead(derAdelante) == 1 && digitalRead(izqAdelante) == 1 && digitalRead(derAtras) == 0 && digitalRead(izqAtras) == 1)          //retrocede derecha
  {
    dato = 6;
  }

  
  switch(dato)
  {
    case 1:
      marcha();
      break;
    case 2:
      giroDerecha();
      break;
    case 3:
      giroIzquierda();
      break;
    case 4:
      atras();
      break;
    case 5:
      giroAtrasIzquierda();
      break;
    case 6:
      giroAtrasDerecha();
      break;
  }
}
  


void marcha()
{
  digitalWrite(PWM_Derecho,HIGH);                   //encendido enable motor derecho (a)
  digitalWrite(MotorDer1,LOW);                      //Movimiento manecilla de reloj apagado
  digitalWrite(MotorDer2,HIGH);                     //Movimiento antihorario encendido
    
  digitalWrite(PWM_Izquierdo,HIGH);                //encendido enable motor izquierdo (b)
  digitalWrite(MotorIzq1,HIGH);
  digitalWrite(MotorIzq2,LOW);  

  digitalWrite(avanzar,HIGH);                     //indicador led.
  delay(50);                                      //importnte encender y apagar el led, cuando sale de la función el indicador queda apagado.
  digitalWrite(avanzar,LOW);
}

void atras()
{
  digitalWrite(PWM_Derecho,HIGH);
  digitalWrite(MotorDer1,HIGH);
  digitalWrite(MotorDer2,LOW);
  
  digitalWrite(PWM_Izquierdo,HIGH);
  digitalWrite(MotorIzq1,LOW);
  digitalWrite(MotorIzq2,HIGH);

  digitalWrite(retroceder,HIGH);
  delay(50);
  digitalWrite(retroceder,LOW);
}

void giroIzquierda()
{
  digitalWrite(PWM_Derecho,LOW);

  digitalWrite(PWM_Izquierdo,HIGH);
  digitalWrite(MotorIzq1,HIGH);
  digitalWrite(MotorIzq2,LOW);

  digitalWrite(izquierda,HIGH);
  delay(50);
  digitalWrite(izquierda,LOW);
}

void giroDerecha()
{
  digitalWrite(PWM_Derecho,HIGH);
  digitalWrite(MotorDer1,LOW);
  digitalWrite(MotorDer2,HIGH);

  digitalWrite(PWM_Izquierdo,LOW);

  digitalWrite(derecha,HIGH);
  delay(50);
  digitalWrite(derecha,LOW);
}

void parar()
{
  digitalWrite(PWM_Derecho,LOW);
  digitalWrite(PWM_Izquierdo,LOW);
}

void giroAtrasDerecha()
{
  digitalWrite(PWM_Derecho,LOW);

  digitalWrite(PWM_Izquierdo,HIGH);
  digitalWrite(MotorIzq1,HIGH);
  digitalWrite(MotorIzq2,LOW);
  
  digitalWrite(retroceder,HIGH);
  digitalWrite(derecha,HIGH);
  delay(50);
  digitalWrite(retroceder,LOW);
  digitalWrite(derecha,LOW);
}

void giroAtrasIzquierda()
{
  digitalWrite(PWM_Derecho,HIGH);
  digitalWrite(MotorDer1,LOW);
  digitalWrite(MotorDer2,HIGH);
  
  digitalWrite(PWM_Izquierdo,LOW);
  
  digitalWrite(retroceder,HIGH);
  digitalWrite(izquierda,HIGH);
  delay(50);
  digitalWrite(retroceder,LOW);
  digitalWrite(izquierda,LOW);
}
