/*
 * Manejo de pantalla LCD
 * lcd Conexiones 
 * VSS -> GND
 * VDD -> 5V
 * RS -> D7
 * RW -> GND
 * E  -> D8
 * DB4 -> D9 
 * DB5 -> D10
 * DB6 -> D11
 * DB7 -> D12
 * A  -> 5V
 * K  -> GND
 * 
 */

#include<LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Curso IoT UPN");
  delay(2000);

}

void loop() {
  lcd.setCursor(6,1);

  String s = reloj();
  lcd.print(s);
}

String reloj()
{
  //Serial.println(millis());
  int n = millis()/1000;
  int segundos = n%60;            //esta linea obtiene el modulo de los milisegundos que siguen contando, al dividir sobre 60, el valor mantiene elreloj al margen
  int minutos = n/60;

  if(segundos == 0)             //evita el error al pasar los 60 segundos.
    {
      lcd.clear();
      //delay(1);
      lcd.print("Curso IoT UPN");
      //delay(1);
    }
   
  String S = String(minutos) + ":" +String(segundos);       //valores asignados a la variable S (caracteres) 
  return(S);                                                // retorno de la funcion
}
