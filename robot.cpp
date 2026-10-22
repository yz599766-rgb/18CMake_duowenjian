// 写源文件 Robot.cpp（后厨）       具体实现怎么干
// 这里必须写 Robot::，意思是“我要实现的是 Robot 这个类里的方法”。
//对.h文件的函数进行完善   完成具体的函数功能
#include "robot.h" // 必须包含对应的头文件

// 实现构造函数
Robot::Robot() {
    std::cout << "[系统] 机器人初始化完成\n";
    // 随便给基座旋转矩阵赋个初值（单位阵）
    base_rotation = Eigen::Matrix3d::Identity();//“把机器人的基座旋转矩阵，重置为毫无旋转的初始正立状态。”
                                        //Identity表示单位矩阵       三维的单位矩阵 表示这个基座状态毫无变化 站立不动
}

// 实现析构函数
Robot::~Robot() {
    std::cout << "[系统] 机器人断电，内存清理完毕。\n";
}

// 实现打印信息的函数
void Robot::print_status() {
    std::cout << "\n--- 当前机器人状态 ---\n";
    
    // 打印关节角
    std::cout << "关节数量: " << joint_angles.size() << "\n";
    for (const auto& angle : joint_angles) {
        std::cout << "  - 角度: " << angle << "\n";
    }

    // 打印配置参数
    std::cout << "配置参数:\n";
    for (const auto& pair : config) {
        std::cout << "  - " << pair.first << " = " << pair.second << "\n";
    }
    
    // 打印基座矩阵
    std::cout << "基座旋转矩阵:\n" << base_rotation << "\n";
}