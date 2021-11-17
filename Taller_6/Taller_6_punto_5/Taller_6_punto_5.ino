/*
 * Lectura de sensor de temperatura (lm35) y despliegue en pantalla Lcd 
 * Visualización de grados centigrados y fahrenheit
 */


 #include <LiquidCrystal.h>
 
 LiquidCrystal lcd(7,8,9,10,11,12);
 byte grado[8] = { 0b00001100, 0b00010010, 0b00010010, 0b00001100, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
 float dato;
 float c,f;
 
 void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.createChar(1,grado);
  lcd.setCursor(2,0);
  lcd.print("Temperatura: ");
  //centigrados
  lcd.setCursor(5,1);
  lcd.write(1);
  lcd.setCursor(6,1);
  lcd.print("C");
  //farenheit
  lcd.setCursor(14,1);
  lcd.write(1);
  lcd.setCursor(15,1);
  lcd.print("F");
}

void loop() {
  float centigrados = leerGrados();
  float faren = fahrenheit();
  lcd.setCursor(0,1);
  lcd.print(centigrados);
  lcd.setCursor(9,1);
  lcd.print(faren);
  Serial.println(analogRead(A0));         //linea de prueba para verificar los datos obtenidos del sensor lm35
  delay(1000);
}

float leerGrados()
{
  dato = analogRead(A0);
  c = (500*dato/1024);        //conversión --> ((5000mV * Sensor)/1023)/(10mV) --> obtenemos un valor en mV se divide todo entre 10mV para obtener los grados
  delay(10);
  /*
   * cen = (5*dato/1024);       //entrega el ressultado en voltios, dividimos en 10mV para obtener el valor en grados centigrados
   * c = c/0.01
   */
   if(c<0)
   {
    c = 0;
   }
  return c;
}
float fahrenheit()
{
  f = (c*9/5)+32;
  return f;
}
