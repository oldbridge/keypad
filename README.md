keypad
======

C static library for interfacing a matrix keypad to a Raspberry Pi.

- Requires bcm2535 library from Mike McCauley (mikem@airspayce.com): http://www.airspayce.com/mikem/bcm2835/

Use
----
- Change keypad.h as required to fit your needs and connections (see connections section below)
- Link with the provided keypad.a library and use the keypad.h header

The following methods are provided:
- init_keypad() : call it before anything to initialize the GPIOs and bcm2535 library
- get_key() : polls for a key returns the mapped value as char or 0 if no key is pressed
- wait_key(): waits for a key to be pressed

Connections
------------
Use this as reference for the keypad:

http://playground.arduino.cc/uploads/Main/keypad_pin_diagram.png

The bcm2535 library uses the P1 connector labeling.

cols[] array in the header defines the columns starting from the leftmost.
rows[] array in the header defines the rows starting from the uppermost.
