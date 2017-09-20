#include "omni_robot_util.h"
#include <iostream>

void omniRobotUtil::add(int a, int b)
{
    std::cout << a + b << std::endl;
}

int main()
{
    omniRobotUtil obj;
    obj.add(2, 3);
    return 0;
}