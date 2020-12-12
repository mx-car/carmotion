/**
 * @author Markus Bader <markus.bader@mx-robotics.com>
 * @license Simplified BSD License
 */

#include "car/motion/odometry.h"
#include <Arduino.h>

using namespace car::motion;

OdomAckermann::OdomAckermann()
: tstamp_last_update(0) 
{
}

void OdomAckermann::update(float motor_speed_left, float motor_speed_right, float streering_angle){
    uint32_t now = micros();
    if(tstamp_last_update == 0) {
        pose_ = car::com::objects::Pose(0,0,0);
    } else {
        double dt = (now - tstamp_last_update) / 1000000.;
        double w = (motor_speed_left + motor_speed_right) / 2.;
        double v = w * M_PI * wheel_diameter_;
        double dx = v*dt;
        pose_.x += dx;
    }
    tstamp_last_update = now;
}

void OdomAckermann::init(float wheel_diameter, float wheel_displacement, float axis_displacement){
    wheel_diameter_ = wheel_diameter;
    wheel_displacement_ = wheel_displacement;
    axis_displacement_ = axis_displacement;
}

void OdomAckermann::getPose(car::com::objects::Pose &pose) const{
    pose = pose_;
}