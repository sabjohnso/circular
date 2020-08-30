#pragma once

//
// ... Circular header files
//
#include <circular/Circulator.hpp>
#include <circular/details/algorithms.hpp>

namespace Circular
{
  using Details::forEach;
  using Details::map;
  using Details::map2;
  using Details::map3;
  using Details::allOf;
  using Details::anyOf;
  using Details::noneOf;
  using Details::countIf;
  using Details::countEach;
} // end of namespace Circular
