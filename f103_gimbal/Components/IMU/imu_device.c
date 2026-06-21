#include "imu_device.h"

uint8_t imu_device_init(Imu_Device_t* dev)
{
    if((NULL == dev) || (NULL == dev->ops) || (NULL == dev->ops->init)) {
        return 1;
    }

    return dev->ops->init(dev);
}

uint8_t imu_device_read_gyro(Imu_Device_t* dev, float* x, float* y, float* z)
{
    if((NULL == dev) || (NULL == dev->ops) || (NULL == dev->ops->read_gyro)) {
        return 1;
    }

    return dev->ops->read_gyro(dev, x, y, z);
}

uint8_t imu_device_read_acc(Imu_Device_t* dev, float* x, float* y, float* z)
{
    if((NULL == dev) || (NULL == dev->ops) || (NULL == dev->ops->read_acc)) {
        return 1;
    }

    return dev->ops->read_acc(dev, x, y, z);
}

uint8_t imu_device_read_temp(Imu_Device_t* dev, float* temp)
{
    if((NULL == dev) || (NULL == dev->ops) || (NULL == dev->ops->read_temp)) {
        return 1;
    }

    return dev->ops->read_temp(dev, temp);
}

