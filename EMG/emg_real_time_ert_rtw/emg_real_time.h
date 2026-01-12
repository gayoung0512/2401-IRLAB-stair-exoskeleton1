/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: emg_real_time.h
 *
 * Code generated for Simulink model 'emg_real_time'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Aug 13 22:48:15 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_emg_real_time_h_
#define RTW_HEADER_emg_real_time_h_
#ifndef emg_real_time_COMMON_INCLUDES_
#define emg_real_time_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#endif                                 /* emg_real_time_COMMON_INCLUDES_ */

#include "emg_real_time_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_i;/* '<Root>/Analog Input' */
} DW_emg_real_time_T;

/* Parameters (default storage) */
struct P_emg_real_time_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: 0.01
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_emg_real_time_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_emg_real_time_T emg_real_time_P;

/* Block states (default storage) */
extern DW_emg_real_time_T emg_real_time_DW;

/* Model entry point functions */
extern void emg_real_time_initialize(void);
extern void emg_real_time_step(void);
extern void emg_real_time_terminate(void);

/* Real-time Model object */
extern RT_MODEL_emg_real_time_T *const emg_real_time_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
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
 * '<Root>' : 'emg_real_time'
 */
#endif                                 /* RTW_HEADER_emg_real_time_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
