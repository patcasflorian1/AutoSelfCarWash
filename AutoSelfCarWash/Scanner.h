void scannerInit(){
  //Wire.begin(); // Wire communication begin
  //Serial.begin(9600); // The baudrate of Serial monitor is set in 9600
  while (!Serial); // Waiting for Serial Monitor
  Serial.println("\n I2C Scanner");
  lcd.begin(20, 4);
  lcd.setBacklight(HIGH); 
  lcd.setCursor(0, 0);
  lcd.print(" \n I2C Scanner");
  delay(2500);
  lcd.clear();
 }
 
 void scannerRun(){
  int test = 0;
  while(test==0){
  
 lcd.print("Scanning...");
  byte error, address; //variable for error and I2C address
  int nDevices;
delay(400);
  Serial.println("Scanning...");
 lcd.clear();
  nDevices = 0;
  for (address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
        nDevices++;
      Serial.print(address, HEX);
      Serial.println("  !");
      lcd.setCursor(1,0);
      lcd.print("Device Found1 : ");lcd.print(nDevices);
      lcd.setCursor((nDevices*2)-2,1);
      lcd.print(address, HEX);
      lcd.setCursor(0,2);
      lcd.print("Exit=>SpumaActiva");
      
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16){
        Serial.print("0");
      Serial.println(address, HEX);
      lcd.setCursor(1,0);
      lcd.print("Device Found :");
      lcd.setCursor(0,1);
      lcd.print(address, HEX);
      lcd.print(" ; ");
      lcd.setCursor(0,2);
      lcd.print("Exit=>SpumaActiva");
      }
    }
  }
  if (nDevices == 0){
    Serial.println("No I2C devices found\n");
    lcd.print("No I2C devices found\n");
     lcd.setCursor(0,2);
      lcd.print("Exit=>SpumaActiva");
  }
  else{
    Serial.println("done\n");
  }

  delay(2500); // wait 5 seconds for the next I2C scan
  lcd.clear();
   checkPush();
        if (keyPress == 28) { 
          delay(200);
         test=1;
          lcd.clear();
        }
  }
 }
