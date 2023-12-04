
/*
 * Include Files
 *
 */
#include "simstruc.h"



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include "code/fpga.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 18
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
extern void Idx2vec(int idx_1, int idx_2, svm_t *svm_values, vec_t *vec);
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void FPGA_Outputs_wrapper(const real_T *svm,
			const real_T *idx1,
			const real_T *idx2,
			const real_T *period,
			const real_T *cap_errors_v,
			const real_T *in1,
			const real_T *in2,
			real_T *pwm,
			real_T *aux,
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

 if (firsttimeEver ==0){
    for (i = 0; i < 81; i++){
       for (j = 0; j < 9; j++)
       {
           lines_array.array[i][j] = lp[i][j];
       }           
    }
    firsttimeEver =1;
}
    
Tss = *in2;
Idx1 = *idx1;
Idx2 = *idx2;
Periodo = *period;


I.A = in1[0];
I.B = in1[1];
I.C = in1[2];
I.U = in1[3];
I.V = in1[4];
I.W = in1[5];

for (i = 0; i < 9; i++)
{
    cap_errors.array[i] = cap_errors_v[i];
}

SVM.CA1 =  svm[0];
SVM.CA2 =  svm[1];
SVM.CA3 =  svm[2];
SVM.CB1 =  svm[3];
SVM.CB2 =  svm[4];
SVM.CB3 =  svm[5];
SVM.CC1 =  svm[6];
SVM.CC2 =  svm[7];
SVM.CC3 =  svm[8];

SVM.DA1 =  svm[9];
SVM.DA2 =  svm[10];
SVM.DA3 =  svm[11];
SVM.DB1 =  svm[12];
SVM.DB2 =  svm[13];
SVM.DB3 =  svm[14];
SVM.DC1 =  svm[15];
SVM.DC2 =  svm[16];
SVM.DC3 =  svm[17];


Idx2vec(Idx1, Idx2, &SVM, &vec);

vec_L.in.array[0] = vec.in.a - vec.in.b;
vec_L.in.array[1] = vec.in.b - vec.in.c;
vec_L.in.array[2] = vec.in.c - vec.in.a;

vec_L.out.array[0] = vec.out.a - vec.out.b;
vec_L.out.array[1] = vec.out.b - vec.out.c;
vec_L.out.array[2] = vec.out.c - vec.out.a;

int ok = 0;
int value_curto = 0;
int curto_init = curto;
int line, n;


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
calculo fun��o custo
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*/
cost_calc(lines_array, curto , 0, vec_L, I, Tss, cap_errors, &result_cost );


acharxs(result_cost.line, result_cost.curto_pos, result_cost.curto_value , vec_L.in.array[0], vec_L.in.array[1], vec_L.out.array[0], vec_L.out.array[1], &rs_matriz1, &rs_matriz2, &rs_matriz3, &rs_matriz4, &rs_matriz5, &rs_matriz6, &rs_matriz7, &rs_matriz8, &rs_matriz9);
       
if (rs_matriz1 == 1555)   rs_matriz1 = 15; 
if (rs_matriz2 == 1555)   rs_matriz2 = 15;
if (rs_matriz3 == 1555)   rs_matriz3 = 15;
if (rs_matriz4 == 1555)   rs_matriz4 = 15;
if (rs_matriz5 == 1555)   rs_matriz5 = 15;
if (rs_matriz6 == 1555)   rs_matriz6 = 15;
if (rs_matriz7 == 1555)   rs_matriz7 = 15;
if (rs_matriz8 == 1555)   rs_matriz8 = 15;
if (rs_matriz9 == 1555)   rs_matriz9 = 15;


pwm[0] = rs_matriz1;
pwm[1] = rs_matriz2;
pwm[2] = rs_matriz3;
pwm[3] = rs_matriz4;
pwm[4] = rs_matriz5;
pwm[5] = rs_matriz6;
pwm[6] = rs_matriz7;
pwm[7] = rs_matriz8;
pwm[8] = rs_matriz9;


aux[0] = vec_L.in.array[0];
aux[1] = result_cost.line;
aux[2] = result_cost.curto_pos;
aux[3] = result_cost.curto_value;
aux[4] = vec_L.out.array[1];
aux[5] = vec_L.out.array[2];
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


