# Smart Traffic Light System

.<img src ="https://user-images.githubusercontent.com/100681513/210295969-4725d2d5-047a-47cd-8134-e79b4fca010e.jpeg" width = 30% height = 30%>
<img src = "https://user-images.githubusercontent.com/100681513/210295972-66a1986a-5fcd-43c8-833c-8b6900cf7587.jpeg" width = 30% height = 30%>

This is a traffic light control system with 4 junctions using Arduino UNO. Full OOP has been implemented in this project. This system will allow the junction with highest density (Number of times waiting * number of cars) to have the green light on. 
 
## Infrared (IR) Sensor 
IR Sensor is placed beside the fifth car position of a road to detect the presence of car passed throught it. It will give a digital signal (HIGH or LOW) to determine the presence of car. 

<img src ="https://user-images.githubusercontent.com/100681513/210291321-d9f90dd8-be33-491c-974a-71a90d0c1902.png" width = 50% height = 50%>


#### IR Sensor Pinout
|    IR Sensor      |      Arduino UNO     |
|:-----------------:|:--------------------:|
|        1          |           7          |
|        2          |           8          |
|        3          |           9          |
|        4          |           10         |

## Shift Register (SN74HC595N)
Instead of using LEDs, 2 shift registers are used to control the LEDs. First shift register connect all the red and yellow LEDs, while the second shift register connect all the green LEDs.

![image](https://user-images.githubusercontent.com/100681513/210291275-f45a44ec-d376-47c0-bc35-c9e8260d7591.png)

|Shift Register 1 Pinout|Shift Register 2 Pinout|
|:--:|:--:|
|<table> <tr><th>Shift Register</th><th>Pinout</th></tr><tr><td>1</td><td>LED R2</td></tr><tr><td>2</td><td>LED R3</td></tr><tr><td>3</td><td>LED R4</td></tr><tr><td>4</td><td>LED Y1</td></tr><tr><td>5</td><td>LED Y2</td></tr><tr><td>6</td><td>LED Y3</td></tr><tr><td>7</td><td>LED Y4</td></tr><tr><td>8</td><td>GND</td></tr><tr><td>9</td><td>N/C</td></tr><tr><td>10</td><td>VCC</td></tr><tr><td>11</td><td>Arduino D6</td></tr><tr><td>12</td><td>Arduino D5</td></tr><tr><td>13</td><td>GND</td></tr><tr><td>14</td><td>Arduino D4</td></tr><tr><td>15</td><td>LED R1</td></tr><tr><td>16</td><td>VCC</td></tr> </table>| <table> <tr><th>Shift Register</th><th>Pinout</th></tr><tr><td>1</td><td>LED G2</td></tr><tr><td>2</td><td>LED G3</td></tr><tr><td>3</td><td>LED G4</td></tr><tr><td>4, 5, 6, 7, 9</td><td>N/C<tr><td>8</td><td>GND</td></tr><tr><td>10</td><td>VCC</td></tr><tr><td>11</td><td>Arduino D2</td></tr><tr><td>12</td><td>Arduino D3</td></tr><tr><td>13</td><td>GND</td></tr><tr><td>14</td><td>Arduino D11</td></tr><tr><td>15</td><td>LED G1</td></tr><tr><td>16</td><td>VCC</td></tr> </table>|


## Coding
#### Constructor of Traffic Light Class
```Arduino
TrafficLight(int Latch1, int Data1, int Clock1, int Latch2, int Data2, int Clock2, int IR1, int IR2, int IR3, int IR4, int TimeBlock)
```
#### Definition of each Parameter
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
