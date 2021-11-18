/*
 * Manejo keypad, utilizando libreria para evitar errores de antirebote
 * Verificación de clave correcta o no
 * 
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
 */


#include <Keypad.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);

//Definir tamaño de teclado matricial
const byte FILAS =  4;                               //VARIABLE BYTE TIENE UNA LONGITUD DE ALMACENAMIENTO DE 8 bits  --> PERMITE ALMACENAR VALORES ENTRE 0 Y 255
const byte COLUMNAS = 4;
int codigo = 0;

char keys[FILAS][COLUMNAS] =                        //DEFINIR UN MAA DE LA DISTRIBUCIÓN DEL TECLADO --> LOS VALORES QUE REPRESENTAN CADA VALOR EN EL TECLADO
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//sin pantalla lcd
//byte pinesFilas[FILAS]  = {9,8,7,6};                    //Se definen los pines de conexión con el arduino. --> se inicializa en una variable tipo byte y se crea un array[] 
//byte pinesColumnas[COLUMNAS]  = {5,4,3,2};


//con pantalla lcd
byte pinesFilas[FILAS]  = {13,6,5,4};                    //Se definen los pines de conexión con el arduino. --> se inicializa en una variable tipo byte y se crea un array[] 
byte pinesColumnas[COLUMNAS]  = {3,2,A1,A0};


Keypad teclado = Keypad(makeKeymap(keys),pinesFilas, pinesColumnas, FILAS, COLUMNAS);          //objeto tipo Keypad(mapa de distribución, ...  cantidad de filas, cantidad de columnas)
char tecla;                                                                                     //para utilizar letras * y #.
char clave[7];                                                  //se deja un bite(digito)vacio denominado null, y a una cadena de caracteres con un null al final se denomina string --> Esto es para comparar ambos string, clave y clave maestra
char claveMaestra[7] = "123456";          
byte indice = 0;                                                // utilizado para cargar el array con los digitos individuales cargados desde el teclado, inicializado en cero para quedar apuntado al inicio del array
   
 void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print(" Manejo teclado");
  lcd.setCursor(3,1);
  lcd.print("Matricial");
  delay(2000);
  lcd.clear();
  
  //pinMode(A0,INPUT);                      //USO DE PINES ANALOGICOS COMO DIGITALES
  //pinMode(A1,INPUT);
}

void loop() {
  tecla = teclado.getKey();           //getKey -> para detectar la entrada de la tecla presionada --> del objeto teclado
            
  lcd.setCursor(0,0);
  lcd.print(" Digitar clave");
  verificarClave();
}


void verificarClave()
{
    if(tecla)                           //solo ingresa en el if, si se presiona una tecla, puede tener mas entradas y no afectaran el código.
    {
      clave[indice] = tecla;            // almacenamiento de valores ingresados por teclado
      indice++;
      Serial.print(tecla);              //visualización mediante monitor serial
      lcd.setCursor(indice,1);          // Se modifica el número de la columna con el valor de la variable indice.
      lcd.print(tecla);
    }
    if(indice == 6)
    {
         /* if(!strcmp(clave, claveMaestra))                //compara los valores (caracteres) de datos tipo string,    Si la comparacion es exitosa devuelve un cero, el if evalua una condición verdadera y el 0 es una condicion falsa--> utilizamos ! para negar el resultado, y tener un valor de 1 si es verdadero
        lcd.setCursor(4,0);
        lcd.print("Clave");
        lcd.setCursor(2,1);
        lcd.print("Incorrecta");
        Serial.println("  Correcta");                 // espacio para visualizar esteticamente la respuesta
       */
       
      lcd.clear();
      indice = 0;
      for(int i=0; i<6;i++)
      { 
         if(clave[i] == claveMaestra[i])
         { 
          codigo = 1;
         }
         else
         {
          codigo = 0;
         }
      }
      if(codigo==1)
      {
        lcd.setCursor(5,0);
        lcd.print("Clave");
        lcd.setCursor(4,1);
        lcd.print("Correcta");
        Serial.println("  Correcta");
        delay(2000);
        lcd.clear();
        
      }
      else
      {
        Serial.println("  Incorrecta");
        lcd.setCursor(5,0);
        lcd.print("Clave");
        lcd.setCursor(3,1);
        lcd.print("Incorrecta");
        delay(2000);
        lcd.clear();
      }
    }
}
