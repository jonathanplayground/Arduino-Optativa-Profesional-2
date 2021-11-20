/*
 * Punto 1 taller 3
 * Genera tabla ascii
 */



void setup() {
  Serial.begin(9600);     //inicializa comunicación serial
  while(!Serial)          //Entenderel uso de este ciclo con (!Serial)
  {
    //Esperar a que el puerto serial se conecte! 
  }
  Serial.println("ACII Tabla - Mapa de caracteres");
}

int thisByte = 33;

void loop() {
  Serial.print("Signo: ");
  Serial.write(thisByte);         //entrega el simbolo que representa el numero 33
  //Serial.print(thisByte);
  Serial.print(", DEC: ");
  Serial.print(thisByte,DEC);     //imprime en formato decimal el valor ingresado
  Serial.print(", Hex: ");
  Serial.print(thisByte, HEX);    //Imprime el valor Hexadecimal
  Serial.print(", OCT: ");
  Serial.print(thisByte, OCT);    //Imprime el valor Octal
  Serial.print(", BIN: ");
  Serial.println(thisByte, BIN);    //Imprime el valor Binario
  delay(1000);

  thisByte++;
  
  //Cuando se imprime el ultimo caracter visible el programa se detiene ( 126 o ..)
  if(thisByte ==40)
  {
    while(true)
    {
      continue;         //Buscar el funcionamiento del comando
    }
  }
}
