#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int sw1=2; 
int sw2=3; 
int sw3=4; 
int sw4=5;  
int buzzer = 6;
int speedlimit;
int speedlimit1; // speed limit 20
int speedlimit2; // speed limit 40
int speedlimit3; // speed limit 60
int speedlimit4; // speed limit 80
int startengine=12;
int startvalOld=1;
int startvalNew;

int BP1=7; //speed increment
int BP2=8; // speed decrement
int B1Val; //stores increment state
int B2Val; //stores decrement state
int vehicleSpeed;
int vehicleRpm;
int i;// for increment
int mspeed;
int ENA = 11;//don't change pins
int IN1 = 10; //don't change pins
int IN2 = 9; //don't change pins

#include <IRremote.h>
int IRpin=9; //declare where data is 
IRrecv IR(IRpin);//where to get data
decode_results cmd;

int dt=2000;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display


void setup() {
  // setting up pins
pinMode(sw1,INPUT);
pinMode(sw2,INPUT);
pinMode(sw3,INPUT);
pinMode(sw4,INPUT);
digitalWrite(sw1, HIGH);
digitalWrite(sw2, HIGH);
digitalWrite(sw3, HIGH);
digitalWrite(sw4, HIGH);

pinMode(BP1,INPUT);
pinMode(BP2,INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(startengine,INPUT);

//Setting push button state
digitalWrite(BP1, HIGH);
digitalWrite(BP2, HIGH);
digitalWrite(startengine, HIGH);


//LCD initialization
lcd.begin();
lcd.clear();         
lcd.backlight();
lcd.print("Speed Governor");
//Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
B1Val=digitalRead(BP1);// read increment
B2Val=digitalRead(BP2);//read decrement
startvalNew=digitalRead(startengine);
speedlimit1=digitalRead(sw1);
speedlimit2=digitalRead(sw2);
speedlimit3=digitalRead(sw3);
speedlimit4=digitalRead(sw4);


if(startvalOld==1 && startvalNew==0){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);                                            ///for latching(to continue to engage)
vehicleRpm=100;
analogWrite(ENA,vehicleRpm);
vehicleSpeed=vehicleRpm-90;
lcd.setCursor(0,0);
lcd.print("Vehiclespeed:");
lcd.print(vehicleSpeed);
}


startvalOld=startvalNew;//to avoid pressing a lot

   

//for increment button...which will fuction like a vehicle's accelerator
if (B1Val==0){
  vehicleSpeed=vehicleSpeed+10;
  vehicleRpm =vehicleSpeed+100;//mapping
  delay(1000);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,vehicleRpm);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Vehiclespeed:");
  lcd.print(vehicleSpeed);
}
//for decrement button...which will fuction like a vehicle's brakes
if (B2Val==0){
  vehicleSpeed=vehicleSpeed-10;
  vehicleRpm =vehicleSpeed+100;
  delay(1000);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,vehicleRpm);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Vehiclespeed:");
  lcd.print(vehicleSpeed);
   
}

//for 20km/hr//FF906F button1

if(cmd.value==0xFF906F)
{
  digitalWrite(BP1,HIGH);
  speedlimit=20;
  if(vehicleSpeed>speedlimit){
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 20");
    lcd.setCursor(0,1);
    lcd.print("Vehiclespeed:");
    vehicleSpeed=vehicleRpm-100;
    lcd.print(vehicleSpeed);
    delay(dt);
    if(B2Val == LOW){
      vehicleSpeed = vehicleSpeed-10;
      vehicleRpm =vehicleSpeed+100;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Speed reducing...");
      delay(dt);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      analogWrite(ENA,vehicleRpm);
      
      }
     else{
      
      for(i=vehicleSpeed;i>=20;i=i-10)
      {  vehicleRpm =i+100;
         vehicleSpeed=i;      
         lcd.clear();
         lcd.print("Speed reducing...");
         digitalWrite(IN1,HIGH);
         digitalWrite(IN2,LOW);
         analogWrite(ENA,vehicleRpm);
         delay(dt);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Speed limit: 20");
         lcd.setCursor(0,1);
         lcd.print("Vehiclespeed:");
         vehicleSpeed=vehicleRpm-100;
         lcd.print(vehicleSpeed);
         delay(dt);
         
      
         
    }
    } 
  }  else if(vehicleSpeed<=speedlimit){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 20");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
    delay(dt);
  }
}

