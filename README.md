## Automated Irrigation System

An IoT system to suggest the irrigation pattern based on soil and light conditions on the field. 

### Data Collection

Data is collected from the field using multiple Light Dependent Resistors (LDRs) and Soil Moisture sensors. 

### Data Processing

The data collected by the sensors is brought into the Intel Edison board. The code file led_test.ino, which contains the actions that need to be performed on this data, is also run on the Edison board. The system then decides the irrigation pattern for the field.

### Data Storage and Analysis

The real-time data is uploaded n the ThingSpeak cloud, available for trend analysis and posting updates to the user. This data, with the help of an Android application based on the MIT App Inventor, enables the user to stay updated with the irrigation data.

It also allows a Manual mode that overrides the Automatic system and lets the user decide the irrigation pattern.

### Code file

The code file with .ino extension should be run in the Arduino IDE.
