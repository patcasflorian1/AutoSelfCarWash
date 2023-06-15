
void getPassw(){
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("ENER PASSWORD");
  lcd.setCursor(2,2);
   int userPassword [5];
  bool passOk = true;
  int nextPass = 0;
  int countPassw = 0 ;
  int nextWhile = 0 ;
  while(passOk == true){
    while(nextPass == 0){
      Serial.print("NextPass");Serial.println(nextWhile);
      delay(300);
checkPush();
if((keyPress>0)&&(keyPress<33)){
userPassword[nextWhile] = keyPress;
lcd.print("*");
delay(300);
nextWhile ++;
}
if(keyPress == 33){
  nextPass = 1;
  keyPress = 0;
  delay(300);
}
    }   
    Serial.print("nextWhile");Serial.println(nextWhile);

    //Pauza
    while(nextPass==1){
      delay(300);
checkPush();

  for(int i=0;i<5;i++){
if(userPassword[i] == password[i]){
  countPassw++;
  Serial.print("userPassword[i]");Serial.println(userPassword[i]);
  Serial.print("password[i]");Serial.println(password[i]);
}
  }
   Serial.print("countPassw");Serial.println(countPassw);
if(countPassw == 5){
  lcd.setCursor(2,3);
lcd.print("Correct");
//nextPass = 1;
 for(int i =0;i<5;i++){
    userPassword[i]=0;
  }
  delay(2500);
  validMaster = false;
  passOk = false;
  nextPass = 2;
}
else{
  lcd.setCursor(2,3);
lcd.print("InCorrect");
 for(int i =0;i<5;i++){
    userPassword[i]=0;
  }
    } 
  
if(keyPress == 33){
 lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("ENER PASSWORD");
  lcd.setCursor(2,2);
  nextPass = 0;
  countPassw = 0 ;
  nextWhile = 0;
  for(int i =0;i<5;i++){
    userPassword[i]=0;
  }
} 
   }
  }
}
