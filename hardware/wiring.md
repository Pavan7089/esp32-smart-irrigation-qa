# Wiring

| Signal | ESP32 pin | Note |
|---|---|---|
| Soil sensor AOUT | GPIO 25 (v0.1) | Changed to GPIO 34 in issue #4 |
| DHT22 data | GPIO 4 | 10 kohm pull-up to 3.3 V |
| Relay IN | GPIO 26 | Active-low: LOW = pump ON |
| Sensor VCC / GND | 3.3 V / GND | |
| Relay VCC / GND | 5 V / GND | |
| Pump | Relay NO contact and 5 V | |

Add a photo of your circuit or a Wokwi screenshot here.
