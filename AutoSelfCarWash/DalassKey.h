 
  void PrintTwoDigitHex (byte b, boolean newline)
{
  Serial.print(b/16, HEX);
  Serial.print(b%16, HEX);
  if (newline) Serial.println();
}
void compareKey()
{
    do
    {

     // data = 0;
      present = ds.reset(); //verificare prezenta dallas key
      ds.write(0x33);  //Send Read data command
    Serial.print("Hex ROM data: ");
      for (i = 1; i <= 6; i++)
      {
        data[i] = ds.read();
       // dataz = dataz + datax[i];
        Serial.print("Data Read ");
       Serial.print(data[i]);
       Serial.println(" ");
       Serial.print("Data Master Read ");
       Serial.print(dataKeyMaster[i]);
       Serial.println(" ");

      }

      // if(dataz==dataz1) //comparare key1
      if (dataKeyMaster[1] == data[1] && dataKeyMaster[2] == data[2] && dataKeyMaster[3] == data[3] && dataKeyMaster[4] == data[4] && dataKeyMaster[5] == data[5] && dataKeyMaster[6] == data[6]) //comparare key1
      {
        validMaster = false;

      }


      // if(dataz==dataz2)  //comparare key2
      if (dataKeyAtt[1] == data[1] && dataKeyAtt[2] == data[2] && dataKeyAtt[3] == data[3] && dataKeyAtt[4] == data[4] && dataKeyAtt[5] == data[5] && dataKeyAtt[6] == data[6]) //comparare key2
      {
       validAtt = false;

      }


      // if(dataz==dataz3)  //comparare key3
      if (dataKeyServ1[1] == data[1] && dataKeyServ1[2] == data[2] && dataKeyServ1[3] == data[3] && dataKeyServ1[4] == data[4] && dataKeyServ1[5] == data[5] && dataKeyServ1[6] == data[6]) //comparare key3
      {
        validServ = false;

      }

      // if(dataz==dataz4)  //comparare key4
      if (dataKeyServ2[1] == data[1] && dataKeyServ2[2] == data[2] && dataKeyServ2[3] == data[3] && dataKeyServ2[4] == data[4] && dataKeyServ2[5] == data[5] && dataKeyServ2[6] == data[6]) //comparare key4
      {
        validServ = false;
          }
      
      present = ds.reset();
    } while (present == true);
  }

//read new Dalass
void dsPresent(){
  byte crc_calc;    //calculated CRC
  byte crc_byte;    //actual CRC as sent by DS2401
//Serial.println("---------- Device present ----------");
    ds.write(0x33);  //Send Read data command
    data[0] = ds.read();
    for (i = 1; i <= 6; i++)
    {
      data[i] = ds.read(); //store each byte in different position in array 
    }
    }
 
    void readKeyFromMemory(){
 int c ;
 for (i = 1, c = 120; i <= 6, c <= 126; i++, c++) //extragere key1
  {
   dataKeyMaster[i] = EEPROM.get(c, dataKeyMaster[i]);
   Serial.print("Data MasterM Read ");
       Serial.print(dataKeyMaster[i]);
       Serial.println(" ");
   
  }
   for (c = 127, i = 1; c <= 132, i <= 6; c++, i++) //extragere key2
  {
   dataKeyAtt[i] = EEPROM.get(c, dataKeyAtt[i]);
  }
  for (c = 133, i = 1; c <= 138, i <= 6; c++, i++) //extragere key3
  {
   dataKeyServ1[i] = EEPROM.get(c, dataKeyServ1[i]);
  }
  for (c = 139, i = 1; c <= 144, i <= 6; c++, i++) //extragere key4
  { 
  dataKeyServ2[i] = EEPROM.get(c, dataKeyServ2[i]);
  }
}

