extern "C" {
    #include <linux/i2c-dev.h>
    #include <i2c/smbus.h>
}
#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */
#include <sys/ioctl.h>
#include <cstdio>
#include <stdint.h>

int main()
{
    int file;
    int adapter_nr = 1; /* probably dynamically determined */
    char filename[20];

    snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
    file = open(filename, O_RDWR);
    if (file < 0) {
        /* ERROR HANDLING; you can check errno to see what went wrong */
        return (1);
    }

    int addr = 0x10; /* The I2C address */

    if (ioctl(file, I2C_SLAVE, addr) < 0) {
        /* ERROR HANDLING; you can check errno to see what went wrong */
        return (1);
    }

    uint8_t reg = 0x00; /* Device register to access */
    int32_t res;
    char buf[10];

    /* Using SMBus commands */
    res = i2c_smbus_read_word_data(file, reg);
    if (res < 0) {
        /* ERROR HANDLING: I2C transaction failed */
    } else {
        printf("Register value is %d", res);
    }
}