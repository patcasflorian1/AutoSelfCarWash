
volatile int coinPin = 18;
volatile int inhibitCoin = 19; 
long timeCoinMill = 0;
int limitCoin = 50;
int coin = 0;
bool insert = false;
//int pasCoin = 0;
int coinPasZone = 310,coinLimitZone = 320;
/*

*/
 //interrupt
void coinInterrupt() {
//  pasCoin =  EEPROM.get(coinPasZone,pasCoin);
  limitCoin =  EEPROM.get(coinLimitZone,limitCoin);
 
while(digitalRead(coinPin) == LOW){
    timeCoinMill++;
}
  if(timeCoinMill>50){ 
   coin ++ ;
    timeCoinMill = 0;
     if(coin>limitCoin){
      digitalWrite(inhibitCoin,HIGH);
     }
     else{
      digitalWrite(inhibitCoin,LOW);
    
     }
  // Serial.println(coin);
 // Serial.println();
      insert = true;
}
  }
