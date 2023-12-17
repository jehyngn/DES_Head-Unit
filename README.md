# DES_Head-Unit
## Introduction

This project aims to develop a Head Unit Qt application running on a Raspberry Pi (RPi) alongside the previously developed PiRacer Instrument Cluster Qt application (was developed to display real-time speed data from the speed sensor on the car).  The project will use Yocto as the build system for the RPi.

The head unit application is a critical component of the in-car infotainment system, providing a user interface for various functions, such as navigation system, , ambient lighting, gear selection, and media playback.




## Head Unit
### Main Screen

- **Header:** Displays essential information such as date and  time
- **Navigation Bar:** Allows users to switch between different features (ambient lighting, gear selection, media app).
- **Ambient Lighting Widget:** Provides controls for customizing ambient lighting settings.
- **Gear Selection Widget:** Indicates the current gear and allows manual selection if applicable.
- **Media App Interface:** Intuitive controls for music and video playback.

### Ambient Lighting

- **Color Palette:** Select from a predefined color palette or customize ambient lighting colors.
- **Brightness Control:** Adjust the brightness of ambient lighting according to user preference.

### Gear Selection

- **Current Gear Display:** Clearly indicates the current gear.
- **Manual Selection:** Able to switch between different gear modes

### Media App

- **Start USB Scan Button:** Initiates the USB scanning process.
- **Playlist View:** Displays the list of available songs with relevant details.
- **Playback Controls:** Play, pause, next, previous buttons for music control.
- **Volume Control:** Slider for adjusting media volume.

### 

### Qt Framework

The GUI is developed using the Qt framework, leveraging QML for declarative UI design and interaction. QObject-based C++ classes handle backend logic and communication with other components.

## Hardware Architecture
![HW_architecture drawio (1)](https://github.com/SEA-ME-Team6/DES_Head-Unit/assets/106136905/0fed61fa-2bc6-4965-886b-cb55bad98cd1)



### Raspberry Pi 4B

- 2-Channel CAN-BUS(FD) Shield (MCP2518FD)
- PiRacer AI Kit (PiRacer Standard)
- 7.9inch DSI LCD (400 x 1280)
- 7inch HDMI LCD (H) (1028 x 600)
- Gamepad controller

### Arduino UNO

- CAN-BUS Shield V2.0 (MCP2515)
- IR infrared Speed Sensor (LM393)
  

## Key Concepts
### SoA(SOME/IP)

### Yocto

### Qt Application Manager
