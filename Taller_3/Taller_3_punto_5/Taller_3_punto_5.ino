/*
 * Lectura de acelerometro ADCL3xx
 * 
 * Comunica la aceleración al computador. Verificar conexiones si implementamos otro disositivo
 * La aceleración de movimiento de los ejes x,y,z
 */

//Entradas analogicas del acelerometro

#include <Wire.h> 
#include <MechaQMC5883.h> 

MechaQMC5883 qmc;     // Se crea un objeto de tipo qmc
const float declinacion =  -7.55;
void setup() {
  Wire.begin();
  Serial.begin(9660);
  qmc.init();         //Funcion init() sobre el objeto qmc
}

void loop() {
  int x, y, z;
  float acimut, geografico;
  
  qmc.read(&x, &y, &z, &acimut);        //pasamos las variables por referencia. -> en & asigna el valor sobre la variable

  geografico = acimut+declinacion;
  if(geografico<0)
  {
    geografico = geografico +360;       // Si aparece un angulo negativo sumamos 360°
  }

  Serial.print("Acimut geografico: ");
  Serial.print(geografico,0);         //El cero despues de la coma indica que no queremos mostrar los valores deciamles
  Serial.println (" grados");
  /*
  Serial.print("x:");
  Serial.print(x);
  Serial.print("\t");
  Serial.print("y:");
  Serial.print(y);
  Serial.print("\t");
  Serial.print("z:");
  Serial.print(z);
  Serial.print("\t");
  Serial.print("acimut:");
  Serial.println(acimut);
  */
  delay(500);
  
}
