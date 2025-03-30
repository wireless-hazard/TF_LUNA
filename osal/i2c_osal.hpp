#ifndef _I2C_OSAL_H
#define _I2C_OSAL_H

#include <stdint.h>

/* opaque struct, so the actual contents are implementation depedent,
 allowing better portability and no leaking of OS-related specifics*/
typedef struct i2c_data i2c_handler_t;

namespace osal
{

i2c_handler_t *i2c_init(uint8_t bus);
void i2c_deinit(i2c_handler_t *handler);
bool i2c_probe(const i2c_handler_t *handler, uint8_t address);
int32_t i2c_read(const i2c_handler_t *handler, uint8_t address, uint16_t reg_addr);

} //namespace osal

#endif