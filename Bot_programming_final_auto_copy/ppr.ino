//#define press_reg_ip 8
//
//int val1 = 55;
//int val2 = 78;
//
//void setup(){
//  pinMode(press_reg_ip, OUTPUT);
//}
//
//void press_regulator()
//{
//    if(ppr_count%2==1)
//    {
//      analogWrite(press_reg_ip, val2);
//      PS3.setLedOn(LED3);
//      PS3.setLedOff(LED4);
//      Serial.println(val2);
//      ppr_count++;
//    }
//    else if(ppr_count%2==0)
//    {
//      analogWrite(press_reg_ip, val1);
//      PS3.setLedOn(LED4);
//      PS3.setLedOff(LED3);
//      Serial.println(val1);
//      ppr_count++;
//    }
//}
