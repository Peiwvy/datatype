#pragma once

#include <iomanip>
#include <iostream>

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace datatype {

struct Pose {
  Eigen::Vector3d    trans;
  Eigen::Quaterniond rot;
};

}  // namespace datatype

inline std::ostream& operator<<(std::ostream& os, const datatype::Pose& data) {
  os << std::setprecision(std::numeric_limits<double>::max_digits10) << std::fixed;
  os << data.trans.x() << " " << data.trans.y() << " " << data.trans.z() << " ";
  os << data.rot.x() << " " << data.rot.y() << " " << data.rot.z() << " " << data.rot.w();
  return os;
}

inline std::istream& operator>>(std::istream& is, datatype::Pose& data) {
  is >> data.trans.x() >> data.trans.y() >> data.trans.z();
  is >> data.rot.x() >> data.rot.y() >> data.rot.z() >> data.rot.w();
  return is;
}