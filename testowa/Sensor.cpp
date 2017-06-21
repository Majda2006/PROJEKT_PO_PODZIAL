#include "Sensor.hpp"
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

Sensor::Sensor(const std::string& _NameSensor)
  : NameSensor(_NameSensor), NrRef(0), Condition(0)
{}

Sensor::~Sensor()
{
  Dev.clear();
}
void Sensor::addDev(Device* obj)
{
  Dev.push_back(obj);
}
void Sensor::delDev(Device* obj)
{
  Dev.erase(std::find(Dev.begin(), Dev.end(), obj));
}
_bool Sensor::swtSen()
{
  Condition = !Condition;
  InformDev();
  return Condition;
}
void Sensor::InformDev()
{
  for(auto iter = Dev.begin(); iter < Dev.end(); iter++)
  {
  //  if( (*iter)->getcond() );
       Sensor *ptr = this;
      (*iter)->update(ptr);
  }
}
std::string Sensor::getName(){return NameSensor;}
_bool       Sensor::getCond(){return Condition;}
float       Sensor::getMeas(){return Measurement;}
void        Sensor::setLimt(const float& _Limit){Limit = _Limit;}
float       Sensor::getLimt(){return Limit;}

//------------------------------------------------------
Time::~Time(){}
Time::Time(const std::string& _Name, const uint16_t& _HH, const uint16_t& _MM)
  : Sensor(_Name)
{}

void Time::Measure()
{
  //TIME check;
  std::cout<<"POMIAR CZASU"<<std::endl;

  InformDev();
}
//---------------------------------------------------------
Termometr::Termometr(const std::string& _Name)
  : Sensor(_Name) {}
Termometr::~Termometr(){}
void Termometr::Measure()
{
  //Code of the read temp from sensor
  std::cout<<"POMIAR TEMP"<<std::endl;
  InformDev();
}
//------------------------------------------------------
Anemometr::Anemometr(const std::string& _Name)
  : Sensor(_Name) {}
Anemometr::~Anemometr(){}

void Anemometr::Measure()
{
  //Code
  InformDev();
}
//------------------------------------------------------
Wetness::Wetness(const std::string& _Name)
  : Sensor(_Name){}
Wetness::~Wetness(){}

void Wetness::Measure()
{
  //Code
  InformDev();
}
//------------------------------------------------------
Sensor* FTime::Create(const std::string& _Name)
{
  //Time
  return (new Time(_Name, 0, 0) );
}
Sensor* FTermometr::Create(const std::string& _Name)
{
  return (new Termometr(_Name) );
}
Sensor* FAnemometr::Create(const std::string& _Name)
{
  return (new Anemometr(_Name) );
}
Sensor* FWetness::Create(const std::string& _Name)
{
  return ( new Wetness(_Name) );
}


