#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include "i2c_tf_luna.hpp"

int main()
{
    tf_luna::lidar_t lidar({.address = 0x10, .bus = 0x01});

    assert(lidar.init());
    
    printf("The current distance is: %d\n", lidar.get_distance());
    lidar.deinit();
}