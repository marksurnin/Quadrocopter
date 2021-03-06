#ifndef SERIAL_H
#define SERIAL_H

#include <string>
#include <map>
#include <vector>
#include <vect.h>
#include <mytime.h>

#include <QObject>
#include "qextserialport.h"

using std::string;
using std::vector;
using std::map;

class quadrocopter;
class joystick;

typedef short unsigned int serial_t;

class serial : public QObject
{
Q_OBJECT
friend class quadrocopter;
friend class joystick;

protected:
    QextSerialPort *port;

    unsigned int rate;
    string device;

    unsigned int maxwait;
    bool serror;

    map<int, BaudRateType> rateMap;

    mytime connectDelay, readTimer;
    number_vect_t connectDelayTime;

    vector<serial_t> buffer;

    unsigned int readBytesN;

    bool busyBit;

    void sopen();
    void sclose();
    void reopen();
public:
    serial();

    //device-specific initialization (unused)
    //virtual void do_connect();
    //virtual void do_disconnect();

    void setMaxwait(unsigned int);
    void setRate(unsigned int);
    void setDevice(string);

    string getDevice();

    void swrite(serial_t);
    void swritePut();
    void swriteClear();

    serial_t sread();
    void flush();

    bool readError();
    void readErrorReset();

    bool isconnected();
    bool iswaiting();
    bool isoperational();
    bool iswriteable();

    vect read_vect_byte(unsigned int axis = 3);
    unsigned int read_unsigned_int_3byte();

    void write_number_vect_t(number_vect_t min_value, number_vect_t max_value, number_vect_t value, unsigned int bytes);
    number_vect_t read_number_vect_t(number_vect_t min_value, number_vect_t max_value, unsigned int bytes);

public slots:
    virtual void on_rx();
};

#endif // SERIAL_H
