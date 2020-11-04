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
                  
            public : MotionVW();
            static const int V = 0;
            static const int W = 1;
            static const int LEFT = 0;
            static const int RIGHT = 1;
            static const int STEERING = 2;

            void init_mechanic(float *wheel_distance, float *axis_distance, float *wheel_diameter);
            void init_target(float *v, float *w);
            void init_controls(float *motor_power_left, float *motor_power_right, float *steering_angle_front);
            void init_mesaurments(float *motor_speed_left, float *motor_speed_right);

            void update(){
                
            }

        private:
            float x[2]; // state v, w
            float y[3]; // power left, power right, angle steering
            float z[2]; // speed left, speed right
        };

    } // namespace motion
} // namespace car

#endif // CAR_MOTION_MOTION_H