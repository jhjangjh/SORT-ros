#ifndef SORT_ROS_H
#define SORT_ROS_H

#include "ros/ros.h"
#include "visualization_msgs/MarkerArray.h"

#include "Sort.h"


class SortRos {

private:

    static SortRos* instance;

    SortRos(void) {
        std::cout << "생성자 호출" << std::endl;
    };
    SortRos(const SortRos& other);
    ~SortRos() {};

public:

    static SortRos* GetInstance() {
        std::cout << "GetInstance 호출" << std::endl;
        if(instance == NULL) instance = new SortRos();
        return instance;
    }



private:

    ros::NodeHandle nh;
    static ros::Publisher pub;
    static ros::Subscriber sub;

    static void rectArrayCallback(const visualization_msgs::MarkerArray::ConstPtr& markerArray);



private:

    static Sort *s;

public:

    void setup(void);

};


#endif