#include "i2c_osal.hpp"
#include "i2c_tf_luna.hpp"
#include "tf_luna_regs_address.hpp"

namespace tf_luna
{

typedef union
{
    uint8_t distance_array[2];
    uint16_t distance;
} distance_t;

bool lidar_t::init(void)
{
    bool status_ok = osal::i2c_init(this->_bus);

    if (status_ok)
    {
        status_ok = osal::i2c_probe(this->_address);
    }

    return status_ok;
}

uint16_t lidar_t::get_distance(void)
{
    int32_t dist_low  = osal::i2c_read(this->_address, DIST_LOW);
    int32_t dist_high = osal::i2c_read(this->_address, DIST_HIGH);
    distance_t distance = {.distance = 0};

    if ((dist_low >= 0) && (dist_high >= 0))
    {
        distance.distance_array[0] = static_cast<uint8_t>(dist_low);
        distance.distance_array[1] = static_cast<uint8_t>(dist_high);
    }

    return distance.distance;
}

}