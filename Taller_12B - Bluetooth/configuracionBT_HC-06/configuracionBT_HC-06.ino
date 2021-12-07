/*
 *Configuración nombre y contraseña de módulo slave HC-06
*/

const int power = 12;
const int led = 13;

char nombreBT[8] = "IoT UPN";
char velocidad = '4';                 //9600 baudios
char pin[5] = "0000";

void setup() {
  Serial.begin(9600);               //Velocidad comunicación serial con monitor
  pinMode(led,OUTPUT);
  pinMode(power,OUTPUT);

  digitalWrite(led,LOW);
  digitalWrite(power,HIGH);         //ENCENDIDO DE BLUETOOTH

  Serial.print("AT");           //importante para iniciar comandos AT
  delay(1000);
/*
  Serial.print("AT+ORGL");
  delay(1000);
  */
  Serial.print("AT+NAME");
  Serial.print(nombreBT);
  delay(1000);

  Serial.print("AT+BAUD");
  Serial.print(velocidad);
  delay(1000);

  Serial.print("AT+PSWD");
  Serial.print(pin);
  delay(1000);

  digitalWrite(led,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
