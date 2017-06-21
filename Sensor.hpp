#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <list>
#include <unistd.h>
#include <vector>
#include <map>

#include "Device.hpp"

typedef uint16_t _bool;
class Device;
class Sensor
{
  protected:
  std::vector<Device*> Dev;
  std::string NameSensor;
  uint16_t    NrRef;
  _bool       Condition;
  float       Measurement;
  float       Limit;
  public:
  Sensor(const std::string&);
  virtual ~Sensor();
  void addDev(Device*);
  void delDev(Device*);
  virtual void InformDev();
  virtual _bool swtSen();
  virtual void Measure() = 0;
  std::string    getName();
  _bool          getCond();
  float          getMeas();
  void           setLimt(const float&);
  float          getLimt();
};

class Time : public Sensor
{
    public:
    uint32_t Timer;
    uint16_t TimeStart;
    Time(const std::string&, const uint16_t&, const uint16_t&);
    ~Time();
   // void InformDev();
    void Measure();
  //  void getTime(uint16_t&, uint16_t&);
};

class Termometr : public Sensor
{
  public:
    Termometr(const std::string&);
    virtual ~Termometr();
    void Measure();
};

class Anemometr : public Sensor
{
  public:
    Anemometr(const std::string& _Name);
    ~Anemometr();
    void Measure();
};

class Wetness : public Sensor
{
  public:
  Wetness(const std::string&);
  ~Wetness();
  void Measure();
};

class FactorySensor
{
  public:
    virtual Sensor* Create(const std::string&) =0;
};

class FTime : public FactorySensor
{
  public:
    Sensor* Create(const std::string&) override;
};

class FTermometr : public FactorySensor
{
  public:
  Sensor* Create(const std::string&) override;
};

class FAnemometr : public FactorySensor
{
  public:
  Sensor* Create(const std::string&) override;
};

class FWetness : public FactorySensor
{
  public:
  Sensor* Create(const std::string&) override;
};


#endif
