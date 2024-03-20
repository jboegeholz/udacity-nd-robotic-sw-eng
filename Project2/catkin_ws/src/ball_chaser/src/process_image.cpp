#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    //ROS_INFO("Received image with encoding: ");
    //ROS_INFO_STREAM(img.encoding);
    int white_pixel = 255;
    // Loop through each pixel in the image and check if one is white
    for (int i = 0; i < img.height * img.step - 2; i++) {
        // if found white pixel break loop and determine sector
        uint8_t red = img.data[i];
        uint8_t green = img.data[i + 1];
        uint8_t blue = img.data[i + 2]; 
        if(red == 255 && green == 255 && blue == 255){
            ROS_INFO("Found white pixel!");
        }
    }
    // send drive request reagrding sector

}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}