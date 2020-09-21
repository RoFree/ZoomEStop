# ZoomEStop
It was always tricky for me to quicly mute or unmute with zoom. I also always found it fun to press EStop buttons. Why not combine them? This leverages the BLE functionality of the ESP32 microcontroller to emultate a bluetooth keyboard. When you press the estop button it presses the keyboard shortcuts to mute audio and stop video. 
Connection Diagram

D15 -----> Estop button connection 1
GND -----> 1K resistor ----> Estop button connection one
3V3 -----> Estop button connection 2

This code assumes you are using a NC estop button. Change the values for other types. 
My implementation places the ESP32 in a IP68 drop proof case (came with EStop button). Feel free to play around with enclouseres. Remeber that if you are using a metal enclosure leave a gap for the ESP32. The gap should be larger than a 5 cm diameter circle. Bigger is better. 
