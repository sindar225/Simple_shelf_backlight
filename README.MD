Simple shelf backlight
======================

The idea behind this project is to create a compact proximity sensor which would turn backlight on and what's more important to run on 9v battery for a long period of time. For this purpose low power mode has been enabled. Although it might have been running in more efficient power saving mode, I deliberately picked PowerSave mode as being a trade-off between power consumption and PWM (for smooth LED start).

*NOTE: To reduce the current draw I unsoldered PWR LED on Arduino and both LEDs on IR sensor.*

More about power saving modes here: https://www.rocketscream.com/blog/2011/07/04/lightweight-low-power-arduino-library/

Demo:
-----
https://www.youtube.com/watch?v=67PNpESbl68

### Components I used in this projects:
* Arduino nano (ATMega 168P)
* 3pin IR Infrared Module 
* CR2032 Copper Led Fairy Lights 2M 20 LEDs https://www.aliexpress.com/item/32831287135.html?spm=a2g0s.9042311.0.0.27424c4diCvnCd
* 9v battery

### Circuit:
![Circuit](/img/Simle_LED_proximity.png)
