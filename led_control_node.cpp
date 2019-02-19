#include <ros/ros.h>
#include <std_msgs/String.h>
#include "std_msgs/Int32.h"
#include "std_msgs/Bool.h"
	

ros::Publisher pub;

	void keyboardCB(const std_msgs::Int32& msg)
	{
	               
	    ROS_INFO_STREAM(msg.data);
	    // Write code to turn the led on if a '1' is pressed
            //    and turn the led off if a '0' is pressed
	    //    other buttons should be ignored
	    // Use the publisher you created in main
	 std_msgs::Bool led;
            if(msg.data == 49)
		{
                led.data=true;
	        pub.publish(led);
		}
            else if (msg.data == 48)
		{
                led.data=false;

                pub.publish(led);
		}
            /// YOUR CODE HERE ///
	}
	
	int main(int argc, char** argv)
	{
	    ros::init(argc, argv, "led_control_node");
	    ros::NodeHandle nh;
	     
	    ros::Subscriber Sub = nh.subscribe("/keyboard", 10,keyboardCB);
	    //ros::spin();

	    std::string key;
            nh.getParam("abc",key);
            
	
	   // If the param is "red" set pub to advertise on the red led topic
           // If the param is "green" set pub to advertise on the green led topic
           // If you cannot remember the topic names, launch the prizm launch file
           //    and run: rostopic list
           // If you cannot remember the topic type, launch the prizm launch file
           //    and run: rostopic info <topic_name>

	     if (key == "red")
                 pub = nh.advertise<std_msgs::Bool>("/red_led",1000);
             else if (key== "green")
		 pub = nh.advertise<std_msgs::Bool>("/green_led",1000);

	    /// YOUR CODE HERE ///
	
	    // Don't change these lines
	    ROS_INFO_STREAM("led_control_node ready!");
	    ROS_INFO_STREAM("Don't forget to press the green button on the PRIZM!");
	    ros::spin();
	}

