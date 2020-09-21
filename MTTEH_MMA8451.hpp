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

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include <Adafruit_Sensor.h>
#include <Adafruit_MMA8451.h>

#ifndef MTTEH_MMA8451_H_
    #define MTTEH_MMA8451_H_

    #define program_died() while (1)
    #define wait_for(x)    while (!x)

class MMA8451
{
  public:
    void init();
    void read();
    void print_X();
    void print_Y();
    void print_Z();
    void print_all();
    void get_event();
    void print_X_event();
    void print_Y_event();
    void print_Z_event();
    void print_all_event();
    uint8_t get_orientation();
};

#endif    // MTTEH_MMA8451_H_