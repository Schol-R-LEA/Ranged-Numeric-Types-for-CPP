#include <iostream>
#include "ranged_numbers.h"

typedef Ranged_Numbers<int16_t, -273, SATURATE, 10000, SATURATE> Celsius_Temp;


int main()
{
  Celsius_Temp a(-300), b(10001);
  
  std::cout << a << std::endl;
  std::cout << b << std::endl;
}

