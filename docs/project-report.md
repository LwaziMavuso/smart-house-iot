# Smart House IoT — Technical Project Report

## 1. Project Overview

The Smart House IoT project is a personal project developed to explore how Internet of Things (IoT) technology can be used to control household functions remotely.

The prototype used an ESP32 microcontroller, three LEDs representing lights in three different rooms, a servo motor representing a door mechanism, and an I²C LCD display for system feedback.

The Blynk platform provided a mobile interface for remotely controlling the room lights and servo motor independently.

This report has been reconstructed retrospectively because the original project documentation was not retained.

## 2. Project Objectives

The main objectives of the project were:

- To explore IoT-based remote control.
- To use an ESP32 microcontroller in a smart-home application.
- To demonstrate independent control of three household lights.
- To demonstrate remote door operation using a servo motor.
- To display system information and component statuses using an LCD.
- To gain practical experience integrating hardware with a mobile application.

## 3. Hardware and Software

### Hardware

- ESP32 microcontroller
- Three LEDs representing lights in three different rooms
- One servo motor representing a door mechanism
- One I²C LCD display

The exact specifications and wiring configurations of the components have not been confirmed.

### Software and Platforms

- Blynk IoT platform
- Arduino programming environment

## 4. System Operation

The ESP32 served as the central microcontroller for the prototype.

The Blynk mobile application provided a remote interface for controlling the three room lights and the servo motor independently.

### 4.1 Room Lighting Control

Three LEDs represented lights in three different rooms. Each LED could be switched ON or OFF independently through the Blynk application.

### 4.2 Door Control

A servo motor represented a door mechanism. It could be operated remotely through the Blynk application.

### 4.3 LCD Display and System Feedback

An I²C LCD display provided information about the system's status.

During startup, the display showed messages such as:

- Smart House Loading
- Smart House Ready

The LCD also displayed the ON/OFF status of the LEDs. The displayed status changed when the corresponding LED was switched on or off.

The exact LCD dimensions, I²C address and display configuration are currently unconfirmed.

## 5. Project Evidence

A photograph of the original prototype is available in the repository's `images` folder.

The photograph serves as supporting evidence of the physical project. Further photographs, circuit diagrams and original source code may be added if recovered or reconstructed.

## 6. Challenges and Documentation Limitations

The original project was completed without a comprehensive technical record.

As a result, the following information is currently unavailable or unconfirmed:

- Original Arduino source code.
- Circuit diagram and detailed wiring configuration.
- ESP32 pin assignments.
- Exact LCD specifications and I²C address.
- Original Blynk configuration and virtual pin assignments.
- Formal test results.

This report has been prepared retrospectively using the available project photograph and the developer's recollection of the project.

## 7. Learning Outcomes

The project provided practical experience in:

- Understanding the role of a microcontroller in an IoT system.
- Exploring remote control through a mobile application.
- Independently controlling multiple electronic components.
- Using LEDs to represent household lighting.
- Using a servo motor to demonstrate physical movement.
- Integrating an LCD display for system feedback.
- Connecting software-based controls with physical hardware.

## 8. Future Improvements

Potential improvements to the project documentation and prototype include:

- Reconstructing the Arduino program based on confirmed functionality.
- Producing a circuit diagram using verified connections.
- Documenting hardware specifications and pin assignments.
- Recreating the Blynk interface and documenting its configuration.
- Recording functional tests and their results.
- Capturing clearer photographs and a demonstration video.

These improvements are proposed future activities and are not presented as completed work.

## 9. Conclusion

The Smart House IoT project explored the use of an ESP32 and Blynk to demonstrate remote control of household lighting and a door mechanism.

The prototype also incorporated an I²C LCD display to communicate startup information and the status of the room lights.

Although the original technical documentation is unavailable, this retrospective report records the project's purpose, confirmed functionality, components and opportunities for further development.

---

**Project type:** Personal IoT project  
**Developer:** Lwazi Mavuso  
**Documentation status:** Reconstructed retrospectively
