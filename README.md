# udacity-nd-robotic-sw-eng

## Gazebo Project
sudo apt-get update && sudo apt-get upgrade -y 
gazebo

## Create the robot chassis

In the model editor, drop a box anywhere in the scene and double click it to change its position and dimension as follows: 

Position: [X, Y, Z] = [0, 0, 0.2]
Visual and Collision geometry: [X, Y, Z] = [0.3, 1.0, 0.1]


Insert a cylinder inside the scene and then edit its position and orientation:

Z pose = 0.2
Roll = 1.5707 rad
Visual and Collision geometry: [Radius, Length] = [0.2, 0.1]

Link the two objects
Joint axis -> z
Align Links -> xAlign Center

Copy the cylinder