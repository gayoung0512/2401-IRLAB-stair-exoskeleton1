/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MPU6050_real_time.c
 *
 * Code generated for Simulink model 'MPU6050_real_time'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Nov 28 21:31:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MPU6050_real_time.h"
#include "MPU6050_real_time_types.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "MPU6050_real_time_private.h"

/* Block signals (default storage) */
B_MPU6050_real_time_T MPU6050_real_time_B;

/* Block states (default storage) */
DW_MPU6050_real_time_T MPU6050_real_time_DW;

/* Real-time model */
static RT_MODEL_MPU6050_real_time_T MPU6050_real_time_M_;
RT_MODEL_MPU6050_real_time_T *const MPU6050_real_time_M = &MPU6050_real_time_M_;

/* Forward declaration for local functions */
static codertarget_arduinobase_inter_T *M_arduinoMPU6050_arduinoMPU6050
  (codertarget_arduinobase_inter_T *obj);
static void MPU6050_real_t_SystemCore_setup(codertarget_arduinobase_inter_T *obj);
static void MPU6050_real_SystemCore_setup_e(codertarget_arduinobase_inter_T *obj);
static codertarget_arduinobase_inter_T *M_arduinoMPU6050_arduinoMPU6050
  (codertarget_arduinobase_inter_T *obj)
{
  codertarget_arduinobase_inter_T *b_obj;
  obj->I2CReadWriteError = 0U;
  obj->InitError = false;
  obj->isInitialized = 0L;
  obj->SampleTime = -1.0;
  obj->IsFirstStep = false;
  b_obj = obj;
  obj->i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
  obj->i2cObjmpu.isInitialized = 0L;
  obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE = NULL;
  obj->i2cObjmpu.matlabCodegenIsDeleted = false;
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void MPU6050_real_t_SystemCore_setup(codertarget_arduinobase_inter_T *obj)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T SwappedDataBytes_0;
  uint8_T regSet;
  uint8_T status;
  obj->isInitialized = 1L;
  obj->InitializationFlag = true;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  obj->i2cObjmpu.BusSpeed = 100000UL;
  MW_I2C_SetBusSpeed(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE,
                     obj->i2cObjmpu.BusSpeed);
  regSet = 128U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes[0], 2UL, false, false);
  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  MW_delay_in_milliseconds(1UL);
  regSet = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes[0], 2UL, false, false);
  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  MW_delay_in_milliseconds(100UL);
  status = 117U;
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
         (uint8_T));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes_0, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                      &SwappedDataBytes_0, 1UL, false, true);
    memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
           (uint8_T));
  } else {
    regSet = 0U;
  }

  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  obj->MPUConnect = (regSet == 104);
  if (obj->MPUConnect) {
    regSet = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 25U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 28U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
             (uint8_T));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)(regSet & 231);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 28U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 27U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
             (uint8_T));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)(regSet & 231);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 27U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 26U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
             (uint8_T));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)((regSet & 248) | 1);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 26U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }
  } else {
    obj->InitError = true;
  }

  obj->InitializationFlag = false;
  obj->isSetupComplete = true;
}

static void MPU6050_real_SystemCore_setup_e(codertarget_arduinobase_inter_T *obj)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T SwappedDataBytes_0;
  uint8_T regSet;
  uint8_T status;
  obj->isInitialized = 1L;
  obj->InitializationFlag = true;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  obj->i2cObjmpu.BusSpeed = 100000UL;
  MW_I2C_SetBusSpeed(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE,
                     obj->i2cObjmpu.BusSpeed);
  regSet = 128U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
    &SwappedDataBytes[0], 2UL, false, false);
  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  MW_delay_in_milliseconds(1UL);
  regSet = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
    &SwappedDataBytes[0], 2UL, false, false);
  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  MW_delay_in_milliseconds(100UL);
  status = 117U;
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
         (uint8_T));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
    &SwappedDataBytes_0, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
                      &SwappedDataBytes_0, 1UL, false, true);
    memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
           (uint8_T));
  } else {
    regSet = 0U;
  }

  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  obj->MPUConnect = (regSet == 104);
  if (obj->MPUConnect) {
    regSet = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 25U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 28U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
             (uint8_T));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)(regSet & 231);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 28U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 27U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
             (uint8_T));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)(regSet & 231);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 27U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 26U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (size_t)1 * sizeof
             (uint8_T));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)((regSet & 248) | 1);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 26U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 105UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }
  } else {
    obj->InitError = true;
  }

  obj->InitializationFlag = false;
  obj->isSetupComplete = true;
}

