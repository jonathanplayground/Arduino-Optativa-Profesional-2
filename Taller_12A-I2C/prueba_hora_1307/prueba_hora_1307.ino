/*
 * Manejo módulo 1307 - evidencia hora y fecha en monitor serial.
 */

#include <Wire.h>                             //Manejo de interfaz I2C
#include <RTC.h>                              //Libreria módulo 1307

static DS1307 RTC;                            //Instanciar objeto llamado RTC

void setup()
{
  Serial.begin(9600);                         //Comunicación serial
  RTC.begin();                                //Inicializar modulo 1307

  Serial.println();                     
  Serial.println("*** RTC 1307 ***");
 
/////////////////////////////////Verifica si existe comunciación entre arduino y RTC. 
  Serial.print("Reloj activo? ");
  if (RTC.isRunning())                                    
    Serial.println("Si");                                  
  else
    Serial.println("No. Existe un error");

///////////////////////////////////////////////////Modo de hora en módulo --> 12H o 24H
  Serial.print("Hour Mode : ");
  if (RTC.getHourMode() == CLOCK_H24)
    Serial.println("24 Hours");
  else
    Serial.println("12 Hours");

////////////////////////////////////////////////////////////////////////////////////////

}

void loop()
{

  switch (RTC.getWeek())                //Verifica el dia de la semana con el atributo getWeek
  {
    case 1:
      Serial.print("Domingo");
      break;
    case 2:
      Serial.print("Lunes");
      break;
    case 3:
      Serial.print("Martes");
      break;
    case 4:
      Serial.print("Miercoles");
      break;
    case 5:
      Serial.print("Jueves");
      break;
    case 6:
      Serial.print("Viernes");
      break;
    case 7:
      Serial.print("Sabado");
      break;
  }

/////////////////////////////////////////Verifica el dia mes y año
  Serial.print(" ");
  Serial.print(RTC.getDay());                     //Atributo encargado de verificar el día actual.
  Serial.print("-");
  Serial.print(RTC.getMonth());                   //Atributo encargado de verificar el mes actual.
  Serial.print("-");
  Serial.print(RTC.getYear());                    //Atributo encargado de verificar el año actual.

  Serial.print(" ");

  Serial.print(RTC.getHours());                   //Atributo encargado de verificar la hora actual.
  Serial.print(":");
  Serial.print(RTC.getMinutes());                 //Atributo encargado de verificar los minutos actuales.
  Serial.print(":");
  Serial.print(RTC.getSeconds());                 //Atributo encargado de verificar los segundos actuales.

///////////////////////////////////////////////////Obtener am o pm.
  if (RTC.getHourMode() == CLOCK_H12)             //Como el módulo cuenta con un sistema horario de 24H no es necesario incluir  las siguientes lineas.
  {
    switch (RTC.getMeridiem())
    {
      case HOUR_AM :
        Serial.print(" AM");
        break;
      case HOUR_PM :
        Serial.print(" PM");
        break;
    }
  }
  Serial.println();
  delay(1000);
}
