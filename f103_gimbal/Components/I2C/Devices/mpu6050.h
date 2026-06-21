#ifndef __MPU6050_H_
#define __MPU6050_H_

#include <stdint.h>

typedef struct Mpu6050_DevType Mpu6050_DevType_t;

typedef struct {
    uint8_t (*write_reg)(uint8_t dev_addr, uint8_t reg, uint8_t data);
    uint8_t (*read_reg)(uint8_t dev_addr, uint8_t reg, uint8_t* buf, uint8_t len);
} Mpu6050_BusOpsType;

struct Mpu6050_DevType {
    const Mpu6050_BusOpsType* bus_ops;
    uint8_t dev_addr;
};

#endif
