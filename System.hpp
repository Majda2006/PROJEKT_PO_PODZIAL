#include "Device.hpp"
#include "Sensor.hpp"

class System
{
  std::vector<FactoryDevice*>    fAllDev;
  std::vector<FactorySensor*>    fAllSen;
  std::map<std::string, Device*> AllDev;
  std::map<std::string, Sensor*> AllSen;
  public:
  System();
  ~System();
  void Init();
  void run();
//  void AddDevSystem();
//  void delDevSystem(const std::string&);
//  void addSenSystem();
//  void delDevSystem(const std::string&);
//  void showAllSystem();
};

