#include "SetPrice.h"
#include "DisplayConta.h"

//Meniu Program
void meniuprog(){
  digitalWrite(inhibitCoin,HIGH);
  //Set Time 
 // delay(600);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print(" Cheia Activa :");
   lcd.setCursor(1,1);
   if(validMaster == false)
   lcd.print(" MASTER");
    if(validAtt == false)
   lcd.print(" ATTENDANT");
    if(validServ == false)
   lcd.print(" SERVICE");
   delay(2500);
  int meniu = 7;
  lcd.clear();
  while (meniu == 7) {
    meniu = 1; 
      
 do{
   //delay(600);      
         lcd.setCursor(0, 0);  
          lcd.print("* SetProg :Pret/Timp "  );
          lcd.setCursor(0, 1); lcd.print(" AfisConta");
          lcd.setCursor(0, 2); lcd.print(" Set DalassKey");
          lcd.setCursor(0, 3); lcd.print(" Display Device");
          lcd.setCursor(1,0); 
          checkPush();
       if (keyPress == 28) { 
          delay(200);
          lcd.clear();
          lcd.noBlink();
           meniu = 2;
        } 
        if (keyPress == 29) 
          {
            delay(200);
            if((validMaster == false)||(validAtt == false)){
           coinTimeSet(); 
            }else{
              displayCoinTime();
            }
          meniu = 1;
          lcd.clear();
          }
      }while(meniu==1);

      
       //Display Conta
 do{
 // delay(600);       
           lcd.setCursor(0, 0); lcd.print("* Afisare Conta");
          lcd.setCursor(0, 1); lcd.print(" Set DalassKey");
          lcd.setCursor(0, 2); lcd.print(" Display Device");
          lcd.setCursor(0,3); lcd.print(" Set TempRef");   
          lcd.setCursor(1,0);  
          checkPush();
        if (keyPress == 28) { 
          delay(200);
          lcd.clear();
          lcd.noBlink();
           meniu = 3;
        } 
        
         if(validServ == false)
        keyToken = 0;
        if(validAtt == false)
        keyToken = 1;
        if(validMaster == false)
        keyToken = 2;
        if (keyPress == 29) 
          {
            delay(200);
            switch (keyToken){
            case 0 :{
             displayConta();
            }break;
            case 1 :{
            displayContaAttendant();
            }break;
            case 2 :{
              displayMaster();
            }
          }
          meniu = 2;
          lcd.clear();
          }
      }while(meniu==2);
      //Set Coin Value     
      do {
      //  delay(600);      
          lcd.setCursor(0, 0); lcd.print("* Set DalassKey");
          lcd.setCursor(0, 1); lcd.print(" Display Device");
          lcd.setCursor(0,2); lcd.print(" Set TempRef"); 
          lcd.setCursor(0,3); lcd.print(" Exit Meniu");   
          lcd.setCursor(1,0); 
          checkPush();
        if (keyPress == 28) { 
          delay(200);
          lcd.noBlink();
          meniu = 4;
          lcd.clear();
        }
          
           delay(200);
        if (keyPress == 29) {
          delay(200);
          lcd.clear();
          progDalassKey();
          meniu = 3;
           delay(200);
          lcd.clear();
        }
      } while (meniu == 3);

//Display Device
      do {
       // delay(600);      
          lcd.setCursor(0, 0); lcd.print("* Display Device");
          lcd.setCursor(0,1); lcd.print(" Set TempRef"); 
          lcd.setCursor(0,2); lcd.print(" Exit Meniu"); 
           lcd.setCursor(0, 3); lcd.print(" SetProg : Pret/Timp"); 
          lcd.setCursor(1,0);
          checkPush();
        if (keyPress == 28) { 
          delay(200);
          lcd.noBlink();
          meniu = 5;
          lcd.clear();
        }
        
           delay(200);
        if (keyPress == 29) {
          delay(200);
          meniu = 4;
           scannerRun();
          lcd.clear();
        }
      } while (meniu == 4);
      //Set Temperature referance
      do
      {
       // delay(600); 
          lcd.setCursor(0,0); lcd.print(" *Set TemperatureRef");    
          lcd.setCursor(0, 1); lcd.print(" Exit Meniu");
          lcd.setCursor(0,2); lcd.print(" SetProg : Pret/Timp"); 
          lcd.setCursor(0,3); lcd.print(" Afisare Conta"); 
          lcd.setCursor(1,0);  
         checkPush();
        if (keyPress == 28) {
         lcd.noBlink();
          meniu = 6;
          digitalWrite(inhibitCoin,LOW);
          delay(200);
          lcd.clear();
        }
          
        delay(250);
        if (keyPress == 29) {
            delay(200); 
           setTemperature();  
          meniu = 5;
          lcd.clear();
         }
      } while (meniu == 5);
   
  //Exit Menu
   do
      {
       // delay(600); 
          lcd.setCursor(0,0); lcd.print(" * Exit Meniu");    
          lcd.setCursor(0, 1); lcd.print(" SetProg : Pret/Timp");
          lcd.setCursor(0,2); lcd.print(" Afisare Conta"); 
          lcd.setCursor(0,3); lcd.print(" Set DalassKey"); 
          lcd.setCursor(1,0);  
         checkPush();
        if (keyPress == 28) {
         lcd.noBlink();
          meniu = 7;
          digitalWrite(inhibitCoin,LOW);
          delay(200);
          lcd.clear();
        }
        delay(250);
        if (keyPress == 29) {
            delay(200);
          present =0;
          meniu = 8;
          setup();
          lcd.clear();
         }
      } while (meniu == 6);
  } 
 delay(100);
  digitalWrite(inhibitCoin,LOW);
}
