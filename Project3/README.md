# Where am I?

## Prerequisites

    sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list'
    wget http://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -

    sudo apt-get update
    sudo apt-get install libignition-math2-dev protobuf-compiler


## Install pgm_map_creator

    cd /home/workspace/catkin_ws/src/
    git clone https://github.com/ismailkoch492/pgm_map_creator.git

    cd ..
    catkin build

## Setup

cp <YOUR GAZEBO WORLD FILE> src/pgm_map_creator/world/<YOUR GAZEBO WORLD FILE>

add <plugin filename="libcollision_map_creator.so" name="collision_map_creator"/> before </world>

1. Terminal
gzserver src/pgm_map_creator/world/my_house.world 

2. Terminal
roslaunch pgm_map_creator request_publisher.launch

