#include <iostream>
#include <chrono>
#include <thread>

#include "sprite/sprite.hpp"
#include "console/console.hpp"

int 
main()
{
  clrcon();
  while(1)
  {
    sprite::print(sprite::tree);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    clrcon();
  }
  return EXIT_SUCCESS;
}
