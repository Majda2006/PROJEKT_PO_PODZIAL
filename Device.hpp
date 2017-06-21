#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <list>
#include <unistd.h>
#include <vector>
#include <map>

#include "Sensor.hpp"

typedef uint16_t _bool;
class Sensor;
class Device
{
  protected:
    _bool condition;
    std::string NameDevice;
  public:
    Device(const std::string&);
    virtual ~Device();
    virtual _bool getcond();
    virtual void  swtCond();

    virtual void send() = 0;
    virtual void update(Sensor*) = 0;
    virtual void addNumb(const std::string&);
    virtual void delNumb(std::string);
    virtual void showList();
};

class DisplayScreen : virtual public Device
{
  std::string Text;
  public:
  DisplayScreen(const std::string& _NameDevice);
  ~DisplayScreen();
  void send();
  void update(Sensor*);
};

class DisplayTime : public Device
{
  uint16_t* hh;
  uint16_t* mm;
  std::string syntaxTIME;
  public:
  DisplayTime(const std::string&);
  ~DisplayTime();
  void send();
  void update(Sensor*);
  //void update(const Time*);
};

class SMS : public Device
{
  std::list<std::string> Number;
  std::string Message;
  public:
  SMS(const std::string& _Name);
  void send();
  void update(Sensor*);
  void addNumb(const std::string&);
  void delNumb(std::string);
  void showList();

};

class FactoryDevice
{
  public:
  virtual Device* Create(const std::string& Name) = 0;
};

class FDisplayScreen : public FactoryDevice
{
  public:
  Device* Create(const std::string& Name);
};

class FDisplayTime : public FactoryDevice
{
  public:
  Device* Create(const std::string& Name);
};

class FSMS : public FactoryDevice
{
  public:
  Device* Create( const std::string& Name);
};

#endif
