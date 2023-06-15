#include "DataVariabile.h"
#include "Coin.h"
#include "Keyboard.h"
#include "Scanner.h"
#include "FunctionWash.h"
#include "TemperatureSensor.h"
#include "Wash.h"
#include "DalassKey.h"
#include "Meniu.h"
#include "Password.h"
#include "Led.h"
//int ThermistorPin = A4;
//int Vo;
//float R1 = 3700;
//float logR2, R2, T, Tc, Tf;
//float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;


void setup() {
  
Serial.begin(9600); 
  Wire.begin();
  // lcd.init(); // initialize the lcd
 // lcd.backlight();
  lcd.begin(20, 4);
  lcd.setBacklight(HIGH); 
  ledDriverInit();
// Wire.setClock(400000L);
 // Start up the library
 // sensors.begin();
 scannerInit();

  pinMode(coinPin, INPUT);
  pinMode(inhibitCoin, OUTPUT);
  //Set val Pin Arduino nano
 digitalWrite(coinPin,HIGH);
  digitalWrite(inhibitCoin,LOW);
 attachInterrupt(digitalPinToInterrupt(coinPin), coinInterrupt, LOW); //SetCoinPin

for(int i = 0;i<6;i++){
 pinMode(BUTTON_PIN [i], INPUT);
delay(10);
digitalWrite(BUTTON_PIN [i],HIGH);
delay(10);
} 
pinMode(ButtonSetup,INPUT_PULLUP);
//pinMode(BUTTON_PIN, INPUT_PULLUP);
for(int i = 0;i<6;i++){
  pinMode(pinReel[i], OUTPUT);

  digitalWrite(pinReel[i],LOW);
delay(10);
} 
// lcd.begin(20, 4);
  //lcd.setBacklight(HIGH); 
  lcd.setCursor(0, 0);
  lcd.print("    Self Car-Wash");
  lcd.setCursor(0, 1);
  lcd.print("Vers1.0EE-01SLF05.23 ");
  lcd.setCursor(2, 2);
  lcd.print(" ZAN-Horduino ");
  lcd.setCursor(2, 3);
  lcd.print(" 1Keyboard 4Comm");
  delay(3000);
  lcd.clear();
  referanceAttCoin = EEPROM.get(referanceAttCoins,referanceAttCoin);
  referanceCoin = EEPROM.get(referanceCoins,referanceCoin);
  // referanceAttCoin = 1530;
   validMaster = true;
  validAtt =true;
  validServ = true;
}

void loop() {
 totalCoin = EEPROM.get(totalCoins,totalCoin);
 masterCoin = EEPROM.get(masterCoins,masterCoin);
 checkPush();
 ledDriverRun();
  dalassKey();
 // dsPresent();
 if (present == 1)
  {
    for(int i = 1;i<6;i++)
    {
      Serial.print("Data[i]");Serial.println(data[i]);
    }
 readKeyFromMemory();
 compareKey();
 present = 0 ;
 }
        if(digitalRead(ButtonSetup) == LOW){
          getPassw();
          //meniuprog();
          
        }
        if ((validMaster == false)||(validAtt == false)||(validServ ==false)) {
           meniuprog();
        }
 tempGet = getTemp();
 temperature = EEPROM.read(temperatureEeprom);
 if(temperature>tempGet){
   digitalWrite(pinReel[0],HIGH);
 }else{
   digitalWrite(pinReel[0],LOW);
 }
 if(totalCoin>referanceAttCoin) {
   
  enableAtt =false;
 }
 if(referanceAttCoin == 0)
enableAtt = true;
 if(masterCoin>referanceCoin) 
   enableMaster = false;

 if(referanceCoin == 0)
   enableMaster = true ;
 if((enableMaster == true)&&(enableAtt == true)){
  if(coin>0){
    wash();
  }
  lcd.setCursor(0,0);
  lcd.print(" Introdu Credit si ");
lcd.setCursor(0, 1);
  lcd.print(" Alege un program");
lcd.setCursor(0, 2);
  lcd.print("  Credit:");
lcd.setCursor(12, 2);
  lcd.print(coin);lcd.print(" RON");
   Serial.print("Coin ");
    Serial.println(coin);
 }else{
   if(enableAtt == false){
lcd.setCursor(0,0);
   lcd.print ("Stopped by the Att");
  lcd.setCursor(0,1);
   lcd.print ("Telefon: 0755579949"); 
 }
 if(enableMaster == false){
 lcd.setCursor(0,0);
   lcd.print ("Stopped by theMaster");
   lcd.setCursor(0,1);
   lcd.print ("Telefon: 0755579949"); 
 }
 }

  //delay(500);
}

