void checkStatus() {
  // si el rtc no se inicializa:
  if(!rtc.begin()) {
    lcd.println("No se encontro RTC");
    abort();
  }
  // si el rtc perdio la alimentacion:
  if(rtc.lostPower()) {
    // ajusta la fecha y hora al tiempo de compilacion
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  rtc.disable32K();
}

int activarAlarma() {  //falta desactivar la alarma
  digitalWrite(timbre, HIGH);
}


String agregarAlarma() {
  String alarma = "hh:mm"; //defino el formato de la alarma    //habria que poner esto afuera
  for (int i=0 ; i < 5 ; i++) {
    if (alarma[i] != ':') { //para evitar que me sobreescriba el ":"
      alarma[i] = keypad.getKey();    
      lcd.print(alarma[i]);   Serial.println("introducida la tecla ");   Serial.print(alarma [i]);
    }
  }
  return alarma;
}


bool checkearAlarmaIgualHora(DateTime date, String alarma) {
  char buffer[] = "hh:mm";      // hago un buffer con el formato que quiero para mi hora
  date.toString(buffer);        // guardo la hora en el buffer
  String aux = String(buffer);  // convierto mi char[] en String para poder compararlo con la alarma
  return aux.equals(alarma);    // comparo el string de la linea anterior (o sea, la hora actual) con la hora de la alarma
}
