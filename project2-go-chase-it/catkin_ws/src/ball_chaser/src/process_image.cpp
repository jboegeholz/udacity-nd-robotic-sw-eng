#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    
    ball_chaser::DriveToTarget service;
    service.request.angular_z = ang_z;
    service.request.linear_x = lin_x;
    client.call(service);

}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    ROS_INFO_STREAM("Received image with encoding: " << img.encoding);
    ROS_INFO_STREAM("Image height: " << img.height);
    ROS_INFO_STREAM("Image width: " << img.width);  
    ROS_INFO_STREAM("Image step: " << img.step);  
    int white_pixel_index = -1;
    // Loop through each pixel in the image and check if one is white
    for (int i = 0; i < img.height * img.step - 2; i+=3) {
        // if found white pixel break loop and determine sector
        uint8_t red = img.data[i];
        uint8_t green = img.data[i + 1];
        uint8_t blue = img.data[i + 2]; 
        if(red == 255 && green == 255 && blue == 255){
            ROS_INFO_STREAM("found white pixel at index:" << i);
            white_pixel_index = i;
            break;
        }
    }
    if(white_pixel_index != -1){
        int white_pixel_x_coordinate = white_pixel_index / 3 % img.width;

        // send drive request reagrding sector
        ROS_INFO_STREAM("found white pixel at x-coordinate:" << white_pixel_x_coordinate);
        if (white_pixel_x_coordinate < img.width / 3){
            ROS_INFO("Found on the left -> drive left");
            drive_robot(0.1,0.1);
        } else if(white_pixel_x_coordinate > img.width / 3 && white_pixel_x_coordinate < 2 * img.width / 3){
            ROS_INFO("Found in the middle -> drive straight ahead!");
            drive_robot(0.1, 0.0);
        } else if(white_pixel_x_coordinate > 2 * img.width / 3){
            ROS_INFO("Found on the right -> drive to the right");
            drive_robot(0.1,-0.1);
        } else {
            ROS_INFO("No white pixel found! -> stop!");
            drive_robot(0.0, 0.0);

        }
    } else {
        drive_robot(0.0, 0.0);
    }

    

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