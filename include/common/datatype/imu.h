#pragma once

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <iomanip>
#include <iostream>

namespace datatype {

struct IMU {
  double             time;
  Eigen::Vector3d    acc;
  Eigen::Vector3d    gyr;
  Eigen::Quaterniond rot;
};

}  // namespace datatype

inline std::ostream& operator<<(std::ostream& os, const datatype::IMU& data) {
  os << std::setprecision(std::numeric_limits<double>::max_digits10) << std::fixed;
  os << data.time << " " << data.acc.x() << " " << data.acc.y() << " " << data.acc.z() << " ";
  os << data.gyr.x() << " " << data.gyr.y() << " " << data.gyr.z() << " ";
  os << data.rot.x() << " " << data.rot.y() << " " << data.rot.z() << " " << data.rot.w();
  return os;
}

inline std::istream& operator>>(std::istream& is, datatype::IMU& data) {
  is >> data.time >> data.acc.x() >> data.acc.y() >> data.acc.z();
  is >> data.gyr.x() >> data.gyr.y() >> data.gyr.z();
  is >> data.rot.x() >> data.rot.y() >> data.rot.z() >> data.rot.w();
  return is;
}