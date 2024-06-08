/*
    Project name : Flow Sensor
    Modified Date: 08-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-flow-sensor
*/

volatile int flow_frequency; // Measures flow sensor pulses
float volume = 0.0;          // Total volume in liters
float l_minute = 0.0;        // Flow rate in liters per minute

unsigned char flowsensor = 2; // Sensor input pin
unsigned long currentTime;
unsigned long cloopTime;

void flow() // Interrupt function to count pulses from the sensor
{
  flow_frequency++;
}

void setup()
{
  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH); // Optional internal pull-up resistor
  Serial.begin(9600);

  // Attach interrupt to the sensor pin
  attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING);

  // Initial message
  Serial.println("Water Flow Meter");
  Serial.println("Circuit Digest");

  currentTime = millis();
  cloopTime = currentTime;
}

void loop()
{
  currentTime = millis();

  // Every second, calculate and display the flow rate and volume
  if (currentTime >= (cloopTime + 1000))
  {
    cloopTime = currentTime; // Update the loop time

    if (flow_frequency != 0)
    {
      // Calculate flow rate in liters per minute (L/min)
      l_minute = (flow_frequency / 7.5); // (Pulse frequency x 60 sec) / 7.5Q = flowrate in L/hour

      l_minute = l_minute / 60; // Convert to liters per second
      volume += l_minute;       // Update the total volume

      // Print to serial monitor
      Serial.print("Rate: ");
      Serial.print(l_minute);
      Serial.println(" L/Sec");

      Serial.print("Total Volume: ");
      Serial.print(volume);
      Serial.println(" L");

      flow_frequency = 0; // Reset the counter for the next second
    }
    else
    {
      Serial.println("Flow rate = 0 L/Sec");

      Serial.print("Total Volume: ");
      Serial.print(volume);
      Serial.println(" L");
    }
  }
}
