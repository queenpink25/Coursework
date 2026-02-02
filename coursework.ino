//Smart Room Environmental Monitoring and Alert System

//pin initializing
int red = 13;          
int yellow = 12;       
int tempSensor = A0;   
int lightSensor = A1;
int piezo = 8;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(piezo, OUTPUT);
  
  Serial.begin(9600);
  
  Serial.println(" sensor readings.....");
}

void loop()
{
  digitalWrite(piezo, LOW); 
  
  int tempValue = analogRead(tempSensor);
  int lightValue = analogRead(lightSensor);
  
  //converting temperature reading to current
  float current = tempValue * (5.0 / 1024.0); 
  //converting current reading to temperature in ℃
  float temp = (current - 0.5) * 100.0; 
  
  
  // Print to Serial Monitor 
  
  Serial.print(" Light intensity: ");
  Serial.println(lightValue);
  Serial.print("Temperature: ");
  Serial.print(temp); 
  
  
  //temperature condition
  if (temp > 35.0) {   
    digitalWrite(red, HIGH);
    // High pitch beep for 100ms
    tone(piezo, 1000, 100);   
    delay(100);
    digitalWrite(red, LOW);    
    delay(100);
  } else {
    digitalWrite(red, LOW);
  }
  
  // Light intensity condition
  if(lightValue > 400) {
    digitalWrite(yellow, LOW);   
  } else {
    digitalWrite(yellow, HIGH); 
  }
  
  delay(500); 
}
