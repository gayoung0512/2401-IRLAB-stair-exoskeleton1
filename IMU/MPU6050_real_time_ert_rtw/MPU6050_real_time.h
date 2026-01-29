/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MPU6050_real_time.h
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

#ifndef RTW_HEADER_MPU6050_real_time_h_
#define RTW_HEADER_MPU6050_real_time_h_
#ifndef MPU6050_real_time_COMMON_INCLUDES_
#define MPU6050_real_time_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#include "io_wrappers.h"
#endif                                 /* MPU6050_real_time_COMMON_INCLUDES_ */

#include "MPU6050_real_time_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Basesensorblock_o1[3];        /* '<S2>/Base sensor block' */
  real_T Basesensorblock_o2[3];        /* '<S2>/Base sensor block' */
  real_T Basesensorblock_o1_o[3];      /* '<S1>/Base sensor block' */
  real_T Basesensorblock_o2_j[3];      /* '<S1>/Base sensor block' */
  uint8_T Basesensorblock_o3;          /* '<S2>/Base sensor block' */
  uint8_T Basesensorblock_o3_h;        /* '<S1>/Base sensor block' */
} B_MPU6050_real_time_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S2>/Base sensor block' */
  codertarget_arduinobase_inter_T obj_d;/* '<S1>/Base sensor block' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */
} DW_MPU6050_real_time_T;

/* Parameters (default storage) */
struct P_MPU6050_real_time_T_ {
  real_T MPU6050IMUSensor_SampleTime;
                                  /* Mask Parameter: MPU6050IMUSensor_SampleTime
                                   * Referenced by: '<S1>/Base sensor block'
                                   */
  real_T MPU6050IMUSensor1_SampleTime;
                                 /* Mask Parameter: MPU6050IMUSensor1_SampleTime
                                  * Referenced by: '<S2>/Base sensor block'
                                  */
};

/* Real-time Model Data Structure */
struct tag_RTM_MPU6050_real_time_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_MPU6050_real_time_T MPU6050_real_time_P;

/* Block signals (default storage) */
extern B_MPU6050_real_time_T MPU6050_real_time_B;

/* Block states (default storage) */
extern DW_MPU6050_real_time_T MPU6050_real_time_DW;

/* Model entry point functions */
extern void MPU6050_real_time_initialize(void);
extern void MPU6050_real_time_step(void);
extern void MPU6050_real_time_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MPU6050_real_time_T *const MPU6050_real_time_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Bias' : Unused code path elimination
 * Block '<Root>/Bias1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MPU6050_real_time'
 * '<S1>'   : 'MPU6050_real_time/MPU6050 IMU Sensor'
 * '<S2>'   : 'MPU6050_real_time/MPU6050 IMU Sensor1'
 */
#endif                                 /* RTW_HEADER_MPU6050_real_time_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
