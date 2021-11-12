/*
 * Punto 3 del taller 2
 * Calculo de valores promedio de una señal análoga
 * Se hará uso de los arreglos (array)
 * Suavizar lo datos de entrada de un sensor, se lee de de manera repetida una entrada análoga(arreglo)
 * se calcula el promedio de las lecturas almacenadas en el arreglo y se imprime el valor (promedio) obtenido.
 */ 

const int pinSensor = A0;               //CONEXIÓN POTENCIOMETRO

const int numReadings = 10;             //Número de muestras que se guardaran en el arreglo --> 10 --> entre mayor sea el número, el suavizado sera mayor pero el proceso será mas lento 

int lecturas[numReadings];               //Se define el arreglo (array) --> Lecturas de la entrada análoga
int readIndex = 0;                       //Indice de las lecturas
int total = 0;                           //Corrida total --> 
int average = 0;                         //El promedio

void setup() {
  Serial.begin(9600);                    //Inicializa comunicación serial, importante para visualizacion monitor serial.
  
  //inicializar lectura en 0  --> los 10 datos del arreglo (array) en cero
  for(int thisReading =0; thisReading < numReadings; thisReading++)   
  {
    lecturas[thisReading] = 0;
  }

} 

void loop() {
  total = total - lecturas[readIndex];                  // resta la ultima lectura --> necesario para eliminar el array guardado con su valor anterior --> 
                                                        //[0-9] - [0] -->(array inicial) - (array nuevo, pero eliminando el valor en [0] del array inicial) --> se suma el nuevo valor en [0] en la siguiente linea.
  lecturas[readIndex] = analogRead(pinSensor);          //lectura del sensor  
  total = total + lecturas[readIndex];                  //Suma la lectura total
  
  /*Serial.println(readIndex);
  Serial.print("total  ");
  Serial.println(total);
  */
  readIndex++;                                          //pasa al siguiente valor del arreglo
  if(readIndex >= numReadings)
  {
    readIndex = 0;                      //Se inicia nuevamente el arreglo en cero
  }

  // Calcular promedio
  average = total/numReadings;
  Serial.print("Señal directa del ptenciometro: ");
  Serial.println(analogRead(pinSensor));
  Serial.print("Señal filtrada: ");
  Serial.println(average);            //Imprimir por monitor serial en código ASCII el valor de avarage(promedio)
  delay(10);                           //retardo entre lecturas para estabilizar

}
