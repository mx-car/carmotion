/**
 * @author Markus Bader <markus.bader@mx-robotics.com>
 * @license Simplified BSD License
 */

#ifndef CAR_MOTION_ODOMETRY_H
#define CAR_MOTION_ODOMETRY_H

#include <car/com/objects/pose.h>

namespace car
{
    namespace motion
    {
        class OdomAckermann
        {
                  
            public : 
            OdomAckermann();
            void init(float wheel_diameter, float wheel_displacement, float axis_displacement);
            void update(float motor_speed_left, float motor_speed_right, float streering_angle);
            void getPose(car::com::objects::Pose &pose) const;

        private:
            float wheel_diameter_;
            float wheel_displacement_;
            float axis_displacement_;
            uint32_t tstamp_last_update;
             
            car::com::objects::Pose pose_;
        };

    } // namespace motion
} // namespace car

#endif // CAR_MOTION_ODOMETRY_H