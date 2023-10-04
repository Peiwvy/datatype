#pragma once

#include <vector>

namespace datatype {

struct Point {
  double x;
  double y;
  double z;
};

struct Quaternion {
  double x;
  double y;
  double z;
  double w;
};

struct Pose {
  Point      position;
  Quaternion orientation;
};

struct MapMetaData {
  double       map_load_time = 0.0;
  float        resolution    = 0.0;
  unsigned int width         = 0;
  unsigned int height        = 0;
  Pose         origin;
};

struct OccupancyGrid {
  MapMetaData      info;
  std::vector<int> data;
};
}  // namespace datatype
