BOARD_TAG = nano328
MONITOR_PORT = /dev/ttyUSB0 #Arduino Divice Path
MONITOR_BAUDRATE 	= 115200
include /usr/share/arduino/Arduino.mk

# ----- How to Writing Program to Arduino Nano -----
# - First 
# in terminal type this command "$ ls -l /dev/serial/by-id/"
# Then output devices
# - Second 
# in terminal type this command "$ ls -la /dev/[Arduino Device]"
# then output permission
# if output "crw--rw--rw ..." you can go next
# else output like"crw--rw---- ..." , you need to type " $ sudo chmod 666 /dev/[Arduino Device] "
# -Third
# to write program to Arduino nano , you type "$ make upload"