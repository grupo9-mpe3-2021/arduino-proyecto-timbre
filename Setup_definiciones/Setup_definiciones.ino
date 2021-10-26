#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Wire.h>
#include <RTClib.h>
#define pinINT 2 
#define timbre 13

LiquidCrystal_I2C lcd(0x27,20,4);
RTC_DS3231 rtc;

int cantidadAlarmas=20; //Cantidad de alarmas. hay que jugar con este valor y size of alarma[] para poder correr bien el codigo. si no se bugea.
String alarma[20]; //String alarma[cantidadAlarmas];
bool activacion = true; 
int actual = 0;//es un index que define donde arrancan a sonar las alarmas. 

// Variables del RTC :
int factorCompensacion = 7;
char date[10] = "hh:mm:ss";
String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

//Variables del Keypad
char key;
const int cantidadFilas = 4; //cuatro filas
const int cantidadColumnas = 4; //cuatro columna
char teclas[cantidadFilas][cantidadColumnas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinFilas[cantidadFilas] = {4,5,6,7}; //este es el pinout de las filas del teclado
byte pinColumnas[cantidadColumnas] = {8,9,10,11}; //este es el pinout de las columnas del teclado
Keypad keypad = Keypad( makeKeymap(teclas), pinFilas, pinColumnas, cantidadFilas, cantidadColumnas );


void setup() {
  Serial.begin(9600);

  // Setup LCD.
  lcd.init();
  lcd.backlight();
  
  // Setup RTC.
  checkStatus();
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //alarmas default.
  
    alarma [0]  = "07:40";
    alarma [1]  = "09:40";
    alarma [2]  = "10:00";
    alarma [3]  = "12:00";
    alarma [4]  = "13:00";
    alarma [5]  = "15:45";
    alarma [6]  = "16:00";
    alarma [7]  = "17:15";
    alarma [8]  = "22:40";
    alarma [9]  = "23:54";
    
    alarma [10] = "06:30";
    alarma [11] = "06:35";
    alarma [12] = "14:25";
    alarma [13] = "16:25";
    alarma [14] = "17:00";
    alarma [15] = "18:00";
    alarma [16] = "XX:XX";
    alarma [17] = "XX:XX";
    alarma [18] = "XX:XX";
    alarma [19] = "XX:XX";
    
  actualizarAlarma();//necesito que se ponga al corriente segun que alarma es la entrante.
  
  Serial.println(F("Setup finalizado"));
}

void loop() {
   
  DateTime now = rtc.now();   // actualiza la hora. 
  //campanita();
  lcd.setCursor (6,0);
  lcd.print (F("Inicio"));
  mostrarMenuA();
  
  key = keypad.getKey(); // lee lo que te deje en la pestaña de menus. 
  switch (key) { // navegacion de los menus

    case 'B':
      lcd.clear();
      lcd.setCursor (2,0);
      lcd.print(F("Mostrando menu B"));      Serial.println(F("Mostrando menu B"));
      delay(1000); //modificar o reorganizar.
      lcd.clear();
      mostrarMenuB();
    break;
    
    case 'C':
      lcd.clear();
      lcd.setCursor (2,0);
      lcd.print(F("Mostrando menu C"));      Serial.println(F("Mostrando menu C"));
      mostrarMenuC();
    break;
    
    case 'D': 
      lcd.clear();
      lcd.setCursor (2,0);
      lcd.print(F("Mostrando menu D"));      Serial.println(F("Mostrando menu D"));
      mostrarMenuD();
    break;
    
  }
  
  char buf3[] = "hh:mm";
  now.toString(buf3);   // pasa la hora al string buf3, y elimina los segundos como parametro.
  Serial.println (buf3); 
  
  if (activacion == true &&  alarma[actual].compareTo(buf3) == 0 ){ // permite desactivar y activar las alarmas.
    activarAlarma();
    actual++;
  }
    else if (activacion == false &&  alarma[actual].compareTo(buf3) == 0 ){
    actual++; 
    }
    
  if (actual == cantidadAlarmas ){
    actual = 0;
  }
}