/* Model step function */
void MPU6050_real_time_step(void)
{
  i_codertarget_arduinobase_int_T *obj_tmp;
  int16_T i;
  uint8_T b_RegisterValue[6];
  uint8_T output_raw[6];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* Outputs for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* MATLABSystem: '<S1>/Base sensor block' */
  if (MPU6050_real_time_DW.obj_d.SampleTime !=
      MPU6050_real_time_P.MPU6050IMUSensor_SampleTime) {
    MPU6050_real_time_DW.obj_d.SampleTime =
      MPU6050_real_time_P.MPU6050IMUSensor_SampleTime;
  }

  /* End of Outputs for SubSystem: '<Root>/MPU6050 IMU Sensor' */
  if (!MPU6050_real_time_DW.obj_d.IsFirstStep) {
    MW_getCurrentTime_in_milliseconds();
    MPU6050_real_time_DW.obj_d.IsFirstStep = true;
  }

  MPU6050_real_time_DW.obj_d.I2CReadWriteError = 0U;
  obj_tmp = &MPU6050_real_time_DW.obj_d.i2cObjmpu;
  status = 59U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 104UL, &output_raw[0],
                      6UL, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)6 *
           sizeof(uint8_T));
  } else {
    for (i = 0; i < 6; i++) {
      b_RegisterValue[i] = 0U;
    }
  }

  if (status != 0) {
    if (MPU6050_real_time_DW.obj_d.InitializationFlag) {
      MPU6050_real_time_DW.obj_d.InitError = true;
    } else if (MPU6050_real_time_DW.obj_d.I2CReadWriteError == 0) {
      MPU6050_real_time_DW.obj_d.I2CReadWriteError = status;
    }
  }

  MPU6050_real_time_B.Basesensorblock_o1_o[0] = b_RegisterValue[0] << 8 |
    b_RegisterValue[1];
  MPU6050_real_time_B.Basesensorblock_o1_o[1] = b_RegisterValue[2] << 8 |
    b_RegisterValue[3];
  MPU6050_real_time_B.Basesensorblock_o1_o[2] = b_RegisterValue[4] << 8 |
    b_RegisterValue[5];
  if (MPU6050_real_time_DW.obj_d.InitError) {
    /* MATLABSystem: '<S1>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o1_o[0] = 0.0;
    MPU6050_real_time_B.Basesensorblock_o1_o[1] = 0.0;
    MPU6050_real_time_B.Basesensorblock_o1_o[2] = 0.0;
  } else {
    /* MATLABSystem: '<S1>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o1_o[0] =
      MPU6050_real_time_B.Basesensorblock_o1_o[0] * 9.80665 / 16384.0;
    MPU6050_real_time_B.Basesensorblock_o1_o[1] =
      MPU6050_real_time_B.Basesensorblock_o1_o[1] * 9.80665 / 16384.0;
    MPU6050_real_time_B.Basesensorblock_o1_o[2] =
      MPU6050_real_time_B.Basesensorblock_o1_o[2] * 9.80665 / 16384.0;
  }

  status = 67U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 104UL, &output_raw[0],
                      6UL, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)6 *
           sizeof(uint8_T));
  } else {
    for (i = 0; i < 6; i++) {
      b_RegisterValue[i] = 0U;
    }
  }

  if (status != 0) {
    if (MPU6050_real_time_DW.obj_d.InitializationFlag) {
      MPU6050_real_time_DW.obj_d.InitError = true;
    } else if (MPU6050_real_time_DW.obj_d.I2CReadWriteError == 0) {
      MPU6050_real_time_DW.obj_d.I2CReadWriteError = status;
    }
  }

  MPU6050_real_time_B.Basesensorblock_o2_j[0] = b_RegisterValue[0] << 8 |
    b_RegisterValue[1];
  MPU6050_real_time_B.Basesensorblock_o2_j[1] = b_RegisterValue[2] << 8 |
    b_RegisterValue[3];
  MPU6050_real_time_B.Basesensorblock_o2_j[2] = b_RegisterValue[4] << 8 |
    b_RegisterValue[5];
  if (MPU6050_real_time_DW.obj_d.InitError) {
    /* MATLABSystem: '<S1>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o2_j[0] = 0.0;
    MPU6050_real_time_B.Basesensorblock_o2_j[1] = 0.0;
    MPU6050_real_time_B.Basesensorblock_o2_j[2] = 0.0;
  } else {
    /* MATLABSystem: '<S1>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o2_j[0] *= 0.00762939453125;
    MPU6050_real_time_B.Basesensorblock_o2_j[1] *= 0.00762939453125;
    MPU6050_real_time_B.Basesensorblock_o2_j[2] *= 0.00762939453125;
  }

  if (MPU6050_real_time_DW.obj_d.InitError) {
    /* MATLABSystem: '<S1>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o3_h = 32U;
  } else {
    /* MATLABSystem: '<S1>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o3_h =
      MPU6050_real_time_DW.obj_d.I2CReadWriteError;
  }

  /* End of MATLABSystem: '<S1>/Base sensor block' */
  /* End of Outputs for SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* Outputs for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor1' */
  /* Outputs for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor1' */
  /* MATLABSystem: '<S2>/Base sensor block' */
  if (MPU6050_real_time_DW.obj.SampleTime !=
      MPU6050_real_time_P.MPU6050IMUSensor1_SampleTime) {
    MPU6050_real_time_DW.obj.SampleTime =
      MPU6050_real_time_P.MPU6050IMUSensor1_SampleTime;
  }

  /* End of Outputs for SubSystem: '<Root>/MPU6050 IMU Sensor1' */
  if (!MPU6050_real_time_DW.obj.IsFirstStep) {
    MW_getCurrentTime_in_milliseconds();
    MPU6050_real_time_DW.obj.IsFirstStep = true;
  }

  MPU6050_real_time_DW.obj.I2CReadWriteError = 0U;
  obj_tmp = &MPU6050_real_time_DW.obj.i2cObjmpu;
  status = 59U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 105UL,
    &SwappedDataBytes, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 105UL, &output_raw[0],
                      6UL, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)6 *
           sizeof(uint8_T));
  } else {
    for (i = 0; i < 6; i++) {
      b_RegisterValue[i] = 0U;
    }
  }

  if (status != 0) {
    if (MPU6050_real_time_DW.obj.InitializationFlag) {
      MPU6050_real_time_DW.obj.InitError = true;
    } else if (MPU6050_real_time_DW.obj.I2CReadWriteError == 0) {
      MPU6050_real_time_DW.obj.I2CReadWriteError = status;
    }
  }

  MPU6050_real_time_B.Basesensorblock_o1[0] = b_RegisterValue[0] << 8 |
    b_RegisterValue[1];
  MPU6050_real_time_B.Basesensorblock_o1[1] = b_RegisterValue[2] << 8 |
    b_RegisterValue[3];
  MPU6050_real_time_B.Basesensorblock_o1[2] = b_RegisterValue[4] << 8 |
    b_RegisterValue[5];
  if (MPU6050_real_time_DW.obj.InitError) {
    /* MATLABSystem: '<S2>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o1[0] = 0.0;
    MPU6050_real_time_B.Basesensorblock_o1[1] = 0.0;
    MPU6050_real_time_B.Basesensorblock_o1[2] = 0.0;
  } else {
    /* MATLABSystem: '<S2>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o1[0] =
      MPU6050_real_time_B.Basesensorblock_o1[0] * 9.80665 / 16384.0;
    MPU6050_real_time_B.Basesensorblock_o1[1] =
      MPU6050_real_time_B.Basesensorblock_o1[1] * 9.80665 / 16384.0;
    MPU6050_real_time_B.Basesensorblock_o1[2] =
      MPU6050_real_time_B.Basesensorblock_o1[2] * 9.80665 / 16384.0;
  }

  status = 67U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 105UL,
    &SwappedDataBytes, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 105UL, &output_raw[0],
                      6UL, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)6 *
           sizeof(uint8_T));
  } else {
    for (i = 0; i < 6; i++) {
      b_RegisterValue[i] = 0U;
    }
  }

  if (status != 0) {
    if (MPU6050_real_time_DW.obj.InitializationFlag) {
      MPU6050_real_time_DW.obj.InitError = true;
    } else if (MPU6050_real_time_DW.obj.I2CReadWriteError == 0) {
      MPU6050_real_time_DW.obj.I2CReadWriteError = status;
    }
  }

  MPU6050_real_time_B.Basesensorblock_o2[0] = b_RegisterValue[0] << 8 |
    b_RegisterValue[1];
  MPU6050_real_time_B.Basesensorblock_o2[1] = b_RegisterValue[2] << 8 |
    b_RegisterValue[3];
  MPU6050_real_time_B.Basesensorblock_o2[2] = b_RegisterValue[4] << 8 |
    b_RegisterValue[5];
  if (MPU6050_real_time_DW.obj.InitError) {
    /* MATLABSystem: '<S2>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o2[0] = 0.0;
    MPU6050_real_time_B.Basesensorblock_o2[1] = 0.0;
    MPU6050_real_time_B.Basesensorblock_o2[2] = 0.0;
  } else {
    /* MATLABSystem: '<S2>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o2[0] *= 0.00762939453125;
    MPU6050_real_time_B.Basesensorblock_o2[1] *= 0.00762939453125;
    MPU6050_real_time_B.Basesensorblock_o2[2] *= 0.00762939453125;
  }

  if (MPU6050_real_time_DW.obj.InitError) {
    /* MATLABSystem: '<S2>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o3 = 32U;
  } else {
    /* MATLABSystem: '<S2>/Base sensor block' */
    MPU6050_real_time_B.Basesensorblock_o3 =
      MPU6050_real_time_DW.obj.I2CReadWriteError;
  }

  /* End of MATLABSystem: '<S2>/Base sensor block' */
  /* End of Outputs for SubSystem: '<Root>/MPU6050 IMU Sensor1' */
  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  MPU6050_real_time_M->Timing.taskTime0 =
    ((time_T)(++MPU6050_real_time_M->Timing.clockTick0)) *
    MPU6050_real_time_M->Timing.stepSize0;
}

