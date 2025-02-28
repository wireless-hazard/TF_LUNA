#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include "i2c_tf_luna.hpp"

int main()
{
    tf_luna::lidar_t lidar(0x10, 1);

    lidar.init();
    
    printf("The current distance is: %d\n", lidar.get_distance());    
}