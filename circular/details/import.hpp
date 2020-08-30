#pragma once

//
// ... Standard header files
//
#include <cstdint>
#include <cmath>
#include <utility>
#include <memory>
#include <iterator>
#include <initializer_list>
#include <vector>
#include <array>

//
// ... External header files
//
#include <type_utility/type_utility.hpp>

namespace Circular::Details
{
  using integer = std::ptrdiff_t;
  using std::abs;
  using std::allocator;
  using std::distance;
  using std::initializer_list;

  using std::forward;
  using std::move;

  using std::vector;
  using std::array;
  using std::copy;
  using std::back_inserter;

  using std::iterator_traits;

  using std::common_type_t;

  using TypeUtility::type_count;

} // end of namespace Circular::Details
