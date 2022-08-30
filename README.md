# DYNAMIC SPEED GOVERNOR FOR HOTSPOT AND SPEED RATED AREAS

---
This repository contains the workflow of a dynamic speed governor. Designed to change as per a location's speed limit, this dynamic speed governor is highly applicable in school zones, hospitals and black spots among others. 

---

## PROBLEM STATEMENT
Overspeeding is among the leading causes of road carnage. Loss of valuable lives as well as destruction of property arise as a result of these accidents. Consequently, the government has erected signposts indicating the speed limit of a certain area. Other measures include the use of traffic lights as well as speed detectors. The project aims to infor  the driver about the zones and the speed limit automatically, which is done by means of using RF technology. The objective of this project is to 
automatically control the speed of the vehicles at speed restricted areas such as schools and hospitals.  

## HOW?
At particular zones (specifically those with existing signposts), transmitters which are tuned at a frequency of about 433MHZ are mounted. These transmitters continuously radiate RF signals. When the vehicle comes within the range of this signal, the receiver (which is mounted on the vehicle) gets activated. Whenever the vehicle is within the zone, the vehicle speed is regulated as per the area's speed limit. This means that the vehicle's speed is decreased to some value which is below the speed limit and kept constant until the vehicle moves out of the zone.

## IMPLEMENTATION
This was done using `Arduino`, `Proteus` and `KiCad` softwares. 

## COMPONENTS USED

### For the transmitter circuit: 

•	`Radio frequency transmitter module` 

This is a small PCB sub-assembly capable of transmitting and modulating a radio wave to carry data.

•	`M145026` or `HT12E` (Encoder)

Converts parallel inputs into serial output. It encodes the 12 bit parallel data into serial for transmission through an RF transmitter. These 12 bit are divided into 8 address bit and 4 data bits.

•	`Push-buttons` 

It is a simple switch mechanism to control the speed limits aspects of the project. The comprise of the 20, 40, 60 and 80 km/hr speed limits.

•   `Two 10k Resistors`

•   `1 uF Capacitor`

![TRANSMITTER SCHEMATIC](https://github.com/KaburaJ/Dynamic-Speed-Governor/blob/main/DEVELOPMENT/Images/TRANSMITTER-RECEIVER%20SIMULATION1.PNG)


### For the receiver cicuit:

•	`Radio frequency receiver module` 

It is a device that accepts radio frequencies from a remote transmitter.

•	`M145027` or `HT12D` (Decoder) 

Used after the RF receiver to decode the serial format and retrieve the original signals as outputs.

•	`Voltage regulator` 

It is system designed to automatically maintain a constant voltage.

•	`Arduino` (Microcontroller) 

•	`Five 200 ohms Resistors` 

•   `Two 10k resistors`

•   ` 1 uF Capacitor`

•	`Push-buttons` 

They include; the `start` button on `pin 12`, `increment`/ `acceleration` button on `pin 4`, `decrement` button on `pin 2`.

•	`Five Leds`

Used to indicate the limit being set in by the remote on the receiver. 

•   `12C` or `LM016` (LCD)

Displays instructions to the vehicle driver

•   `PCF8574`

Used with `LM016`. It has two output pins, making the LCD programming much easier.

•   `L298` (Motor Driver)


•   ` 12V DC Motor`

Used to simulate the behaviour of the vehicle's wheels whilst the program runs.

•   `Buzzer`

Used as an indicator that warns the driver of the changing speed limits - therefore giving him or her an opportunity to decrease the vehicle's speed manually. If ignored, the speed governing system takes over.

![RECEIVER SCHEMATIC](https://github.com/KaburaJ/Dynamic-Speed-Governor/blob/main/DEVELOPMENT/Images/TRANSMITTER-RECEIVER%20SIMULATION.PNG)

## WORKFLOW

![WORKFLOW](https://github.com/KaburaJ/Dynamic-Speed-Governor/blob/main/DEVELOPMENT/Images/PROCEDURE.PNG)

## CONCLUSION

The strategy for this project was to produce a much easily operable and reliable device
This design explains the vehicle speed controller based on the RF technology. It has explained how transmitters installed some roads sections and receivers installed in vehicles can be used to communicate with the each other thereby providing control over the vehicle speed. The design approach was based on a combination of two block units which are the transmitter and the receiver
The results obtained were promising and show that this design can be a potential vehicle speed governor because of its capacity to influence the receiver speed, by giving some expected limits i.e. in the empirical trials, the receiver’s speed was successfully changed as a result of the detection of the signals from the transmitter. This would mean that the design can be more reliable, effective and can be a lasting solution in curbing over speeding in Kenya if fully implemented
The design also worked well for a close range of about 20cm between the transmitter and the receiver because of low transmit power and the value of each speed limit test was then displayed on the LCD display at the receiver side. 
Thus, there can be hope to revolutionize the traffic management and avoid accidents caused due to over speeding in the near future of our country.

## RECOMMENDATIONS
•	Provision of tools that emulate the external real application environment such as a real vehicle for testing the performance of the developed RF based vehicle speed governor

•	Modification may be done on signal processing for digital speed display. The speed controller algorithm developed for this speed governor was based on Pulse Width Modulation (PMW) technique at the receiver end, but other control mechanisms such as fuzzy logic system may also be adopted to give   accurate reasoning, acceptable reasoning and also help to deal with uncertainty in the designing process.

•	Further work can be carried out to study how different frequencies avoid high chances of channel interferences in cases of co-located zones/sections of the roads. The 433MHz technology holds less information and the technology itself is very rudimentary. The 433MHz signals are typically only one-way. This however makes the 433 MHz devices, less reliable. So, further research can be carried out using other technologies like Zig Bee (2.4GHz) or Z-Wave (868.42 MHz) for testing purposes.

•	Instead of the radio frequency we could have used GPS solutions such as Google Maps to reduce hardware costs and increase coverage.

•	Accessibility to components needed to achieve the goals of the project





## REFERENCES
•How a Car Works “How a fuel injection system works”, howacarworks.com, [online] Available, https://www.howacarworks.com/basics/how-a-fuel-injection-system-works 

•Arduino “Get Started with Arduino Uno”, Arduino.cc, [online] Available https://www.arduino.cc/en/Guide/ArduinoUno 

•Robot Platform “Dual H-bridge Motor Driver - L293D IC”, robotplatform.com, [online] Available [https://www.robotplatform.com/howto/L293/motor_driver_1.html 

•Lastminute Engineers “How 433MHz RF Tx-Rx Modules Work & Interface with Arduino”, lastminuteenineers.com, [active] Available, https://lastminuteengineers.com/433mhz-rf-wireless-arduino-tutorial/ 

•RoadSafetyNz “How Do Modern Speed Limiters Work?”, roadsafetynz.org, [online] Available, http://www.roadsafetynz.org/modern-speed-limiters.html
        
