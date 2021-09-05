void gripper_up()
{
  digitalWrite(gdir, HIGH);  // assuming HIGH shows anticlockwise direction
  analogWrite(gpwm, speedm+10);
  Serial.println("Gripper UP");
}

void gripper_down()
{
  digitalWrite(gdir, LOW);   // assuming LOW shows clockwise direction
  analogWrite(gpwm, speedm-5);
  Serial.println("Gripper DOWN");
}
