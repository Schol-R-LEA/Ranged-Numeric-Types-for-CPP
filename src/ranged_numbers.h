#ifndef _RANGED_NUMBERS_H_
#define _RANGED_NUMBERS_H_

#include <iostream>

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
               value = upper - value;
               restrict_lower();
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
               value = lower + value;
               restrict_upper();
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

   Ranged_Numbers& operator+(Ranged_Numbers& op)
   {
      Ranged_Numbers result(this->value + op.value);
      return result;
   };

  template <typename OST> friend std::ostream& operator<<(std::ostream& os, OST& rn);

};


template <typename OST> std::ostream& operator<<(std::ostream& os, OST& rn)
{
  os << rn.value;
  return os;
}


#endif
