const float REQUIRED_VOLTAGE = 5.0;
const float TOLERANCE = 0.2;

void setup() {
  // initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // read the voltage from the external source
  float voltage = readVoltage();

  // check if the voltage is within the required range
  if (voltage < REQUIRED_VOLTAGE - TOLERANCE || voltage > REQUIRED_VOLTAGE + TOLERANCE) {
    // notify the user if the voltage is outside the required range and by how much
    Serial.println("The voltage has changed from the required value! by " + String(voltage - REQUIRED_VOLTAGE) + "V");
  }
}

float readVoltage() {
  // read the input on analog pin 0
  float sensorValue = analogRead(0);

  // convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);

  return voltage;
}

