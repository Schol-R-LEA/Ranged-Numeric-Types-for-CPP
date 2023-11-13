A simple template class for generating integer and floating-point types within fixed ranges.

Takes a base type, a lower bound, a parameter setting how underflows should be handled, an
upper bound, another parameter setting how overlow conditions should be handled.

_Example Usage_
This defines an integer class `Celsius_Temp` with a range of -273...10000, where underflow throws an exception and overflow saturates.

```c++
typedef Ranged::Ranged_Numbers<int16_t, -273, Ranged::EXCEPT, 10000, Ranged::SATURATE> Celsius_Temp;

Celsius_Temp w(-10);
Celsius_Temp x(10000);
Celsius_Temp y(-272);
Celsius_Temp z(5);

std::out << w / z;    // -2
std::cout << x + z;   // saturates, 10000
std::out << y - z;    // throws an underflow exception

```