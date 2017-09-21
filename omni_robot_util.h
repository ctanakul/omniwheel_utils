#ifndef OMNI_ROBOT_UTIL_H
#define OMNI_ROBOT_UTIL_H
#include <Eigen/Dense>

namespace BoeingLifter

{
class omniRobotUtil
{
public:
  void add(int a, int b);
  Eigen::Vector4d getAngVelFourWheels(double radius, double length, double width, double Wz, double Vx, double Vy);
  Eigen::Vector3d getTwistFourWheels(double radius, double length, double width, double u1, double u2, double u3, double u4);
};

}

int main(void);

#endif