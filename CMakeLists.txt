# 1. 规定最低的CMake版本
cmake_minimum_required(VERSION 3.10)

# 2. 给工程起个名字
project(RobotProject)

# 3. 设定C++版本（我们用了智能指针，必须14以上）
set(CMAKE_CXX_STANDARD 14)

# 4. 寻找 Eigen3 库
find_package(Eigen3 REQUIRED)

# 5. 生成可执行文件（名字叫 robot_app，由 main.cpp 和 Robot.cpp 共同编译而成）
add_executable(robot_app main.cpp robot.cpp)

# 6. 把 Eigen 库链接到我们的 robot_app 上
target_link_libraries(robot_app Eigen3::Eigen)
