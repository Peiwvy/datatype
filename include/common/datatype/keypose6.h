// 用于 timestamp x y z rx ry rz
#pragma once

#include <iomanip>
#include <iostream>

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace datatype {

struct KeyPose6 {
  double          time = 0.0;
  Eigen::Vector3d trans;
  Eigen::Vector3d rot;

  KeyPose6(double t, double tx, double ty, double tz, double rx, double ry, double rz) : time(t), trans(tx, ty, tz), rot(rx, ry, rz) {}

  KeyPose6() : time(0.0), trans(0, 0, 0), rot(0, 0, 0) {}  // 默认构造函数
};

}  // namespace datatype

inline std::ostream& operator<<(std::ostream& os, const datatype::KeyPose6& data) {
  os << std::setprecision(4) << std::fixed;
  os << data.time << " " << data.trans.x() << " " << data.trans.y() << " " << data.trans.z() << " ";
  os << data.rot.x() << " " << data.rot.y() << " " << data.rot.z() << " ";
  return os;
}

inline std::istream& operator>>(std::istream& is, datatype::KeyPose6& data) {
  is >> data.time >> data.trans.x() >> data.trans.y() >> data.trans.z();
  is >> data.rot.x() >> data.rot.y() >> data.rot.z();
  return is;
}
