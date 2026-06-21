#include "bsp_i2c.h"

static i2c_bus_t I2c_valBus_Mp;

i2c_bus_t* BSP_I2C_GetBus(void)
{
    return &I2c_valBus_Mp;
}
