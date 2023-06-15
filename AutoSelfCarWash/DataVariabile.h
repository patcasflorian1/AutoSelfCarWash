
#include<EEPROM.h>
#include <elapsedMillis.h>
#include <LiquidCrystal_PCF8574.h>
#include "HardwareSerial.h"
#include "Arduino.h"
#include "PCF8574.h"
//#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Set i2c address
PCF8574 ledDriver(0x21); //38 ;21
elapsedMillis timeElapsedLed; //declare global if you don't want it reset every time loop runs
// Variables will change:
int ledState = 0;             // ledState used to set the LED
// constants won't change:
const long interval = 400;           // interval at which to blink (milliseconds)
     
//LiquidCrystal_I2C lcd(0x27, 20, 4); // I2C address 0x27, 16 column and 2 rows
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x26 ori 0x3F for a 20 chars and 4 line display
// Data wire is conntec to the Arduino digital pin 37
#define ONE_WIRE_BUS 37 //Sensor Temp
#define DS_KEY 36 // dalass key
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);
OneWire ds(DS_KEY);  
 byte i;           // This is for the for loops
  boolean present;  // device present varj
  byte data[8];     // container for the data from device
byte dataKeyMaster[8];   // container for the data from device1
byte dataKeyAtt[8];   // container for the data from device2
byte dataKeyServ1[8];   // container for the data from device3
byte dataKeyServ2[8];   // container for the data from device4
int memoryKeyDalass = 120; //zone memory in the eeprom for dalass key(4 pcs)

  byte crc_calc;    //calculated CRC
  byte crc_byte;    //actual CRC as sent by DS2401
  
// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);
//Validate by Master and Admin
 bool validMaster = true;
 bool validAtt =true;
 bool validServ = true;
 bool enableAtt = true;
 bool enableMaster = true;
//Rell DataVariable
int pinReel [6] = {2,3,4,5,6,7}; //electrovalva pompa , pompa ,spumaActiva,spuma,osmoza,ceara
//Keyboard DataVariable
int BUTTON_PIN [6] = {28,29,30,31,32,33}; //butoane SpumaActiva,SpalarePresiune,SpalareCuSpuma,Osmoza,Ceara,Pauza
int ButtonSetup = 35; //secret setup
// ... password data ...
int password[] = {32,31,30,29,28}; // press button => ceara,osmoza,SpalareCuSpuma,SpalareCuPresiune,SpumaActiva,Pauza
int keyPress = 0 ;
int keyToken = 0;
// Variabila total bani incasati
int totalCoin;
//Variabile timp VaccumClean
int minuteRamase = 0;
int secundeRamase = 0;
int programSelector = 0;
unsigned long int totalTimeCoin = 0;
//variable for price time/Ron
float newCoin = 0;
//initializare rezervare zone de memorie in eeprom
 int timeCoin1 = 0,timeCoin2 = 0,timeCoin3 = 0,timeCoin4 = 0,timeCoin5 = 0,timeCoin6 = 0 ,masterCoin = 0,referanceCoin = 0,referanceAttCoin = 0;
 int breakTime = 20,tempSelector,contorBreak = 0;
 int temperature = 0;
 float tempGet;
//.........zona minute/RON.................
//.........rezervare zone de memorie in eeprom.................
int totalCoins = 10;  // zona memorare total bani incasati
int timeCoinsEeprom1 = 20; 
int timeCoinsEeprom2 = 30;
int timeCoinsEeprom3 = 40;
int timeCoinsEeprom4 = 50;
int timeCoinsEeprom5 = 60;
int timeCoinsEeprom6 = 70;
int temperatureEeprom = 80;
int masterCoins = 90;
int referanceCoins = 100;
int referanceAttCoins = 110;
//boolean active1 = false;
boolean isOk1 =false;
//EndStation1
// ..........Led Variable ...
int P[8]={0,1,2,3,4,5,6,7};
int ledAdressZone;
// ..........Meniu data variabile....
 int isOk = 0;
 bool menuOk = true;