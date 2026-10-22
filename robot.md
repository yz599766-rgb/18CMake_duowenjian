在真正的机器人公司里，代码绝对不能全塞在 main.cpp 里。一个控制工程通常有几十个 .cpp 文件。为什么？因为你要把代码分块：

    Robot.h：相当于菜单，告诉别人这个机器人能干什么（只写声明）。

    Robot.cpp：相当于后厨，具体实现怎么干（写具体代码）。

    main.cpp：相当于顾客，只管看菜单点菜（点功能），不看后厨怎么炒(顾客负责添加数据，交给后厨执行)

    所以最后打印到终端的可执行文件  虽然结合了 main.cpp  和  robot.cpp  ,实际输出的是后厨robot.cpp的命令

    注意在main.cpp 和 robot.cpp中都要出现声明robot.h (菜单)





问题一：
    robot.h文件
    #pragma once //  防止头文件被重复包含（C++工程必备）

同一个.cpp中：    
#include "A.h"
#include "B.h"

int main() { return 0; }
而 A.h 和 B.h 里面，都包含了 Robot.h：

灾难现场直播：

    编译器开始处理 main.cpp。

    看到 #include "A.h"，把 A.h 复制过来。一看里面有 #include "Robot.h"，于是把 Robot.h 的代码复制进来。

    接着往下看 main.cpp，看到了 #include "B.h"，把 B.h 复制过来。一看里面又有 #include "Robot.h"，于是又把 Robot.h 的代码复制了一遍！

结果，在 main.cpp 这一个文件里，class Robot { ... }; 这个图纸，出现了两次。

C++ 编译器（在处理 main.cpp 时）看到两个一模一样名字的 class Robot，直接报错：“你丫怎么在同一个文件里给我定义了两次 Robot？内存放不下！”



三、加上 #pragma once 后，奇迹发生了

当你在 Robot.h 的第一行加了 #pragma once：

    编译器在处理 main.cpp 时，第一次遇到 Robot.h，把它读进去，并记在脑海里：“Robot.h 我读过了。”

    往下走，遇到 B.h 里的 Robot.h，编译器一看：“等等，这个 Robot.h 我刚才在这个 main.cpp 里读过了，直接跳过，不准再复制了！”

所以，#pragma once 保护的是“同一个.cpp中，同一个文件不被无脑复制两次”，而不是防止全项目的其他 .cpp 文件去引用它。






问题二：
.cpp里面
  base_rotation = Eigen::Matrix3d::Identity();
在机器人学里，一个 3x3 的旋转矩阵如果是单位矩阵，代表没有任何旋转（X轴、Y轴、Z轴都没有转动）。

如果不写这一句，C++ 会在内存里给 base_rotation 分配一块地盘，但里面装的全是未知的乱码（垃圾值）。如果带着乱码去算机器人的姿态，机器人一开机就会瞬间计算出错误的倾角，直接原地抽搐甚至炸机。

等你的机器人开始动起来，这个矩阵就会疯狂变化了
// 1. 开机时：单位矩阵（无旋转）
base_rotation = Eigen::Matrix3d::Identity();

// 2. 机器人走了一步，IMU（陀螺仪）传来了新的旋转数据
Eigen::Matrix3d delta_R = ...; // 这一步的旋转量

// 3. 把新的旋转叠加到原来的姿态上（矩阵相乘）
base_rotation = base_rotation * delta_R; 
base_rotation 就不再是单位矩阵了，里面装的就是机器人在空间里歪了多少度、转了多少度的真实数据。

步骤
第一步：建一个新的工程文件夹

不要在原来的单文件目录里搞，我们开个新的。
在终端里输入：mkdir ~/robot_project
cd ~/robot_project
code .

第二步：写头文件 Robot.h（菜单
第三步：写源文件 Robot.cpp（后厨）

在 VS Code 里新建文件 Robot.cpp，敲入下面的代码。
注意：这里必须写 Robot::，意思是“我要实现的是 Robot 这个类里的方法”

第四步：写主函数 main.cpp（顾客）

新建 main.cpp。在这里，你只需要引入菜单（Robot.h），然后直接用。你不需要在这里写 #include <Eigen/Dense>，因为头文件里已经帮你包含了。
你的目录里应该有三个文件：Robot.h、Robot.cpp、main.cpp。

第五步：重头戏 —— 编写 CMakeLists.txt

新建 CMakeLists.txt（注意大小写必须完全一致）。
这就是告诉 CMake：“去把哪几个文件抓过来，一起编译”



注意：
CMakeLists.txt  这个文件必须建在 robot_project 这个项目根目录下。 而且它必须和你的 main.cpp、Robot.cpp、Robot.h 放在同一个层级。

robot_project/           <-- 你的项目根目录
├── CMakeLists.txt       <-- 必须在这里（指挥中心）
├── Robot.h              <-- 头文件（菜单）
├── Robot.cpp            <-- 源文件（后厨）
└── main.cpp             <-- 主程序（顾客）



第六步：cmake make 编译  建立build文件   注意这个build文件也要建立在与CMakeLists.txt main.cpp 相同目录下















