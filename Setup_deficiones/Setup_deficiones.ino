// agregar con interrupciones via  hw un boton fisico que con el flanco ascendente (cuando lo detecta),cambie el estado.

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Wire.h>
#include <RTClib.h>
#define pinINT 2 
#define timbre 11

LiquidCrystal_I2C lcd(0x27,20,4);
RTC_DS3231 rtc;


String alarma1 = "hh:mm"; //defino el formato de la alarma
String alarma2 = "hh:mm"; //defino el formato de la alarma

// Variables del RTC :
int factorCompensacion = 7; // El reloj esta desfasado 7 segundos, esta variable toma en cuenta esa diferencia.
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
byte pinFilas[cantidadFilas] = {10, 9, 8, 7}; //este es el pinout de las filas del teclado
byte pinColumnas[cantidadColumnas] = {6, 5, 4, 3}; //este es el pinout de las columnas del teclado
Keypad keypad = Keypad( makeKeymap(teclas), pinFilas, pinColumnas, cantidadFilas, cantidadColumnas );

void setup() {
  Serial.begin(9600);
  checkStatus();
  lcd.init();
  lcd.backlight();
  Serial.println("Setup finalizado");
}

void loop() {
  DateTime now = rtc.now();
  key = keypad.getKey();
  switch (key) {
    case 'A':
      mostrarMenuA(now);
      break;
    case 'B':
      mostrarMenuB();
      break;
    case 'C':
      mostrarMenuC();
      alarma1= agregarAlarma();
      break;
  }
  if (checkearAlarmaIgualHora(now, alarma1) == true) {
    Serial.println("la hora es igual a la alarma");  activarAlarma();
  }
}
