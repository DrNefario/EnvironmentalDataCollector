#include <DHT.h>;

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)

int normalDelayTime = 300000;
int enhancedDelayTime = 60000;
int testingDelayTime = 2000;

int internalFanPMWPin = 13;

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for Arduino

void setup() {
  Serial.begin(9600);
	dht.begin();
}

void loop() {

//SECTION BREAKOUT - IP67 CONTROL BOX SENSORS
/* This section should be set to read and configure all sensors housed within the IP67 box
Internal Temp / Humidity
Lightning Detection
RTC
GPS
Cellular Signal Strength
UV Index 
Sunlight Detector
Fan Status */

  //Read data and store it to variables
  
  float humidity = dht.readHumidity();
  float tempC= dht.readTemperature();
  float heatIndex = dht.computeHeatIndex(dht.convertCtoF(tempC), humidity);
  bool internalFanStatus = false;
  
  if (dht.convertCtoF(tempC) >= 75) { // 75F
      analogWrite(internalFanPMWPin, 255);  // Turn on fan
      internalFanStatus = true;
  } else if (dht.convertCtoF(tempC) <= 70) { // 70F
      analogWrite(internalFanPMWPin,0); // Turn off fan
      internalFanStatus = false;
  }

// AIR QUALITY BOX SENSORS -
/* VOC, AQI, External Temp, Humidity, Heat Index, Barometric Pressure, Fan Status */

// WEATHER STATION SENSORS
/* Wind Speed, Wind Direction, Rainfall */

// OUTPUT DATA FIELDS HERE TO SERIAL MONITOR / SCREEN / LOGGER / or JSON OBJ.

    if (internalFanStatus) {
      Serial.print("Internal fan is ON | ");
    } else {
      Serial.print("Internal fan is OFF | ");
    }
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%, Temp: ");
    Serial.print(dht.convertCtoF(tempC));
    Serial.print("F | ");
    Serial.print(tempC);
    Serial.print("C");
    Serial.print(" | Heat Index: ");
    Serial.println(heatIndex);

    delay(testingDelayTime); //Delay on loop needs set to 300000 (5 minutes)
}

   
