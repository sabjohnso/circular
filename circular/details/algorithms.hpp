#pragma once

//
// ... Circular header files
//
#include <circular/Circulator.hpp>

namespace Circular::Details
{
  template<typename Circ, typename UnaryFunction>
  UnaryFunction
  forEach(Circ first, UnaryFunction f)
  {
    auto it = first;
    do
    {
      f(it);
      ++it;
    }
    while(it != first);
    return f;
  }

  template<typename InputCirc, typename OutputIt, typename UnaryOperation>
  OutputIt
  map(InputCirc first, OutputIt out, UnaryOperation f)
  {
    auto it = first;
    do
    {
      *out = f(it);
      ++it; ++out;
    }
    while(it != first);
    return out;
  }

  template<typename InputCirc1, typename InputCirc2, typename OutputIt, typename BinaryOperation>
  OutputIt
  map2(InputCirc1 first1, InputCirc2 it2, OutputIt out, BinaryOperation f)
  {
    auto it1 = first1;
    do
    {
      *out = f(it1, it2);
      ++it1; ++it2; ++out;
    }
    while(it1 != first1);
    return out;
  }

  template<
    typename InputCirc1,
    typename InputCirc2,
    typename InputCirc3,
    typename OutputIt,
    typename TernaryOperation
    >
  OutputIt
  map3(InputCirc1 first1, InputCirc2 it2, InputCirc3 it3, OutputIt out, TernaryOperation f)
  {
    auto it1 = first1;
    do
    {
      *out = f(it1, it2, it3);
      ++it1; ++it2; ++it3; ++out;
    }
    while(it1 != first1);
    return out;
  }

  template<typename InputCirc, typename UnaryPredicate>
  bool
  allOf(InputCirc first, UnaryPredicate pred)
  {
    bool result = true;
    auto it = first;
    do
    {
      result = pred(it);
      ++it;
    }
    while(result && it != first);
    return result;
  }

  template<typename InputCirc, typename UnaryPredicate>
  bool
  anyOf(InputCirc first, UnaryPredicate pred)
  {
    bool result = false;
    auto it = first;
    do
    {
      result = pred(it);
      ++it;
    }
    while((! result) && it != first);
    return result;
  }

  template<typename InputCirc, typename UnaryPredicate>
  bool
  noneOf(InputCirc first, UnaryPredicate pred){
    return !(anyOf(first, pred));
  }

  template<typename InputCirc, typename UnaryPredicate>
  typename CirculatorTraits<InputCirc>::differnce_type
  countIf(InputCirc first, UnaryPredicate pred)
  {
    typename CirculatorTraits<InputCirc>::differnce_type result = 0;
    auto it = first;
    do
    {
      if(pred(it))
      {
        ++result;
      }
    }
    while(it != first);
    return result;
  }

  template<typename InputCirc, typename T>
  typename CirculatorTraits<InputCirc>::differnce_type
  countEach(InputCirc first, T const& value)
  {
    return countIf(first, [&](auto it){ return *it == value; });
  }

} // end of namespace Circular::Details
