#include "i2c_tf_luna.hpp"
#include "tf_luna_regs_address.hpp"

namespace tf_luna
{

typedef union
{
    uint8_t as_array[2];
    uint16_t concatenated;
} concat_t;

bool lidar_t::init(void)
{
    this->handler = osal::i2c_init(this->_bus);
    bool status_ok = false;

    if (this->handler != nullptr)
    {
        status_ok = osal::i2c_probe(this->handler, this->_address);
    }

    return status_ok;
}

void lidar_t::deinit(void)
{
    osal::i2c_deinit(this->handler);
}

uint16_t lidar_t::get_distance(void)
{
    int32_t dist_low  = osal::i2c_read(this->handler, this->_address, DIST_LOW);
    int32_t dist_high = osal::i2c_read(this->handler, this->_address, DIST_HIGH);
    concat_t distance = {.concatenated = 0};

    if ((dist_low >= 0) && (dist_high >= 0))
    {
        distance.as_array[0] = static_cast<uint8_t>(dist_low);
        distance.as_array[1] = static_cast<uint8_t>(dist_high);
    }

    return distance.concatenated;
}

uint16_t lidar_t::get_temperature(void)
{
    int32_t temp_low  = osal::i2c_read(this->handler, this->_address, TEMP_LOW);
    int32_t temp_high = osal::i2c_read(this->handler, this->_address, TEMP_HIGH);
    concat_t temperature = {.concatenated = 0};

    if ((temp_low >= 0) && (temp_high >= 0))
    {
        temperature.as_array[0] = static_cast<uint8_t>(temp_low);
        temperature.as_array[1] = static_cast<uint8_t>(temp_high);
    }

    return temperature.concatenated;    
}

uint16_t lidar_t::get_timestamp(void)
{
    int32_t tick_low  = osal::i2c_read(this->handler, this->_address, TICK_LOW);
    int32_t tick_high = osal::i2c_read(this->handler, this->_address, TICK_HIGH);
    concat_t timestamp = {.concatenated = 0};

    if ((tick_low >= 0) && (tick_high >= 0))
    {
        timestamp.as_array[0] = static_cast<uint8_t>(tick_low);
        timestamp.as_array[1] = static_cast<uint8_t>(tick_high);
    }

    return timestamp.concatenated;    
}

}