/**
 * @author Markus Bader <markus.bader@mx-robotics.com>
 * @license Simplified BSD License
 */

#ifndef CAR_MOTION_MOTION_H
#define CAR_MOTION_MOTION_H

namespace car
{
    namespace motion
    {
        class MotionVW
        {
            public : 
            class State
            {
            public:
                float x[2]; // v, w
                float y[3]; // power left, power right, angle steering
                float z[2]; // speed left, speed right
            };
            
            public : MotionVW();
            void init_mechanic(float *wheel_distance, float *axis_distance, float *wheel_diameter);
            void init_target(float *v, float *w);
            void init_output(float *motor_power_left, float *motor_power_right, float *steering_angle_front);
            void init_input(float *motor_speed_left, float *motor_speed_right);

        private:
        };

    } // namespace motion
} // namespace car

#endif // CAR_MOTION_MOTION_H