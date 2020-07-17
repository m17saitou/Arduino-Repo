BOARDS_TXT 		= /usr/share/arduino10/hardware/arduino/boards.txt
ARDUINO_CORE_PATH= /usr/share/arduino10/hardware/arduino/cores/arduino
ARDMK_DIR = /usr/share/arduino
AVR_TOOLS_DIR = /usr
BOARDS_TXT = /usr/share/arduino10/hardware/arduino//boards.txt
ARDUINO_VAR_PATH = /usr/share/arduino10/hardware/arduino/variants
BOOTLOADER_PARENT = /usr/share/arduino/hardware/archlkinux-arduino/avr/bootloaders
BOARD_TAG 		= nano328
MONITOR_PORT	= /dev/ttyUSB0 #Arduino Divice Path
ARDUINO_PORT 	= /dev/ttyUSB0
MONITOR_BAUDRATE 	= 115200
MCU = atmega328
ARDUINO_DIR = /usr/share/arduino
AVRDUDE_CONF 	= /usr/share/arduino10/hardware/tools/
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