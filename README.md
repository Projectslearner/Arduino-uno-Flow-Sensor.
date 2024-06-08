# Flow Sensor Using Arduino UNO

#### Project Overview

This project demonstrates how to measure the flow rate and total volume of liquid using a flow sensor with an Arduino UNO. The sensor reads the flow rate in liters per second and calculates the total volume of liquid passed through the sensor.

#### Components Needed

1. **Arduino UNO Board**
2. **Flow Sensor**
3. **Breadboard**
4. **Jumper Wires**

#### Block Diagram

![Flow Sensor Diagram](flow_sensor_diagram.png)

#### Circuit Wiring

1. **Flow Sensor:**
   - Connect the VCC pin of the flow sensor to the 5V pin on the Arduino.
   - Connect the GND pin of the flow sensor to the GND pin on the Arduino.
   - Connect the signal output pin of the flow sensor to digital pin 2 on the Arduino.

#### Instructions

1. **Set Up the Circuit:**
   - Assemble the circuit according to the wiring instructions.
   - Ensure all connections are secure and components are correctly placed on the breadboard.

2. **Upload the Code:**
   - Copy and paste the provided code into the Arduino IDE.
   - Verify and upload the code to your Arduino board.

3. **Observe the Sensor Readings:**
   - Open the Serial Monitor in the Arduino IDE.
   - The measured flow rate and total volume will be printed in liters per second (L/Sec) and liters (L), respectively, with updates every second.

#### Code Explanation

- **Variables and Initialization:**
  - The code defines variables to store the flow frequency (`flow_frequency`), volume (`volume`), and flow rate (`l_minute`).
  - The flow sensor is connected to digital pin 2 (`flowsensor`).
  - An interrupt is attached to count pulses from the sensor.

- **Setup Function:**
  - Initializes the sensor pin as an input and enables the internal pull-up resistor.
  - Begins serial communication at a baud rate of 9600.
  - Attaches an interrupt to the sensor pin to count rising pulses.
  - Prints an initial message to the Serial Monitor.

- **Loop Function:**
  - Calculates the flow rate and total volume every second.
  - If there is flow detected, the flow rate is calculated in liters per second, and the total volume is updated and printed to the Serial Monitor.
  - If no flow is detected, it prints a message indicating a flow rate of 0 L/Sec.

#### Applications

- **Water Management:** Use the flow sensor for monitoring and managing water usage in various applications.
- **Industrial Systems:** Implement in industrial processes to measure and control liquid flow.
- **Irrigation Systems:** Integrate into irrigation systems to monitor water flow and usage.

---



🌐 [projectslearner.com](https://www.projectslearner.com)  
📧 [projectslearner@gmail.com](mailto:projectslearner@gmail.com)  
📸 [Instagram](https://www.instagram.com/projectslearner/)  
📘 [Facebook](https://www.facebook.com/projectslearner)  
▶️ [YouTube](https://www.youtube.com/@ProjectsLearner)  
📘 [LinkedIn](https://www.linkedin.com/in/projectslearner)

## Made for you with ❣️ from ProjectsLearner