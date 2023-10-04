// datatype
#include "common/datatype/io.h"
#include "common/datatype/reflector.h"
// gtest
#include <gtest/gtest.h>
// standard
#include <cstdio>
#include <random>

// param
constexpr int NUM  = 1000;
constexpr int SEED = 0;

// namespace
using namespace datatype;

// tests
TEST(datatype, ReflectorFrame) {
  std::vector<ReflectorFrame>        data_save(NUM);
  std::vector<ReflectorFrame>        data_load;
  std::string                        filename = "reflector_test.txt";
  SensorIO<ReflectorFrame>           io;
  std::default_random_engine         rng(SEED);
  std::normal_distribution<double>   norm;
  std::uniform_int_distribution<int> uniform_num(1, 5);
  // generate random data
  for (int i = 0; i < NUM; i++) {
    data_save[i].time = i;
    data_save[i].num  = uniform_num(rng);
    for (int j = 0; j < data_save[i].num; j++) {

      datatype::Reflector this_reflector{};
      this_reflector.index = j;
      this_reflector.x     = norm(rng);
      this_reflector.y     = norm(rng);

      data_save[i].reflector.push_back(this_reflector);
    }
  }
  // save all
  ASSERT_TRUE(io.open(filename, std::ios_base::out));
  ASSERT_TRUE(io.saveAll(data_save.begin(), data_save.end()));
  io.close();
  // load all
  ASSERT_TRUE(io.open(filename, std::ios_base::in));
  ASSERT_TRUE(io.loadAll(std::back_inserter(data_load)));
  io.close();
  // check all
  ASSERT_EQ(data_save.size(), data_load.size());
  for (int i = 0; i < NUM; i++) {
    ASSERT_NEAR(data_save[i].time, data_load[i].time, 1e-7);
    ASSERT_EQ(data_save[i].num, data_load[i].num);
    for (int j = 0; j < data_load[i].num; j++) {
      ASSERT_EQ(data_save[i].reflector[j].index, data_load[i].reflector[j].index);
      ASSERT_NEAR(data_save[i].reflector[j].x, data_load[i].reflector[j].x, 1e-7);
      ASSERT_NEAR(data_save[i].reflector[j].y, data_load[i].reflector[j].y, 1e-7);
    }
  }
  // save once
  ASSERT_TRUE(io.open(filename, std::ios_base::out));
  ASSERT_TRUE(io.saveOnce(data_save[0]));
  io.close();
  // load once
  ASSERT_TRUE(io.open(filename, std::ios_base::in));
  ASSERT_TRUE(io.loadOnce(data_load[0]));
  io.close();
  // check once
  ASSERT_EQ(data_save.size(), data_load.size());
  ASSERT_NEAR(data_save[0].time, data_load[0].time, 1e-7);
  ASSERT_EQ(data_save[0].num, data_load[0].num);
  for (int j = 0; j < data_load[0].num; j++) {
    ASSERT_EQ(data_save[0].reflector[j].index, data_load[0].reflector[j].index);
    ASSERT_NEAR(data_save[0].reflector[j].x, data_load[0].reflector[j].x, 1e-7);
    ASSERT_NEAR(data_save[0].reflector[j].y, data_load[0].reflector[j].y, 1e-7);
  }
}
