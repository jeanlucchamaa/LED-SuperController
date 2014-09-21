LED SuperController
===================
-Source code for, and all sketches related to the devlopment and final implementation of an Arduino-Based LED controller.
-Most complete edition of the final/installed sketch is LED_CODE.ino in the repository root.
-Subfolders serve as places to hold preliminary sketches, and experimental code for implementing sub-features independently.


Based upon the Arduino Nano 3.1 with an ATmega328P at the core, this project is engineered to power a 100 point non-addressable LED strip in variety of interesting ways.

FEATURES
========
- Option to control lights with the OEM infared remote controller, or control maually with the arduino and attached hardware.
- 3 potentiometers to precisely control the Red, Green, and Blue values of the outuput color.
- Fade feature, with variable fade length.
- Strobe/Flash feature.
- Party mode (Audio-Reactive).  Reads audio in from a microphone, and uses the results of an fft to detect the bassline of a song. Flashes the LEDs in time with the music, in response to multiple fft bins.  Color options available.
- 16x2 Character RGB blacklit LCD for displaying menus and options. (Backlight color to match strip color)
- 5-way navigational switch for menu navigation and digital input.
- Whatever other modes that can be accomodated and are wanted.
