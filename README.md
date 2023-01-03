# Smart Traffic Light System
![WhatsApp Image 2023-01-03 at 10 22 29](https://user-images.githubusercontent.com/100681513/210292681-e2b9312b-ab8c-494c-84d8-53709af9cb3a.jpeg=228x171)![WhatsApp Image 2023-01-03 at 10 22 28](https://user-images.githubusercontent.com/100681513/210292704-9d4a4e44-7977-4403-a994-da5eaf0ef486.jpeg=228x171)


This is a traffic light control system with 4 junctions using Arduino. This system will allow the junction with highest density (Number of times waiting * number of cars) to have the green light on. 
 
## Infrared (IR) Sensor 
IR Sensor is placed beside the fifth car position of a road to detect the presence of car passed throught it. It will give a digital signal (HIGH or LOW) to determine the presence of car. 

![image](https://user-images.githubusercontent.com/100681513/210291321-d9f90dd8-be33-491c-974a-71a90d0c1902.png)


Pinout:
|    IR Sensor      |      Arduino UNO     |
|:-----------------:|:--------------------:|
|        1          |           7          |
|        2          |           8          |
|        3          |           9          |
|        4          |           10         |

## Shift Register (SN74HC595N)
Instead of using LEDs, 2 shift registers are used to control the LEDs. First shift register connect all the red and yellow LEDs, while the second shift register connect all the green LEDs.

![image](https://user-images.githubusercontent.com/100681513/210291275-f45a44ec-d376-47c0-bc35-c9e8260d7591.png)

Shift Register 1 Pinout:
|Shift Register|Arduino UNO|
|:------------:|:---------:|
|1|LED R2|
|2|LED R3|
|3|LED R4|
|4|LED Y1|
|5|LED Y2|
|6|LED Y3|
|7|LED Y4|
|8|GND|
|9|N/C|
|10|VCC|
|11|Arduino D6|
|12|Arduino D5|
|13|GND|
|14|Arduino D4|
|15|LED R1|
|16|VCC|

Shift Register 2 Pinout:
|Shift Register|Arduino UNO|
|:------------:|:---------:|
|1|LED G2|
|2|LED G3|
|3|LED G4|
|4,5,6,7,9|N/C|
|8|GND|
|10|VCC|
|11|Arduino D2|
|12|Arduino D3|
|13|GND|
|14|Arduino D11|
|15|LED G1|
|16|VCC|

## Coding
```Arduino
TrafficLight(int Latch1, int Data1, int Clock1, int Latch2, int Data2, int Clock2, int IR1, int IR2, int IR3, int IR4, int TimeBlock)
```
|Parameter|Definition|
|:------------:|:---------:|
|Latch1|Latch Pin (SR1)|
|Data1|Data Pin (SR1)|
|Clock1|Clock Pin (SR1)|
|Latch2|Latch Pin (SR2)|
|Data2|Data Pin (SR2)|
|Clock2|Clock Pin (SR2)|
|IR1|IR Sensor Pin at 1st junction|
|IR2|IR Sensor Pin at 2nd junction|
|IR3|IR Sensor Pin at 3rd junction|
|IR4|IR Sensor Pin at 4th junction|
|TimeBlock|Time Block for each junction to move|
