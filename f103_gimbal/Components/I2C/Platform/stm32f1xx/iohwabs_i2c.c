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
    I2C_HandleTypeDef* i2c_handler = (I2C_HandleTypeDef*)bus->user_data;
    i2c_err_t ret = I2C_ERR_OK;
    uint8_t transfer_addr = ((uint8_t)(dev_addr) << 1);

    HAL_I2C_Mem_Read(i2c_handler, transfer_addr, tx_buf[0], I2C_MEMADD_SIZE_8BIT, rx_buf, rx_len, 100);

    return ret;
}

i2c_err_t stm32f1xx_i2c_reset(i2c_bus_t* bus)
{
    i2c_err_t ret = I2C_ERR_OK;

    return ret;
}

i2c_hw_ops_t stm32f1xx_hw_ops = {
    .init = stm32f1xx_i2c_init,
    .master_xfer = stm32f1xx_master_xfer,
    .reset = stm32f1xx_i2c_reset,
};
