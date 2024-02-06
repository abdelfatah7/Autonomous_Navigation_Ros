#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //first goal
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = -6.45;
  goal.target_pose.pose.position.y = -4.57;
  goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending goal 1");
  ac.sendGoal(goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Reached first goal");
  else
    ROS_INFO("Failed to reach first goal for some reason");

  //wait for 3 seconds
  ros::Duration(0.5).sleep();

  //second goal
  goal.target_pose.pose.position.x = 7.42;
  goal.target_pose.pose.position.y = -9.79;

  ROS_INFO("Sending goal 2");
  ac.sendGoal(goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Reached second goal");
  else
    ROS_INFO("Failed to reach second goal for some reason");


  //wait for 3 seconds


  //third goal
  goal.target_pose.pose.position.x = 10.7;
  goal.target_pose.pose.position.y = 3.85;

  ROS_INFO("Sending goal 3");
  ac.sendGoal(goal);

  ac.waitForResult();


  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Reached third goal");
  else
    ROS_INFO("Failed to reach third goal for some reason");

    ros::Duration(1).sleep();

    //fourth goal
  goal.target_pose.pose.position.x = 4.41;
  goal.target_pose.pose.position.y = 0.506;

  ROS_INFO("Sending goal 4");
  ac.sendGoal(goal);

  ac.waitForResult();


  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Reached fourth goal");
  else
    ROS_INFO("Failed to reach fourth goal for some reason");




//fifth goal
  goal.target_pose.pose.position.x = 0.981;
  goal.target_pose.pose.position.y = -9.52;

  ROS_INFO("Sending goal 5");
  ac.sendGoal(goal);

  ac.waitForResult();


  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Reached fifth goal");
  else
    ROS_INFO("Failed to reach fifth goal for some reason");




//six goal
  goal.target_pose.pose.position.x = -3.2;
  goal.target_pose.pose.position.y = -0.487;

  ROS_INFO("Sending goal 6");
  ac.sendGoal(goal);

  ac.waitForResult();


  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Reached six goal");
  else
    ROS_INFO("Failed to reach six goal for some reason");




  return 0;
}