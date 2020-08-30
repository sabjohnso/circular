#pragma once

//
// ... Circular header files
//
#include <circular/details/import.hpp>
#include <circular/details/Circulator.hpp>

namespace Circular::Details
{
  template<typename T, integer N>
  class FixedCirculant
  {
    static_assert(N > 0);

    using storage_type = array<T,N>;
    storage_type storage;

  public:
    static constexpr integer extent = N;
    using value_type = T;

    FixedCirculant() = default;

    constexpr
    FixedCirculant(T const& x)
      : storage{{std::move(x)}}
    {}

    constexpr
    FixedCirculant(T&& x)
      : storage{{x}}
    {}

    constexpr
    FixedCirculant(FixedCirculant&& input)
      : storage(move(input.storage))
    {}


    template<typename T1, typename T2, typename ... Ts>
    constexpr
    FixedCirculant(T1&& x1, T2&& x2, Ts&& ... xs)
      : storage{{forward<T1>(x1), forward<T2>(x2), forward<Ts>(xs) ... }}
    {
      static_assert(type_count<T1, T2, Ts ...> <= N);
    }

    decltype(auto)
    operator [](integer index) { return storage[modulo(index, extent)]; }

    constexpr decltype(auto)
    operator [](integer index) const { return storage[modulo(index, extent)]; }

    static constexpr integer
    size(){ return N; }

    auto
    begin(){ return Circulator(storage.begin(), storage.end()); }

    auto
    begin() const { return Circulator(storage.begin(), storage.end()); }

    auto
    cbegin() const { return begin(); }

  private:

    friend auto
    begin(FixedCirculant& xs){ return xs.begin(); }

    friend auto
    begin(FixedCirculant const& xs){ return xs.begin(); }

    friend auto
    cbegin(FixedCirculant const& xs){ return xs.begin(); }

    friend constexpr integer
    size(FixedCirculant const& xs){ return xs.size(); }

  }; // end of class FixedCirculant

  template<typename T1, typename ... Ts>
  FixedCirculant(T1&& x, Ts&& ... xs) -> FixedCirculant<common_type_t<T1,Ts...>, type_count<T1,Ts...>>;

} // end of namespace Circular::Details
