/*
** MTTEH MMA8451 Co-Library
** https://github.com/MTTEH/MTTEH_MMA8451
**
** Authors :
**  - Narutarded (https://github.com/narutarder).
**  - Kiradae (https://github.com/Kiradae).
**  - GGLinnk (https://github.com/GGLinnk) <gglinnk@protonmail.com>.
**  - Wabia (https://github.com/wabia).
**
** Licence GPLv3
**
**/

#include "MTTEH_MMA8451.hpp"

Adafruit_MMA8451 mma_gyroaccel_sensor = Adafruit_MMA8451();
sensors_event_t mma_gyroaccel_event;

void init()
{
    //check_serial();

    Serial.println("MMA8451 Initialization !");

    if (!mma_gyroaccel_sensor.begin()) {
        Serial.println("MMA8451 Initialisation Failed !");
        Serial.println("Program died !");
        program_died();
    }
    Serial.println("MMA8451 Connected!");
    mma_gyroaccel_sensor.setRange(MMA8451_RANGE_2_G);
    Serial.print("Range = ");
    Serial.print(2 << mma_gyroaccel_sensor.getRange());
    Serial.println("G");
}

void read()
{
    mma_gyroaccel_sensor.read();
}

void print_X()
{
    Serial.print("X: ");
    Serial.println(mma_gyroaccel_sensor.x);
}

void print_Y()
{
    Serial.print("Y: ");
    Serial.println(mma_gyroaccel_sensor.y);
}

void print_Z()
{
    Serial.print("Z: ");
    Serial.println(mma_gyroaccel_sensor.z);
}

void print_all()
{
    print_X();
    print_Y();
    print_Z();
    Serial.println("");
}

void get_event()
{
    mma_gyroaccel_sensor.getEvent(&mma_gyroaccel_event);
}

void print_X_event()
{
    Serial.print("X: ");
    Serial.print(mma_gyroaccel_event.acceleration.x);
    Serial.println("m/s^2");
}

void print_Y_event()
{
    Serial.print("Y: ");
    Serial.print(mma_gyroaccel_event.acceleration.y);
    Serial.println("m/s^2");
}

void print_Z_event()
{
    Serial.print("Z: ");
    Serial.print(mma_gyroaccel_event.acceleration.z);
    Serial.println("m/s^2");
}

void print_all_event()
{
    print_X_event();
    print_Y_event();
    print_Z_event();
    Serial.println("");
}

uint8_t get_orientation()
{
    return mma_gyroaccel_sensor.getOrientation();
}