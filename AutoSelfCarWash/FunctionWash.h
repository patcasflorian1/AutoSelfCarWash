

//Set time-price for spumaActiva
void spumaActiva(){

   if(programSelector == 6){
     programSelector = tempSelector;
   }
  
   lcd.clear();
     if(programSelector!=1){
           for(int i=0;i<6;i++){ 
      digitalWrite(pinReel[i],LOW);
      delay(5);
      }
       
       digitalWrite(pinReel[0],HIGH);
       digitalWrite(pinReel[1],HIGH);
      digitalWrite(pinReel[2],HIGH);
       switch(programSelector){
         case 0 :{
            totalCoin =  EEPROM.get(totalCoins,totalCoin);
          totalCoin = totalCoin+coin;
          EEPROM.put(totalCoins,totalCoin);
         isOk1=true;
            totalTimeCoin = coin*timeCoin1;
     minuteRamase = (coin*timeCoin1)/60;
     secundeRamase =((coin*timeCoin1)%60);
     coin = 0;    
     programSelector=1;
     lcd.clear();
          // digitalWrite(pinReel[0],HIGH);
         }break;
         case 2 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin2);
       totalTimeCoin =  newCoin* timeCoin1;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=1;
      lcd.clear();
   //  digitalWrite(pinReel[0],HIGH);
         }break;
      case 3 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin3);
       totalTimeCoin =  newCoin* timeCoin1;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=1;
      lcd.clear();
     // digitalWrite(pinReel[0],HIGH);
         }break;
        case 4 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin4);
       totalTimeCoin =  newCoin* timeCoin1;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=1;
      lcd.clear();
    //  digitalWrite(pinReel[0],HIGH);
         }break;
         case 5 : {
             newCoin = ((float)totalTimeCoin/(float)timeCoin5);
       totalTimeCoin =  newCoin* timeCoin1;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=1;
      lcd.clear();
         } break;
       }
     } 

}
//__end void spumaActiva
//Set time-price for clatire
 void clatireCuPresiune(){
    if(programSelector == 6){
     programSelector = tempSelector;
   }
  lcd.clear();
     if(programSelector!=2){
          for(int i=0;i<4;i++){
        
      digitalWrite(pinReel[i],LOW);
      delay(5);
      }
      digitalWrite(pinReel[0],HIGH);
      digitalWrite(pinReel[1],HIGH);
       switch(programSelector){
         case 0 :{
            totalCoin =  EEPROM.get(totalCoins,totalCoin);
          totalCoin = totalCoin+coin;
          EEPROM.put(totalCoins,totalCoin);
         isOk1=true;
            totalTimeCoin = coin*timeCoin2;
     minuteRamase = (coin*timeCoin2)/60;
     secundeRamase =((coin*timeCoin2)%60);
     coin = 0;
     programSelector=2;
     lcd.clear();
           
     // digitalWrite(pinReel[1],HIGH);
         }break;
         case 1 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin1);
       totalTimeCoin =  newCoin* timeCoin2;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=2;
      lcd.clear();
     // digitalWrite(pinReel[1],HIGH);
         }break;
      case 3 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin3);
       totalTimeCoin =  newCoin* timeCoin2;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=2;
      lcd.clear();
            
     // digitalWrite(pinReel[1],HIGH);
         }break;
        case 4 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin4);
       totalTimeCoin =  newCoin* timeCoin2;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=2;
      lcd.clear();
      newCoin = 0;
      //digitalWrite(pinReel[1],HIGH);
         }break; 
       case 5 : {
        newCoin = ((float)totalTimeCoin/(float)timeCoin5);
       totalTimeCoin =  newCoin* timeCoin2;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=2;
      lcd.clear();
      newCoin = 0;
       }break;
       }
     }
 }
 //__end void clatire
 //Set time-price for spalareCuSpuma
 void spalareCuSpuma(){
    if(programSelector == 6){
     programSelector = tempSelector;
   }
     lcd.clear();
     if(programSelector!=3){
          for(int i=0;i<6;i++){
        
      digitalWrite(pinReel[i],LOW);
      delay(5);
      }
      digitalWrite(pinReel[0],HIGH);
      digitalWrite(pinReel[1],HIGH);
      digitalWrite(pinReel[3],HIGH);
       switch(programSelector){
         case 0 :{
            totalCoin =  EEPROM.get(totalCoins,totalCoin);
          totalCoin = totalCoin+coin;
          EEPROM.put(totalCoins,totalCoin);
         isOk1=true;
            totalTimeCoin = coin*timeCoin3;
     minuteRamase = (coin*timeCoin3)/60;
     secundeRamase =((coin*timeCoin3)%60);
     coin = 0;     
     programSelector=3;
     lcd.clear();
           
         }break;
         case 1 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin1);
       totalTimeCoin =  newCoin* timeCoin3;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=3;
      lcd.clear();
       
      newCoin = 0;
     // digitalWrite(pinReel[2],HIGH);
         }break;
      case 2 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin2);
       totalTimeCoin =  newCoin* timeCoin3;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=3;
      lcd.clear(); 
      newCoin = 0;
     // digitalWrite(pinReel[2],HIGH);
         }break;
        case 4 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin4);
       totalTimeCoin =  newCoin* timeCoin3;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=3;
      lcd.clear();
      newCoin = 0;
         }break;
         case 5 : {
          newCoin = ((float)totalTimeCoin/(float)timeCoin5);
       totalTimeCoin =  newCoin* timeCoin3;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=3;
      lcd.clear();
      newCoin = 0;
         } break;
        
       }
     }
 }
 //__end void spalareCuSpuma
