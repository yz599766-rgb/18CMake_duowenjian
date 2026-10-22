#pragma once //  防止头文件被重复包含（C++工程必备）    保证同一个文件不被复制两次
// 只要是 .h 头文件，第一行永远加上 #pragma once。
// 在需要的 .cpp 文件里，可以放心大胆地写 #include "Robot.h"，想写几次写几次（当然同一个文件里写一次就行了）。写多次，也只读一次
//.h文件是菜单   声明我这个类的功能和属性   告诉别人我这个机器人的功能（函数）和属性（变量）
//函数只声明 无具体功能    属性 也只定义变量  数据类型 变量名
#include <iostream>
#include <vector> 
#include <map>
#include <string>

// 这里顺便引入Eigen，因为咱们是机器人工程
#include <Eigen/Dense> 


//写一个robot类的  机器人图纸  图纸里面有机器人的功能 和  我想展示的机器人的相关属性
class Robot {
public:
    // 成员变量：机器人关节角和配置参数  机器人的属性
    std::vector<double> joint_angles;
    std::map<std::string, double> config;
    
    // 声明一个 Eigen 矩阵，用来存基座姿态
    Eigen::Matrix3d base_rotation;

    // 构造函数和析构函数（只声明，不写大括号里的具体内容）
    // 机器人初始化和析构功能
    Robot();
    ~Robot();

    // 声明一个打印信息的函数   我机器人的打印功能
    void print_status();
};