//for 40km/hr//FFF807 for button 3

else if(cmd.value==0xFFF807)
{speedlimit=40;
  if(vehicleSpeed>40){
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 40");
    lcd.setCursor(0,1);
    lcd.print("Vehiclespeed:");
    vehicleSpeed=vehicleRpm-100;
    lcd.print(vehicleSpeed);
    delay(dt);
    if(B2Val == LOW){
      vehicleSpeed = vehicleSpeed-10;
      vehicleRpm =vehicleSpeed+100;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Speed reducing...");
      delay(dt);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      analogWrite(ENA,vehicleRpm);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Vehiclespeed:");
      lcd.print(vehicleSpeed);
      }
    else{
      for(i=vehicleSpeed;i>40;i=i-10)
      {  vehicleRpm =i+100;
         vehicleSpeed=i;
         lcd.clear();
         lcd.print("Speed reducing...");
         digitalWrite(IN1,HIGH);
         digitalWrite(IN2,LOW);
         analogWrite(ENA,vehicleRpm);
         delay(dt);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Speed limit: 40");
         lcd.setCursor(0,1);
         lcd.print("Vehiclespeed:");
         vehicleSpeed=vehicleRpm-100;
         lcd.print(vehicleSpeed);
         delay(dt);
    }
    } 
  }  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 40");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
    delay(dt);
  }
}

//for 60km/hr FFB04F bttton 4

else if(cmd.value==0xFFB04F)
{
  digitalWrite(BP1,HIGH);
  speedlimit=60;
  if(vehicleSpeed>speedlimit){
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 60");
    lcd.setCursor(0,1);
    lcd.print("Vehiclespeed:");
    vehicleSpeed=vehicleRpm-100;
    lcd.print(vehicleSpeed);
    delay(dt);
    if(B2Val == LOW){
      vehicleSpeed = vehicleSpeed-10;
      vehicleRpm =vehicleSpeed+100;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Speed reducing...");
      delay(dt);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      analogWrite(ENA,vehicleRpm);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Vehiclespeed:");
      lcd.print(vehicleSpeed);
      delay(dt);
      }
    else{
      for(i=vehicleSpeed;i>60;i=i-10)
      {  vehicleRpm =i+100;
         vehicleSpeed=i;
         lcd.clear();
         lcd.print("Speed reducing...");
         digitalWrite(IN1,HIGH);
         digitalWrite(IN2,LOW);
         analogWrite(ENA,vehicleRpm);
         delay(dt);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Speed limit: 60");
         lcd.setCursor(0,1);
         lcd.print("Vehiclespeed:");
         vehicleSpeed=vehicleRpm-100;
         lcd.print(vehicleSpeed);
         delay(dt);
    }
    } 
  }  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 60");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
    delay(dt);
  }
}


//for 80km/hr  FFA857 button 8

else if(cmd.value==0xFFA857)
{
  speedlimit=80;
  if(vehicleSpeed>speedlimit){
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 80");
    lcd.setCursor(0,1);
    lcd.print("Vehiclespeed:");
    vehicleSpeed=vehicleRpm-100;
    lcd.print(vehicleSpeed);
    delay(dt);
    if(B2Val == LOW){
      vehicleSpeed = vehicleSpeed-10;
      vehicleRpm =vehicleSpeed+100;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Speed reducing...");
      delay(dt);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      analogWrite(ENA,vehicleRpm);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Vehiclespeed:");
      lcd.print(vehicleSpeed);
      }
    else{
      for(i=vehicleSpeed;i>80;i=i-10)
      {  vehicleRpm =i+100;
         vehicleSpeed=i;
         lcd.clear();
         lcd.print("Speed reducing...");
         digitalWrite(IN1,HIGH);
         digitalWrite(IN2,LOW);
         analogWrite(ENA,vehicleRpm);
         delay(dt);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Speed limit: 80");
         lcd.setCursor(0,1);
         lcd.print("Vehiclespeed:");
         vehicleSpeed=vehicleRpm-100;
         lcd.print(vehicleSpeed);
    }
    } 
  }  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 80");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
    delay(dt);
  }
}
if(vehicleSpeed==0){
analogWrite(ENA,0);

}
}
