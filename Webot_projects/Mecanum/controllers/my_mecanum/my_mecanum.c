/*
 * File:          my_mecanum.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
#include <webots/robot.h>
#include <webots/motor.h>


/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char *argv[]) {
  /* necessary to initialize webots stuff */
  wb_robot_init();

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
  WbDeviceTag motors[4];
  
  char motors_name[4][10] = {"LF_Motor","RF_Motor","LB_Motor","RB_Motor"};

  for(int i = 0;i < 4;i++)
  {
    motors[i] = wb_robot_get_device(motors_name[i]);
    wb_motor_set_position(motors[i],INFINITY);
    //速度控制电机,位置控制电机前进路程?(视频中说的是汽车的油)
    wb_motor_set_velocity(motors[i],0);//速度初始化为0
  }
  //初始化结束

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
    // double LS = 3.0;
    // double RS = 3.0;
    
    // wb_motor_set_velocity(motors[0],LS);
    // wb_motor_set_velocity(motors[1],RS);
    // wb_motor_set_velocity(motors[2],LS);
    // wb_motor_set_velocity(motors[3],RS);
    
    //麦轮底盘的控制  
  double v_x = 0.0;
  double v_y = 5.0;  
  double v_r = 0.0;
  
  double v[4];
  v[0] = v_x + v_y + v_r;
  v[1] = v_x - v_y - v_r;
  v[2] = v_x - v_y + v_r;
  v[3] = v_x + v_y - v_r;
  for(int i = 0;i < 4;i++)
  {
    wb_motor_set_velocity(motors[i],v[i]);
  }


    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}


