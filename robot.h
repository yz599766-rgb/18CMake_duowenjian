#pragma once //  防止头文件被重复包含（C++工程必备）    保证同一个文件不被复制两次
// 只要是 .h 头文件，第一行永远加上 #pragma once。
// 在需要的 .cpp 文件里，可以放心大胆地写 #include "Robot.h"，想写几次写几次（当然同一个文件里写一次就行了）。写多次，也只读一次

#include <iostream>
#include <vector> 
#include <map>
#include <string>

// 这里顺便引入Eigen，因为咱们是机器人工程
#include <Eigen/Dense> 

class Robot {
public:
    // 成员变量：机器人关节角和配置参数
    std::vector<double> joint_angles;
    std::map<std::string, double> config;
    
    // 声明一个 Eigen 矩阵，用来存基座姿态
    Eigen::Matrix3d base_rotation;

    // 构造函数和析构函数（只声明，不写大括号里的具体内容）
    Robot();
    ~Robot();

    // 声明一个打印信息的函数
    void print_status();
};