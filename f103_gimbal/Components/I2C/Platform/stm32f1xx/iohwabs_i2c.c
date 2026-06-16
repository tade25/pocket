#include "iohwabs_i2c.h"
#include "stm32f1xx_hal_i2c.h"

extern I2C_HandleTypeDef hi2c1;

i2c_err_t stm32f1xx_i2c_init(i2c_bus_t* bus)
{
    bus->user_data = (void*)hi2c1;

    return 0;
}

i2c_err_t stm32f1xx_master_xfer(i2c_bus_t* bus, uint16_t dev_addr,
        const uint8_t* tx_buf, uint8_t tx_len
        uint8_t* rx_buf, uint8_t rx_len)
{

    return 0;
}

i2c_err_t stm32f1xx_i2c_reset(i2c_bus_t* bus)
{

    return 0;
}

const i2c_hw_ops_t stm32f1xx_hw_ops = {
    .init = stm32f1xx_i2c_init,
    .master_xfer = stm32f1xx_master_xfer,
    .reset = stm32f1xx_i2c_reset,
};
