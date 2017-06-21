#include "Device.hpp"
//#include "Sensor.hpp"
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

Device::Device(const std::string& _NameDevice)
  : NameDevice(_NameDevice), condition(0)
{}
Device::~Device(){};
_bool Device::getcond(){return condition;};
void  Device::swtCond(){condition = !condition;}
void  Device::addNumb(const std::string&){};
void  Device::delNumb(std::string){};
void  Device::showList(){};
//-------------------------------------------------------
DisplayScreen::DisplayScreen(const std::string& _NameDevice)
  : Device(_NameDevice) {}
DisplayScreen::~DisplayScreen(){}
void DisplayScreen::send()
{
  //Code of display an information on screen
  std::cout<<Text<<std::endl;
  std::cout<<"DispalyScreen_Wyswietlono"<<std::endl;
}

void DisplayScreen::update(Sensor* obj)
{
  Text.clear();
  Text = obj->getName();
  Text.append(": ");
  Text.append(patch::to_string(obj->getMeas() ));
  send();
}
//--------------------------------------------------------
DisplayTime::DisplayTime(const std::string& _Name)
  : Device(_Name)
{
  hh = new uint16_t;
  mm = new uint16_t;
}
DisplayTime::~DisplayTime()
{
  delete hh;
  delete mm;
}
void DisplayTime::send()
{
  //CODE of the time display
  std::cout<<syntaxTIME<<std::endl;
  std::cout<<"Pokazano czas:"<<std::endl;
}

void DisplayTime::update(Sensor* obj)
{

  //obj->getTime(hh,mm);
  syntaxTIME.clear();
  //syntaxTIME.append(std::to_string((unsignedhh*));
  syntaxTIME.append(":");
  //syntaxTIME.append(std::t-_string((unsigned)mm*));
  send();
}
//-------------------------------------------------------
SMS::SMS(const std::string& _Name)
  : Device(_Name)
{}

void SMS::send()
{
  //CODE
  std::cout<<"Wyslano SMS do: "<<std::endl;
  showList();
  std::cout<<Message<<std::endl;
}
void SMS::update(Sensor* obj)
{
  Message.clear();
  Message.append(obj->getName());
  Message.append(": ");
  Message.append(patch::to_string(obj->getMeas()));
  if(obj->getMeas() >= obj->getLimt())
    send();
}
void SMS::addNumb(const std::string& NewNumb)
{
  Number.push_back(NewNumb);
}
void SMS::delNumb(std::string Numb)
{
  Number.remove(Numb);
}
void SMS::showList()
{
  Message.clear();
  for(auto iter = Number.cbegin(); iter != Number.cend(); iter++)
  {
    Message.append(*iter);
    Message.append("\n");
  }
  //send();
}
//--------------------------------------------------------
Device* FDisplayScreen::Create(const std::string& Name)
{
  return (new DisplayScreen(Name));
}
Device* FDisplayTime::Create(const std::string& Name)
{
  return (new DisplayTime(Name));
}
Device* FSMS::Create(const std::string& Name)
{
  return (new SMS(Name));
}
//-------------------------------------------------------

