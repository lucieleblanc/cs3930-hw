# Assignment 3: Wireless Installation 


## Assembling the Hardware

### Materials

- ESP32
- ESP32 extension board
- breadboard
- ESP32 power source
- Raspberry Pi
- HDMI cable (display)
- USB-C cable (power)
- USB dongle for keyboard/mouse

Buttons:
- 2 large buttons
- 4 M/M jumper cables
- 4 10kOhm resistors

Enclosure:
- Paper, any kind
- Tape

### Instructions




### Installing and running the software

Install Arduino IDE on the Raspberry Pi.
Open `esp_paint/esp_paint.ino` with Arduino. 
Compile and upload it to the ESP32.

Next, you'll need to install Java (version 8) on the Raspberry Pi.
```$ sudo apt install openjdk-8-jre```
Then, download the .jar file needed to run Processing via a Python script.
```$ curl https://py.processing.org/processing.py-linux64.tgz p5.tgz```
Extract and uncompress the file you just downloaded.
```$ tar xzvf p5.tgz```

Now, change the Raspberry Pi's wi-fi connection to the ESP32 instead of a normal router.
To run the Python script for the alarm clock, you'll need to run Java with the `.jar` file in the folder you just un`tar`ed. 
It will look something like this:
```$ java -jar p5/processing-py.jar alarmclockpy/alarmclockpy.pyde```


