#include "RVector3D.h"
#include "Arduino.h"

#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

class Accelerometer
{
private:
    static const unsigned int Axis = 3, AvgN = 1;
    static const double Accuracy = 1E-2;
    
    static const double adcAref = 5, adcMaxvalue = 1023;
    double mapA[Axis], mapB[Axis];
    
    int ports[Axis];

public:
    Accelerometer(int newPorts[Axis])
    {
        mapA[0] = 0.8616664408; mapB[0] = 1.5204146893;
        mapA[1] = 0.892143084;  mapB[1] = 1.8134632093;
        mapA[2] = 0.8861390819; mapB[2] = 1.5457698227;

        for(unsigned i = 0; i < Axis; i++)
            ports[i] = newPorts[i];
    }

    RVector3D getReadings(); //in m/s^2 divided by g
    RVector3D getVoltageReadings(); //in volts
    RVector3D getRawReadings();
};

#endif
