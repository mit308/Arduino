double kp=1.2, kd=0.8;
int dir1=25, pwm1=12, dir2=9, pwm2=10;
int dir4=36, pwm4=8, dir3=29, pwm3=11;               
int analogip=A1, junction=8;
int setPoint=35;
double error, lastError, rateError;
int pos=0;
int speedW=50;
int count=0;
float out = 0;
int previous=0;

int key=0;

void setup()
{
pinMode(dir1, OUTPUT);
pinMode(dir2, OUTPUT);
pinMode(dir3, OUTPUT);
pinMode(dir4, OUTPUT);
pinMode(pwm1, OUTPUT);
pinMode(pwm2, OUTPUT);
pinMode(pwm3, OUTPUT);
pinMode(pwm4, OUTPUT);

pinMode(analogip, INPUT);
pinMode(junction, INPUT);
Serial.begin(9600);
}

void loop() 
{
if(Serial.available()>0)
{
  key=Serial.parseInt();
  if(key==1)
{
  while(1)
  {
    pos=(float(analogRead(analogip))/923)*70;
    Serial.println(pos);
    
      
      
      error= setPoint - pos;
      Serial.print("Error: ");
      Serial.print(error);
      out=kp*error+kd*(error-lastError);
      Serial.print("  Gain: ");
      Serial.print(out);
      lastError=error;
      int plus = speedW + out;
      Serial.print("  Speed: ");
      Serial.print(plus);
      int minus= speedW - out;
      Serial.print("  Speed: ");
      Serial.println(minus);
      if(error==0|| error==1 || error== -1)
      {
        digitalWrite(dir1, HIGH);
        analogWrite(pwm1, speedW); //for wheel1
        digitalWrite(dir2, HIGH);
        analogWrite(pwm2, speedW);// for wheel2
        digitalWrite(dir3, LOW);
        analogWrite(pwm3, speedW);// for wheel3
        digitalWrite(dir4, LOW);
        analogWrite(pwm4, speedW);// wheel4
       
      }
      else if(error<-1)
      {
        digitalWrite(dir1, HIGH);
        analogWrite(pwm1, 60);
        digitalWrite(dir2, HIGH);
        analogWrite(pwm2, plus);
        digitalWrite(dir3, LOW);
        analogWrite(pwm3, plus);
        digitalWrite(dir4, LOW);
        analogWrite(pwm4, minus);
       
      }
      else if(error>1)
      {
        digitalWrite(dir1, HIGH);
        analogWrite(pwm1, minus);
        digitalWrite(dir2, HIGH);
        analogWrite(pwm2, plus);
        digitalWrite(dir3, LOW); 
        analogWrite(pwm3, plus);
        digitalWrite(dir4, LOW);
        analogWrite(pwm4, minus);
        
      }
        Serial.println("Junction detected");
      }
 }

    }
  }

  
