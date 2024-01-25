#pragma once

#include "pose2d.h"

#include <iomanip>
#include <iostream>

namespace datatype {

struct Pose2DStamped : Pose2D {
  double time = 0.0;
};

}  // namespace datatype

inline std::ostream& operator<<(std::ostream& os, const datatype::Pose2DStamped& data) {
  os << std::setprecision(std::numeric_limits<double>::max_digits10) << std::fixed;
  os << data.time << " ";
  os << static_cast<const datatype::Pose2D&>(data);
  return os;
}

inline std::istream& operator>>(std::istream& is, datatype::Pose2DStamped& data) {
  is >> data.time;
  is >> static_cast<datatype::Pose2D&>(data);
  return is;
}