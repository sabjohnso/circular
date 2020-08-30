#pragma once

//
// ... Circular header files
//
#include <circular/details/import.hpp>
#include <circular/details/utility.hpp>
#include <circular/Circulator.hpp>

namespace Circular
{

  /**
   *  @brief A container which offers fixed time access to
   *  individual elements with modular indexing
   *
   *  @ingroup sequences
   *
   *  @tparam T  Element type.
   *  @tparam Allocator Allocator type defaulting to ::Circular::Details::Allocator<T>.
   *
   *  A Circulant can be described as a dynamic as a dynamic array
   *  with modular indexing.
  */
  template<
    typename T,
    typename Size = ::Circular::Details::integer,
    typename Index = ::Circular::Details::integer,
    typename Allocator = ::Circular::Details::allocator<T>
    >
  class Circulant
  {
    using size_type = Size;
    using index_type = Index;
    using storage_type = ::Circular::Details::vector<T,Allocator>;

    storage_type storage;

  public:

    using value_type = T;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using reference = value_type&;
    using const_reference = value_type const&;


    Circulant() = default;

    Circulant(Circulant const& input)
    {
      using namespace ::Circular::Details;

      storage.reserve(input.size());
      copy(input.storage.begin(), input.storage.end(),
           back_inserter(storage));
    }

    Circulant(size_type n, T init = {})
      : storage(n, init)
    {}

    Circulant(::Circular::Details::initializer_list<T> init)
      : Circulant(begin(init), end(init))
    {}

    template<typename Iter>
    Circulant(Iter first, Iter last)
      : storage(first, last)
    {}

    size_type
    size() const
    {
      return storage.size();
    }

    reference
    operator [](size_type index)
    {
      return storage[index];
    }

    const_reference
    operator [](size_type index) const
    {
      return storage[modulo(index, size())];
    }

    auto
    begin(){ return Circulator(storage.begin(), storage.end()); }

    auto
    begin() const { return Circulator(storage.begin(), storage.end()); }

    auto
    cbegin() const { return begin(); }

  private:

    friend auto
    begin(Circulant& xs){ return xs.begin(); }

    friend auto
    begin(Circulant const& xs){ return xs.begin(); }

    friend size_type
    size(Circulant const& xs){ return xs.size(); }

  }; // end of class Circulant;


} // end of namespace Circular
