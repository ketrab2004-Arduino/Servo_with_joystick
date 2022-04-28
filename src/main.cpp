#include <Arduino.h>
#include <Servo.h>

#define XPINOUT 4
#define YPINOUT 3

// analogue:
#define XPININ 0
#define YPININ 1

Servo servoX;
Servo servoY;

void setup() {
    pinMode(XPINOUT, OUTPUT);
    pinMode(YPINOUT, OUTPUT);

    servoX.attach(XPINOUT);
    servoY.attach(YPINOUT);

    servoX.write(90);
    servoY.write(90);

    Serial.begin(9600);

    delay(5000);
    Serial.println(F("begin!"));
}

void loop() {
    int inX = analogRead(XPININ);
    int inY = analogRead(YPININ);

    Serial.print(F("  X:"));
    Serial.println(inX);
    Serial.print(F("  Y:"));
    Serial.println(inY);

    servoX.write(
        map(
            inX,
            0,
            1023,
            0,
            180
        )
    );

    servoY.write(
        map(
            inY,
            0,
            1023,
            0,
            180
        )
    );

    Serial.println(F("Mapped:"));
    Serial.print(F("  x:"));
    Serial.println(map(
            inX,
            0,
            1023,
            0,
            180
        ));
    Serial.print(F("  y:"));
    Serial.println(map(
            inY,
            0,
            1023,
            0,
            180
        ));
    Serial.println(F("=========="));

    //delay(1000);
}