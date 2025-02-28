#ifndef _I2C_OSAL_H
#define _I2C_OSAL_H

#include <stdint.h>

namespace osal
{

bool i2c_init(uint8_t bus);
bool i2c_probe(uint8_t address);
int32_t i2c_read(uint8_t address, uint16_t reg_addr);

} //namespace osal

#endif