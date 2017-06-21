#include "System.hpp"
#include <windows.h>

int main()
{
  System o1;
  o1.Init();
  while(1)
  {
    o1.run();
    Sleep(2);
  }
  return 0;
}

