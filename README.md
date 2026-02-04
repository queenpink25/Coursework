# Coursework

live Demo
https://youtu.be/suw-NHYzns8

###Project Description

The Smart Room Environmental Monitoring and Alert System is an Arduino-based solution that monitors temperature and light intensity in real time. It provides visual and audible alerts whenever environmental conditions exceed predefined thresholds, ensuring a safe, comfortable, and energy-efficient indoor environment.

###System Architecture

The system is built around an Arduino UNO, which collects data from sensors, processes it, and triggers alerts based on set conditions.
Components and Connections
Arduino UNO – Main controller
Temperature Sensor (TMP36 / LM35) → Analog Pin A0
Light Sensor (Photoresistor) → Analog Pin A1
Red LED → Digital Pin 13 (High temperature alert)
Yellow LED → Digital Pin 12 (Low light indicator)
Piezo Buzzer → Digital Pin 8 (Audible alarm)
LCD Display – Shows real-time readings
Serial Monitor – Displays sensor data for debugging and logging

###Architecture Flow 

Temperature Sensor (A0) ─┐
                         │
Light Sensor (A1) ───────┼──> Arduino UNO ──> Red LED (Pin 13)
                         │                  Yellow LED (Pin 12)
                         │                  Piezo Buzzer (Pin 8)
                         └──> LCD Display / Serial Monitor

###How It Works

The Arduino reads temperature and light values every 500 milliseconds.
Temperature data is converted into degrees Celsius.
Sensor readings are displayed on the LCD screen and Serial Monitor.
If temperature rises above 35°C, the system activates:
Flashing red LED
Alternating high-low buzzer sound
If light intensity drops below 400, the yellow LED turns ON.
When conditions return to normal, alerts automatically stop.

###Key Features

Real-time temperature and light monitoring

Dual alert system (visual + audible)

LCD and Serial Monitor output

Automatic light-based energy control

Easily adjustable thresholds

###Customization

Change temperature threshold (default: 35°C)
Adjust light sensitivity level (default: 400)
Modify buzzer tones and LED blink rates
Add more sensors using free analog pins

###Troubleshooting

Check wiring if sensor values seem incorrect
Ensure proper sensor power and grounding
Use the Serial Monitor to verify live readings
Confirm buzzer is properly initialized in code

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
