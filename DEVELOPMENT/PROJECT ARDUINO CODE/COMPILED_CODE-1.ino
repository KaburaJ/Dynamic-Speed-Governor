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
int BP1=7; //speed increment
int BP2=8; // speed decrement
int B1Val; //stores increment state
int B2Val; //stores decrement state
int vehicleSpeed;
int vehicleRpm;
int i;
int mspeed;
int ENA = 11;//don't change pins
int IN1 = 10; //don't change pins
int IN2 = 9; //don't change pins

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

//Setting push button state
digitalWrite(BP1, HIGH);
digitalWrite(BP2, HIGH);

//LCD initialization
lcd.init();
lcd.clear();         
lcd.backlight();
lcd.print("Speed Governor");
//Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
B1Val=digitalRead(BP1);// read increment
B2Val=digitalRead(BP2);//read decrement
speedlimit1=digitalRead(sw1);
speedlimit2=digitalRead(sw2);
speedlimit3=digitalRead(sw3);
speedlimit4=digitalRead(sw4);

vehicleRpm = (mspeed/255)*2000;
vehicleSpeed = (vehicleRpm/2000)*200;

//for increment button...which will fuction like a vehicle's accelerator
if (B1Val==0){
  vehicleSpeed=vehicleSpeed+10;
  delay(1000);
  analogWrite(IN1, vehicleSpeed);
  analogWrite(IN2, 0);
}
//for decrement button...which will fuction like a vehicle's brakes
if (B2Val==0){
  vehicleSpeed=vehicleSpeed-10;
  delay(1000);
  analogWrite(IN1, vehicleSpeed);
  analogWrite(IN2, 0);
}

//for 20km/hr
if(speedlimit1==LOW && speedlimit2==HIGH && speedlimit3==HIGH && speedlimit4==HIGH)
{
  speedlimit=20;
  if(vehicleSpeed>speedlimit){
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 20");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
    lcd.clear();
    if(B2Val == LOW){
      vehicleSpeed = vehicleSpeed-10;
      lcd.print("Speed reducing...");
      lcd.clear(); 
      analogWrite(IN1, vehicleSpeed);//for motor driver
      analogWrite(IN2, 0); //for motor driver
      }
    else{
    for(i=vehicleSpeed;i>speedlimit;i=i-10)
    {
      lcd.print("Speed reducing...");
      lcd.clear(); 
      analogWrite(IN1, vehicleSpeed);
      analogWrite(IN2, 0);
    }
    } 
  }  else{
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 20");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
     delay(2000);
    lcd.clear();
  }
}

//for 40km/hr
else if(speedlimit1==HIGH && speedlimit2==LOW && speedlimit3==HIGH && speedlimit4==HIGH)
{
   speedlimit=40;
  if(vehicleSpeed>speedlimit){
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 40");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
    lcd.clear();
    if(B2Val == LOW){
      vehicleSpeed = vehicleSpeed-10;
      lcd.print("Speed reducing...");
      lcd.clear(); 
      analogWrite(IN1, vehicleSpeed);//for motor driver
      analogWrite(IN2, 0);//for motor driver
      }
    else{
    for(i=vehicleSpeed;i>speedlimit;i=i-10)
    {
      lcd.print("Speed reducing...");
      lcd.clear(); 
      analogWrite(IN1, vehicleSpeed);
      analogWrite(IN2, 0);
    }
    } 
  }  else{
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 40");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
     delay(2000);
    lcd.clear();
  }
}

//for 60km/hr
else if(speedlimit1==HIGH && speedlimit2==HIGH && speedlimit3==LOW && speedlimit4==HIGH)
{
  speedlimit=60;
  if(vehicleSpeed>speedlimit){
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 60");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
    lcd.clear();
    if(B2Val == LOW){
      vehicleSpeed = vehicleSpeed-10;
      lcd.print("Speed reducing...");
      lcd.clear(); 
      analogWrite(IN1, vehicleSpeed);//for motor driver
      analogWrite(IN2, 0);//for motor driver
      }
    else{
    for(i=vehicleSpeed;i>speedlimit;i=i-10)
    {
      lcd.print("Speed reducing...");
      lcd.clear(); 
      analogWrite(IN1, vehicleSpeed);
      analogWrite(IN2, 0);
    }
    } 
  }  else{
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 60");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
    delay(2000);
    lcd.clear();
  }
}


//for 80km/hr
else if(speedlimit1==HIGH && speedlimit2==HIGH && speedlimit3==HIGH && speedlimit4==LOW)
{
  speedlimit=80;
  if(vehicleSpeed>speedlimit){
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 80");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
    lcd.clear();
    if(B2Val == LOW){
      vehicleSpeed = vehicleSpeed-10;
      lcd.print("Speed reducing...");
      lcd.clear(); 
      analogWrite(IN1, vehicleSpeed);//for motor driver
      analogWrite(IN2, 0);//for motor driver
      }
    else{
    for(i=vehicleSpeed;i>speedlimit;i=i-10)
    {
      lcd.print("Speed reducing...");
      lcd.clear(); 
      analogWrite(IN1, vehicleSpeed);
      analogWrite(IN2, 0);
    }
    } 
  } else{
    lcd.setCursor(0,0);
    lcd.print("Speed limit: 80");
    lcd.setCursor(0,1);
    lcd.print("Vehicle speed ");
    lcd.print(vehicleSpeed);
    delay(2000);
    lcd.clear();
  }
}


}
