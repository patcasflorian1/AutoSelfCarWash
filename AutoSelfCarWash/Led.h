

  
 void ledDriverInit(){
// Set pinMode to OUTPUT
 for(int i=0; i<8;i++){
ledDriver.pinMode(i, OUTPUT);
ledDriver.digitalWrite(i,HIGH);
delay(50);
 }

  Serial.print("Init ledDriver...");
  if (ledDriver.begin()){
    Serial.println("OK-LED");
  }else{
    Serial.println("KO-LED");
  }
 }

 void ledDriverRun(){
 // int intervalBlink =1000;
     ledState = 0;
     for(int i=0; i<4;i++){ 
       while(ledState == 0){
          checkPush();
        if (keyPress >0) { 
        ledState = 2;
        i = 4;
        }
        dalassKey();
 // dsPresent();
 if (present == 1)
  {
    ledState = 2;
        i = 4;
    for(int i = 1;i<6;i++)
    {
      Serial.print("Data[i]");Serial.println(data[i]);
    }
 readKeyFromMemory();
 compareKey();
 present = 0 ;
 }
        if((timeElapsedLed>=interval)&&(ledState == 0)){
    ledState = 1;
    ledDriver.digitalWrite(P[i], HIGH); //delay(400)
      ledDriver.digitalWrite(P[i+4], HIGH); //delay(400)

      timeElapsedLed=0;
     }
    }
    while(ledState == 1){
       checkPush();
        if (keyPress >0) { 
        ledState = 2;
        i = 4;
        }
        dalassKey();
 // dsPresent();
 if (present == 1)
  {
    ledState = 2;
        i = 4;
    for(int i = 1;i<6;i++)
    {
      Serial.print("Data[i]");Serial.println(data[i]);
    }
 readKeyFromMemory();
 compareKey();
 present = 0 ;
 }
      if ((timeElapsedLed>= interval)&&(ledState == 1)) {
      ledState = 0;
      ledDriver.digitalWrite(P[i], LOW); //delay(400);
       ledDriver.digitalWrite(P[i+4], LOW); //delay(400);
      timeElapsedLed=0;
    }
    }
  }  
 }