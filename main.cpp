// 新建 main.cpp。(顾客看菜单)在这里，你只需要引入菜单（Robot.h），然后直接用。你不需要在这里写 #include <Eigen/Dense>，因为头文件里已经帮你包含了。
//main.cpp顾客     通过->点.h里面的功能和属性  并对属性赋值   就像点面条 你要加个一两  二两 一个道理


#include <iostream>
#include <memory>
#include "robot.h" // 引入我们自己的菜单

int main() 
{
    std::cout << "--- 程序开始 ---\n";

    // 造机器人
    std::unique_ptr<Robot> my_robot = std::make_unique<Robot>();

    // 添加数据
    my_robot->joint_angles.push_back(0.5);
    my_robot->joint_angles.push_back(1.2);
    my_robot->config["Kp"] = 50.0;
    my_robot->config["Kd"] = 1.0;

    // 调用类里的打印函数
    my_robot->print_status();

    std::cout << "--- 程序结束 ---\n";
    return 0;
}