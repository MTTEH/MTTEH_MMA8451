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

void MMA8451::init()
{
    //check_serial();
    _sensor = Adafruit_MMA8451();
    Serial.println("MMA8451 Initialization !");

    if (!_sensor.begin()) {
        Serial.println("MMA8451 Initialisation Failed !");
        Serial.println("Program died !");
        program_died();
    }
    Serial.println("MMA8451 Connected!");
    _sensor.setRange(MMA8451_RANGE_2_G);
    Serial.print("Range = ");
    Serial.print(2 << _sensor.getRange());
    Serial.println("G");
}

void MMA8451::read()
{
    _sensor.read();
}

void MMA8451::Print::X()
{
    Serial.print("X: ");
    Serial.println(_sensor.x);
}

void MMA8451::Print::Y()
{
    Serial.print("Y: ");
    Serial.println(_sensor.y);
}

void MMA8451::Print::Z()
{
    Serial.print("Z: ");
    Serial.println(_sensor.z);
}

bool MMA8451::get_event()
{
    return _sensor.getEvent(&_event);
}

void MMA8451::Event::Print::X()
{
    Serial.print("X: ");
    Serial.print(_event.acceleration.x);
    Serial.println("m/s^2");
}

void MMA8451::Event::Print::Y()
{
    Serial.print("Y: ");
    Serial.print(_event.acceleration.y);
    Serial.println("m/s^2");
}

void MMA8451::Event::Print::Z()
{
    Serial.print("Z: ");
    Serial.print(_event.acceleration.z);
    Serial.println("m/s^2");
}

uint8_t MMA8451::get_orientation()
{
    return _sensor.getOrientation();
}