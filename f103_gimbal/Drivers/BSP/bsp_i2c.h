#ifndef __BSP_I2C_H_
#define __BSP_I2C_H_

#include "i2c_core.h"

extern i2c_bus_t* Bsp_I2C_GetBus(void);
extern void Bsp_I2C_Init(void);

#endif
