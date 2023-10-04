// format: timestamp num index range degree ...
#pragma once

#include <iomanip>
#include <iostream>
#include <vector>

namespace datatype {

struct Reflector {
  int   index;
  float x;
  float y;
};

struct ReflectorFrame {  // 用于存储关键帧检测的反光板信息
  double                 time = 0.0;
  int                    num  = 0;
  std::vector<Reflector> reflector;
};

}  // namespace datatype

inline std::ostream& operator<<(std::ostream& os, const datatype::ReflectorFrame& data) {
  os << std::setprecision(std::numeric_limits<double>::max_digits10) << std::fixed;
  os << data.time << " " << data.reflector.size() << " ";
  for (const auto& this_reflector : data.reflector) {
    os << this_reflector.index << " " << this_reflector.x << " " << this_reflector.y << " ";
  }
  return os;
}

inline std::istream& operator>>(std::istream& is, datatype::ReflectorFrame& data) {
  is >> data.time >> data.num;
  for (int i = 0; i < data.num; ++i) {
    datatype::Reflector this_reflector{};
    is >> this_reflector.index >> this_reflector.x >> this_reflector.y;
    data.reflector.push_back(this_reflector);
  }

  return is;
}

inline std::ostream& operator<<(std::ostream& os, const datatype::Reflector& data) {
  os << data.index << " " << data.x << " " << data.y << " ";
  return os;
}

inline std::istream& operator>>(std::istream& is, datatype::Reflector& data) {
  is >> data.index >> data.x >> data.y;

  return is;
}