//Set time-price for clatireFaraPete Osmoza
 void clatireFaraPete(){
    if(programSelector == 6){
     programSelector = tempSelector;
   }
       lcd.clear();   
     if(programSelector!=4){
       for(int i=0;i<6;i++){       
      digitalWrite(pinReel[i],LOW);
      delay(5);
      }
      // digitalWrite(pinReel[0],HIGH);
      digitalWrite(pinReel[1],HIGH);
      digitalWrite(pinReel[4],HIGH);
       switch(programSelector){
         case 0 :{
            totalCoin =  EEPROM.get(totalCoins,totalCoin);
          totalCoin = totalCoin+coin;
          EEPROM.put(totalCoins,totalCoin);
         isOk1=true;
            totalTimeCoin = coin*timeCoin4;
     minuteRamase = (coin*timeCoin4)/60;
     secundeRamase =((coin*timeCoin4)%60);
     coin = 0;  
  digitalWrite(inhibitCoin,LOW);
     programSelector=4;
     lcd.clear(); 
    //  digitalWrite(pinReel[3],HIGH);
         }break;
         case 1 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin1);
       totalTimeCoin =  newCoin* timeCoin4;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=4;
      lcd.clear();
       
     newCoin = 0;
     // digitalWrite(pinReel[3],HIGH);
         }break;
      case 2 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin2);
       totalTimeCoin = newCoin* timeCoin4;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=4;
      lcd.clear();
       
      newCoin = 0;
    // digitalWrite(pinReel[3],HIGH);
         }break;
        case 3 :{
           newCoin = ((float)totalTimeCoin/(float)timeCoin3);
       totalTimeCoin = newCoin* timeCoin4;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=4;
      lcd.clear();
     newCoin = 0;
         }break; 
         case 5 :{
     newCoin = ((float)totalTimeCoin/(float)timeCoin5);
       totalTimeCoin = newCoin* timeCoin4;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=4;
      lcd.clear();
     newCoin = 0;
         }break;
         
       }
     }
 }
 //__end void clatireFaraPete
 //Program Ceara
 void ceara(){
   if(programSelector == 6){
     programSelector = tempSelector;
   }
   lcd.clear();   
     if(programSelector!=5){
       for(int i=0;i<6;i++){       
      digitalWrite(pinReel[i],LOW);
      delay(5);
      }
       digitalWrite(pinReel[0],HIGH);
      digitalWrite(pinReel[1],HIGH);
      digitalWrite(pinReel[5],HIGH);
       switch(programSelector){
         case 0 :{
            totalCoin =  EEPROM.get(totalCoins,totalCoin);
          totalCoin = totalCoin+coin;
          EEPROM.put(totalCoins,totalCoin);
         isOk1=true;
            totalTimeCoin = coin*timeCoin4;
     minuteRamase = (coin*timeCoin4)/60;
     secundeRamase =((coin*timeCoin4)%60);
     coin = 0;  
  digitalWrite(inhibitCoin,LOW);
     programSelector=5;
     lcd.clear(); 
    //  digitalWrite(pinReel[3],HIGH);
         }break;
         case 1 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin1);
       totalTimeCoin =  newCoin* timeCoin5;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=5;
      lcd.clear();
     newCoin = 0;
     // digitalWrite(pinReel[3],HIGH);
         }break;
      case 2 :{
            newCoin = ((float)totalTimeCoin/(float)timeCoin2);
       totalTimeCoin = newCoin* timeCoin5;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=5;
      lcd.clear();
       
      newCoin = 0;
    // digitalWrite(pinReel[3],HIGH);
         }break;
        case 3 :{
           newCoin = ((float)totalTimeCoin/(float)timeCoin3);
       totalTimeCoin = newCoin* timeCoin5;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=5;
      lcd.clear();
       
     newCoin = 0;
     // digitalWrite(pinReel[3],HIGH);
         }break;
         case 4 :{
           newCoin = ((float)totalTimeCoin/(float)timeCoin4);
       totalTimeCoin =  newCoin* timeCoin5;
     minuteRamase = totalTimeCoin/60;
     secundeRamase =totalTimeCoin%60;
      programSelector=5;
      lcd.clear();  
      newCoin = 0;
         } break;
         
       }
     }
 }
 //End Program Ceara
 //Pauza
 void pauza(){
       for(int i=0;i<6;i++){       
      digitalWrite(pinReel[i],LOW);
      delay(5);
      } 
  lcd.clear(); 
 programSelector = 6;
 }
 //end Pauza