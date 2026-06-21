#include "iohwabs_i2c.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_i2c.h"

extern I2C_HandleTypeDef hi2c1;

i2c_err_t stm32f1xx_i2c_init(i2c_bus_t* bus)
{
    i2c_err_t ret = I2C_ERR_OK;

    bus->user_data = (void*)&hi2c1;

    return ret;
}

i2c_err_t stm32f1xx_master_xfer(i2c_bus_t* bus, uint16_t dev_addr,
        const uint8_t* tx_buf, uint8_t tx_len,
        uint8_t* rx_buf, uint8_t rx_len)
{
    i2c_err_t ret = I2C_ERR_OK;

    return ret;
}

i2c_err_t stm32f1xx_i2c_reset(i2c_bus_t* bus)
{
    i2c_err_t ret = I2C_ERR_OK;

    return ret;
}

const i2c_hw_ops_t stm32f1xx_hw_ops = {
    .init = stm32f1xx_i2c_init,
    .master_xfer = stm32f1xx_master_xfer,
    .reset = stm32f1xx_i2c_reset,
};

void I2C_TestFunction(void)
{
    HAL_StatusTypeDef ret;
    uint8_t data = 0x11;

    ret = HAL_I2C_Master_Transmit(&hi2c1, 0x68, &data, 1, 100);
}
