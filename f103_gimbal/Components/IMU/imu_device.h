#ifndef __IMU_DEVICE_H_
#define __IMU_DEVICE_H_

#include <stdint.h>
#include <stddef.h>

typedef struct Imu_Device Imu_Device_t;

typedef struct {
    uint8_t (*init)(Imu_Device_t*);
    uint8_t (*read_gyro)(Imu_Device_t*, float*, float*, float*);
    uint8_t (*read_acc)(Imu_Device_t*, float*, float*, float*);
    uint8_t (*read_temp)(Imu_Device_t*, float*);
} Imu_OpsType;

struct Imu_Device { 
    const Imu_OpsType* ops;
    void* private_data;
};

extern uint8_t imu_device_init(Imu_Device_t* dev);
extern uint8_t imu_device_read_gyro(Imu_Device_t* dev, float* x, float* y, float* z);
extern uint8_t imu_device_read_acc(Imu_Device_t* dev, float* x, float* y, float* z);
extern uint8_t imu_device_read_temp(Imu_Device_t* dev, float* temp);

#endif
