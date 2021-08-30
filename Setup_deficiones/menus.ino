int mostrarMenuA(DateTime date) {
  Serial.println("Mostrando menu A");
  char buf1[] = "hh:mm:ss";
  char buf2[] = "DD:MM:YYYY";
  lcd.setCursor(0, 0);    lcd.print(date.toString(buf1));   Serial.println(date.toString(buf1));
  lcd.setCursor(0, 1);    lcd.print(date.toString(buf2));   Serial.println(date.toString(buf2)); 
}

int mostrarMenuB() {
  Serial.println("Mostrando menu B");
  lcd.setCursor(0, 0);    lcd.print("Proximas alarmas:");
  lcd.setCursor(0, 1);    lcd.print("Alarma 1:");   lcd.print(alarma1);
  lcd.setCursor(0, 2);    lcd.print("Alarma 2:");   lcd.print(alarma2);
}

int mostrarMenuC() {
  Serial.println("Mostrando menu C");
  lcd.setCursor(0, 0);    lcd.print("Configuracion:");
  lcd.setCursor(0, 1);    lcd.print("1- Agregar Alarmas");
  lcd.setCursor(0, 2);    lcd.print("2- Eliminar Alarmas");
  lcd.setCursor(0, 3);    lcd.print("3- Alarma manual");
  key = keypad.waitForKey();
  /* estoy SEGURO que waitForKey() va a causar un bug, porque va a pausar todo
  y no te va a permitir ir a a ningun otro menu ni se va a activar la alarma,
   pero aca se queda hasta que se me ocurra una mejor solucion */
  Serial.println("introducida la tecla ");   Serial.print(key);
  switch (key) {
    case '1':
      mostrarMenuAgregarAlarma();
      break;
    case '2':
      mostrarMenuEliminarAlarma();
      break;
    case '3':
      activarAlarma();
      break;
  }
}

int mostrarMenuEliminarAlarma(){
  Serial.println("Mostrando menu de eliminar alarma");
}

void mostrarMenuAgregarAlarma() {
  Serial.println("Mostrando menu para agregar alarma");
  lcd.setCursor(0, 0);    lcd.print("AGREGAR ALARMA ");
  lcd.setCursor(0, 1);
}