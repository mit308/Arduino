void up_left_slow()
{
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR1, speed_slow);

  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR1, LOW);
  Serial.println("Go left diagonal in forward slow");
}

void down_left_slow()
{
 analogWrite(pwmR1, speed_slow);
 analogWrite(pwmL2, speed_slow);

 digitalWrite(dirR1, LOW);
 digitalWrite(dirL2, LOW);
 Serial.println("Go left diagonal in reverse slow");
} 

void up_right_slow()
{
 analogWrite(pwmL1, speed_slow);
 analogWrite(pwmR2, speed_slow);

 digitalWrite(dirL1, HIGH);
 digitalWrite(dirR2, LOW);
 Serial.println("Go right diagonal in forward slow");
}

void down_right_slow()
{
 analogWrite(pwmL2, speed_slow);
 analogWrite(pwmR1, speed_slow);

 digitalWrite(dirL2, LOW);
 digitalWrite(dirR1, LOW);
 Serial.println("Go right diagonal in reverse slow");
}

void up_left_fast()
{
  analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR2, speed_fast);

  digitalWrite(dirL1, HIGH);
  digitalWrite(dirL2, HIGH);
  Serial.println("Go left diagonal in forward fast");
}

void down_left_fast()
{
 analogWrite(pwmL1, speed_fast);
 analogWrite(pwmR2, speed_fast);

 digitalWrite(dirL1, LOW);
 digitalWrite(dirL2, LOW);
 Serial.println("Go left diagonal in backward fast");
} 

void up_right_fast()
{
 analogWrite(pwmL2, speed_fast);
 analogWrite(pwmR1, speed_fast);

 digitalWrite(dirL2, HIGH);
 digitalWrite(dirR1, HIGH);
 Serial.println("Go right diagonal in forward fast");
}

void down_right_fast()
{
 analogWrite(pwmL2, speed_fast);
 analogWrite(pwmR1, speed_fast);

 digitalWrite(dirL2, LOW);
 digitalWrite(dirR1, LOW);
 Serial.println("Go right diagonal in backward fast");
}
