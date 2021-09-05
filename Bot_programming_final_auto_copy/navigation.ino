
void forward_fast()
{
  //speed_fast=map(ly, 117, 0, 0, 85);
  analogWrite(pwmL1, speed_fast+13);
  analogWrite(pwmR1, speed_fast+13);
  analogWrite(pwmL2, speed_fast+5);
  analogWrite(pwmR2, speed_fast);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
  Serial.println("Going forward fast");
  //Serial.println(speed_fast);

  if(PS3.getButtonPress(L1))
  {
    anticlockwise_slow();
  }
  else if(PS3.getButtonPress(R1))
  {
    clockwise_slow();
  } 
  
}

void forward_slow()
{
  //speed_slow = map(rx, 117, 0, 0, 40);
  analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, HIGH);
  Serial.println("Going forward slow");
  if(PS3.getButtonPress(L1))
  {
    anticlockwise_slow();
  }
  else if(PS3.getButtonPress(R1))
  {
    clockwise_slow();
  }
  
}


void backward_fast()
{
  analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast+5);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
  Serial.println("Going backward Fast");
  if(PS3.getButtonPress(L1))
  {
    anticlockwise_slow();
  }
  else if(PS3.getButtonPress(R1))
  {
    clockwise_slow();
  }
  
}

void backward_slow()
{
  analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, LOW);
  Serial.println("Going backward Slow");
  if(PS3.getButtonPress(L1))
  {
    anticlockwise_slow();
  }
  else if(PS3.getButtonPress(R1))
  {
    clockwise_slow();
  }
}

void right_fast()
{
  analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast);
  analogWrite(pwmR2, speed_fast+20);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, HIGH);
  Serial.println("Going Right fast");
  if(PS3.getButtonPress(L1))
  {
    anticlockwise_slow();
  }
  else if(PS3.getButtonPress(R1))
  {
    clockwise_slow();
  }
}


void right_slow()
{
  
  analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);
  digitalWrite(dirL1, LOW);
  digitalWrite(dirR1, LOW);
  digitalWrite(dirL2, HIGH);
  digitalWrite(dirR2, HIGH);
  Serial.println("Going right slow");
  if(PS3.getButtonPress(L1))
  {
    anticlockwise_slow();
  }
  else if(PS3.getButtonPress(R1))
  {
    clockwise_slow();
  }
  
}

void left_fast()
{
  
  analogWrite(pwmL1, speed_fast);
  analogWrite(pwmR1, speed_fast);
  analogWrite(pwmL2, speed_fast+10);
  analogWrite(pwmR2, speed_fast);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, LOW);
  Serial.println("Going left fast");
  if(PS3.getButtonPress(L1))
  {
    anticlockwise_slow();
  }
  else if(PS3.getButtonPress(R1))
  {
    clockwise_slow();
  }
  
}

void left_slow()
{
  
  analogWrite(pwmL1, speed_slow);
  analogWrite(pwmR1, speed_slow);
  analogWrite(pwmL2, speed_slow);
  analogWrite(pwmR2, speed_slow);
  digitalWrite(dirL1, HIGH);
  digitalWrite(dirR1, HIGH);
  digitalWrite(dirL2, LOW);
  digitalWrite(dirR2, LOW);
  Serial.println("Going left slow");
  if(PS3.getButtonPress(L1))
  {
    anticlockwise_slow();
  }
  else if(PS3.getButtonPress(R1))
  {
    clockwise_slow();
  }
  
}
