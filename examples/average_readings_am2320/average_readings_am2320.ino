#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"

Adafruit_AM2320 am2320 = Adafruit_AM2320();

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10); // hang out until serial port opens
  }

  Serial.println("Adafruit AM2320 Average Temperature Test");
  am2320.begin();
}

void loop() {
  float avgTemp = am2320.readTemperatureAvg(5, 2000);
  // 5 is the amount of measurements
  // 2000 is the time in ms between the measurements

  // print out average temperature reading when ready
  if (!isnan(avgTemp)) {
    Serial.print("Average Temperature: ");
    Serial.println(avgTemp);
  }

  delay(100);
}
