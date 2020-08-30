#pragma once

//
// ... Circular header files
//
#include <circular/details/import.hpp>

namespace Circular::Details
{
  template<typename T, typename U>
  constexpr T
  modulo(T m, U n){
    return m < 0
      ? (n - (abs(m) % n)) % n
      : m % n;
  }

} // end of namespace Circular::Details
