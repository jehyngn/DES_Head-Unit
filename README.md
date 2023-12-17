# DES_Head-Unit

## Preview

## Introduction

This project aims to develop a Head Unit Qt application running on a Raspberry Pi (RPi) alongside the previously developed PiRacer Instrument Cluster Qt application (was developed to display real-time speed data from the speed sensor on the car).  The project will use Yocto as the build system for the RPi.

The head unit application is a critical component of the in-car infotainment system, providing a user interface for various functions, such as navigation system, , ambient lighting, gear selection, and media playback.


## Key Concepts
### SoA(SOME/IP)

### Yocto

### Qt Application Manager


## Head Unit


### Gear Selection

- **Current Gear Display:** Clearly indicates the current gear.
- **Manual Selection:** Able to switch between different gear modes
  
### Ambient Lighting

- **Color Palette:** Select from a predefined color palette or customize ambient lighting colors.

### Head Lamp
- **Head Lamp Control:** Control the head lamp through gamepad

### Media App

- **Start USB Scan** Initiates the USB scanning process.
- **Playlist View:** Displays the list of available songs with relevant details.
- **Playback Controls:** Play, pause, next, previous buttons for music control.
- **Volume Control:** Slider for adjusting media volume.


### Qt Framework

The GUI is developed using the Qt framework, leveraging QML for declarative UI design and interaction. QObject-based C++ classes handle backend logic and communication with other components.

## Hardware Architecture
![HW_architecture drawio (1)](https://github.com/SEA-ME-Team6/DES_Head-Unit/assets/106136905/0fed61fa-2bc6-4965-886b-cb55bad98cd1)


