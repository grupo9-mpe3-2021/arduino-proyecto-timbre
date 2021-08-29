int mostrarMenuA(DateTime date) {
  char buf1[] = "hh:mm:ss";
  char buf2[] = "DD:MM:YYYY";
  lcd.setCursor(0, 0);    lcd.println(date.toString(buf1));   Serial.println(date.toString(buf1));
  lcd.setCursor(0, 1);    lcd.println(date.toString(buf2));   Serial.println(date.toString(buf2)); 
}

int mostrarMenuB() {
  lcd.setCursor(0, 0);    lcd.print("Proximas alarmas:");
  lcd.setCursor(0, 1);    lcd.print("Alarma 1:");   lcd.print(alarma1);
  lcd.setCursor(0, 2);    lcd.print("Alarma 2:");   lcd.print(alarma2);
}

int mostrarMenuC() {
  lcd.setCursor(0, 0);    lcd.print("Configuracion:");
  lcd.setCursor(0, 1);    lcd.print("1- Agregar Alarmas");
  lcd.setCursor(0, 2);    lcd.print("2- Eliminar Alarmas");
  lcd.setCursor(0, 3);    lcd.print("3- Alarma manual");
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
        
}

void mostrarMenuAgregarAlarma() {
  lcd.setCursor(0, 0);    lcd.print("AGREGAR ALARMA ");
  lcd.setCursor(0, 1);
  alarma1= agregarAlarma();
}