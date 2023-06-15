
void displayConta(){
  lcd.clear();
   totalCoin = EEPROM.get(totalCoins,totalCoin);
   boolean set = true;
    while(set){
     checkPush(); //read the keypad
    lcd.setCursor(1,0);
    lcd.print("  Total Amount : ");
    lcd.setCursor(4,1);
    lcd.print(totalCoin);
    lcd.print(" Ron");
    lcd.setCursor(0,2);
    lcd.print("Exit=>SpumaActiva");
    if(keyPress == 28){
     delay(350);
     set = false;
     validMaster = true;
  validAtt =true;
  validServ = true;
    }
  }
}

void displayContaAttendant(){
  lcd.clear();
   totalCoin = EEPROM.get(totalCoins,totalCoin);
   boolean set = true;
    while(set){
     checkPush(); //read the keypad
    lcd.setCursor(1,0);
    lcd.print("  Total Amount : ");
    lcd.setCursor(4,1);
    lcd.print(totalCoin);
    lcd.print(" Ron");
    lcd.setCursor(0,2);
    lcd.print("Exit=>SpumaActiva");
    lcd.setCursor(0,3);
    lcd.print("Delete=>Pauza");
     if(keyPress == 28){
     delay(350);
     set = false;
     validMaster = true;
  validAtt =true;
  validServ = true;
    }
    if(keyPress == 33){
     delay(350);
     totalCoin = 0 ;
     EEPROM.put(totalCoins,totalCoin);
    }
    if(keyPress == 29){
     delay(350);
     if((totalCoin-50)>100){
     totalCoin = totalCoin - 50 ;
     EEPROM.put(totalCoins,totalCoin);
     }
    }
     if(keyPress == 30){
     delay(350);
     referanceAttCoin = referanceAttCoin + 50 ;
     EEPROM.put(referanceAttCoins,referanceAttCoin);
     lcd.clear();
     lcd.print("Coin AttRef");
     lcd.setCursor(0,1);
     referanceAttCoin = EEPROM.get(referanceAttCoins,referanceAttCoin);
     lcd.print(referanceAttCoin);
     delay(500);
     lcd.clear();
     }
     if(keyPress == 31){
     delay(350);
     referanceAttCoin = 0;
     EEPROM.put(referanceAttCoins,referanceAttCoin);
      lcd.clear();
     lcd.print("Coin AttRef");
     lcd.setCursor(0,1);
     referanceAttCoin = EEPROM.get(referanceAttCoins,referanceAttCoin);
     lcd.print(referanceAttCoin);
     delay(500);
     lcd.clear();
    }
    if(keyPress == 32){
     delay(350);
      lcd.clear();
     lcd.print("Coin AttRef");
     lcd.setCursor(0,1);
     referanceAttCoin = EEPROM.get(referanceAttCoins,referanceAttCoin);
     lcd.print(referanceAttCoin);
     delay(500);
     lcd.clear();
    }
  }
}

void displayMaster(){
 lcd.clear();
   totalCoin = EEPROM.get(totalCoins,totalCoin);
   masterCoin = EEPROM.get(masterCoins,masterCoin);
   referanceCoin = EEPROM.get(referanceCoins,referanceCoin);
   boolean set = true;
    while(set){
     checkPush(); //read the keypad
    lcd.setCursor(1,0);
    lcd.print("  Total Amount : ");
    lcd.setCursor(0,1);
    lcd.print("Att:");
    lcd.print(totalCoin);
    lcd.print("Mast:");
    lcd.print(masterCoin);
    lcd.setCursor(0,2);
    lcd.print("Exit=>SpumaActiva");
    lcd.setCursor(0,3);
    lcd.print("Delete=>Pauza");

     if(keyPress == 28){
     delay(350);
     set = false;
     validMaster = true;
  validAtt =true;
  validServ = true;
    }
    if(keyPress == 33){
     delay(350);
     masterCoin = 0 ;
     EEPROM.put(masterCoins,masterCoin);
    }
    if(keyPress == 30){
     delay(350);
     referanceCoin = referanceCoin + 50 ;
     EEPROM.put(referanceCoins,referanceCoin);
     lcd.clear();
     lcd.print("Coin MasterRef");
     lcd.setCursor(0,1);
     referanceCoin = EEPROM.get(referanceCoins,referanceCoin);
     lcd.print(referanceCoin);
     delay(500);
     lcd.clear();
     }
     if(keyPress == 31){
     delay(350);
     referanceCoin = 0;
     EEPROM.put(referanceCoins,referanceCoin);
      lcd.clear();
     lcd.print("Coin MasterRef");
     lcd.setCursor(0,1);
     referanceCoin = EEPROM.get(referanceCoins,referanceCoin);
     lcd.print(referanceCoin);
     delay(500);
     lcd.clear();
    }
    if(keyPress == 32){
     delay(350);
      lcd.clear();
     lcd.print("Coin MasterRef");
     lcd.setCursor(0,1);
     referanceCoin = EEPROM.get(referanceCoins,referanceCoin);
     lcd.print(referanceCoin);
     delay(500);
     lcd.clear();
    }
    }
}