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
