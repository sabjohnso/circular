//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... Circular header files
//
#include <circular/FixedCirculant.hpp>

namespace Circular::Testing
{
  TEST(FixedCirculant, DefaultConstruction)
  {
    FixedCirculant<int, 3> xs{};
    EXPECT_EQ(xs[0], 0);
    EXPECT_EQ(xs.size(), 3);
  }

  TEST(FixedCirculant, ValueConstruction)
  {
    FixedCirculant xs(3);
    EXPECT_EQ(xs[0], 3);
    EXPECT_EQ(xs.size(), 1);
  }

  TEST(FixedCirculant, ValuesConstruction)
  {
    FixedCirculant xs(3, 4, 5);
    EXPECT_EQ(xs.size(), 3);
    EXPECT_EQ(xs[0], 3);
    EXPECT_EQ(xs[1], 4);
    EXPECT_EQ(xs[2], 5);
  }

  TEST(FixedCirculant, ArrayAccess)
  {
    FixedCirculant xs(3, 4, 5);
    EXPECT_EQ(xs.size(), 3);
    EXPECT_EQ(xs[-4], 5);
    EXPECT_EQ(xs[-3], 3);
    EXPECT_EQ(xs[-2], 4);
    EXPECT_EQ(xs[-1], 5);
    EXPECT_EQ(xs[0], 3);
    EXPECT_EQ(xs[1], 4);
    EXPECT_EQ(xs[2], 5);
    EXPECT_EQ(xs[3], 3);
    EXPECT_EQ(xs[4], 4);
    EXPECT_EQ(xs[5], 5);
  }

  TEST(FixedCirculant, Circulator)
  {
    FixedCirculant xs(3, 4, 5);
    auto c = begin(xs);
    EXPECT_EQ(*c, 3);
  }
} // end of namespace Circular::Testing
