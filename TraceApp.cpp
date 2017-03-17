#include "TraceApp.h"

TraceApp::TraceApp(SoftwareSerial &uart, uint32_t baud): m_puart(&uart)
{
  _baud = baud;
  _valid = false;
}

void TraceApp::begin(void)
{
  m_puart->begin(_baud);
  while (m_puart->available() > 0)
  {
    m_puart->read();
  }
}

bool TraceApp::valid(void)
{
  return _valid;
}

void TraceApp::routine(void)
{
  while (m_puart->available() > 0)
  {
    char nullByte = char(m_puart->read());
    if (nullByte == ';')
    {
      comdata[data_p] = nullByte;
      data_p = 0;

      if ((char)comdata[0] == 'o')
      {
        strtok(comdata, ",");
        dataX = atof(strtok(NULL, ","));
        dataY = atof(strtok(NULL, ","));
        dataT = atof(strtok(NULL, ";"));
        _valid = true;
      }
      else
      {
        _valid = false;
      }
    }
    else
    {
      comdata[data_p] = nullByte ;
      data_p++ ;
    }
  }
}

int TraceApp::getX(void)
{
  return dataX;
}

int TraceApp::getY(void)
{
  return dataY;
}

int TraceApp::getT(void)
{
  return dataT;
}

