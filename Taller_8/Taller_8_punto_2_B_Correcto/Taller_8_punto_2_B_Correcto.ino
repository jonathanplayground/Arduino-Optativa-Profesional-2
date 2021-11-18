/*
 * Manejo teclado matricial sin libreria.
 */

int numFilas = 4;
int numColumnas = 4;

byte pinesFilas[] = {9,8,7,6};                             //Creación vector con filas de conexión para arduino
byte pinesColumnas[] = {5,4,1,0};                         //Creación vector con los numero de pines de conexión del arduino.

char teclas[4][4] =                                     //Creación de matriz 4x4 con los respectivos valores asignados
{ 
  { '1','2','3', 'A' }, 
  { '4','5','6', 'B' }, 
  { '7','8','9', 'C' }, 
  { '#','0','*', 'D' } 
};


void setup() {
  
  for(int i = 0; i < numFilas; i++)
  {
    pinMode(pinesFilas[i],OUTPUT);
    digitalWrite(pinesFilas[i],HIGH);
  }
  for(int j = 0; j < numColumnas; j++)
  {
    pinMode(pinesColumnas[j],INPUT_PULLUP);
  }

  Serial.begin(9600);
}

void loop() {
  //Barrido por filas
  for(int i = 0; i < numFilas; i++)
  {
    digitalWrite(pinesFilas[i], LOW);
    for(int j = 0; j < numColumnas; j++)
    {
      if(digitalRead(pinesColumnas[j])== LOW)
      {
        Serial.print("Tecla: ");
        Serial.println(teclas[i][j]);
        while(digitalRead(pinesColumnas[j]) == LOW){}
      }
    }
    digitalWrite(pinesFilas[i], HIGH);
  }
  delay(10);
}
