#include "System.hpp"
#include <windows.h>

System::System()
{}
System::~System()
{
  for(auto iter = fAllDev.begin(); iter != fAllDev.end(); iter++)
    delete (*iter);
  for(auto iter = fAllSen.begin(); iter != fAllSen.end(); iter++)
    delete (*iter);
  for(auto iter = AllDev.begin(); iter != AllDev.end(); iter++)
    delete (iter->second);
  for(auto iter = AllSen.begin(); iter != AllSen.end(); iter++)
    delete (iter)->second;

  fAllDev.clear();
  fAllSen.clear();
  AllDev.clear();
  AllSen.clear();
}

void System::Init()
{
  fAllDev.push_back(new FDisplayScreen);
  fAllDev.push_back(new FDisplayTime);
  fAllDev.push_back(new FSMS);

  fAllSen.push_back(new FTime);
  fAllSen.push_back(new FTermometr);
  fAllSen.push_back(new FAnemometr);
  fAllSen.push_back(new FWetness);

  AllDev.insert(std::pair<std::string, Device*>("Wyswietlacz0", fAllDev[0]->Create("Wyswietlacz0")));
  AllDev.insert(std::pair<std::string, Device*>("Wyswietlacz1", fAllDev[1]->Create("Wyswietlacz1")));
  AllDev.insert(std::pair<std::string, Device*>("ModulGSM", fAllDev[2]->Create("ModulGSM")));

  AllSen.insert(std::pair<std::string, Sensor*>("Zegar", fAllSen[0]->Create("Zegar")));
  AllSen.insert(std::pair<std::string, Sensor*>("Termometr1", fAllSen[0]->Create("Termomentr1")));
  AllSen.insert(std::pair<std::string, Sensor*>("Anemometr1", fAllSen[0]->Create("Anemometr1")));
  AllSen.insert(std::pair<std::string, Sensor*>("Wilgotnosc1", fAllSen[0]->Create("Wilgotnosc1")));

  auto iter_dev = AllDev.find("Wyswietlacz0");
  while(iter_dev != AllDev.end())
  {
    iter_dev->second->swtCond();
    iter_dev++;
  }

  auto iter1 = AllSen.find("Zegar");
  auto iter2 = AllSen.find("Termometr1");
  auto iter3 = AllSen.find("Anemometr1");
  auto iter4 = AllSen.find("Wilgotnosc1");

  auto iterD1 = AllDev.find("Wyswietlacz0");
  auto iterD2 = AllDev.find("Wyswietlacz1");
  auto iterD3 = AllDev.find("ModulGSM");

  iter1->second->addDev(iterD2->second);
  iter2->second->addDev(iterD1->second);
  iter2->second->addDev(iterD3->second);

  iter3->second->addDev(iterD1->second);
  iter3->second->addDev(iterD3->second);

  iter4->second->addDev(iterD1->second);
  iter4->second->addDev(iterD3->second);


  auto iter_gsm = AllDev.find("ModulGSM");
  iter_gsm->second->addNumb("+48500111232");
  iter_gsm->second->addNumb("+48823100921");
  iter_gsm->second->addNumb("+48512411692");
  iter_gsm->second->addNumb("+48653121242");
}

void System::run()
{
  for(auto iter = AllSen.cbegin(); iter != AllSen.cend(); iter++)
  {
    iter->second->Measure();
    Sleep(3);
  }
}


