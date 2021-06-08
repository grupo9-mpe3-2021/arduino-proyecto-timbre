   //la sintaxis de sprintf es sprintf (str, formato, argumentos);
   //si pongo "%03d" seria que me rellena 3 cifras con un "0", y tendria por ejemplo 27.000°C
   // el d es para que imprima en base decimal
void printDate(DateTime date)
{
  
   lcd.print(daysOfTheWeek[date.dayOfTheWeek()]);
   lcd.print("   ");
   
   sprintf(buf, "%02d", date.day());
   lcd.print(buf);
   lcd.print('/');
   
   sprintf(buf, "%02d", date.month());
   lcd.print(buf);
   lcd.print('/');
   
   sprintf(buf, "%04d", date.year());
   lcd.print(buf);

   lcd.setCursor(0, 1);
    lcd.print((int)rtc.getTemperature());
    lcd.print(char(0xDF));
    lcd.println("C");
    lcd.print(" ");
   
   sprintf(buf, "%02d", date.hour());
   lcd.print(buf);
   lcd.print(':');
   
   sprintf(buf, "%02d", date.minute());
   lcd.print(buf);
   lcd.print(':');
   
   sprintf(buf, "%02d", date.second());
   lcd.print(buf);
   lcd.print(" ");
}

void checkStatus()
{
  if ( !rtc.begin() ) 
  {
     lcd.print("Couldn't find RTC");
     while (1); //este while es para congelar el programa
  }
  
  if ( rtc.lostPower() ) // Si se ha perdido la corriente, fijar fecha y hora
  {
     rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));     // Fijar a fecha y hora de compilacion
     // Fijar a fecha y hora específica. Ejemplo, 21 de Enero de 2016 a las 03:00:00 --> rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
  }
}


void setupAlarm(DateTime date)
{
  
}
