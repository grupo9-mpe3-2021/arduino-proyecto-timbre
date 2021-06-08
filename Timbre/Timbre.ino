#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
#include <Key.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x20,16,2);
RTC_DS3231 rtc;

String daysOfTheWeek[7] = { "DOM", "LUN", "MAR", "MIE", "JUE", "VIE", "SAB" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
char buf[64];
const int cantidadFilas = 4; //cuatro filas
const int cantidadColumnas = 4; //cuatro columnas

char teclas[cantidadFilas][cantidadColumnas] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinFilas[cantidadFilas] = {9, 8, 7, 6}; //este es el pinout de las filas del teclado
byte pinColumnas[cantidadColumnas] = {5, 4, 3, 2}; //este es el pinout de las columnas del teclado

Keypad keypad = Keypad( makeKeymap(teclas), pinFilas, pinColumnas, cantidadFilas, cantidadColumnas );

void setup()
{ 
  lcd.init();
  lcd.backlight();
  checkStatus();
}

void loop()
{
  // Obtener fecha actual y mostrar por lcd
  DateTime now = rtc.now();
  printDate(now);
  delay(30);
  
  char key = keypad.getKey();
}
