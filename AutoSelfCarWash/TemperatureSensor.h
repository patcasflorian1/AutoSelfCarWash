

float getTemp(){
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  //print the temperature in Celsius
 // Serial.print("Temperature: ");
 // Serial.print(sensors.getTempCByIndex(0));
 // Serial.print((char)176);//shows degrees character
 // Serial.print("C  |  ")
 float tmp = sensors.getTempCByIndex(0); 
  lcd.setCursor(2, 3);
  lcd.print("Temp ");lcd.print(tmp);lcd.print("");lcd.write(0xdf);lcd.print("C");
  //print the temperature in Fahrenheit
  //Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  //Serial.print((char)176);//shows degrees character
  //Serial.println("F");
  return tmp ;
}

void setTemperature(){
  temperature = EEPROM.read(temperatureEeprom);
   bool setTemp = true ;
   lcd.clear();
    do{
    checkPush();  
   lcd.setCursor(0,0);
  lcd.print("Set TempReferance"); 
   lcd.setCursor(0,1);
  lcd.print("++ => SpumaActiva");
   lcd.setCursor(0,2);
  lcd.print("Save => Pauza");
  lcd.setCursor(0,3);
  lcd.print("Temperatura: ");
  if(temperature<10)
  lcd.print("0");
  lcd.print(temperature);
   lcd.write(0xdf);lcd.print("C");
   
   if(keyPress == 28){
      delay(350);  
     temperature ++;
   
       if(temperature>25){
         temperature = 0;
       }
    }
     if(keyPress == 30){
      delay(350);  
     temperature = 0;
     lcd.clear();
    }

   if(keyPress == 33){
      delay(350);  
    EEPROM.put(temperatureEeprom,temperature);
    lcd.clear();  
    setTemp = false;
    menuOk = true;
    keyPress = 0;
    }
}while(setTemp==true);
lcd.clear();
}