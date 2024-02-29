# Catkin Workspace
cd catkin_ws/src
catkin_init_workspace

git clone https://github.com/udacity/RoboND-simple_arm.git simple_arm
rosdep install -i simple_arm

cd catkin_ws
catkin_make
source devel/setup.bash

roslaunch simple_arm robot_spawn.launch

## C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)