
/*
 * Include Files
 *
 */
#include "simstruc.h"



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include "code/modulation.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 3
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void modulation_Outputs_wrapper(const real_T *in1,
			const real_T *in2,
			const real_T *in3,
			real_T *out,
			real_T *idx,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */

  Ts =1/2000;
  N =in3[1];

  //Gm=ceil((N-1)/2);

  Vin[0] = 1.0*in1[0];
  Vin[1] = 1.0*in1[1];
  Vin[2] = 1.0*in1[2];


  Vout[0] = 1*in2[0];
  Vout[1] = 1*in2[1];
  Vout[2] = 1*in2[2];  

  calculate_SVM(Vin, &duty_in, &PWM_in);
  calculate_SVM(Vout, &duty_out, &PWM_out);

  Ta = (duty_in.ul) ;
  Tb = (duty_in.ul + duty_in.lu) ;
  //dzeroin = Ts - Ta - Tb;

  Tc = (duty_out.ul) ;
  Td = (duty_out.ul + duty_out.lu) ;
  //dzeroout = Ts - Tc - Td;
  
  out[0] = PWM_in.CA1;
  out[1] = PWM_in.CA2;
  out[2] = PWM_in.CA3;
  out[3] = PWM_in.CB1;
  out[4] = PWM_in.CB2;
  out[5] = PWM_in.CB3;
  out[6] = PWM_in.CC1;
  out[7] = PWM_in.CC2;
  out[8] = PWM_in.CC3;

  out[9] = PWM_out.CA1;
  out[10] = PWM_out.CA2;
  out[11] = PWM_out.CA3;
  out[12] = PWM_out.CB1;
  out[13] = PWM_out.CB2;
  out[14] = PWM_out.CB3;
  out[15] = PWM_out.CC1;
  out[16] = PWM_out.CC2;
  out[17] = PWM_out.CC3;

  idx[0] = Ta;
  idx[1] = Tb;

  idx[2] = Tc;
  idx[3] = Td;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


