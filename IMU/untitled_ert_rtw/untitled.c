/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Feb 25 16:56:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_types.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "untitled_private.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static codertarget_arduinobase_inter_T *u_arduinoMPU6050_arduinoMPU6050
  (codertarget_arduinobase_inter_T *obj);
static void untitled_SystemCore_setup(codertarget_arduinobase_inter_T *obj);
static codertarget_arduinobase_inter_T *u_arduinoMPU6050_arduinoMPU6050
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

static void untitled_SystemCore_setup(codertarget_arduinobase_inter_T *obj)
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

/* Model step function */
void untitled_step(void)
{
  i_codertarget_arduinobase_int_T *obj_tmp;
  int16_T i;
  uint8_T b_RegisterValue[6];
  uint8_T output_raw[6];
  uint8_T b_output[2];
  uint8_T output_raw_0[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* Outputs for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* Outputs for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* MATLABSystem: '<S1>/Base sensor block' */
  if (untitled_DW.obj.SampleTime != untitled_P.MPU6050IMUSensor_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.MPU6050IMUSensor_SampleTime;
  }

  /* End of Outputs for SubSystem: '<Root>/MPU6050 IMU Sensor' */
  if (!untitled_DW.obj.IsFirstStep) {
    MW_getCurrentTime_in_milliseconds();
    untitled_DW.obj.IsFirstStep = true;
  }

  untitled_DW.obj.I2CReadWriteError = 0U;
  obj_tmp = &untitled_DW.obj.i2cObjmpu;
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
    if (untitled_DW.obj.InitializationFlag) {
      untitled_DW.obj.InitError = true;
    } else if (untitled_DW.obj.I2CReadWriteError == 0) {
      untitled_DW.obj.I2CReadWriteError = status;
    }
  }

  untitled_B.Basesensorblock_o1[0] = b_RegisterValue[0] << 8 | b_RegisterValue[1];
  untitled_B.Basesensorblock_o1[1] = b_RegisterValue[2] << 8 | b_RegisterValue[3];
  untitled_B.Basesensorblock_o1[2] = b_RegisterValue[4] << 8 | b_RegisterValue[5];
  if (untitled_DW.obj.InitError) {
    /* MATLABSystem: '<S1>/Base sensor block' */
    untitled_B.Basesensorblock_o1[0] = 0.0;
    untitled_B.Basesensorblock_o1[1] = 0.0;
    untitled_B.Basesensorblock_o1[2] = 0.0;
  } else {
    /* MATLABSystem: '<S1>/Base sensor block' */
    untitled_B.Basesensorblock_o1[0] = untitled_B.Basesensorblock_o1[0] *
      9.80665 / 16384.0;
    untitled_B.Basesensorblock_o1[1] = untitled_B.Basesensorblock_o1[1] *
      9.80665 / 16384.0;
    untitled_B.Basesensorblock_o1[2] = untitled_B.Basesensorblock_o1[2] *
      9.80665 / 16384.0;
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
    if (untitled_DW.obj.InitializationFlag) {
      untitled_DW.obj.InitError = true;
    } else if (untitled_DW.obj.I2CReadWriteError == 0) {
      untitled_DW.obj.I2CReadWriteError = status;
    }
  }

  untitled_B.Basesensorblock_o2[0] = b_RegisterValue[0] << 8 | b_RegisterValue[1];
  untitled_B.Basesensorblock_o2[1] = b_RegisterValue[2] << 8 | b_RegisterValue[3];
  untitled_B.Basesensorblock_o2[2] = b_RegisterValue[4] << 8 | b_RegisterValue[5];
  if (untitled_DW.obj.InitError) {
    /* MATLABSystem: '<S1>/Base sensor block' */
    untitled_B.Basesensorblock_o2[0] = 0.0;
    untitled_B.Basesensorblock_o2[1] = 0.0;
    untitled_B.Basesensorblock_o2[2] = 0.0;
  } else {
    /* MATLABSystem: '<S1>/Base sensor block' */
    untitled_B.Basesensorblock_o2[0] *= 0.00762939453125;
    untitled_B.Basesensorblock_o2[1] *= 0.00762939453125;
    untitled_B.Basesensorblock_o2[2] *= 0.00762939453125;
  }

  status = 65U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj_tmp->I2CDriverObj.MW_I2C_HANDLE, 104UL, &output_raw_0
                      [0], 2UL, false, true);
    memcpy((void *)&b_output[0], (void *)&output_raw_0[0], (size_t)2 * sizeof
           (uint8_T));
  }

  if (status != 0) {
    if (untitled_DW.obj.InitializationFlag) {
      untitled_DW.obj.InitError = true;
    } else if (untitled_DW.obj.I2CReadWriteError == 0) {
      untitled_DW.obj.I2CReadWriteError = status;
    }
  }

  if (untitled_DW.obj.InitError) {
    /* MATLABSystem: '<S1>/Base sensor block' */
    untitled_B.Basesensorblock_o4 = 32U;
  } else {
    /* MATLABSystem: '<S1>/Base sensor block' */
    untitled_B.Basesensorblock_o4 = untitled_DW.obj.I2CReadWriteError;
  }

  /* End of MATLABSystem: '<S1>/Base sensor block' */
  /* End of Outputs for SubSystem: '<Root>/MPU6050 IMU Sensor' */
  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled_M, 10.0);
  untitled_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (3187063797U);
  untitled_M->Sizes.checksums[1] = (895116617U);
  untitled_M->Sizes.checksums[2] = (3826723157U);
  untitled_M->Sizes.checksums[3] = (2996293113U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* SystemInitialize for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* Start for MATLABSystem: '<S1>/Base sensor block' */
  untitled_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
  untitled_DW.obj.matlabCodegenIsDeleted = true;
  u_arduinoMPU6050_arduinoMPU6050(&untitled_DW.obj);

  /* Start for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  untitled_DW.obj.SampleTime = untitled_P.MPU6050IMUSensor_SampleTime;

  /* End of Start for SubSystem: '<Root>/MPU6050 IMU Sensor' */
  untitled_SystemCore_setup(&untitled_DW.obj);

  /* End of SystemInitialize for SubSystem: '<Root>/MPU6050 IMU Sensor' */
}

/* Model terminate function */
void untitled_terminate(void)
{
  i_codertarget_arduinobase_int_T *obj;

  /* Terminate for Atomic SubSystem: '<Root>/MPU6050 IMU Sensor' */
  /* Terminate for MATLABSystem: '<S1>/Base sensor block' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1L) && untitled_DW.obj.isSetupComplete)
    {
      obj = &untitled_DW.obj.i2cObjmpu;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &untitled_DW.obj.i2cObjmpu;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1L) {
      obj->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Base sensor block' */
  /* End of Terminate for SubSystem: '<Root>/MPU6050 IMU Sensor' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
