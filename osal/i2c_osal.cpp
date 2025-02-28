#include <i2c_osal.hpp>

extern "C" {
    #include <linux/i2c-dev.h>
    #include <i2c/smbus.h>
}

#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */
#include <sys/ioctl.h>
#include <cstdio>

static int fd = 0;

namespace osal
{

bool i2c_init(uint8_t bus)
{
    char device_busname[20]{0,};

    snprintf(device_busname, 19, "/dev/i2c-%d", bus);

    fd = open(device_busname, O_RDWR);

    return (fd != 0);
}

bool i2c_probe(uint8_t address)
{
    return (ioctl(fd, I2C_SLAVE, address) > 0);
}

int32_t i2c_read(uint8_t address, uint16_t reg_addr)
{
    if (ioctl(fd, I2C_SLAVE, address) < 0) {
        return -1;
    }

    return i2c_smbus_read_word_data(fd, reg_addr);
}

} //namespace osal