#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest/doctest.h"
#include "ranged_numbers.h"

typedef Ranged::Ranged_Numbers<int16_t, -273, Ranged::EXCEPT, 10000, Ranged::SATURATE> Celsius_Temp;
typedef Ranged::Ranged_Numbers<uint16_t, 10, Ranged::WRAP, 25, Ranged::WRAP> Ten_25;

TEST_CASE("Test a simple range representing Celsius temperatures.")
{
  Celsius_Temp x(10000), y(10001);
  REQUIRE_THROWS(Celsius_Temp(-300));
  CHECK((x == y));
  REQUIRE_THROWS(Celsius_Temp(-1) + Celsius_Temp(-273));
  CHECK((x == (Celsius_Temp(10000) + Celsius_Temp(1))));
}


TEST_CASE("Test wrapping in a simple range of 10 to 25.")
{
  std::cout << Ten_25(10) << std::endl;
  std::cout << Ten_25(25) << std::endl;
  std::cout << Ten_25(9) << std::endl;
  std::cout << Ten_25(8) << std::endl;
  std::cout << Ten_25(7) << std::endl;
  std::cout << Ten_25(6) << std::endl;
  std::cout << Ten_25(26) << std::endl;
  std::cout << Ten_25(27) << std::endl;
  std::cout << Ten_25(28) << std::endl;
  std::cout << Ten_25(29) << std::endl;
  CHECK((Ten_25(25) == (Ten_25(9))));
  CHECK((Ten_25(24) == (Ten_25(8))));
  CHECK((Ten_25(23) == (Ten_25(7))));
  CHECK((Ten_25(22) == (Ten_25(6))));
  CHECK((Ten_25(10) == (Ten_25(26))));
  CHECK((Ten_25(11) == (Ten_25(27))));
  CHECK((Ten_25(12) == (Ten_25(28))));
  CHECK((Ten_25(13) == (Ten_25(29))));
}
