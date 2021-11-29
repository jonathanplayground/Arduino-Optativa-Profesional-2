
#include <Time.h>               
#include <TimeLib.h>                          //Libreria para obtener conteo de hora.
#include <Wire.h>                             //manejo de interfaz I2C  
#include <DS1307RTC.h>                        // La libreria que gestiona el DS1307 RTC para Time
//#include <LCD.h>                            //presenta errores al verificar el código, no es necesaria la presente libreria
#include <LiquidCrystal_I2C.h>

//#define I2C_ADDR 0x27

//LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7);             // Presenta errores al verificar el código, se remplaza con la linea continua.
LiquidCrystal_I2C     lcd(0X27,16,2);     //ó 0X20


void setup()
{
  Serial.begin(115200);
  lcd.begin (16, 2);                               // Inicializar el display con 16 caraceres 2 lineas
  //lcd.backlight();                               //Brillo pantalla, no necesario en este código
  //lcd.setBacklight(HIGH);
  //getDate(__DATE__);  

  setSyncProvider(RTC.get);                       // Sincronizar con el RTC
  setTime(18, 14, 00, 27, 11, 2021);               // Establecer hora y fecha; hora --> hora, minuto, segundo; Fecha --> dia,mes,año  
   
  //////////////////////////Verificar sincronización con RTC
  if (timeStatus() != timeSet)
  Serial.println("Unable to sync with the RTC");
  else
  Serial.println("RTC has set the system time");
}

void digitalClockDisplay()
{
 lcd.home (); // go home
 lcd.print(hour());
 printDigits(minute());
 printDigits(second());
 lcd.setCursor ( 0, 1 ); // go to the 2nd line
 lcd.print(day());
 lcd.print("/");
 lcd.print(month());
 lcd.print("/");
 lcd.print(year());
}

void printDigits(int digits)
{
 lcd.print(":");
 if (digits < 10)
 lcd.print('0');
 lcd.print(digits);
}

void loop()
{
 digitalClockDisplay();
 delay(1000);
}
