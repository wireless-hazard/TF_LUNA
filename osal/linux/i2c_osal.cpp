#include <i2c_osal.hpp>

extern "C" {
    #include <linux/i2c-dev.h>
    #include <i2c/smbus.h>
}

#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */
#include <sys/ioctl.h>
#include <cstdio>

/* Definition of the i2c_data struct. It might be different depending on the port
 for Linux, holds the i2c-related file descriptor */
struct i2c_data 
{
    int fd; /*file descriptor for i2c*/
};

namespace osal
{

bool i2c_init(i2c_handler_t *handler, uint8_t bus)
{
    char device_busname[20]{0,};

    snprintf(device_busname, 19, "/dev/i2c-%d", bus);

    handler->fd = open(device_busname, O_RDWR);

    return (handler->fd != 0);
}

bool i2c_probe(const i2c_handler_t *handler, uint8_t address)
{
    return (ioctl(handler->fd, I2C_SLAVE, address) > 0);
}

int32_t i2c_read(const i2c_handler_t *handler, uint8_t address, uint16_t reg_addr)
{
    if (ioctl(handler->fd, I2C_SLAVE, address) < 0) {
        return -1;
    }

    return i2c_smbus_read_word_data(handler->fd, reg_addr);
}

} //namespace osal