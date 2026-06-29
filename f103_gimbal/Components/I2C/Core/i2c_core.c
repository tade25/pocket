#include "i2c_core.h"
#include "iohwabs_i2c.h"

i2c_err_t i2c_bus_init(i2c_bus_t* bus, i2c_config_t* config, i2c_hw_ops_t* hw_ops)
{
    i2c_err_t ret;

    if((NULL == bus) || (NULL == config) || (NULL == hw_ops))
        return I2C_ERR_PARAM;

    bus->config = *config;
    bus->hal_ops = hw_ops;

    if(NULL != bus->hal_ops->init)
        bus->hal_ops->init(bus);

    return ret;
}

i2c_err_t i2c_master_transfer(i2c_bus_t* bus, uint16_t dev_addr,
        const uint8_t* tx_buf, uint8_t tx_len,
        uint8_t* rx_buf, uint8_t rx_len)
{
    i2c_err_t ret;

    if((NULL == bus) || (NULL == bus->hal_ops))
        return I2C_ERR_PARAM;

    if(((tx_len > 0) && (NULL == tx_buf)) ||\
        ((rx_len > 0) && (NULL == rx_buf))) {
        return I2C_ERR_PARAM;
    }

    if(NULL != bus->hal_ops->master_xfer)
        bus->hal_ops->master_xfer(bus, dev_addr, tx_buf, tx_len, rx_buf, rx_len);

    return ret;
}

i2c_err_t i2c_bus_reset(i2c_bus_t* bus)
{
    i2c_err_t ret;

    return ret;
}
