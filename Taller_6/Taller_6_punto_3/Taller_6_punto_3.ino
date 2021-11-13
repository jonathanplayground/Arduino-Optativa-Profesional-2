/*
 *Definicion de caracteres del usuario --> creacion caracter grados!  
 */

 #include<LiquidCrystal.h>
 LiquidCrystal lcd(7,8,9,10,11,12);
 
 byte grado[8] = { 0b00001100, 0b00010010, 0b00010010, 0b00001100, 0b00000000, 0b00000000, 0b00000000, 0b00000000};     // matriz de arreglso con valores binarios para generar el caracter
 
 void setup() 
 {
  lcd.begin(16,2);        //  Inicializar LCD (columnas,filas)
  lcd.createChar(1,grado);     //creacion de nueva variable char --> para caracter grados. (nombreCaracter, nombreMatrizBinaria)
  lcd.setCursor(0,0);      //Coordenadas de LCD 
  lcd.print("Estamos a 20");
  lcd.write(1);
}

void loop() {
  // put your main code here, to run repeatedly:

}
