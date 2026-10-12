🏥 Nurse Call System Using ESP32 and MQTT

An IoT-Based Patient Assistance and Real-Time Communication System

---

1. Project Overview

The Nurse Call System is an Internet of Things (IoT) project designed to demonstrate how patients can request assistance from nursing staff using a simple electronic system.

The project was initially developed and tested using an Arduino Uno. It was subsequently extended using an ESP32 microcontroller to enable wireless communication through Wi-Fi and the MQTT protocol.

The system allows a patient to activate a call, provides a visual indication through an LED, and transmits the call status to a remote MQTT client.

2. Project Objectives

- Design a functional patient-to-nurse calling system.
- Implement push-button control and LED signalling.
- Develop and test a physical prototype using Arduino Uno.
- Integrate ESP32 Wi-Fi connectivity.
- Implement MQTT communication for remote monitoring.
- Verify the system using the Wokwi simulator and HiveMQ MQTT client.

3. Hardware Components

Component| Purpose
Arduino Uno| Initial physical prototype
ESP32| Wi-Fi-enabled microcontroller
Patient push button| Activates a nurse call
Nurse push button| Clears an active call
Red LED| Indicates an active call
220 Ω resistor| Limits LED current
Connecting wires| Electrical connections

4. Technologies and Tools

Technology| Application
Arduino C++| Embedded programming
Wokwi| ESP32 circuit simulation
Wi-Fi| Wireless network connectivity
MQTT| Lightweight message communication
HiveMQ| Public MQTT broker and testing client
GitHub| Project documentation and source code

5. System Operation

Step 1 – Patient Request

The patient presses the call button.

Step 2 – Visual Notification

The ESP32 activates the call status and switches on the red LED.

Step 3 – MQTT Communication

The ESP32 publishes a "CALL" message to the MQTT topic:

"nursecall4240/room1"

Step 4 – Nurse Response

The nurse presses the reset button to acknowledge and clear the call.

Step 5 – Call Cancellation

The LED switches off, and the ESP32 publishes a "CLEARED" message to the same MQTT topic.

6. Physical Prototype – Arduino Uno

The initial prototype was assembled and tested using a physical Arduino Uno board.

The circuit demonstrated the fundamental operation of the nurse call system using two push buttons and an LED.

Physical Prototype Photograph

Physical Prototype Demonstration

The recorded Arduino Uno demonstration video will be inserted here.

7. ESP32 Circuit Simulation – Wokwi

The system was extended using an ESP32 microcontroller in the Wokwi simulation environment.

The ESP32 version supports Wi-Fi connectivity and MQTT message publishing while preserving the original button and LED functionality.

Simulation Screenshot

The Wokwi circuit screenshot will be inserted here.

Simulation Demonstration Video

The recorded Wokwi demonstration video will be inserted here.

Live Simulation:

"Open the ESP32 Nurse Call System in Wokwi" (https://wokwi.com/projects/477702034076485633)

8. MQTT Communication and Testing

MQTT communication was implemented using the PubSubClient library and the HiveMQ public MQTT broker.

MQTT Configuration

Parameter| Value
Broker| "broker.hivemq.com"
MQTT Port| "1883"
Topic| "nursecall4240/room1"
Patient Message| "CALL"
Nurse Message| "CLEARED"

Test Results

- ESP32 successfully connected to Wi-Fi.
- ESP32 successfully connected to the MQTT broker.
- Pressing the patient button generated a "CALL" message.
- Pressing the nurse button generated a "CLEARED" message.
- Both messages were observed in the HiveMQ WebSocket client.

MQTT Test Screenshot

The HiveMQ test screenshot will be inserted here.

9. Project Files

File| Description
"sketch.ino"| ESP32 program source code
"diagram.json"| Wokwi circuit configuration
"libraries.txt"| Required external library declaration
"README.md"| Project documentation

10. Conclusion

The Nurse Call System demonstrates the integration of embedded electronics, wireless networking, and MQTT communication in a basic healthcare assistance prototype.

The Arduino Uno implementation validated the physical input and output functions, while the ESP32 implementation enabled remote communication through Wi-Fi.

The successful transmission of "CALL" and "CLEARED" messages confirmed the operation of the MQTT communication process.

This project provides a foundation for further development, including multi-room monitoring, a dedicated nurse dashboard, and improved reliability.

---

Project Status: Functional educational prototype.

Important: This system is intended for educational demonstration only. It is not a certified medical device, and the public MQTT broker must not be used for real patient information.
