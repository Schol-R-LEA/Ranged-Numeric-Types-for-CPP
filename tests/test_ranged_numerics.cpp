#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest/doctest.h"
#include "ranged_numbers.h"

typedef Ranged::Ranged_Numbers<int16_t, -273, Ranged::EXCEPT, 10000, Ranged::SATURATE> Celsius_Temp;
typedef Ranged::Ranged_Numbers<uint8_t, 10, Ranged::WRAP, 25, Ranged::WRAP> Ten_25;

TEST_CASE("Test a simple range representing Celsius temperatures.")
{
  Celsius_Temp x(10000), y(10001);
  REQUIRE_THROWS(Celsius_Temp(-300));
  CHECK((x == y));
  CHECK((x == (x + y)));
  REQUIRE_THROWS(Celsius_Temp(-1) - Celsius_Temp(273));
}

TEST_CASE("Test wrapping in a simple range of 10 to 25.")
{
   for (uint8_t i=9, j=25; i > 0; i--, j--)
   { 
      CHECK((Ten_25(i) == Ten_25(j)));
   }
   for (uint8_t i=26, j=10; i <= 30; i++, j++)
   { 
      CHECK((Ten_25(i) == Ten_25(j)));
   }   
}

TEST_CASE("Test arithmetic for .")
{

}
