#include <LiquidCrystal.h>
byte Sh[] = {
  B00000,
  B10101,
  B10101,
  B10101,
  B10101,
  B10101,
  B10101,
  B11111
};

byte M[] = {
  B00000,
  B11011,
  B11011,
  B10101,
  B10101,
  B10001,
  B10001,
  B10001
};

LiquidCrystal lcd(7,6,5,4,3,2);
#define d_beep 9
#define MIC A2
void setup(){
  lcd.begin(16,2);
  lcd.createChar(0, Sh);
  sh_letter = lcd.write(0);
  m_letter = lcd.write(1);
  lcd.createChar(1, M);
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  analogWrite(d_beep,0);
  lcd.print(sh_letter);
  lcd.print("y");
  lcd.print(m_letter);
  lcd.print("o");
  lcd.print(m_letter);
  lcd.print("ep");
  delay(1000);
}
void loop(){
long mic_readings = analogRead(MIC);
lcd.setCursor(0,0);
lcd.print("= ");
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
if (mic_readings = NULL){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("No readings");
}
  
lcd.clear();
}
