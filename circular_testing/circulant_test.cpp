//
// ... Standard header files
//
#include <vector>
//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... Circular header files
//
#include <circular/Circulant.hpp>
#include <circular/algorithms.hpp>

using std::vector;

namespace Circular::Testing
{


  TEST(Circulant, DefaultConstruction)
  {
    Circulant<int> c{};
    EXPECT_EQ(c.size(), 0);
  }

  TEST(Circulant, SizeConstruction)
  {
    Circulant<double> c(10);
    EXPECT_EQ(c.size(), 10);
    EXPECT_TRUE(allOf(begin(c),[](auto x){ return *x == 0.0;}));
  }

  TEST(Circulant, SizeInitConstruction)
  {
    Circulant<double> c(10, 1.0);
    EXPECT_EQ(c.size(), 10);
    EXPECT_TRUE(allOf(begin(c),[](auto x){ return *x == 1.0;}));
  }

  TEST(Circulant, IteratorConstruction)
  {
    vector xs = {1.0, 2.0};
    auto c = Circulator(begin(xs), end(xs));

    EXPECT_EQ(c.size(), xs.size());
    EXPECT_EQ(c[ 0], 1.0);
    EXPECT_EQ(c[-1], 2.0);
  }

} // end of namespace Circular::Testing
