# Elephant Vending Machine Remote

This directory contains the code for the remote devices.
* The button directory contains the button reading code for the 3 monitor raspberry pis
* The default_img directory contains the default images required on the 3 monitor raspberry pis
* The motor directory contains the motor code and the ESP8266 WiFi code for the treat dispenser Arduino

The code `button.py` was modified to be compatible with the GPIO wiring on the Sensor RPis. The back-end
executes `button.py` independently on each display each time after receiving an input signal from one of
the Sensor Pis.
