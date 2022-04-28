#include <Arduino.h>
#include <Servo.h>

#define SERIAL_PRINT 0

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

    #if SERIAL_PRINT
    Serial.begin(9600);

    delay(5000);
    Serial.println(F("begin!"));
    #endif
}

void loop() {
    int inX = analogRead(XPININ);
    int inY = analogRead(YPININ);

    #if SERIAL_PRINT
    Serial.print(F("  X:"));
    Serial.println(inX);
    Serial.print(F("  Y:"));
    Serial.println(inY);
    #endif

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

    #if SERIAL_PRINT
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
    #endif
}