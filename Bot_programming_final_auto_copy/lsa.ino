void lsa_front()
{
  lsa_count++;
  if(lsa_count%2==1)
  {
   while(lsa_count%2!=0)
   {
    int pos=(float(analogRead(analogip))/923)*70;
     Serial.println(pos);
     error=SetPoint-pos;
     int out=kp*error+kd*(error-LastError);
     LastError=error;
     int plus= speedW+out;
     int minus=speedW-out;
     Serial.print("plus speed   ");
     Serial.print(plus);
     Serial. print("minus speed  ");
     Serial. println(minus);
     if(error=0|| error==2 || error==-2)
     {
      analogWrite(pwmL1, speedW);
      analogWrite(pwmR1, speedW);
      analogWrite(pwmL2, speedW);
      analogWrite(pwmR2, speedW);
      digitalWrite(dirL1, HIGH);
      digitalWrite(dirR1, LOW);
      digitalWrite(dirL2, HIGH);
      digitalWrite(dirR2, LOW);
     }
     else if(error>2)
     {
      analogWrite(pwmL1, plus);
      analogWrite(pwmR1, minus);
      analogWrite(pwmL2, plus);
      analogWrite(pwmR2, minus);
      digitalWrite(dirL1, HIGH);
      digitalWrite(dirR1, LOW);
      digitalWrite(dirL2, HIGH);
      digitalWrite(dirR2, LOW);
     }
     else if(error<-2)
     {
      digitalWrite(dirL1, HIGH);
      digitalWrite(dirR1, LOW);
      digitalWrite(dirL2, HIGH);
      digitalWrite(dirR2, LOW);
      analogWrite(pwmL1, plus);
      analogWrite(pwmR1, minus);
      analogWrite(pwmL2, plus);
      analogWrite(pwmR2, minus);
     }
     if(PS3.getButtonClick(L3))
     {
      break;
     }
   }
  }
}
