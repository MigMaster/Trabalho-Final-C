#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2); 

 int backLight = 13;
 const int trigger = 8; 
 const int echo = 7; 
 float dist;
 
void setup()
{
  Serial.begin(9600);
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); 
  
  lcd.begin(16,2);             
  lcd.clear();
 
  lcd.setCursor(0,0);          
  lcd.setCursor(0,1);   

  lcd.setCursor(13, 1);  
  lcd.write(byte(1)); 
  
  lcd.setCursor(15, 1);  
  lcd.write(byte(1)); 
  delay(2000);    
} 

void loop()
{ 
  
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);         
  
  digitalWrite(trigger, HIGH);   
  delayMicroseconds(10);        
  digitalWrite(trigger,LOW);      


  dist = pulseIn(echo, HIGH);                                
  dist = dist/58;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distancia: ");
  lcd.print(dist);
  delay(200);
  

}
  