void checkStatus() {
  // si el rtc no se inicializa:
  if (!rtc.begin()) {
    lcd.print(F("No se encontro RTC"));  Serial.println(F("No se encontro RTC"));
    abort();
  }
  else {
    Serial.println(F("Se ha encontrado el RTC correctamente"));
  }
  // si el rtc perdio la alimentacion:
  if (rtc.lostPower()) {
    // ajusta la fecha y hora al tiempo de compilacion
    Serial.println(F("El RTC perdio la alimentacion"));    Serial.println(F("ajustando la fecha y hora al tiempo de compilacion"));
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  rtc.disable32K();
  Serial.println(F("Finalizado el checkeo de status"));
}

int activarAlarma() {  //falta cambiar por millis()
  lcd.clear();
  digitalWrite(timbre, HIGH);   Serial.println(F("Activando alarma set1!"));
  lcd.setCursor (2, 1);
  lcd.print(F("Alarma Activada"));
  delay(3000); // cambiar tiempo de activacion.

  digitalWrite(timbre, LOW);    Serial.println(F("Desactivando alarma!"));
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(F("Alarma Desactivada"));
  delay(1500);

  lcd.clear();
}

int activarAlarma2() { //testear funcionamiento.

  lcd.clear();
  digitalWrite(timbre, HIGH);   Serial.println(F("Activando alarma set2!"));

  lcd.setCursor (4, 1);
  lcd.print (F("-Pulsar '*'-"));
  lcd.setCursor (0, 2);
  lcd.print (F("Desactiva la Alarma"));  Serial.println(F("Pulsar '*' para desactivar la Alarma"));

  keypad.waitForKey() == '*'; // espera a que se pulse '*' para desactivar la alarma.
  lcd.clear();
  digitalWrite(timbre, LOW);    Serial.println(F("Desactivando alarma!"));

}


void sort(String myArray[], int size) {
  String auxiliar;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j<(size-1) ; ++j) {
      if (myArray[j] > (myArray[j + 1])) {
        auxiliar = (myArray[j + 1]);
        (myArray[j + 1]) = myArray[j];
        myArray[j] = auxiliar;
      }
    }
  }
}
String agregarAlarma() {
  /*
    Esta funcion recibe inputs del teclado y los mete a un String llamado alarma, el cual luego retorna
    Args:
        ninguno
    Returns:
        un String con la hora introducida en el teclado
  */
  lcd.setCursor(0, 1);
  lcd.print (F("Formato hh:mm "));    Serial.println(F("Agregando Alarma..."));
  String aux1 = "hh:mm"; //defino el formato de la alarma
  for (int i = 0 ; i < 5 ; i++) {
    if (aux1[i] != ':') { //para evitar que me sobreescriba el ":"
      aux1[i] = keypad.waitForKey();
      lcd.print(aux1[i]);   Serial.print(F("introducida la tecla "));   Serial.println(aux1[i]);
    }
    else {
      lcd.print(aux1[i]);
    }
  }
  return aux1;
}

void actualizarAlarma() { 
  /*
   * Esta funcion funciona de la siguiente forma:
   * TODO de pisacane
   * 
   * 
   * Esta funcion se usa en los siguientes casos:
   * TODO de pisacane
   */
  Serial.println(F("Llamando actualizarAlarma()"));
  // fija la siguiente alarma luego de un reset o power on.

  DateTime now = rtc.now();
  
  char alarmaVacia[] = "XX:XX";
  char horaActual[] = "hh:mm";
  now.toString(horaActual);
  actual = 0;
  int aux2 = 0; 
  for (int i = 0; i < cantidadAlarmas ; i++){
    if (alarma[i].compareTo(alarmaVacia) == 0 ){
      Serial.println(F("Sorteando i guess"));
      sort(alarma, 20); //Aca va el sort de golmar
    }
  }
  
  //esto hace que actual se loopee entre la cantidad maxima de alarmas
  for (int i = 0; i < cantidadAlarmas ; i++) { //alarma[actual].compareTo(buf4) <= 0
    if ( alarma[actual].compareTo(horaActual) <= 0 ) { // 
      Serial.println(F("Haciendo actual ++"));
      actual++;
    }
    Serial.print("alarma ");    Serial.print(i+1);     Serial.print(" actualizada con el valor "); 
    Serial.println(alarma[i]);
  }
  Serial.print("Valor de actual: ");    Serial.println(actual); 
}

void eliminarAlarma(int alarmaABorrar) {
  Serial.print(F("Recibido que hay que borrar la alarma en la posición "));    Serial.println(alarmaABorrar);
  alarma[alarmaABorrar-1] = "XX:XX";
  actualizarAlarma();
}



/*
  bool checkearAlarmaIgualHora(DateTime date, String alarma) {
  /*
    Esta funcion checkea si la hora actual es igual a la hora de la alarma
    Args:
        Hora actual
        La hora de la alarma (string)
    Returns:
        true o false dependiendo si alarma == date

  Serial.println(F("Checkeando si la alarma es igual a la hora... "));
  char buffer[] = "hh:mm";      // hago un buffer con el formato que quiero para mi hora
  date.toString(buffer);        // guardo la hora en el buffer
  String aux = String(buffer);  // convierto mi char[] en String para poder compararlo con la alarma
  //necesito el true de abajo,

  return aux.equals(alarma[actual]); // pregunto si la hora actual y la hora de la alarma son ==
  // Si es es asi, devuelve true, en caso contrario, devuelve false

  }

  compareTo()
  [StringObject Function]
  Description

  Compares two Strings, testing whether one comes before or after the other, or whether they’re equal. The strings are compared character by character, using the ASCII values of the characters. That means, for example, that 'a' comes before 'b' but after 'A'. Numbers come before letters.
  Syntax

  myString.compareTo(myString2)
  Parameters

  myString: a variable of type String.
  myString2: another variable of type String.
  Returns

  a negative number: if myString comes before myString2.
  0: if String equals myString2.
  a positive number: if myString comes after myString2.

*/
