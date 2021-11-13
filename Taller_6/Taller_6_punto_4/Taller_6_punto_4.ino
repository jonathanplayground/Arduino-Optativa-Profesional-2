/*
 * Lectura de sensor de temperatura (lm35) y despliegue en pantalla Lcd
 */


 #include <LiquidCrystal.h>
 
 LiquidCrystal lcd(7,8,9,10,11,12);
 byte grado[8] = { 0b00001100, 0b00010010, 0b00010010, 0b00001100, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
 int dato;
 float c;
 
 void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.createChar(1,grado);
  lcd.setCursor(2,0);
  lcd.print("Temperatura: ");
  lcd.setCursor(10,1);
  lcd.write(1);
  lcd.setCursor(11,1);
  lcd.print("C");
}

void loop() {
  float centigrados = leerGrados();
  lcd.setCursor(4,1);
  lcd.print(centigrados);
  Serial.println(analogRead(A0));         //linea de prueba para verificar los datos obtenidos del sensor lm35
  delay(1000);
}

float leerGrados()
{
  dato = analogRead(A0);
  //c = (dato*500/1024);        //conversión --> ((5000mV * Sensor)/1023)/(10mV) --> obtenemos un valor en mV se divide todo entre 10mV para obtener los grados
  c = dato*0.49;                // Es necesario multiplicarpor la divicion entre 500/1024, porque al superar cierto valor de bits el programa envia datos incorrectos
  /*
   * cen = (5*dato/1024);       //entrega el ressultado en voltios, dividimos en 10mV para obtener el valor en grados centigrados
   * c = c/0.01
   */
  return c;
}
