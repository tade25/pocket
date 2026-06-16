#ifndef __I2C_CORE_H_
#define __I2C_CORE_H_

#include <stdint.h>

typedef enum {
    I2C_ERR_OK = 0,
    I2C_ERR_PARAM,
    I2C_ERR_ACK,
    I2C_ERR_HW,
} i2c_err_t;

typedef struct
{
    uint32_t i2c_freq;
    uint8_t id;
} i2c_config_t;

typedef struct
{
    i2c_config_t config;
    i2c_hw_ops_t hal_ops;
    void* user_data;
} i2c_bus_t;

typedef struct
{
    i2c_err_t (*init)(i2c_bus_t*);
    i2c_err_t (*master_xfer)(i2c_bus_t*, uint16_t, const uint8_t*, uint8_t, uint8_t*, uint8_t);
    i2c_err_t (*reset)(i2c_bus_t*);
} i2c_hw_ops_t;

extern i2c_err_t i2c_bus_init(i2c_bus_t* bus, i2c_config_t* config, i2c_hw_ops_t* hw_ops);
extern i2c_err_t i2c_master_transfer(i2c_bus_t* bus, uint16_t dev_addr,
        const uint8_t* tx_buf, uint8_t tx_len
        uint8_t* rx_buf, uint8_t rx_len);
extern i2c_err_t i2c_bus_reset(i2c_bus_t* bus);

#endif
