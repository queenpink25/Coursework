# Coursework

---

##  Video Walkthrough

Watch the video for a detailed explanation of the **system design, architecture, and Arduino code walkthrough**.

🔗 https://youtu.be/suw-NHYzns8

---

##  System Overview
This Smart Room Environmental Monitoring and Alert System monitors **temperature and light intensity** in real time using sensors connected to an Arduino UNO.

---

##  System Architecture
- **Input:** Temperature sensor (A0), Light sensor / LDR (A1)  
- **Processing:** Arduino UNO  
- **Output:**  
  - Red LED → Temperature alert  
  - Yellow LED → Light status  
  - Piezo buzzer → Audio alert  

---

##  Code Walkthrough
The code demonstrates:
- Analog sensor data acquisition  
- Conversion of sensor values to real-world units  
- Conditional logic for alerts  
- Real-time monitoring via the Serial Monitor  

---

##  Applications
- Smart rooms  
- Environmental monitoring  
- Embedded systems learning  
- Arduino & IoT fundamentals  

---

###Project Circuit
<img width="1430" height="713" alt="image" src="https://github.com/user-attachments/assets/6068fab5-f41a-4a14-aada-5fea4ce174ab" />


###Code
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
    
    delay(100);L
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

###How to simulate

Click this link  below in tinkercad
Click start simulation
tap serial monitor to track real time temp & light values
change values on TMP & Photo resistor to see behaviour in the Leds ,and serial monitor values
https://www.tinkercad.com/things/3Um25PLwObX-smart-room-environmental-monitoring-and-alert-system/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall&sharecode=D7oV5M2wRA2Ys3xI_zs_FG2s9Zsg_FSJ8XVzYDvP7wI

Watch the video for detailed system design and code walkthrough 

https://youtu.be/suw-NHYzns8

👥 Project Participants
ASASIRA QUEEN PINKLEN
SENYONJO DISAN
NAMUGERWA WITTY SHALUAH
LUKODA FAHA
