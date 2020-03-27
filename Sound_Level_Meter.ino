#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
#define d_beep 9
#define MIC A2
void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  analogWrite(d_beep,0);
}
void loop(){
long mic_readings = analogRead(MIC);
lcd.setCursor(0,0);
lcd.print("WyMoMeP = ");
lcd.print(mic_readings);
lcd.print("dB");
if (mic_readings >= 60){
  lcd.setCursor(0,1);
  lcd.print("Normal level");
}
if (mic_readings < 60){
  lcd.setCursor(0,1);
  lcd.print("Perfect level");
}
if (mic_readings >= 90){
  lcd.setCursor(0,1);
  lcd.print("Dangerous level");
  analogWrite(d_beep, 51);
  delay(1000);
  analogWrite(d_beep, 153);
  delay(1000);
  analogWrite(d_beep, 0);
}
delay(750);
lcd.clear();
}