/* Model initialize function */
void MPU6050_real_time_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(MPU6050_real_time_M, 10.0);
  MPU6050_real_time_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  MPU6050_real_time_M->Sizes.checksums[0] = (1732942124U);
  MPU6050_real_time_M->Sizes.checksums[1] = (1785248790U);
  MPU6050_real_time_M->Sizes.checksums[2] = (3842443538U);
  MPU6050_real_time_M->Sizes.checksums[3] = (1801388232U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    MPU6050_real_time_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(MPU6050_real_time_M->extModeInfo,
      &MPU6050_real_time_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MPU6050_real_time_M->extModeInfo,
                        MPU6050_real_time_M->Sizes.checksums);
    rteiSetTPtr(MPU6050_real_time_M->extModeInfo, rtmGetTPtr(MPU6050_real_time_M));
  }

  /* SystemInitialize for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* Start for MATLABSystem: '<S1>/Base sensor block' */
  MPU6050_real_time_DW.obj_d.i2cObjmpu.matlabCodegenIsDeleted = true;
  MPU6050_real_time_DW.obj_d.matlabCodegenIsDeleted = true;
  M_arduinoMPU6050_arduinoMPU6050(&MPU6050_real_time_DW.obj_d);

  /* Start for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  MPU6050_real_time_DW.obj_d.SampleTime =
    MPU6050_real_time_P.MPU6050IMUSensor_SampleTime;

  /* End of Start for SubSystem: '<Root>/MPU6050 IMU Sensor' */
  MPU6050_real_t_SystemCore_setup(&MPU6050_real_time_DW.obj_d);

  /* End of SystemInitialize for SubSystem: '<Root>/MPU6050 IMU Sensor' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor1' */
  /* Start for MATLABSystem: '<S2>/Base sensor block' */
  MPU6050_real_time_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
  MPU6050_real_time_DW.obj.matlabCodegenIsDeleted = true;
  M_arduinoMPU6050_arduinoMPU6050(&MPU6050_real_time_DW.obj);

  /* Start for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor1' */
  MPU6050_real_time_DW.obj.SampleTime =
    MPU6050_real_time_P.MPU6050IMUSensor1_SampleTime;

  /* End of Start for SubSystem: '<Root>/MPU6050 IMU Sensor1' */
  MPU6050_real_SystemCore_setup_e(&MPU6050_real_time_DW.obj);

  /* End of SystemInitialize for SubSystem: '<Root>/MPU6050 IMU Sensor1' */
}

