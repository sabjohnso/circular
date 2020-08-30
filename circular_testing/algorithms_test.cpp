//
// ... Standard header files
//
#include <vector>
#include <iterator>

//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... Circular header files
//
#include <circular/Circulant.hpp>
#include <circular/FixedCirculant.hpp>
#include <circular/algorithms.hpp>

using std::vector;

namespace Circular::Testing
{
  TEST(Algorithms, ForEach)
  {
    Circulant<double> xs = {1.0, 2.0, 3.0, 4.0, 5.0};
    int count = 0;
    forEach(begin(xs), [&](auto){ ++count; });
    EXPECT_EQ(count, xs.size());
  }

  TEST(Algorithms, Map)
  {
    Circulant<double> xs = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> ys{};
    map(begin(xs), back_inserter(ys), [](auto xi){ return xi[0] - xi[-1]; });
    EXPECT_EQ(ys.size(), xs.size());
    EXPECT_EQ(ys[0], -4.0);
    EXPECT_EQ(ys[1],  1.0);
    EXPECT_EQ(ys[2],  1.0);
    EXPECT_EQ(ys[3],  1.0);
    EXPECT_EQ(ys[4],  1.0);
  }

  TEST(Algorithms, Map2)
  {
    Circulant xs = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector <double> zs;
    map2(begin(xs), next(begin(xs)), back_inserter(zs),
         [](auto xi, auto yi)
         {
           return xi[1]-yi[0];
         });

    EXPECT_EQ(zs.size(), xs.size());
    EXPECT_EQ(zs[0], 0.0);
    EXPECT_EQ(zs[1], 0.0);
    EXPECT_EQ(zs[2], 0.0);
    EXPECT_EQ(zs[3], 0.0);
    EXPECT_EQ(zs[4], 0.0);
  }

  TEST(Algorithms, Map3)
  {
    Circulant xs = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector <double> as;
    map3(begin(xs), begin(xs)+1, begin(xs)+2, back_inserter(as),
         [](auto xi, auto yi, auto zi)
         {
           return 2*xi[1] - yi[0] -zi[-1];
         });

    EXPECT_EQ(as.size(), xs.size());
    EXPECT_EQ(as[0], 0.0);
    EXPECT_EQ(as[1], 0.0);
    EXPECT_EQ(as[2], 0.0);
    EXPECT_EQ(as[3], 0.0);
    EXPECT_EQ(as[4], 0.0);
  }

  TEST(Algorithms, AllOfPass)
  {
    Circulant xs = {true, true, true};
    EXPECT_TRUE(allOf(begin(xs), [](auto xi){return xi[0] && xi[1];}));
  }

  TEST(Algorithms, AllOfFail)
  {
    Circulant xs = {true, false, true};
    EXPECT_FALSE(allOf(begin(xs), [](auto xi){return xi[0] && xi[1];}));
  }

  TEST(Algorithms, AnyOfPass)
  {
    Circulant xs = {true, false, true};
    EXPECT_TRUE(anyOf(begin(xs), [](auto xi){return xi[0] && xi[1];}));
  }

  TEST(Algorithms, AnyOfFail)
  {
    Circulant xs = {true, false, true, false};
    EXPECT_FALSE(anyOf(begin(xs), [](auto xi){return xi[0] && xi[1];}));
  }

  TEST(Algorithms, NoneOfPass)
  {
    Circulant xs = {true, false, true, false};
    EXPECT_TRUE(noneOf(begin(xs), [](auto xi){return xi[0] && xi[1];}));
  }

  TEST(Algorithms, NoneOfFail)
  {
    Circulant xs = {true, false, true};
    EXPECT_FALSE(noneOf(begin(xs), [](auto xi){return xi[0] && xi[1];}));
  }

  TEST(Algorithms, CountIf)
  {
    Circulant xs = {1.0, 2.0, 3.0, 4.0};
    EXPECT_EQ(countIf(begin(xs), [](auto xi){ return xi[0] < xi[1]; }), 3);
  }

  TEST(Algorithms, CountEach)
  {
    Circulant xs = {1.0, 2.0, 3.0, 4.0};
    EXPECT_EQ(countEach(begin(xs), 3.0), 1);
  }

} // end of namespace Circular::Testing
