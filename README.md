# udacity-nd-robotic-sw-eng

## Project 1 - Gazebo World

for a working environment on my Apple Silicon Mac I used brew / mamba / Robostack:

    brew install micromamba
    micromamba create -n ros_env -c conda-forge -c robostack-staging ros-noetic-desktop
    micromamba create -n ros_env -c conda-forge -c robostack-staging ros-noetic-desktop-full
    micromamba activate ros_env`

Now we can start gazebo
with
    
    gazebo

### My first Gazebo World
![my-first-gazebo-world.png](Project1%2Fmy-first-gazebo-world.png)

### Build Plugin

    micromamba activate ros_env
    cd build/
    cmake ../
    make
    
Copy dylib into world dir!