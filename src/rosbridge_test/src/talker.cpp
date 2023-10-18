#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/Float64.h"
#include <sstream>

std_msgs::Float64 msgAbsoluteForce;

void forceTorqueSensorCallback(const geometry_msgs::Pose::ConstPtr& forceTorque)
{
    msgAbsoluteForce.data = sqrt( pow(forceTorque->position.x , 2) + pow(forceTorque->position.y , 2) + pow(forceTorque->position.z , 2));
    std::cout<<"absoluteForce: "<<msgAbsoluteForce.data<<std::endl;

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher forceTorqueSensor = n.advertise<geometry_msgs::Pose>("force_torque_sensor", 1000);
    ros::Publisher absoluteForce = n.advertise<std_msgs::Float64>("absolute_force", 1000);
    ros::Publisher airskinInterrupt = n.advertise<std_msgs::String>("AIRSKIN_Interrupt", 1000);
    ros::Subscriber forceTorqueSensorSub = n.subscribe("force_torque_sensor", 1000, forceTorqueSensorCallback);
    ros::Rate loop_rate(10);
 

    ros::spin();
    
    return 0;
}