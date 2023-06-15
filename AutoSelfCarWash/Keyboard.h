
void checkPush()
{
  for(int i= 0;i<6;i++){
  int pushed = digitalRead(BUTTON_PIN [i]);  // read input value
  // check if the input is HIGH (button released)
  if (pushed == LOW){  
   // digitalWrite(pinReel[i], HIGH);  // turn LED OFF
   Serial.print("Button "); Serial.println(BUTTON_PIN [i]);
    keyPress = BUTTON_PIN[i];
    break;
  }
  else{
   // digitalWrite(pinReel[i], LOW);  // turn LED ON
   keyPress = 0;
  }
  }
}