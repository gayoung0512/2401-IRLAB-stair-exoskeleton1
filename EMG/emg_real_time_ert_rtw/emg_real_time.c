/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: emg_real_time.c
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

#include "emg_real_time.h"
#include "emg_real_time_types.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_emg_real_time_T emg_real_time_DW;

/* Real-time model */
static RT_MODEL_emg_real_time_T emg_real_time_M_;
RT_MODEL_emg_real_time_T *const emg_real_time_M = &emg_real_time_M_;

/* Model step function */
void emg_real_time_step(void)
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_inter_T *obj;
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (emg_real_time_DW.obj_i.SampleTime !=
      emg_real_time_P.AnalogInput_SampleTime) {
    emg_real_time_DW.obj_i.SampleTime = emg_real_time_P.AnalogInput_SampleTime;
  }

  obj = &emg_real_time_DW.obj_i;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (emg_real_time_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     datatype_id);

  /* End of MATLABSystem: '<Root>/Analog Input' */

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (emg_real_time_DW.obj.SampleTime != emg_real_time_P.AnalogInput1_SampleTime)
  {
    emg_real_time_DW.obj.SampleTime = emg_real_time_P.AnalogInput1_SampleTime;
  }

  obj = &emg_real_time_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (emg_real_time_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     datatype_id);

  /* End of MATLABSystem: '<Root>/Analog Input1' */
}

/* Model initialize function */
void emg_real_time_initialize(void)
{
  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    emg_real_time_DW.obj_i.matlabCodegenIsDeleted = false;
    emg_real_time_DW.obj_i.SampleTime = emg_real_time_P.AnalogInput_SampleTime;
    obj = &emg_real_time_DW.obj_i;
    emg_real_time_DW.obj_i.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    emg_real_time_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    emg_real_time_DW.obj.matlabCodegenIsDeleted = false;
    emg_real_time_DW.obj.SampleTime = emg_real_time_P.AnalogInput1_SampleTime;
    obj = &emg_real_time_DW.obj;
    emg_real_time_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15UL);
    emg_real_time_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void emg_real_time_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &emg_real_time_DW.obj_i;
  if (!emg_real_time_DW.obj_i.matlabCodegenIsDeleted) {
    emg_real_time_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((emg_real_time_DW.obj_i.isInitialized == 1L) &&
        emg_real_time_DW.obj_i.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (emg_real_time_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  obj = &emg_real_time_DW.obj;
  if (!emg_real_time_DW.obj.matlabCodegenIsDeleted) {
    emg_real_time_DW.obj.matlabCodegenIsDeleted = true;
    if ((emg_real_time_DW.obj.isInitialized == 1L) &&
        emg_real_time_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close
        (emg_real_time_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
