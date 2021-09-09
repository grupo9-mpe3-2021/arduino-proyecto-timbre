void checkStatus() {
  // si el rtc no se inicializa:
  if(!rtc.begin()) {
    lcd.print("No se encontro RTC");  Serial.println("No se encontro RTC");
    abort();
  }
  // si el rtc perdio la alimentacion:
  if(rtc.lostPower()) {
    // ajusta la fecha y hora al tiempo de compilacion
    Serial.println("ajustando la fecha y hora al tiempo de compilacion");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  rtc.disable32K();
}

int activarAlarma() {  //falta cambiar por millis()
  digitalWrite(timbre, HIGH);   Serial.println("Activando alarma!");
  delay(1000);
  actual++;
  digitalWrite(timbre, LOW);    Serial.println("Desactivando alarma!");
 // actual es el parametro donde se fija que alarma elegir. 
}


String agregarAlarma() {
  /*
    Esta funcion recibe inputs del teclado y los mete a un String llamado alarma, el cual luego retorna
    Args:
      * ninguno
    Returns:
      * un String con la hora introducida en el teclado
  */
  String alarma = "hh:mm"; //defino el formato de la alarma    //habria que poner esto afuera  <-- no se que quise decir con este comentario, evidentemente con el return se puede hacer miAlarma = agregarAlarma() y listo
  for (int i=0 ; i < 5 ; i++) {
    if (alarma[i] != ':') { //para evitar que me sobreescriba el ":"
      alarma[i] = keypad.waitForKey();    
      lcd.print(alarma[i]);   Serial.println("introducida la tecla ");   Serial.print(alarma [i]);
    }
  }
  return alarma;
}


bool checkearAlarmaIgualHora(DateTime date, String alarma) {
  /*
    Esta funcion checkea si la hora actual es igual a la hora de la alarma
    Args:
      * Hora actual
      * La hora de la alarma (string)
    Returns:
      * true o false dependiendo si alarma == date
  */
  Serial.println("Checkeando si la alarma es igual a la hora... ");
  char buffer[] = "hh:mm";      // hago un buffer con el formato que quiero para mi hora
  date.toString(buffer);        // guardo la hora en el buffer
  String aux = String(buffer);  // convierto mi char[] en String para poder compararlo con la alarma
  //necesito el true de abajo,
  return aux.equals(alarma[actual]);    // pregunto si la hora actual y la hora de la alarma son ==   // Si es es asi, devuelve true, en caso contrario, devuelve false
}/*
int actualizarAlarma(){ 
      do{ // avanza en el tiempo el orden de las alarmas para que cuando sea necesario que suene la alarma por el horario, que este comparando contra la alarma que corresponde.
        alarma++;  
       } while ( alarma[actual] > date ); //falta definir la condicional.
  }

int ordenarAlarmas(){
  int c= cantidadDeAlarmas;
  for (int a=0;a<c;a++){ // C es la cantidad de alarmas.
    for (int b=a;b<c;b++){
         if ( alarma[a] < alarma[b] ){
            alarma[a] = d; d es mi variable auxiliar.
             
         }
    }
  }
}*/




 
