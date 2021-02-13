# Assignment 1: Generative Kiosk Art

### Getting started

First, ensure that your Raspberry Pi has [internet access](https://www.raspberrypi.org/documentation/configuration/wireless/wireless-cli.md).
Depending on your text editor and environment preferences, 
either connect your Pi to a monitor, 
or [ssh into it](https://learn.adafruit.com/adafruits-raspberry-pi-lesson-6-using-ssh/enabling-ssh) to do local development.
You may also want to install `git`, if it's not there already.

### Processing/monitor setup

Install Processing on your Pi:

```$ curl https://processing.org/download/install-arm.sh | sudo sh```

### Python/LED setup

Materials:
* Raspberry Pi 4
* NeoPixel 8 RGB LED Module
* 3 female-to-female wires

Attach each wire to one of the NeoPixel's three "IN" pins.
Link the S (signal) pin to Pi'l GPIO21, the pin closest to the ethernet port and th e edge of the board.
Link the P (power) pin to the Pi's 3.3V, the pin diagonally opposite to GPIO21.
Link the G (ground) pin 3-by-2 pins down from the power pin, into the Pi's GROUND pin.

Ensure that Python3 is installed on your Pi:

```$ python3 --version```

Run `neopixels_colors.py` using administrator privileges.

```$ sudo python3 neopixels_colors.py```

### Start on boot

The `.config/autorun/` directory contains a file, `p5.desktop`, that starts the two programs on boot. Simply copy the entire `.config` folder into your home directory to ensure that the Pi runs it on boot.
This file assumes that 
the path to your home directory is `/home/pi` 
and that this repo is in a folder called `hw`. 
If this isn't the case, please edit the path in the p5.desktop file 
to match the path of the python script and Processing sketch, respectively.

### Final product

A video of the final product can be found [here](https://drive.google.com/file/d/1dhQXFhMjVCgU0hlayRtIte_hQ1ik8BGU/view?usp=sharing) -- apologies in advance for the low video quality.


