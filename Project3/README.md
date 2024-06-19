# Where am I?

## Prerequisites

    sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list'
    wget http://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -

    sudo apt-get update
    sudo apt-get install libignition-math2-dev protobuf-compiler


## Install pgm_map_creator

    cd /home/workspace/catkin_ws/src/
    git clone https://github.com/ismailkoch492/pgm_map_creator.git