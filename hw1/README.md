# Assignment 1: Generative Kiosk Art

### Getting started

First, ensure that your Raspberry Pi has [internet access](https://www.raspberrypi.org/documentation/configuration/wireless/wireless-cli.md).
Depending on your text editor and environment preferences, 
either connect your Pi to a monitor, 
or [ssh into it](https://learn.adafruit.com/adafruits-raspberry-pi-lesson-6-using-ssh/enabling-ssh) to do local development.

### Processing/monitor setup

Install Processing on your Pi:

```$ curl https://processing.org/download/install-arm.sh | sudo sh```

### Python/LED setup

Ensure that Python3 is installed on your Pi:

```$ python3 --version```

### Start on boot

The `.config/autorun/` directory contains a file, `p5.desktop`, that starts the two programs on boot. Simply copy the entire `.config` folder into your home directory to ensure that the Pi runs it on boot.
This file assumes that 
the path to your home directory is `/home/pi` 
and that this repo is in a folder called `hw`. 
If this isn't the case, please edit the path in the p5.desktop file 
to match the path of the python script and Processing sketch, respectively.


### Final product

A video of the final product can be found [here](https://drive.google.com/file/d/1dhQXFhMjVCgU0hlayRtIte_hQ1ik8BGU/view?usp=sharing) -- apologies in advance for the low video quality.


