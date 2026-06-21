#include "i2c_core.h"
#include "iohwabs_i2c.h"

i2c_err_t i2c_bus_init(i2c_bus_t* bus, i2c_config_t* config, i2c_hw_ops_t* hw_ops)
{
    i2c_err_t ret;

    return ret;
}

i2c_err_t i2c_master_transfer(i2c_bus_t* bus, uint16_t dev_addr,
        const uint8_t* tx_buf, uint8_t tx_len,
        uint8_t* rx_buf, uint8_t rx_len)
{
    i2c_err_t ret;

    return ret;
}

i2c_err_t i2c_bus_reset(i2c_bus_t* bus)
{
    i2c_err_t ret;

    return ret;
}
