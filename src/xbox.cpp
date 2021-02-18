#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>

class Xbox
{
public:
	Xbox();
private:
	void JoyCallback(const sensor_msgs::Joy::ConstPtr& msg);
	ros::NodeHandle nh;

	float axesL1,axesL2,axesR1,axesR2;
	ros::Publisher pub;
	ros::Subscriber sub;
};

void Xbox::JoyCallback(const sensor_msgs::Joy::ConstPtr& msg)
{
	geometry_msgs::Twist twist;
	
	twist.angular.x=0;
	twist.angular.y=0;
	twist.angular.z=msg->axes[0];
	twist.linear.x=msg->axes[4];
	twist.linear.y=msg->axes[3];
	twist.linear.z=0;
	
	pub.publish(twist);
}

Xbox::Xbox()
{
	pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
	sub = nh.subscribe<sensor_msgs::Joy>("joy",10,&Xbox::JoyCallback,this);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "xbox");
	Xbox xbox;

	ros::spin();
	
	
}
