#include <i2c_osal.hpp>

extern "C" {
    #include <linux/i2c-dev.h>
    #include <i2c/smbus.h>
}

#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */
#include <sys/ioctl.h>
#include <cstdio>
#include <string>

/* Definition of the i2c_data struct. It might be different depending on the port
 for Linux, holds the i2c-related file descriptor */
struct i2c_data 
{
    int fd; /*file descriptor for i2c*/
};

namespace osal
{

static inline i2c_handler_t *make_i2c_handler(void)
{
    return new i2c_data{};
}

static inline void destroy_i2c_handler(i2c_handler_t *handler)
{
    delete handler;
    handler = nullptr;
}

i2c_handler_t *i2c_init(uint8_t bus)
{
    std::string device_busname = std::string{"/dev/i2c-"} + std::to_string(bus);
    
    i2c_handler_t *i2c_handle = make_i2c_handler();

    i2c_handle->fd = open(device_busname.c_str(), O_RDWR);

    return i2c_handle;
}

bool i2c_probe(const i2c_handler_t *handler, uint8_t address)
{
    return (ioctl(handler->fd, I2C_SLAVE, address) >= 0);
}

int32_t i2c_read(const i2c_handler_t *handler, uint8_t address, uint16_t reg_addr)
{
    if (ioctl(handler->fd, I2C_SLAVE, address) < 0) {
        return -1;
    }

    return i2c_smbus_read_word_data(handler->fd, reg_addr);
}

void i2c_deinit(i2c_handler_t *handler)
{
    destroy_i2c_handler(handler);
}

} //namespace osal