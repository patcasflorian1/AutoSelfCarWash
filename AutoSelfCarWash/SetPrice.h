
// setare timp/coin
void coin_time(int timeCoin,int timeCoinsEeprom,String msg){
    checkPush();
   lcd.clear();
    delay(250);
    bool setPrice = true ;
    do{
    checkPush();  
   lcd.setCursor(0,0);
  lcd.print("++ => SpumaActiva");
   lcd.setCursor(0,1);
  lcd.print("-- => SpCuPresiune");
   lcd.setCursor(0,2);
  lcd.print("Save => Pauza");
   lcd.setCursor(0,3);
  lcd.print("1Ron= ");
  if(timeCoin/60<10)
  lcd.print("0");
  lcd.print(timeCoin/60);
   lcd.print("M");
    lcd.print("+");
    lcd.setCursor(11,3);
    lcd.print("Sec:");
    if((timeCoin%60)<10)
      lcd.print("0");
   lcd.print(timeCoin%60);

   if(keyPress == 28){
      delay(350);  
     timeCoin ++;
     if(msg.equals("Pauza")){
       if(timeCoin>breakTime){
         timeCoin = 0;
       }
     }
      if(timeCoin > 600){
        timeCoin = 0;
      }
    }
     if(keyPress == 29){
      delay(350);  
     timeCoin --;
      if(timeCoin <=0){
        timeCoin = 0;
      }
    }
     if(keyPress == 30){
      delay(350);  
     timeCoin = 0;
     lcd.clear();
    }

   if(keyPress == 33){
      delay(350);  
    EEPROM.put(timeCoinsEeprom,timeCoin);
    lcd.clear();  
    setPrice = false;
    menuOk = true;
    keyPress = 0;
    }
}while(setPrice==true);
lcd.clear();
}



void menuSet(int timeCoinSet,int timeCoinsEepromSet,String mesaj){
  isOk = 0 ;
 while(isOk==0){
    checkPush();  
   lcd.setCursor(0,0);
  lcd.print("Pret "); lcd.print(mesaj);
   lcd.setCursor(0,1);
  lcd.print("Next=>SpumaActiva");
  lcd.setCursor(0,2);
  lcd.print("Setare=>Spal.Cu Pres");
    lcd.setCursor(0,3);
    lcd.print(" Iesire => Pauza");
     if(keyPress == 28){
      delay(350);
      isOk=1;
      lcd.clear();
    }
     //delay(350);
   if(keyPress == 29){
     delay(350);
     coin_time(timeCoinSet,timeCoinsEepromSet,mesaj);
     // isOk=2;
      //menuOk=false;
      lcd.clear();
    }
     if(keyPress == 33){
      delay(350);
      isOk=7;
      menuOk = false;
      lcd.clear();
    }
}
}

void coinTimeSet(){
  timeCoin1 =  EEPROM.get(timeCoinsEeprom1,timeCoin1); //spuma activa
  timeCoin2 = EEPROM.get(timeCoinsEeprom2,timeCoin2);  //presiune
  timeCoin3 = EEPROM.get(timeCoinsEeprom3,timeCoin3);  //spalare cu spuma
  timeCoin4 = EEPROM.get(timeCoinsEeprom4,timeCoin4);   //osmoza
  timeCoin5 = EEPROM.get(timeCoinsEeprom5,timeCoin5);   //ceara
  timeCoin6 = EEPROM.get(timeCoinsEeprom6,timeCoin6);   //pauza
  delay(300);
  lcd.clear();
  do{
    if(menuOk == true)
    menuSet(timeCoin1,timeCoinsEeprom1,"SpumaActiva");
    if(menuOk == true)
    menuSet(timeCoin2,timeCoinsEeprom2,"SpalareCuPres");
    if(menuOk == true)
    menuSet(timeCoin3,timeCoinsEeprom3,"SpalareCuSpuma");
    if(menuOk == true)
    menuSet(timeCoin4,timeCoinsEeprom4,"Osmoza");
    if(menuOk == true)
    menuSet(timeCoin5,timeCoinsEeprom5,"Ceara");
    if(menuOk == true)
    menuSet(timeCoin6,timeCoinsEeprom6,"Pauza");
  }while(menuOk == true);
}

void displayCoinTime(){
  timeCoin1 =  EEPROM.get(timeCoinsEeprom1,timeCoin1); //spuma activa
  timeCoin2 = EEPROM.get(timeCoinsEeprom2,timeCoin2);  //presiune
  timeCoin3 = EEPROM.get(timeCoinsEeprom3,timeCoin3);  //spalare cu spuma
  timeCoin4 = EEPROM.get(timeCoinsEeprom4,timeCoin4);   //osmoza
  timeCoin5 = EEPROM.get(timeCoinsEeprom5,timeCoin5);   //ceara
  timeCoin6 = EEPROM.get(timeCoinsEeprom6,timeCoin6);   //pauza
  delay(300);
  lcd.clear();
  int nextprice = 0;
  bool printDisplay = true ;
 do {
  
   checkPush(); 
   if(keyPress == 28){
     nextprice ++;
     delay(500);
     lcd.clear();
   }
   if(keyPress == 33){
     printDisplay = false;
   } 
   lcd.setCursor(0,0);
   lcd.print("Next =>SpumaActiva");
   lcd.setCursor(0,1);
   lcd.print("Exit => Pauza");

  
   switch (nextprice){
     case 0 :{
       lcd.setCursor(0,2);
       lcd.print("1Ron ");
       lcd.print("SpumaActiva =");
       lcd.setCursor(3,3);
       lcd.print(timeCoin1/60);
       lcd.print("min : sec ");
       lcd.print(timeCoin1%60);
     }break;
     case 1 :{
       lcd.setCursor(0,2);
       lcd.print("1Ron ");
       lcd.print("SpalarePres =");
       lcd.setCursor(3,3);
       lcd.print(timeCoin2/60);
      lcd.print("min : sec ");
       lcd.print(timeCoin2%60);
     }break;
     case 2 :{
        lcd.setCursor(0,2);
       lcd.print("1Ron ");
       lcd.print("SpalareCuSpuma=");
       lcd.setCursor(3,3);
       lcd.print(timeCoin3/60);
       lcd.print("min : sec ");
       lcd.print(timeCoin3%60);
     }break;
     case 3 :{
       lcd.setCursor(0,2);
       lcd.print("1Ron "); 
       lcd.print(" Osmoza =");
       lcd.setCursor(3,3);
       lcd.print(timeCoin4/60);
       lcd.print("min : sec ");
       lcd.print(timeCoin4%60);
     }break;
     case 4 :{
       lcd.setCursor(0,2);
       lcd.print("1Ron ");
       lcd.print(" Ceara =");
       lcd.setCursor(3,3);
       lcd.print(timeCoin5/60);
       lcd.print("min : sec ");
       lcd.print(timeCoin5%60);
     }break;
     case 5 :{
      lcd.setCursor(0,2);
       lcd.print(" Pauza : ");
       lcd.print(timeCoin6%60);
       lcd.print(" sec ");
     }break;
   }
   if(nextprice > 5)
     nextprice = 0;
  }while(printDisplay == true);
}
