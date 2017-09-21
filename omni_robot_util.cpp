#include <iostream>
#include "omni_robot_util.h"
#include <Eigen/Dense>

namespace BoeingLifter
{
void omniRobotUtil::add(int a, int b)
{
    std::cout << a + b << std::endl;
}
Eigen::Vector4d omniRobotUtil::getAngVelFourWheels(double radius, double length, double width, double Wz, double Vx, double Vy)
{
    Eigen::MatrixXd H(4, 3);
    H << (-length - width), 1, -1, (length + width), 1, 1, (length + width), 1, -1, (-length - width), 1, 1;
    Eigen::Vector3d twist(Wz, Vx, Vy);
    return 1 / radius * (H * twist);
}

Eigen::Vector3d omniRobotUtil::getTwistFourWheels(double radius, double length, double width, double u1, double u2, double u3, double u4)
{
    double Vx = (u1 + u2) * radius / 2;
    double Vy = radius / 2 * (u2 + u4 - 2 * (Vx / radius));
    double Wz = (u1 - (Vx / radius) + (Vy / radius)) * radius / (-length - width);
    Eigen::Vector3d twist(Wz, Vx, Vy);
    return twist;
}
}

// int main()
// {
//     BoeingLifter::omniRobotUtil obj;
//     obj.add(2, 3);
//     Eigen::Vector4d x = obj.getAngVelFourWheels(0.25, 1.3, 1.27, 1, 1.267, -1.24);
//     Eigen::Vector3d y = obj.getTwistFourWheels(0.25, 1.3, 1.27, x(0), x(1), x(2), x(3));
//     std::cout << y << std::endl;
//     return 0;
// }
