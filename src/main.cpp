#include <Arduino.h>
#include <Servo.h>

#define YPINOUT 3
#define XPINOUT 4
Servo servoY;
Servo servoX;

void setup() {
    pinMode(YPINOUT, OUTPUT);
    pinMode(XPINOUT, OUTPUT);

    servoY.attach(YPINOUT);
    servoX.attach(XPINOUT);

    servoY.write(90);
    servoX.write(90);

    Serial.begin(9600);

    delay(5000);
    Serial.println(F("begin!"));
}

void loop() {
    int inX = analogRead(0);
    int inY = analogRead(1);

    Serial.print(F("  X:"));
    Serial.println(inX);
    Serial.print(F("  Y:"));
    Serial.println(inY);

    servoY.write(
        map(
            inY,
            0,
            1023,
            0,
            180
        )
    );

    servoX.write(
        map(
            inX,
            0,
            1023,
            0,
            180
        )
    );

    Serial.println(F("Mapped:"));
    Serial.print(F("  y:"));
    Serial.println(map(
            inY,
            0,
            1023,
            0,
            180
        ));
    Serial.print(F("  x:"));
    Serial.println(map(
            inX,
            0,
            1023,
            0,
            180
        ));
    Serial.println(F("=========="));

    //delay(1000);
}