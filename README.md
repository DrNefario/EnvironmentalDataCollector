# EnvironmentalDataCollector (EDC) 2560
Environmental data gathering project for AT Mega2650

This project is for creating an environmental data feed from multiple sources (Mega2560 project(s)) gathering sensor data about the above water / ground environment.  There are three parts to this project.  
  
1st - Hardware requirements.  This needs to be a self-contained project since access to Wifi is non-existent in field deployments.  Cellular IoT is prefered choice of communication.  
                              The hardware needs to be powered 24x7, so a backup power souce is a necessity that will need to provide enough power for running the 2560 and the sensor arrays, along with                                        processing time.

This device will return the following metrics:
Temperature in C 
Humidity
Barometric pressure
Wind speed
Wind direction
Rainfall amount
AQI particulates
VOC levels of various gasses
UV Index
Sunlight levels (Sunrise / Set)
Lightning Detection
Charging Voltage
Charge Level
GPS
RTC

What I have come up with is the following parts list:

(Already Purchased)
Mega2560 - R2 - 25.00 - No longer manufactured
20W 12V Solar panel - 32.09 - https://www.amazon.com/dp/B07RZBVTGR
Solar Charger Regulator (Miniboard) w/ 3 bank 18650 holder - 20.54 - https://www.amazon.com/dp/B0CT7TG2WF
12 pc Gas Sensor Detectors MQ-2,3,4,5,6,7,8,9,135 - 17.11 - https://www.amazon.com/dp/B0978KXFCQ
PMS5003 2.5 micrometer AQI Dust Sensor - $18.99 - https://www.amazon.com/dp/B0B1J8FQ7M
DHT22 / AM2302 Digital Temp and Humidity Sensor - 7.57 - https://www.amazon.com/dp/B01N9BA0O4
LM393 - Light Detection Sensor - 5.95 - https://www.amazon.com/dp/B07XFZ99XL
IP67 Waterproof project box - 38.49 - https://www.amazon.com/dp/B08282VRXW
Nylon Plastic 3 - 6.5mm Waterproof Cable Glands - 12.99 - https://www.amazon.com/dp/B094ZFG7DB
22 AWG wire spool - 36.99 - https://www.amazon.com/dp/B079GK9BJ4
4 18650 Rechargable LiPo battery Cells w/ Wall Charger - 28.95 - Liionwholesale.com - P#s (4x - EVE-18650-33V, 1x - xtar-mc2plus_wall)

(Waiting to purchase)
SIM7000A LTE CAT-M1 NB-IoT Cellular / GPS shield - 69.00 - https://www.amazon.com/dp/B07H3XKNLH
BME280 Temperature, Humidity, and Barometric Pressure Sensor - 13.39 - https://www.amazon.com/BME280-Environmental-Sensor-Temperature-Atmospheric/dp/B088HJHJXG
Weather Meter Kit (Includes Anamometer, Wind Direction, and Rain Gauge - RJ11 Terminated) - 79.95 - https://www.amazon.com/Weather-Meter-Kit-Anemometer-terminated/dp/B084DBXMPX
AS3935 Lightning Detector - 27.99 - https://www.amazon.com/JESSINIE-Lightning-MA5532-AE-Lighting-Detection/dp/B0BG2GN6T5
Anamometer 3 Cup Replacement - 15.99 - https://www.amazon.com/Toddmomy-Replacement-Anemometer-Detector-Weather/dp/B0CQZTWSCF
30mm 3.3 / 5V Fans - 9.99 - https://www.amazon.com/Easycargo-Raspberry-30x30x7mm-Brushless-30mmx30mmx7mm/dp/B0792BW2VH
DS3231 / AT24C32 RTC - 5.99 - https://www.amazon.com/dp/B07Q7NZTQS

Various Items - 
M2.5 / M3 Screws / Nuts / Brass Stand Offs, Isolators, Project Board for Mega2560, Various Wires, Connectors, etc.
IoT cellular card.
Voltage converter 1.8V to 20V (adjustable)
3d Print louvers for project box.
Federal Signal Model 2t siren case - may have to fabricate this on a smaller scale... the Federal Signal Model 2T is 24" tall and 15" diameter... that's too large.  
Maybe use a galvanized chimney pipe and cap.

2nd - Software Requirements -

Using the Mega 2560, the max program size is 256K.
JSON object layout for the transmitted object.
JSON object layout for the lightning detection.
Message size should be less than 10K per transmission.  Would like 1K or lower.
Data transmission rate should default to every 5 minutes* - (real time adustable value)
If barometric pressure falls (low pressure system), the device should change the transmission rate to every minute.  
It should also continually check the lightning sensor during the low barometric pressure state. When it detects lightning, transmit a different 
JSON object with the time and distance of the strike.

When the barmometric pressure raises (high pressure system), this transmission rate should return to every 5 minutes, and power down the lightning sensor.
                                

3rd - Backend requirements - Since this is designed to be a stand alone system with no access to Wifi or a network, the only other means of communication is via cellular.  

 Server with NoSQL DB (DynamoDB)
 AWS Private 5G interface
 Webserver to build code to analyze the data and serve reports / send SMS for AQI alerts.
 Static web address (.com) - Goodings.com?
