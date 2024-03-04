# Catkin Workspace

    cd catkin_ws
    catkin_make
    source devel/setup.bash
    roslaunch my_robot world.launch

## C++17

    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

## URDF checken

    sudo apt install liburdfdom-tools
    check_urdf my_robot.xacro

## Fehler "SpawnModel: Failure - model name my_robot already exist."

    rosservice call /gazebo/delete_model "{model_name: 'my_robot'}"