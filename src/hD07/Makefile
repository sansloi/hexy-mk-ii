## Makefile comes from: https://github.com/WeAreLeka/Bare-Arduino-Project Adjust paths to fit your system's needs'
## Before you edit this further, note your faths. 
#For the arduino we're really assuming they're in 
#a /sketchbook dir in your home dir


### PROJECT_DIR
### This is the path to where you have created/cloned your project
#PROJECT_DIR       = /Users/MyUserName/path/to/my/Project
#PROJECT_DIR       =	~/sketchbook/
#PROJECT_DIR		=	/home/.../.../stuff

### ARDMK_DIR
### Path to the Arduino-Makefile director
##Directory where the '*.mk' files are stored.
#ARDMK_DIR         = $(PROJECT_DIR)/Arduino-Makefile
##actually it's path to arduino IDE and/r core files are stored
ARDMK_DIR	= /usr/share/arduino

### ARDUINO_DIR
### Path to the Arduino application and resources directory.
### On OS X:
#ARDUINO_DIR       = /Applications/Arduino.app/Contents/Java
ARDUINO_DIR       = /usr/share/arduino

### ARDUINO_SKETCHBOOK
### Path to 'sketchbook'directory
ARDUINO_SKETCHBOOK	=	~/sketchbook

##ARDUINO_PREFERENCES_PATH
ARDUINO_PREFERENCES_PATH	= ~/sketches/preferences.txt

### USER_LIB_PATH, optional, default to user's sketchbook
### Path to where the your project's libraries are stored.
#USER_LIB_PATH    :=  $(PROJECT_DIR)/libraries
USER_LIB_PAT	= ~/sketchbook/libraries ##~/sketchbook/libraries/armadillo

### BOARD_TAG
### It must be set to the board you are currently using. (i.e uno, mega2560, etc.)
BOARD_TAG         = nano328
#the nano v3 is the 328 one
#BOARD_TAG		=	nano 
#the nano v2 should be the regular nano
#BOARD_TAG		=	mega2560
#BOARD_TAG		=	atmega328	

### MONITOR_BAUDRATE
### It must be set to Serial baudrate value you are using.
MONITOR_BAUDRATE  = 9600

### AVR_TOOLS_DIR
### Path to the AVR tools directory such as avr-gcc, avr-g++, etc.
### On OS X with `homebrew`:
#AVR_TOOLS_DIR     = /usr/local
### or on Linux: (remove the one you don't want)
#AVR_TOOLS_DIR     = /usr
AVR_TOOLS_DIR	=	/usr/share/arduino/hardware/tools/avr

### AVRDUDE
### Path to avrdude directory.
### On OS X with `homebrew`:
#AVRDUDE          = /usr/local/bin/avrdude
### or on Linux: (remove the one you don't want)
AVRDUDE          = /usr/bin/avrdude

### CFLAGS_STD
### Set the C standard to be used during compilation. Documentation (https://github.com/WeAreLeka/Arduino-Makefile/blob/std-flags/arduino-mk-vars.md#cflags_std)
CFLAGS_STD        = -std=gnu11

### CXXFLAGS_STD
### Set the C++ standard to be used during compilation. Documentation (https://github.com/WeAreLeka/Arduino-Makefile/blob/std-flags/arduino-mk-vars.md#cxxflags_std)
CXXFLAGS_STD      = -std=gnu++11

### CXXFLAGS
### Flags you might want to set for debugging purpose. Comment to stop.
CXXFLAGS         += -pedantic -Wall -Wextra

### MONITOR_PORT
### The port your board is connected to. Using an '*' tries all the ports and finds the right one.
#MONITOR_PORT      = /dev/tty.usbmodem*
#MONITOR_PORT	   = /dev/ttyUSB*
MONITOR_PORT	   = /dev/ttyUSB3


### CURRENT_DIR
### Do not touch - used for binaries path
CURRENT_DIR       = $(shell basename $(CURDIR))

### OBJDIR
### This is where you put the binaries you just compile using 'make'
OBJDIR            = $(PROJECT_DIR)/bin/$(BOARD_TAG)/$(CURRENT_DIR)

### Do not touch - the path to Arduino.mk, inside the ARDMK_DIR
include $(ARDMK_DIR)/Arduino.mk
