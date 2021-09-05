/*---------------Defining libraries----------------*/
#include <PS3BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
USB Usb;   //USBHub Hub1(&Usb); // Some dongles have a hub inside
BTD Btd(&Usb);   // You have to create the Bluetooth Dongle instance like so
PS3BT PS3(&Btd);    // This will just create the instance
bool printTemperature, printAngle;

/*----------------------variable declaration--------------------------*/
#define pwmL1 11
#define dirL1 24
#define pwmR1 12
#define dirR1 26


#define pwmL2 6
#define dirL2 14
#define pwmR2 4
#define dirR2 5

#define gpwm 3         
#define gdir 25

#define box_pne 42
#define gpne 44
#define leftpne 38
#define rightpne 28

#define press_reg_ip 8

#define analogip A0
#define junction A1

int lx,ly,rx,ry;
int upc=0, gripc=0, lc=0, rc=0;
int speedm = 25;
int speed_fast = 80;
int speed_slow = 40;
int rotation_speed = 30;
int buttnSt = 2;
int ppr_count=0;
int SetPoint=35;
int error=0, LastError=0;
int kp=0, kd=0;
int lsa_count=0;
int speedW=30;

/*-------------------------SETUP---------------------*/
void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect 
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
/*-------------------------PINMODE------------------------*/
  pinMode(pwmL1, OUTPUT);
  pinMode(pwmL2, OUTPUT);
  pinMode(dirL1, OUTPUT);
  pinMode(dirL2, OUTPUT);
  pinMode(pwmR1, OUTPUT);
  pinMode(pwmR2, OUTPUT);
  pinMode(dirR1, OUTPUT);
  pinMode(dirR2, OUTPUT);
  pinMode(gdir, OUTPUT);
  pinMode(gpwm, OUTPUT);
  pinMode(box_pne, OUTPUT);
  pinMode(leftpne, OUTPUT);
  pinMode(rightpne, OUTPUT);
  pinMode(buttnSt, OUTPUT);
  pinMode(press_reg_ip, OUTPUT);
  pinMode(analogip, INPUT);
  pinMode(junction, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttnSt), stop, LOW); 
}
void loop() {
  Usb.Task(); // checks which button is pressed 
//    lx=PS3.getAnalogHat(LeftHatX);
//    ly=PS3.getAnalogHat(LeftHatY);
//    rx=PS3.getAnalogHat(RightHatX);
//    ry=PS3.getAnalogHat(RightHatY);
     
  if (PS3.PS3Connected || PS3.PS3NavigationConnected)
  { 
      /*-------------------BUTTON FUNCTIONS--------------*/
      if(PS3.getButtonClick(SELECT))
      {
        kill();
        digitalWrite(buttnSt, LOW);
        delay(3000);
        Serial.println("Shut Down");
      }
      /*-------------GRIPPER MOTOR------------*/
      else if(PS3.getButtonPress(UP))
          {
            gripper_up();
            wheel_stop();
          }
          else if(PS3.getButtonPress(DOWN))
          {
            Serial.println("DOWN");
            gripper_down();
            wheel_stop();
          } 
      /*---------------------------------------BNAVIGATION BUTTONS------------*/
      
      else if(PS3.getButtonClick(LEFT))
      {
        upboxpne();
        grippne();
      }
      /*----------------CATAPULT PNEUMATIC-------------*/
      else if(PS3.getButtonClick(CIRCLE))
      {
        lpne();
      }
      else if(PS3.getButtonClick(SQUARE))
      {
        rpne();
      }
      /*------------------GRIPPER PNEUMATIC-------------*/
      else if(PS3.getButtonClick(CROSS))
      {
        grippne();
      }
      else if(PS3.getButtonClick(TRIANGLE))
      {
        upboxpne();
      }
      /*-----------------------------PPR COMMANDS------------*/
      
     else if(PS3.getButtonClick(RIGHT)){
      automate();
     }
       /*--------------WHEELS & NAVIGATION----------------*/
         
      else if (PS3.getAnalogHat(LeftHatY)==0 && 65<PS3.getAnalogHat(LeftHatX) && PS3.getAnalogHat(LeftHatX)<189 && PS3.getAnalogHat(RightHatX)==128 && PS3.getAnalogHat(RightHatY)==128)
      {
        forward_fast();
      }
      else if(PS3.getAnalogHat(LeftHatY)==255 && 65<PS3.getAnalogHat(LeftHatX) && PS3.getAnalogHat(LeftHatX)<189 && PS3.getAnalogHat(RightHatX)==128 && PS3.getAnalogHat(RightHatY)==128)
      {
        backward_fast();
      }
      else if(PS3.getAnalogHat(LeftHatX)==0 && 62<PS3.getAnalogHat(LeftHatY) && PS3.getAnalogHat(LeftHatY)<192 && PS3.getAnalogHat(RightHatX)==128 && PS3.getAnalogHat(RightHatY)==128)
      {
        left_fast();
      }
      else if(PS3.getAnalogHat(LeftHatX)==255 && 62<PS3.getAnalogHat(LeftHatY) && PS3.getAnalogHat(LeftHatY)<192 && PS3.getAnalogHat(RightHatX)==128 && PS3.getAnalogHat(RightHatY)==128)
      {
        right_fast();
        //Serial.print(lx);
      }
      else if(PS3.getAnalogHat(RightHatY)==0 && 65<PS3.getAnalogHat(RightHatX) && PS3.getAnalogHat(RightHatX)<189 && PS3.getAnalogHat(LeftHatY)==128 && PS3.getAnalogHat(LeftHatX)==128)
      {
        forward_slow();
      }
      else if(PS3.getAnalogHat(RightHatY)==255 && 65<PS3.getAnalogHat(RightHatX) && PS3.getAnalogHat(RightHatX)<189 && PS3.getAnalogHat(LeftHatX)==128 && PS3.getAnalogHat(LeftHatY)==128)
      {
        backward_slow();
      }
      else if(PS3.getAnalogHat(RightHatX)==0 && 62<PS3.getAnalogHat(RightHatY) && PS3.getAnalogHat(RightHatY)<192 && PS3.getAnalogHat(LeftHatY)==128 && PS3.getAnalogHat(LeftHatX)==128)
      {
        left_slow();
      }
      else if(PS3.getAnalogHat(RightHatX)==255 && 62<PS3.getAnalogHat(RightHatY) && PS3.getAnalogHat(RightHatY)<192 && PS3.getAnalogHat(LeftHatX)==128 && PS3.getAnalogHat(LeftHatY)==128)
      {
        right_slow();
      }
      /*------------------------------------LSA---------------------------*/
     /*else if(PS3.getButtonClick(START))
      {
        lsa_front();
      }
    
      /*----------------------------------- CLOCKWISE AND ANTICLOCKWISE AND DIAGONALS ------------------------------*/
  
      else if(PS3.getButtonPress(L1))
      {
        clockwise_slow();
      }
      else if(PS3.getButtonPress(R1))
      {
        anticlockwise_slow();
      }
      else if(PS3.getButtonPress(L2))
      {
//        up_left_slow();
      }
      else if(PS3.getButtonPress(R2))
      {
//        up_right_slow();
      }
      else
      {
        motor_stop();
      }
  /*-----------------------------------------DIAGONALS--------------------------------------*/
    /*  else if(lx==0 && ly==0)
      {
        up_left_fast();      // left forward fast
      }
      else if(lx==0 && ly==255)
      {
        down_left_fast();  // left reverse fast
      }
      else if(lx==255 && ly==0)
      {
        up_right_fast(); // right forward fast
      }
      else if(lx==255 && ly==255)
      {
        down_right_fast();  //  right reverse fast
      }
      else if(rx==0 && ry==0)
      {
        up_left_slow();  // left forward slow
      }
      else if(rx==0 && ry==255)
      {
        down_left_slow();  // left reverse slow
      }
      else if(rx==255 && ry==0)
      {
        up_right_slow();   // right forward slow
      }
      else if(rx==255 && ry==255)
      {
        down_right_slow();  // right reverse slow
      }
      */
      /*if (PS3.getButtonClick(PS))
      {
        Serial.print(F("\r\nPS"));
        PS3.disconnect();
        }*/
      }
    }
void stop(){
  kill();
}
