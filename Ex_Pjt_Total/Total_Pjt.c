/*
 * Course Support License -- for instructional use for courses.  Not for
 * government, research, commercial, or other organizational use.
 *
 * File: Total_Pjt.c
 *
 * Code generated for Simulink model 'Total_Pjt'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri Jan 30 15:48:00 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Total_Pjt.h"
#include <math.h>
#include "rtwtypes.h"

/* Block states (default storage) */
DW_Total_Pjt_T Total_Pjt_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Total_Pjt_T Total_Pjt_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Total_Pjt_T Total_Pjt_Y;

/* Real-time model */
static RT_MODEL_Total_Pjt_T Total_Pjt_M_;
RT_MODEL_Total_Pjt_T *const Total_Pjt_M = &Total_Pjt_M_;

/* Model step function */
void Total_Pjt_step(void)
{
  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/pushSwitch1'
   */
  if (!Total_Pjt_U.pushSwitch1) {
    /* Outport: '<Root>/BLUE_LED' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     *  Sin: '<S1>/Sine Wave'
     */
    Total_Pjt_Y.BLUE_LED = (uint16_T)floor(sin((real_T)Total_Pjt_DW.counter *
      2.0 * 3.1415926535897931 / 300.0) * 25000.0 + 25000.0);
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/sw_unpush' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Outport: '<Root>/BLUE_LED' incorporates:
     *  Constant: '<S1>/Constant'
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     *  SignalConversion generated from: '<S3>/In1'
     */
    Total_Pjt_Y.BLUE_LED = 0U;

    /* End of Outputs for SubSystem: '<S1>/sw_unpush' */
  }

  /* End of If: '<S1>/If' */

  /* Update for Sin: '<S1>/Sine Wave' */
  Total_Pjt_DW.counter++;
  if (Total_Pjt_DW.counter == 300) {
    Total_Pjt_DW.counter = 0;
  }

  /* End of Update for Sin: '<S1>/Sine Wave' */
}

/* Model initialize function */
void Total_Pjt_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Total_Pjt_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
