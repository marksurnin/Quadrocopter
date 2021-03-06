#ifndef INFOLED_H
#define INFOLED_H

#include "Definitions.h"

#ifdef DEBUG_DAC
#include "DAC8512.h"
#endif

class InfoLED
{
private:
    int pin;
#ifdef DEBUG_DAC
    DAC8512 DACDev;
#endif

public:
    enum typeT{DIGITAL, PW,
#ifdef DEBUG_DAC
               DAC
#endif
    } type;
    void setOn();
    void setOff();

    // set new state
    // 0 or 1 for DIGITAL type or
    // 0...100 for PW type
    void setState(int state);

    InfoLED(int nPin, typeT nType = DIGITAL);
    InfoLED();
};

#endif // INFOLED_H
