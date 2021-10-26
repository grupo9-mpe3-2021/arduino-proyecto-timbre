void mostrarMenuA() {
   // mejorar estetica
   lcd.setCursor (15,0); 
   if (activacion == true){
    lcd.print(F("T:Act"));
   }
   else if (activacion == false) {
    lcd.print (F("T:Des"));
   }
   
   DateTime  now = rtc.now();   
    
   char buf1[] = "hh:mm:ss";
   char buf2[] = "DD/MM/YYYY";
   
   lcd.setCursor(0, 1);    lcd.print(now.toString(buf1));     //Serial.println(now.toString(buf1));
   lcd.setCursor(0, 2);    lcd.print(now.toString(buf2));     //Serial.println(now.toString(buf2));
   lcd.setCursor(0, 3);    lcd.print(F("Prox Alarma: "));     lcd.print(alarma[actual]);     //Serial.println("Siguiente Alarma: ");
   //delay(999);   //delay para evitar que se pase de rosca el display.    
}

void  mostrarMenuB() {
  // ver si funca 
  lcd.setCursor(0, 0);    lcd.print(F("Proximas alarmas:"));
  lcd.setCursor(0, 1);    lcd.print(F("Alarma 1:  "));   lcd.print(alarma[actual]);    //Serial.println(F(alarma[actual]));
  lcd.setCursor(0, 2);    lcd.print(F("Alarma 2:  "));   lcd.print(alarma[actual+1]);  //Serial.println(F(alarma[actual+1]));
  lcd.setCursor(0, 3);    lcd.print(F("Alarma 3:  "));   lcd.print(alarma[actual+2]);  //Serial.println(F(alarma[actual+2]));
  for (int i=0 ; i<cantidadAlarmas ; i++){
    Serial.println (alarma[i]);
  }
  
  keypad.waitForKey();
  lcd.clear();  
}

void mostrarMenuC() {
   // ver si funca
  lcd.setCursor(0, 1);    lcd.print(F("Configuracion:"));
  lcd.setCursor(0, 2);    lcd.print(F("1- Agregar Alarmas"));
  lcd.setCursor(0, 3);    lcd.print(F("2- Eliminar Alarmas"));
  
  key = keypad.waitForKey();  Serial.print(F("introducida la tecla "));   Serial.println(key);
  switch (key) {
    case '1':
      lcd.clear();
      mostrarMenuAgregarAlarma(); // corregir funcionamiento
      alarma[2] = agregarAlarma();
      lcd.clear();
      break;
    case '2':
      lcd.clear();
      mostrarMenuEliminarAlarma(); // corregir funcionamiento
      //eliminarAlarma();
      lcd.clear();
      break; 
    default:
      lcd.clear();
      break;
  }
}

void mostrarMenuEliminarAlarma(){ // por ahora magia hace esto xd.
  Serial.println(F("Mostrando menu de eliminar alarma"));
}

int mostrarMenuAgregarAlarma() {
  Serial.println(F("Mostrando menu para agregar alarma"));
  lcd.setCursor(0, 0);    lcd.print(F("AGREGAR ALARMA "));
}

void mostrarMenuD() { // activa el timbre hasta que toques de nuevo D.
  // ver si funca
  lcd.setCursor (0,1);
  lcd.print (F("1-Alarma Automatica"));

  lcd.setCursor (0,2);
  lcd.print (F("2-Alarma Manual"));

  lcd.setCursor (0,3);
  lcd.print (F("3-Act/Desact Timbre"));
  
  key = keypad.waitForKey(); 
  switch (key){
    
    case '1':
      lcd.clear();
      Serial.println(F("Activando caso ,alarma Set1"));
      activarAlarma();
    break;

    case '2':
      lcd.clear();
      lcd.print(F(" Activando Alarma"));  Serial.println(F("Activando caso ,alarma Set2"));
      activarAlarma2();
    break;
    
    case '3':
      lcd.clear();
      if (activacion == true){
        
        lcd.setCursor(3,1);
        lcd.print("*Advertencia*");
        
        lcd.setCursor(0,2);
        lcd.print(F("Desactivando Alarmas"));  Serial.println(F("La activacion de alarmas fue desactivada."));
        
        activacion = false;
        
        delay (2000);
        lcd.clear();
      }
      else if (activacion == false){
        
        lcd.setCursor(3,1);
        lcd.print(F("*Advertencia*"));
        
        lcd.setCursor(2,2);
        lcd.print(F("Activando Alarmas"));     Serial.println(F("La activacion de alarmas fue activada."));
        
        activacion = true;
        
        delay (2000);
        lcd.clear();    
      }
      break;  
      default: lcd.clear();
  }
}
