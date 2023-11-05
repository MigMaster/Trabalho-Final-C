

int led = 10; 
int ldr = A0; 
int valorldr = 0;

void setup() {
  pinMode (led, OUTPUT); 
  pinMode (ldr, INPUT); 
  Serial.begin(3600); 
}

void loop() {
   valorldr = analogRead (ldr);
   Serial.println(valorldr);
   
   if((valorldr) < 500){ 
    digitalWrite(led, HIGH);
  }  
  else{
    digitalWrite(led, LOW);
  }  
}