void progDalassKey()
{
  bool keyMem =true;
 int mem1 = 0, temp = 0,temp1 = 0;;
  byte datamem = 0;
 //1-Wire bus reset, needed to start operation on the bus,
  //returns a 1/TRUE if presence pulse detected
 

  while (temp1 == 0)
  {
   if(validMaster == false)
  temp = 0 ;
  if(validAtt == false)
  temp = 1 ;
  if(validServ == false)
  temp = 2;
   
    while (temp == 0)
    {
      checkPush();
      if(keyMem == true){
      lcd.setCursor(3,0);
       lcd.print("Progam Key");
       lcd.setCursor(1,1);
       lcd.print("Adauga  MasterKey");
        lcd.setCursor(0,2);
       lcd.print("NextKey=>SpumaActiva");
       lcd.setCursor(0,3);
       lcd.print("ExitProgKey=>Pauza");
      }
        if(keyMem == false){
         lcd.setCursor(0,0);
          lcd.print("Memorare Master");
          lcd.setCursor(1,1);
       lcd.print("Key Saved");
       lcd.setCursor(0,2);
       lcd.print("NextKey=>SpumaActiva");
       lcd.setCursor(0,3);
       lcd.print("ExitProgKey=>Pauza");
      }
        present = ds.reset();
        if (present == true) //Memorare key1
        {
          keyMem = false;
          present = false;
          Serial.println("---------- Device present ----------");
          lcd.setCursor(0,0);
          lcd.print("Device Present");
          ds.write(0x33);  //Send Read data command
          Serial.print("Hex ROM data: ");
          for (datamem = 1, mem1 = 120; datamem <= 6, mem1 <= 126; datamem++, mem1++)
          {
            dataKeyMaster[datamem] = ds.read(); //store each byte in different position in array
            EEPROM.put(mem1, dataKeyMaster[datamem]);
          }
         delay(3000);
         lcd.clear();
        }
      if (keyPress == 28) //SpumaActiva
      {
          delay(300);
        temp = 1;
        keyMem = true;
      }
       if (keyPress == 33) //Pauza
      {
          delay(300);
        temp = 4;
        temp1 = 1;
      }
    }

    while (temp == 1) //Memorare keyAtt
    {
      checkPush();
        if(keyMem == true){
      lcd.setCursor(3,0);
       lcd.print("Progam Key");
       lcd.setCursor(1,1);
       lcd.print("Adauga  AttKey");
        lcd.setCursor(0,2);
       lcd.print("NextKey=>SpumaActiva");
       lcd.setCursor(0,3);
       lcd.print("ExitProgKey=>Pauza");
      }
       if(keyMem == false){
         lcd.setCursor(0,0);
          lcd.print("Memorare AttKey");
          lcd.setCursor(1,1);
       lcd.print("Key Saved");
       lcd.setCursor(0,2);
       lcd.print("NextKey=>SpumaActiva");
       lcd.setCursor(0,3);
       lcd.print("ExitProgKey=>Pauza");
      }
      
        present = ds.reset();
        if (present == true)
        {
          keyMem = false;
          present = false;
          Serial.println("---------- Device present ----------");
          lcd.setCursor(0,0);
          lcd.print("Device present");
          ds.write(0x33);  //Send Read data command
          for (mem1 = 127, datamem = 1; mem1 <= 132, datamem <= 6; mem1++, datamem++)
          {
            dataKeyAtt[datamem] = ds.read();
            EEPROM.put(mem1, dataKeyAtt[datamem]);
          }
       lcd.setCursor(0,1);
          lcd.print("Memorare Attendant");
          delay(1500);
          lcd.clear();
        }
     if (keyPress == 28) //SpumaActiva
      {
        delay(300);
        lcd.clear();
        temp = 2;
         keyMem = true;
      }
       if (keyPress == 33) //Pauza
      {
          delay(300);
        lcd.clear();
        temp = 4;
        temp1 = 1;
      }
    }
    while (temp == 2) //Memorare keyServ1
    {
      checkPush();
        if(keyMem == true){
      lcd.setCursor(3,0);
       lcd.print("Progam Key");
       lcd.setCursor(1,1);
       lcd.print("Adauga  Serv1");
        lcd.setCursor(0,2);
       lcd.print("NextKey=>SpumaActiva");
       lcd.setCursor(0,3);
       lcd.print("ExitProgKey=>Pauza");
      }
       if(keyMem == false){
         lcd.setCursor(0,0);
          lcd.print("Memorare Serv1");
          lcd.setCursor(1,1);
       lcd.print("Key Saved");
       lcd.setCursor(0,2);
       lcd.print("NextKey=>SpumaActiva");
       lcd.setCursor(0,3);
       lcd.print("ExitProgKey=>Pauza");
      }
        present = ds.reset();
        if (present == true)
        {
          keyMem = false;
          present = false;
          Serial.println("---------- Device present ----------");
          lcd.setCursor(0,0);
          lcd.print("Device present");
          ds.write(0x33);  //Send Read data command


          Serial.print("Hex ROM data: ");
          for (mem1 = 133, datamem = 1; mem1 <= 138, datamem <= 6; mem1++, datamem++)
          {
            dataKeyServ1[datamem] = ds.read(); //store each byte in different position in array

            Serial.print(dataKeyServ1[datamem], HEX);
            EEPROM.put(mem1, dataKeyServ1[datamem]);
          }
          lcd.setCursor(0,1);
          lcd.print("Memorare Serv1");
          delay(1500);
          lcd.clear();
        }
     if (keyPress == 28) //SpumaActiva
      {
        delay(300);
        lcd.clear();
        temp = 3;
         keyMem = true;
      }
       if (keyPress == 33) //Pauza
      {
        delay(300);
        lcd.clear();
        temp = 4;
        temp1 = 1;
      }
    }
    while (temp == 3) //Memorare Serv2
    {
      checkPush();
      if(keyMem == true){
      lcd.setCursor(3,0);
       lcd.print("Progam Key");
       lcd.setCursor(1,1);
       lcd.print("Adauga  Serv2");
        lcd.setCursor(0,2);
       lcd.print("NextKey=>SpumaActiva");
       lcd.setCursor(0,3);
       lcd.print("ExitProgKey=>Pauza");
      }
       if(keyMem == false){
         lcd.setCursor(0,0);
          lcd.print("Memorare Serv2");
          lcd.setCursor(1,1);
       lcd.print("Key Saved");
       lcd.setCursor(0,2);
       lcd.print("NextKey=>SpumaActiva");
       lcd.setCursor(0,3);
       lcd.print("ExitProgKey=>Pauza");
      }
        present = ds.reset();
        if (present == true)
        {
          delay(300);
          keyMem = false;
          present = false;
          Serial.println("---------- Device present ----------");
           lcd.setCursor(0,0);
          lcd.print("Device present");
          ds.write(0x33);  //Send Read data command
          Serial.print("Hex ROM data: ");
          for (mem1 = 139, datamem = 1; mem1 <= 144, datamem <= 6; mem1++, datamem++)
          {
           dataKeyServ2[datamem] = ds.read(); //store each byte in different position in array

            Serial.print(dataKeyServ2[datamem], HEX);
            EEPROM.put(mem1, dataKeyServ2[datamem]);
          }
           lcd.setCursor(0,1);
          lcd.print("Memorare Serv2");
          delay(1500);
          lcd.clear();
        }
     
       checkPush();
    if (keyPress == 28) //Spuma Activa
      {
        delay(300);
        lcd.clear();
       keyMem = true;
        temp = 0;
        temp1 = 0;
      }
      if (keyPress == 33)  //Pauza
      {
       delay(300); 
        temp = 4;
        temp1 = 1;
       lcd.clear();
       lcd.print("Exit Prog");
        delay(1500);
      }
    }
  }
}
/*
void resetKey(){

  int b = 0; delay(500);
    while (b == 0)
    {
      // Serial.println("SW2 ");
      pixels.setPixelColor(0, pixels.Color(0, 0, 0)); pixels.show(); delay(500);
      pixels.setPixelColor(0, pixels.Color(255, 0, 25)); pixels.show();

      delay(300);
      if (digitalRead(sw1) == 0)
      {
        // Serial.println(" SW1");
        for ( c = 1,  i = 1; c <= 30, i <= 30; c++, i++)
        {

          EEPROM.put(c, i);
          pixels.setPixelColor(0, pixels.Color(255, 0, 25)); pixels.show();

          delay(100);
          pixels.setPixelColor(0, pixels.Color(0, 20, 255)); pixels.show();

          delay(100);
        }
        b = 1;
      }
      if (digitalRead(sw2) == LOW)
      {
        b = 1;
      }


    }
}



*/

   void dalassKey(){

    //1-Wire bus reset, needed to start operation on the bus,
  //returns a 1/TRUE if presence pulse detected
  present = ds.reset();
  if (present == 1)
  {
    Serial.println("---------- Device present ----------");
    ds.write(0x33);  //Send Read data command
    data[0] = ds.read();
    Serial.print("Family code: 0x");
    PrintTwoDigitHex (data[0], 1);
    Serial.print("Hex ROM data: ");
    for (i = 1; i <= 6; i++)
    {
      data[i] = ds.read(); //store each byte in different position in array
      PrintTwoDigitHex (data[i], 0);
      Serial.print(" ");
    }

    Serial.println();
    crc_byte = ds.read(); //read CRC, this is the last byte
    crc_calc = OneWire::crc8(data, 7); //calculate CRC of the data
    Serial.print("Calculated CRC: 0x");
    PrintTwoDigitHex (crc_calc, 1);
    Serial.print("Actual CRC: 0x");
    PrintTwoDigitHex (crc_byte, 1);
  }
  else //Nothing is connected in the bus
  {
    //Serial.println("xxxxx Nothing connected xxxxx");
    for (i = 1; i <= 6; i++)
    {
      data[i] = i+data[i]; //store each byte in different position in array
     // PrintTwoDigitHex (data[i], 0);
     // Serial.print(" ");
    }
  }
  return data;
  }

 