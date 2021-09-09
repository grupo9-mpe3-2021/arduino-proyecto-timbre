void mostrarMenuA(DateTime date) {
  char buf1[] = "hh:mm:ss";
  char buf2[] = "DD/MM/YYYY";
  Serial.println(date.toString(buf1));
  Serial.println(date.toString(buf2));
  Serial.println("Mostrando menu A");
  
  do{ 
    DateTime now = rtc.now();  
    lcd.setCursor(0, 0);    lcd.print(date.toString(buf1));   
    lcd.setCursor(0, 1);    lcd.print(date.toString(buf2));     
  }while ( key = 'A' );
}

void mostrarMenuB() {
  Serial.println("Mostrando menu B");
  lcd.setCursor(0, 0);    lcd.print("Proximas alarmas:");
  lcd.setCursor(0, 1);    lcd.print("Alarma 1:");   lcd.print(alarma1);
  lcd.setCursor(0, 2);    lcd.print("Alarma 2:");   lcd.print(alarma2);
}

void mostrarMenuC() {
  Serial.println("Mostrando menu C");
  lcd.setCursor(0, 0);    lcd.print("Configuracion:");
  lcd.setCursor(0, 1);    lcd.print("1- Agregar Alarmas");
  lcd.setCursor(0, 2);    lcd.print("2- Eliminar Alarmas");
  lcd.setCursor(0, 3);    lcd.print("3- Alarma manual");
  key = keypad.waitForKey();
  
  /* estoy SEGURO que waitForKey() va a causar un bug, porque va a pausar todo
  y no te va a permitir ir a a ningun otro menu ni se va a activar la alarma,
   pero aca se queda hasta que se me ocurra una mejor solucion SOY PISACANE waitForKey() tiene q ser una interrupcion, se puede hacer ya que es via hardware la 
   activacion de la misma. dsps te mando el cosito que encontre.
   
   
   Hi if we want to listen till a key is pressed and read that pressed value, we dont wanna use the getKey() anymore. Instead use like this

char kpress= keypad.waitForKey();

keypad here refer to the keypad object name you have given earlier. This usage will wait for keypad press event and read the value to kpress char variable.

Bineesh

    basicamente habria que cambiar el getkey que ya tenemos por el waitforkey. al estar de esa manera en teoria deberia seguir funcionando el resto del codigo
    ya que en teoria funciona en simultaneo. o que directamente loope el menu y que dentro del mismo actualice la hora¿? ademas tene en cuenta de que por
    como esta configurada la alarma para sonar, la alarma suena cuando llega a tal hora no? pero no especifica el durante, no tiene duracion de alarma. 
    para el programa, la alarma sucede durante un instante de coincidencia de parametros, (cuando la hora actual es igual a la hora de la alarma). l
    la duracion de la misma se la damos nosotros cuando metemos la funcion activarAlarma(). al no ser un intervalo, no se que pasaria cuando uno justo realice algo, durante-
    la hora de la alarma(cuando tenga q sonar).
   */
  Serial.println("introducida la tecla ");   Serial.print(key);
  switch (key) {
    case '1':
      mostrarMenuAgregarAlarma();
      lcd.clear();
      break;
    case '2':
      mostrarMenuEliminarAlarma();
      lcd.clear();
      break;
    case '3':
      activarAlarma();
      lcd.clear();
      break;
    case 'A': // esto de aca no funca correctamente.
    lcd.clear();
    break; 
    case 'B':
    lcd.clear();
    break;
    case 'C':
    lcd.clear();
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
