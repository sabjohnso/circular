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
#include <circular/Circulator.hpp>

using ::std::vector;
using ::Circular::Circulator;

namespace Circular::Testing
{
  TEST(Circulator, Construction)
  {
    vector xs = {1.0, 2.0, 3.0};
    auto c = Circulator(begin(xs), end(xs));
    EXPECT_EQ(c.size(), 3);
  }

  TEST(Circulator, Dereference)
  {
    vector xs = {1.0, 2.0};
    auto c = Circulator(begin(xs), end(xs));
    EXPECT_EQ(*c, 1.0);
  }

  TEST(Circulator, ArrayAccess)
  {
    vector xs = {1.0, 2.0, 3.0};
    auto c = Circulator(begin(xs), end(xs));

    EXPECT_EQ(c[-4], 3.0);
    EXPECT_EQ(c[-3], 1.0);
    EXPECT_EQ(c[-2], 2.0);
    EXPECT_EQ(c[-1], 3.0);
    EXPECT_EQ(c[ 0], 1.0);
    EXPECT_EQ(c[ 1], 2.0);
    EXPECT_EQ(c[ 2], 3.0);
    EXPECT_EQ(c[ 3], 1.0);
  }

  TEST(Circulator, Increment)
  {
    vector xs = {1.0, 2.0, 3.0};
    auto c = Circulator(begin(xs), end(xs));

    EXPECT_EQ(*c, 1.0);
    ++c;
    EXPECT_EQ(*c, 2.0);
    ++c;
    EXPECT_EQ(*c, 3.0);
    ++c;
    EXPECT_EQ(*c, 1.0);
  }

  TEST(Circulator, PostIncrement)
  {
    vector xs = {1.0, 2.0, 3.0};
    auto c = Circulator(begin(xs), end(xs));

    EXPECT_EQ(*c++, 1.0);
    EXPECT_EQ(*c++, 2.0);
    EXPECT_EQ(*c++, 3.0);
    EXPECT_EQ(*c++, 1.0);
  }

  TEST(Circulator, Decrement)
  {
    vector xs = {1.0, 2.0, 3.0};
    auto c = Circulator(begin(xs), end(xs));

    EXPECT_EQ(*c, 1.0);
    --c;
    EXPECT_EQ(*c, 3.0);
    --c;
    EXPECT_EQ(*c, 2.0);
    --c;
    EXPECT_EQ(*c, 1.0);
  }

  TEST(Circulator, PostDecrement)
  {
    vector xs = {1.0, 2.0, 3.0};
    auto c = Circulator(begin(xs), end(xs));

    EXPECT_EQ(*c--, 1.0);
    EXPECT_EQ(*c--, 3.0);
    EXPECT_EQ(*c--, 2.0);
    EXPECT_EQ(*c--, 1.0);
  }
} // end of namespace Circular::Testing
