#include "bsp_imu.h"
#include "bsp_i2c.h"
#include "mpu6050.h"

static uint8_t Bsp_Mpu6050_WriteReg(uint8_t dev_addr, uint8_t reg, uint8_t data)
{

    return 0;
}

static uint8_t Bsp_Mpu6050_ReadReg(uint8_t dev_addr, uint8_t reg, uint8_t* buf, uint8_t len)
{

    return 0;
}

static const Mpu6050_BusOpsType Mpu6050_valBusOps_Mp = {
    .write_reg = Bsp_Mpu6050_WriteReg,
    .read_reg = Bsp_Mpu6050_ReadReg,
};

static Mpu6050_DevType_t Mpu6050_valDev_Mp = {
    .bus_ops = &Mpu6050_valBusOps_Mp,
    .dev_addr = 0x68,
};

static uint8_t Bsp_Imu_Init(Imu_Device_t* dev)
{

    return 0;
}

static uint8_t Bsp_Imu_ReadGyro(Imu_Device_t* dev, float* x, float* y, float* z)
{

    return 0;
}

static uint8_t Bsp_Imu_ReadAcc(Imu_Device_t* dev, float* x, float* y, float* z)
{

    return 0;
}

static uint8_t Bsp_Imu_ReadTemp(Imu_Device_t* dev, float* temp)
{

    return 0;
}

static const Imu_OpsType Imu_valOps_Mp = {
    .init = Bsp_Imu_Init,
    .read_gyro = Bsp_Imu_ReadGyro,
    .read_acc = Bsp_Imu_ReadAcc,
    .read_temp = Bsp_Imu_ReadTemp,
};

static Imu_Device_t Imu_valDev_Mp = {
    .ops = &Imu_valOps_Mp,
    .private_data = (void*)&Mpu6050_valDev_Mp,
};

Imu_Device_t* Bsp_Imu_GetDev(void)
{
    return &Imu_valDev_Mp;
}
