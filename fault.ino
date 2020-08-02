#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int voltageSensor=0;
int fire=A1;
int smoke=A2;
int fault=10;
float voltageDc;
int voltageAc;
int fireSensor;
int smokeSensor;

void setup() {
  pinMode(fire,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(fault, OUTPUT);
  lcd.begin(16, 4);
  lcd.setCursor(0,0);
  lcd.print("Voltage:");
  lcd.setCursor(0,1);
  lcd.print("Fire:");
  lcd.setCursor(0,2);
  lcd.print("Smoke:");
  lcd.setCursor(0,3);
  lcd.print("Status:");
}

void loop() {
  voltageSensor = analogRead(A0);
  fireSensor= digitalRead(fire);
  smokeSensor= digitalRead(smoke);
  voltageDc=(voltageSensor*5)/(1023);
  voltageAc=(voltageDc*230)/3.7;
  if(voltageAc>186 && voltageAc<=248 && fireSensor == LOW && smokeSensor == LOW){
    lcd.setCursor(8,3);
    lcd.print("    ok");
    digitalWrite(fault, HIGH);
  }
  else{
    lcd.setCursor(8,3);
    lcd.print("Not Ok");
    digitalWrite(fault, LOW);
  }
  lcd.setCursor(8,0);
  lcd.print(voltageAc);
  if(fireSensor == HIGH){lcd.setCursor(6,1);lcd.print(" Not ok");}
  if(fireSensor == LOW){lcd.setCursor(6,1);lcd.print(" ok    ");}
  if(smokeSensor == HIGH){lcd.setCursor(6,2);lcd.print(" Not ok");}
  if(smokeSensor == LOW ){lcd.setCursor(6,2);lcd.print(" ok    ");}
 
}
