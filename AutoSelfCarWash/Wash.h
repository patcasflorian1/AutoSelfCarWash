

// activare releu vacuumCleaner
void wash(){
elapsedMillis timeContor; //declare global if you don't want it reset every time loop runs
elapsedMillis timeElapsedBreak; //declare global if you don't want it reset every time loop runs
// delay in milliseconds between blinks of the LED
   unsigned int interval = 1000;
 programSelector = 0;
 //Extract from memory price of coin
   timeCoin1 =  EEPROM.get(timeCoinsEeprom1,timeCoin1);
   timeCoin2 = EEPROM.get(timeCoinsEeprom2,timeCoin2);
   timeCoin3 = EEPROM.get(timeCoinsEeprom3,timeCoin3);
   timeCoin4 = EEPROM.get(timeCoinsEeprom4,timeCoin4);
   timeCoin5 = EEPROM.get(timeCoinsEeprom5,timeCoin5);
   timeCoin6 = EEPROM.get(timeCoinsEeprom6,timeCoin6);
   //unsigned long returnArray[4];
//Return if coin = 0
   lcd.noBlink();
   if(coin == 0){
     lcd.clear();
    lcd.print(" Credit 0");
    delay(1200);
    lcd.clear();
    return;
       }
     
       lcd.clear();
   
       while((isOk1 == false)||(coin>0)){
        checkPush ();
       contorBreak = 0;
       lcd.setCursor(2,0);
  lcd.print("Alegeti Programul");
  lcd.setCursor(8,1);
  lcd.print("Din ");
  lcd.setCursor(2,2);
 lcd.print("Lista de Butoane");
  lcd.setCursor(4,3);
  lcd.print("Credit:");
  lcd.print(coin);
  lcd.print(" RON");
     
    //ledDriverRunVaccum();
        
        Serial.print("keyPress "); Serial.println(keyPress);
       if(keyPress>0){
          masterCoin = EEPROM.get(masterCoins,masterCoin);
          totalCoin =  EEPROM.get(totalCoins,totalCoin);
          totalCoin = totalCoin+coin;
          masterCoin = masterCoin + coin;
          EEPROM.put(totalCoins,totalCoin);
          EEPROM.put(masterCoins,masterCoin);
        isOk1=true;
        digitalWrite(inhibitCoin,LOW);
         programSelector=0;
         timeContor=0;
         lcd.clear();
         switch(keyPress){
           case 28 : {
             spumaActiva();
           }break;
           case 29 : {
             clatireCuPresiune();
           }break;
           case 30 : {
             spalareCuSpuma();
           }break;
           case 31 : {
             clatireFaraPete();
           }break;
           case 32 : {
             ceara();
           }break;
         }
       }
    };
       
       while(isOk1==true){
     ;
          checkPush ();
    digitalWrite(inhibitCoin,HIGH);

     if(isOk1 == true) {   
    switch (keyPress) {
           case 28 : {
             spumaActiva();
           }break;
           case 29 : {
             clatireCuPresiune();
           }break;
           case 30 : {
             spalareCuSpuma();
           }break;
           case 31 : {
             clatireFaraPete();
           }break;
           case 32 : {
             ceara();
           }break;
            case 33 : {
              if(contorBreak == 0){
                contorBreak=1;
              tempSelector = programSelector ;
             pauza();
              }
           }break;
    }
     }
    
        
            
   //__End Set time-Price
//Display Time
    lcd.setCursor(0,0);
   switch(programSelector){
     case 1:{
         lcd.print("   Spuma Activa:"); 
         lcd.setCursor(0,3); lcd.print("Pret: ");
         lcd.print("1Ron="); lcd.print(timeCoin1/60);
         lcd.print(",");
         lcd.print(timeCoin1%60);
         lcd.print("Min");
     }break;
     case 2: {
       lcd.print("Spalare Cu Presiune:");
       lcd.setCursor(0,3); lcd.print("Pret: ");
       lcd.print("1Ron="); lcd.print(timeCoin2/60);
       lcd.print(",");
       lcd.print(timeCoin2%60);
       lcd.print("Min");
     }break;
     case 3 :{
      lcd.print(" Spalare Cu Spuma:");
      lcd.setCursor(0,3); lcd.print("Pret: ");
      lcd.print("1Ron="); lcd.print(timeCoin3/60);
      lcd.print(",");
      lcd.print(timeCoin3%60);
      lcd.print("Min");
     }break;
     case 4 :{
      lcd.print(" Clatire Fara Pete:");
      lcd.setCursor(0,3); lcd.print("Pret: ");
      lcd.print("1Ron="); lcd.print(timeCoin4/60);
      lcd.print(",");
      lcd.print(timeCoin4%60);
      lcd.print("Min");
     }break;
     case 5 :{
      lcd.print(" Sigilare cu Ceara:");
      lcd.setCursor(0,3); lcd.print("Pret: ");
      lcd.print("1Ron="); lcd.print(timeCoin5/60);
      lcd.print(",");
      lcd.print(timeCoin5%60);
      lcd.print("Min");
     }break;
     case 6 :{
       lcd.print("     Pauza ");
     }break;
   }
   if(programSelector == 6){
   
     lcd.setCursor( 2,2);
     lcd.print(" Secunde :");
    if(timeCoin6<10)
    lcd.print("0"); 
     lcd.print(timeCoin6);
     if(timeCoin6 <=0){
       lcd.clear();
       programSelector = tempSelector;
       Serial.print("selector "); Serial.println(programSelector);
       switch(programSelector){
     case 1:{
         digitalWrite(pinReel[0],HIGH);
       digitalWrite(pinReel[1],HIGH);
      digitalWrite(pinReel[2],HIGH);
     }break;
     case 2: {
      digitalWrite(pinReel[0],HIGH);
      digitalWrite(pinReel[1],HIGH);
     }break;
     case 3 :{
      digitalWrite(pinReel[0],HIGH);
      digitalWrite(pinReel[1],HIGH);
      digitalWrite(pinReel[3],HIGH);
     }break;
     case 4 :{
       digitalWrite(pinReel[0],HIGH);
      digitalWrite(pinReel[1],HIGH);
      digitalWrite(pinReel[4],HIGH);
     }break;
     case 5 :{
       digitalWrite(pinReel[0],HIGH);
      digitalWrite(pinReel[1],HIGH);
      digitalWrite(pinReel[5],HIGH);
     }break;
   }
     }
     if(timeElapsedBreak >= interval){
       timeElapsedBreak = 0 ;
       timeCoin6 --;
     }
   }

//Timer for St1
if((programSelector>0)&&(programSelector<6))
{
  checkPush ();
  lcd.setCursor(0,1);
  lcd.print("   Timp Ramas :");
  lcd.setCursor(3,2);
   lcd.print("Min:");
   if(minuteRamase>=10){
     lcd.print(minuteRamase);
          }
          else{
            
             lcd.print("0");
            lcd.print(minuteRamase); 
          }      
   lcd.print(",");
   if(secundeRamase>=10){
   // lcd.setCursor(9,2);
     lcd.print(secundeRamase);
   }
   else{
   // lcd.setCursor(9,2);
     lcd.print("0");
  lcd.print(secundeRamase);
   }
   checkPush ();
  lcd.print(" Sec");
  if(timeContor>=interval){
    if((secundeRamase <=0)&&(minuteRamase>0)){
    minuteRamase--;
   secundeRamase = 59;
    }
    secundeRamase--;
    totalTimeCoin--;
    timeContor =0;
    }
   
    if(totalTimeCoin<=0){
      totalTimeCoin = 0;
      timeContor =0;
      programSelector=0;
       lcd.clear();
     // coin = 0;
      isOk1 = false;
      for(int i=0;i<4;i++){
        
      digitalWrite(pinReel[i],LOW);
      }
      digitalWrite(inhibitCoin,LOW);
    }
}
//end Timer for St1
if(isOk1 ==true){
  digitalWrite(inhibitCoin, HIGH);
}
  } 
}