/* Model terminate function */
void MPU6050_real_time_terminate(void)
{
  i_codertarget_arduinobase_int_T *obj;

  /* Terminate for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* Terminate for MATLABSystem: '<S1>/Base sensor block' */
  if (!MPU6050_real_time_DW.obj_d.matlabCodegenIsDeleted) {
    MPU6050_real_time_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((MPU6050_real_time_DW.obj_d.isInitialized == 1L) &&
        MPU6050_real_time_DW.obj_d.isSetupComplete) {
      obj = &MPU6050_real_time_DW.obj_d.i2cObjmpu;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &MPU6050_real_time_DW.obj_d.i2cObjmpu;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1L) {
      obj->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Base sensor block' */
  /* End of Terminate for SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* Terminate for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor1' */
  /* Terminate for MATLABSystem: '<S2>/Base sensor block' */
  if (!MPU6050_real_time_DW.obj.matlabCodegenIsDeleted) {
    MPU6050_real_time_DW.obj.matlabCodegenIsDeleted = true;
    if ((MPU6050_real_time_DW.obj.isInitialized == 1L) &&
        MPU6050_real_time_DW.obj.isSetupComplete) {
      obj = &MPU6050_real_time_DW.obj.i2cObjmpu;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &MPU6050_real_time_DW.obj.i2cObjmpu;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1L) {
      obj->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Base sensor block' */
  /* End of Terminate for SubSystem: '<Root>/MPU6050 IMU Sensor1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
