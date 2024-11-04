#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(9); // Attach the servo to digital pin 9
  pinMode(7, INPUT); // Set pin 7 as input for the IR sensor
}

void loop() {
  int irValue = digitalRead(7); // Read the IR sensor value
  
  // If the IR sensor detects an object (HIGH)
  if (irValue == HIGH) {
    // Move servo to 90 degrees at 20% faster speed
    for (int pos = servo.read(); pos < 90; pos++) {
      servo.write(pos);
      delay(10); // Further increase speed by reducing delay to 30ms
    }
  } 
  // If the IR sensor does not detect an object (LOW)
  else {
    // Move servo back to 0 degrees at 20% faster speed
    for (int pos = servo.read(); pos > 0; pos--) {
      servo.write(pos);
      delay(10); // Further increase speed by reducing delay to 30ms
    }
  }
}
