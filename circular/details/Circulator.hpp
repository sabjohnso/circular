#pragma once

//
// ... Circular header files
//
#include <circular/details/import.hpp>
#include <circular/details/utility.hpp>

namespace Circular::Details
{

  template<typename T>
  struct CirculatorTraits
  {
    using difference_type = typename T::differnce_type;
    using value_type = typename T::value_type;
    using reference = typename T::refernce;
  }; // end of struct CirculatorTraits


  template<typename Iter,
           typename Size = ::Circular::Details::integer,
           typename Index = ::Circular::Details::integer>
  class Circulator
  {
    using size_type = Size;
    using index_type = Index;
    using iterator_type = Iter;

    iterator_type it;
    size_type nelem;
    index_type index;

  public:

    using differnce_type = index_type;
    using value_type = typename ::Circular::Details::iterator_traits<iterator_type>::value_type;
    using reference = typename ::Circular::Details::iterator_traits<iterator_type>::reference;

    Circulator(iterator_type first, iterator_type last)
      : it(first)
      , nelem( ::Circular::Details::distance(first, last))
      , index(0)
    {}

    Circulator(iterator_type first, size_type n)
      : it(first)
      , nelem(n)
      , index(0)
    {}

    size_type
    size() const { return nelem; }

    decltype(auto)
    operator [](index_type offset)
    {
      return it[::Circular::Details::modulo(index + offset, nelem)];
    }

    decltype(auto)
    operator *(){ return (*this)[0]; }

    Circulator&
    operator +=(index_type offset)
    {
      index += offset;
      return *this;
    }

    Circulator&
    operator -=(index_type offset)
    {
      return *this += -offset;
    }

    Circulator&
    operator ++()
    {
      return *this += 1;
    }

    Circulator
    operator ++(int)
    {
      Circulator result = *this;
      *this += 1;
      return result;
    }

    Circulator&
    operator --()
    {
      return *this += -1;
    }

    Circulator
    operator --(int)
    {
      Circulator result = *this;
      *this += -1;
      return result;
    }

  private:

    friend bool
    operator ==(Circulator const& x, Circulator const& y)
    {
      using ::Circular::Details::modulo;
      return modulo(x.index, x.size()) == modulo(y.index, x.size());
    }

    friend bool
    operator !=(Circulator const& x, Circulator const& y)
    {
      return !(x == y);
    }

  }; // end of class Circulator

  template<typename Iter>
  Circulator(Iter first, Iter last) -> Circulator<Iter>;

  template<typename Iter>
  Circulator(Iter first, ::Circular::Details::integer n) -> Circulator<Iter>;

} // end of namespace Circular::Details
