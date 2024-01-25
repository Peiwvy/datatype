# 说明

机器人数据序列化工具库，请参考示例程序查看如何使用

## 依赖

- Eigen3

## 类型说明

- pose: trans(Eigen::Vector3d) + rot(Eigen::Quaterniond)
- poseStamped: time(double) + pose
- keypose: time(double) + index(unsigned int) + pose
- keypose6: time(double) + trans(Eigen::Vector3d) + rot(Eigen::Vector3d)

## ChangeLog

- ver: 1.3.0 移除序列化数据末端空格
- ver: 1.2.4 增加 Reflector 序列化
- ver: 1.2.3 移除reflector_body，增加reflector 修改为 time num [index x y]
- ver: 1.2.2 增加reflector_body
- ver: 1.2.1 增加reflector pose & 修复vector类型保存异常bug
- ver: 1.1.0 完善
