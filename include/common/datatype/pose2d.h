#pragma once

#include <iomanip>
#include <iostream>

namespace datatype {
struct Pose2D {
  double x;
  double y;
  double theta;
};
}  // namespace datatype

inline std::ostream& operator<<(std::ostream& os, const datatype::Pose2D& data) {
  os << std::setprecision(std::numeric_limits<double>::max_digits10) << std::fixed;
  os << data.x << " " << data.y << " " << data.theta;
  return os;
}

inline std::istream& operator>>(std::istream& is, datatype::Pose2D& data) {
  is >> data.x >> data.y >> data.theta;
  return is;
}
