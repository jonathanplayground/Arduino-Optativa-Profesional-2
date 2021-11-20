/*
 * Dependiendo del dato recibido por puerto serie, realiza una accion con el uso de la sentencia switch
 * sE ENVIARAN LOS CARACTERES A,B,C,D,E, Y SE ENCENDERAN LOS PINES DEL 2 A 6, SEGÚN EL CARACTER RECIBIDO
 * Los demas caracteres mandendran apagados los led
 */



int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;

int inByte =0;

void setup() {
  Serial.begin(9600);
  for(int thisPin = 2; thisPin<7; thisPin++)
  {
    pinMode(thisPin, OUTPUT);
  }
  /*
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  */
}

void loop() {
  // LECTURA DEL PUERTO SRRIAL
  if(Serial.available()>=0)
  {
    inByte = Serial.read();
  }

  switch(inByte)
  {
    case 'a':
      digitalWrite(2,HIGH);
      delay(1000);                        //retardo necesario para verificar la acción
      break;
    case 'b':
      digitalWrite(3,HIGH);
      delay(1000);
      break;
    case 'c':
      digitalWrite(led3,HIGH);
      break;
    case 'd':
      digitalWrite(led4,HIGH);
      break;
    case 'e':
      digitalWrite(led5,HIGH);
      break;
    default:                  //caso llamado defaul, utilizado para representar los casos faltantes
      for(int thisPin = 2; thisPin <7; thisPin++)
      {
        digitalWrite(thisPin, LOW);
      }
  }

}
