#ifndef TraceApp_h
#define TraceApp_h
#include "Arduino.h"
#include <inttypes.h>
#include <SoftwareSerial.h>

class TraceApp
{
  public:
    TraceApp(SoftwareSerial &uart, uint32_t baud = 9600);
    int getX(void);
    int getY(void);
    int getT(void);
    void begin(void);
    void routine(void);
    bool valid(void);
  private:
    SoftwareSerial *m_puart;
    char comdata[50], data_p; 
    int  dataX, dataY, dataT;
    uint32_t _baud;
    bool _valid;

};

#endif
