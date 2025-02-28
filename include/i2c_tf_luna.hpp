#ifndef I2C_TF_LUNA_H
#define I2C_TF_LUNA_H

namespace tf_luna
{

    class lidar_t
    {
    public:
        lidar_t(uint8_t address = 0x10, uint8_t bus = 1) : _address{address}, _bus{bus} {};
        bool init(void);
        uint16_t get_distance(void);
    private:
        uint16_t _address;
        uint8_t _bus;
    };
}

#endif //I2C_TF_LUNA_H