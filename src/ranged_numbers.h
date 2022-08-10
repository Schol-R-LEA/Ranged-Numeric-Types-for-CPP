#ifndef _RANGED_NUMBERS_H_
#define _RANGED_NUMBERS_H_

#include <iostream>
#include <typeinfo>
#include <cmath>

namespace Ranged 
{
  enum Flow_Characteristic {WRAP, SATURATE, EXCEPT};

  class Underflow_Exception
  {

  };

  class Overflow_Exception
  {

  };


  template <typename T, T lower, Flow_Characteristic underflow, T upper, Flow_Characteristic overflow> class Ranged_Numbers
  {
  private:
    T value;

    void restrict_lower()
    {
      if (value >= lower)
        return;
      else
        {
          switch (underflow)
            {
            case WRAP:
              value = upper - abs(lower - value) + 1;
              break;
            case SATURATE:
              value = lower;
              break;
            default:
              throw Underflow_Exception();
            }
        }
    };

    void restrict_upper()
    {
      if (value <= upper)
        return;
      else
        {
          switch (overflow)
            {
            case WRAP:
              value = lower + abs(upper - value) - 1;
              break;
            case SATURATE:
              value = upper;
              break;
            default:
              throw Overflow_Exception();
            }
        }
    };

  public:

    Ranged_Numbers(T v):value(v)
    {
      restrict_lower();
      restrict_upper();
    };

    Ranged_Numbers(Ranged_Numbers& rn):value(rn.v)
    {
      restrict_lower();
      restrict_upper();
    };


    Ranged_Numbers operator+(const Ranged_Numbers& op)
    {
      return Ranged_Numbers(this->value + op.value);
    };

    Ranged_Numbers operator-(const Ranged_Numbers& op)
    {
      return Ranged_Numbers(this->value - op.value);
    };

    Ranged_Numbers operator*(const Ranged_Numbers& op)
    {
      return Ranged_Numbers(this->value * op.value);
    };

    Ranged_Numbers operator/(const Ranged_Numbers& op)
    {
      return Ranged_Numbers(this->value / op.value);
    };

   Ranged_Numbers operator=(const Ranged_Numbers& op)
    {
      this->value = op.value;
    };


    bool operator==(const Ranged_Numbers& op)
    {
      return (this->value == op.value);
    };


    template <typename OST> friend std::ostream& operator<<(std::ostream& os, const OST& rn);

  };


  template <typename OST> std::ostream& operator<<(std::ostream& os, const OST& rn)
  {
     if (typeid(rn.value) == typeid(unsigned char) ||  typeid(rn.value) == typeid(signed char))
     {
        os << static_cast<int16_t>(rn.value);
     }
     else
     {      
        os << rn.value;
     }
     return os;
  }
};

#endif
