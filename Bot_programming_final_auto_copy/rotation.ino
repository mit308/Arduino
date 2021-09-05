void clockwise_fast()
{
  analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
  Serial.println("CLockwise Fast");
  
}

void clockwise_slow()
{

  analogWrite(pwmL1, rotation_speed);
  analogWrite(pwmR1, rotation_speed);
  analogWrite(pwmL2, rotation_speed);
  analogWrite(pwmR2, rotation_speed);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, LOW);
  Serial.println("CLockwise Slow");
  
}

void anticlockwise_fast()
{

  analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
  Serial.println("Anti-CLockwise Fast");
  
}

void anticlockwise_slow()
{

  analogWrite(pwmL1, rotation_speed);
  analogWrite(pwmR1, rotation_speed);
  analogWrite(pwmL2, rotation_speed);
  analogWrite(pwmR2, rotation_speed);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, HIGH);
  Serial.println("Anti-CLockwise Slow");
  
}
