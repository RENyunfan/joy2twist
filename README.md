# joy2twist

> Yunfan REN
>
> renyunfan@outlook.com

# How to install

### 0 install joy

```bash
sudo apt-get install ros-melodic-joy
```

### 1 Creat a work space

```bash
mkdir -p catkin_ws/src
cd catkin_ws/src
```

### 2 Download the package

```bash
git clone https://gitee.com/RENyunfan/joy2twist.git
# or
git clone https://github.com/RENyunfan/joy2twist.git
```

### 3 Build

```bash
cd catkin_ws
catkin_make
source devel/setup.bash
```

### 4 Usage

First edit the launch file to set the remap to the topic you want to publish.(Default topic:`/mavros/setpoint_velocity/cmd_vel`).

If you want to publish as `TwistStamped`, just set the param to true.

```XML
<launch>
<!--	if you want to use mavros for UAV simulation, you need to publish TwistStamped, remember to-->
<!--	set the param to TRUE-->

	<arg name="use_stamped" value="true"> </arg>
	<node pkg="joy" name="joy_node" type="joy_node" output="screen" />


	<node pkg="joy2twist" name="xbox" type="xbox" output="screen" >
	    <param name="/use_stamped"   value="$(arg use_stamped)"/>
		<remap from="cmd_vel" to="/mavros/setpoint_velocity/cmd_vel" />
	</node>

</launch>
```

Then go to the root of the workspace

```bash
cd catkin_ws
source devel/setup.bash
roslaunch joy2twist xbox
```

