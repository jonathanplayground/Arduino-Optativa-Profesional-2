int MotorDer1=2; //El pin 2 de Arduino se conecta con el pin In1 del L298N
int MotorDer2=3; //El pin 3 de Arduino se conecta con el pin In2 del L298N

int MotorIzq1=4; //El pin 7 de Arduino se conecta con el pin In3 del L298N
int MotorIzq2=5; //El pin 4 de Arduino se conecta con el pin In4 del L298N

int PWM_Derecho=6; //El pin 5 de Arduino se conecta con el pin EnA del L298N
int PWM_Izquierdo=7; //El pin 6 de Arduino se conecta con el pin EnB del L298N

int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;

//int velocidad=150; //Se declara una variable para guardar la velocidad



void setup() {
  Serial.begin(9600);
  //Se configuran los pines como salida
pinMode(MotorDer1, OUTPUT);
pinMode(MotorDer2, OUTPUT);
pinMode(MotorIzq1, OUTPUT);
pinMode(MotorIzq2, OUTPUT);
pinMode(PWM_Derecho, OUTPUT);
pinMode(PWM_Izquierdo, OUTPUT);

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
}

void loop() {
/*
 * //Velocidad graduada motor derecho prueba de velocidad con ciclo for.
  for(velocidad = 0; velocidad <255; velocidad++)
  {
    analogWrite(PWM_Derecho,velocidad);           // variación de velocidad con salida PWM (VERIFICACIÓN DE CICLO DE TRABAJO.)
    digitalWrite(MotorDer1,LOW);
    digitalWrite(MotorDer2,HIGH);
    digitalWrite(in1,velocidad);                 //indicador led, con aumento de iluminocidad señal PWM            
    digitalWrite(in2,LOW);
    Serial.println(velocidad);                  //valor númerico de señal pwm visualizado en monitor serial
    delay(50);
  }
  delay(3000);
*/
  
  marcha();
  delay(7000);
  atras();
  delay(7000);
  giroDerecha();
  delay(7000);
  giroIzquierda();
  delay(7000);
}

void marcha()
{
  digitalWrite(PWM_Derecho,HIGH);                   //encendido enable motor derecho (a)
  digitalWrite(MotorDer1,LOW);                      //Movimiento manecilla de reloj
  digitalWrite(MotorDer2,HIGH);                     //Movimiento antihorario
  digitalWrite(in1,LOW);                           //indicador led sentido horario
  digitalWrite(in2,HIGH);                            //indicador led sentido Antihorario
  
  digitalWrite(PWM_Izquierdo,HIGH);                //encendido enable motor izquierdo (b)
  digitalWrite(MotorIzq1,HIGH);
  digitalWrite(MotorIzq2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  
}

void atras()
{
  digitalWrite(PWM_Derecho,HIGH);
  digitalWrite(MotorDer1,HIGH);
  digitalWrite(MotorDer2,LOW);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  digitalWrite(PWM_Izquierdo,HIGH);
  digitalWrite(MotorIzq1,LOW);
  digitalWrite(MotorIzq2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void giroDerecha()
{
  digitalWrite(PWM_Derecho,LOW);
  //digitalWrite(MotorDer1,LOW);
  //digitalWrite(MotorDer2,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);

  digitalWrite(PWM_Izquierdo,HIGH);
  digitalWrite(MotorIzq1,HIGH);
  digitalWrite(MotorIzq2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void giroIzquierda()
{
  digitalWrite(PWM_Derecho,HIGH);
  digitalWrite(MotorDer1,LOW);
  digitalWrite(MotorDer2,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  digitalWrite(PWM_Izquierdo,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW); 
}
