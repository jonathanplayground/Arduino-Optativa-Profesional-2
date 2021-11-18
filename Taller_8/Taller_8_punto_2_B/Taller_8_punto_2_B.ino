/*
 * MANEJO TECLADO MATRICIAL SIN LIBRERIA
 * 
 * No tiene buen funcionamiento 
 */


const unsigned long period = 50; 
unsigned long prevMillis = 0;

byte iRow = 0, iCol = 0; 
const byte countRows = 4; 
const byte countColumns = 4; 
const byte rowsPins[countRows] = { 11, 10, 9, 8 }; 
const byte columnsPins[countColumns] = { 7, 6, 5, 4 }; 
byte r;

char keys[countRows][countColumns] = 
{ 
  { '1','2','3', 'A' }, 
  { '4','5','6', 'B' }, 
  { '7','8','9', 'C' }, 
  { '#','0','*', 'D' } 
  };

  
void setup() {
  // Iniciar valores
  Serial.begin(9600); 
  for (byte c = 0; c < countColumns; c++) 
  { 
    pinMode(columnsPins[c], INPUT_PULLUP); 
  } 
  for (byte r = 0; r < countRows; r++)
  { 
    pinMode(rowsPins[r], OUTPUT); 
    digitalWrite(rowsPins[r], HIGH); 
  }  
}

void loop() {
  if (millis() - prevMillis > period)                                       // Espera no bloqueante 
  { 
    prevMillis = millis(); 
    if (readKeypad())                                        // Detección de tecla pulsada 
    { 
      Serial.println(keys[iCol][iRow]);                     // Mostrar tecla 
    }
  }
}

bool readKeypad() 
{ // Barrer todas las filas 
  for (byte r = 0; r < countRows; r++) 
  { 
    pinMode(rowsPins[r], OUTPUT); 
    digitalWrite(rowsPins[r], LOW); // Poner en LOW fila 
    // Comprobar la fila 
    for (byte c = 0; c < countColumns; c++) 
    { 
      if (digitalRead(columnsPins[c]) == LOW) 
      // Pulsación detectada 
      { 
        iRow = r; iCol = c; 
        return true; 
      } 
     }
   }


pinMode(rowsPins[r], HIGH); // Ponen en HIGH fila 
digitalWrite(rowsPins[r], INPUT); // Poner en alta impedancia 
return false; 
}
