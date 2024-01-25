#pragma once

#include "pose.h"

#include <iomanip>
#include <iostream>

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace datatype {

struct PoseStamped : Pose {
  double time = 0.0;
};

}  // namespace datatype

inline std::ostream& operator<<(std::ostream& os, const datatype::PoseStamped& data) {
  os << std::setprecision(std::numeric_limits<double>::max_digits10) << std::fixed;
  os << data.time << " ";
  os << static_cast<const datatype::Pose&>(data);

  return os;
}

inline std::istream& operator>>(std::istream& is, datatype::PoseStamped& data) {
  is >> data.time;
  is >> static_cast<datatype::Pose&>(data);
  return is;
}