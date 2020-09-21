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

#ifndef MTTEH_MMA8451_H_
#define MTTEH_MMA8451_H_

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

#define program_died() while (1)
#define wait_for(x)    while (!x)

class MMA8451
{
    static Adafruit_MMA8451 _sensor;
    static sensors_event_t _event;

  public:
    void init();
    void read();
    class Print
    {
      public:
        void X();
        void Y();
        void Z();
    };
    bool get_event();
    class Event
    {
        class Print
        {
          public:
            void X();
            void Y();
            void Z();
        };
    };
    uint8_t get_orientation();
};

#endif    // MTTEH_MMA8451_H_