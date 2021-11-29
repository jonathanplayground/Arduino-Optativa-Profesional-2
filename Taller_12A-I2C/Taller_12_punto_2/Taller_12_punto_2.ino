/*
 * El siguiente código brinda un escaneo para verificar la dirección de los módulos que utilizan I2C para su funcionamiento.
 */


#include <Wire.h>                  //manejo de interfaz I2C     

void setup()
{
  Wire.begin();                   //Inicializa libreria wire
  Serial.begin(9600);             //Comunicación serial inicializada a 9600 baudios
  
  Serial.println("\nI2C Scanner");
}
 
 
void loop()
{
  byte error, address;                    //variables tipo byte para las 127 direcciones utilizadas por I2C
  int nDevices;                           //Variable creada para el numero de dispositivos conectados
 
  Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    
    Wire.beginTransmission(address);                                //inicia lectura de dispositivos conectados, cuando encuentra un dispositivos retorna el valor
    error = Wire.endTransmission();                                 //Finaliza la lectura de dispositivos I2C y almacena el valor en la variable error
 
    if (error == 0)
    {
      Serial.print("I2C Dispositivo encontrado en la direccion 0x");
      if (address<16)
        Serial.print("0");
        Serial.println(address,HEX);
        nDevices++;                                                 //Adiciona el numero de dispositivos encontrados
    }
    else if (error == 4)                                            //Error desconocido en algun dispositivo. 
    {
      Serial.print("Error desconocido en la direccion 0x");
      if (address<16)
        Serial.print("0");
        Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)                                                // Ningun dispositivo encontrado, cuando no se almacenan en la variable nDevice 
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");                                     //Si hay dispositivos envia mensaje de correcto.
 
  delay(5000);           // wait 5 seconds for next scan
} 
