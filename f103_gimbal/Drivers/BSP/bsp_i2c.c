#include "bsp_i2c.h"
#include "iohwabs_i2c.h"

static i2c_bus_t I2C_valBus_Mp;

i2c_bus_t* Bsp_I2C_GetBus(void)
{
    return &I2C_valBus_Mp;
}

void Bsp_I2C_Init(void)
{
    i2c_config_t config;

    config.i2c_freq = 100000;
    config.id = 0;

    (void)i2c_bus_init(&I2C_valBus_Mp, &config, &stm32f1xx_hw_ops);
}
