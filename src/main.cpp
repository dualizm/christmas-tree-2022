#include <iostream>
#include <chrono>
#include <thread>

#include "sprite.hpp"
#include "console.hpp"

int 
main()
{
  clrcon();
  while(1)
  {
    sprite::print();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    clrcon();
  }
  return EXIT_SUCCESS;
}
