

void upboxpne()
{
  upc++;
  if(upc%2==0)
    {
     digitalWrite(box_pne, LOW);
     Serial.println("Box Pneumatic band hua");
    }
    else
    {
      digitalWrite(box_pne, HIGH); 
      Serial.println("Box Pneumatic khul gaya");
    }
  
}

void grippne()
{
  gripc++;
  if(gripc%2==0)
    {
     digitalWrite(gpne, LOW);
     Serial.println("Box Pneumatic band gripper");
    }
    else
    {
      digitalWrite(gpne, HIGH);
      Serial.println("Box Pneumatic khula gripper");
    }
}

void lpne()
{
  lc++;
  if(lc%2==0)
    {
     digitalWrite(leftpne, LOW);
     Serial.println("Left Pneumatic band hua");
    }
    else
    {
      digitalWrite(leftpne, HIGH); 
      Serial.println("Left Pneumatic khul gaya");
    }
    
}

void rpne()
{
    rc++;
    if(rc%2==0)
        {
         digitalWrite(rightpne, LOW); 
         Serial.println("Right Pneumatic band hua");
        }
        else
        {
          digitalWrite(rightpne, HIGH); 
          Serial.println("Right Pneumatic khul gaya"); 
        }
}
