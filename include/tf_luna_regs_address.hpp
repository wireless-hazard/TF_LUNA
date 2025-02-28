#ifndef _TF_LUNA_REGS_ADDR_H
#define _TF_LUNA_REGS_ADDR_H

namespace tf_luna
{

typedef enum {
    DIST_LOW                 = 0x00,
    DIST_HIGH                = 0x01,
    AMP_LOW                  = 0x02,
    AMP_HIGH                 = 0x03,
    TEMP_LOW                 = 0x04,
    TEMP_HIGH                = 0x05,
    TICK_LOW                 = 0x06,
    TICK_HIGH                = 0x07,
    ERROR_LOW                = 0x08,
    ERROR_HIGH               = 0x09,
    VERSION_REVISION         = 0x0A,
    VERSION_MINOR            = 0x0B,
    VERSION_MAJOR            = 0x0C,
    // 0x10-0x1D SN
    ULTRA_LOW_POWER          = 0x1F,
    SAVE                     = 0x20,
    SHUTDOWN_REBOOT          = 0x21,
    SLAVE_ADDR               = 0x22,
    MODE                     = 0x23,
    TRIG_ONE_SHOT            = 0x24,
    ENABLE                   = 0x25,
    FPS_LOW                  = 0x26,
    FPS_HIGH                 = 0x27,
    LOW_POWER                = 0x28,
    RESTORE_FACTORY_DEFAULTS = 0x29,
    AMP_THR_LOW              = 0x2A,
    AMP_THR_HIGH             = 0x2B,
    DUMMY_DIST_LOW           = 0x2C,
    DUMMY_DIST_HIGH          = 0x2D,
    MIN_DIST_LOW             = 0x2E,
    MIN_DIST_HIGH            = 0x2F,
    MAX_DIST_LOW             = 0x30,
    MAX_DIST_HIGH            = 0x31,
    // 0x3C-0x3F SIGNATURE -- LUNA
} i2c_register_table_t;

} //namespace tf_luna

#endif