#ifndef I2C_TF_LUNA_H
#define I2C_TF_LUNA_H

#include "i2c_osal.hpp"

namespace tf_luna
{

    class lidar_t
    {
    public:
        typedef struct {uint8_t address; uint8_t bus;} i2c_struct_t;
        lidar_t(i2c_struct_t config) : _address{config.address}, _bus{config.bus}, handler{nullptr} {};
        bool init(void);
        uint16_t get_distance(void);
    private:
        uint16_t _address;
        uint8_t _bus;
        i2c_handler_t *handler;
    };
}

#endif //I2C_TF_LUNA_H