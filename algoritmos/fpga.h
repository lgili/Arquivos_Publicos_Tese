
#include "structures.h"

#include "simstruc.h"
#include <math.h>
#include <stdio.h>
//#include "modulation.h"

void Idx2vec(int idx_1, int idx_2, svm_t *svm_values, vec_t *vec);
static int findMin(int vec[3]);
static int findMax(array_double_t vec);
void solve_pwm(int curto, int VinL[3], int VoutL[3], int Value2Curto, array_t *xls);
void cost_calc(array_lines_t lines_array, int pos_curto_u, int curto_value, vec_array_t vec_L, vars_for_modules_t I, double ts, array_double_t cap_errors, result_cost_t *result_cost);


void solveX(int matriz[4][5], int *x1, int *x2, int *x3, int *x4);
void acharxs(int line, int curto1, int value_curto, int rs2, int rs3, int rs4, int rs5, int *x1, int *x2, int *x3, int *x4, int *x5, int *x6, int *x7, int *x8, int *x9);
void acharxsold(int line, int curto1, int value_curto, int rs2, int rs3, int rs4, int rs5, int *x1, int *x2, int *x3, int *x4, int *x5, int *x6, int *x7, int *x8, int *x9);

void achacurto(int line, int *curto1, int *curto2, int *curto3, int *curto4, int *curto5);

void correntes(int line, double Ia, double Ib, double Ic, double Iu, double Iv, double Iw, double *cx1, double *cx2, double *cx3, double *cx4, double *cx5, double *cx6, double *cx7, double *cx8, double *cx9);


int Vab_Calc[81][9] = {
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, -1, 0, -1, 1, 0},
    {1, 0, 0, 0, 0, -1, -1, 0, 1},
    {0, 1, 0, -1, 0, 0, 1, -1, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, -1, 0, -1, 1},
    {0, 0, 1, -1, 0, 0, 1, 0, -1},
    {0, 0, 1, 0, -1, 0, 0, 1, -1},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, -1, 0, -1, 1, 0},
    {1, 0, 0, 0, 0, -1, -1, 0, 1},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, -1, 0, 0, 1, -1, 0},
    {0, 1, 0, 0, 0, -1, 0, -1, 1},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 0, 1, -1, 0, 0, 1, 0, -1},
    {0, 0, 1, 0, -1, 0, 0, 1, -1},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, -1, -1, 0, 1},
    {0, 1, 0, 0, 0, -1, 0, -1, 1},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, -1, 0, -1, 1, 0},
    {0, 0, 1, 0, -1, 0, 0, 1, -1},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 1, 0, -1, 0, 0, 1, -1, 0},
    {0, 0, 1, -1, 0, 0, 1, 0, -1},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {1, 0, 0, -1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 1, 0, 0, -1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
    {0, 0, 1, 0, 0, -1, 0, 0, 0},
};
int Vbc_Calc[81][9] = {
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {-1, 1, 0, 1, 0, 0, 0, -1, 0},
    {1, -1, 0, 0, 1, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {-1, 0, 1, 1, 0, 0, 0, 0, -1},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {1, 0, -1, 0, 0, 1, -1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, -1, 1, 0, 1, 0, 0, 0, -1},
    {0, 1, -1, 0, 0, 1, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {-1, 1, 0, 1, 0, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {1, -1, 0, 0, 1, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {-1, 0, 1, 1, 0, 0, 0, 0, -1},
    {1, 0, -1, 0, 0, 1, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, -1, 1, 0, 1, 0, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {0, 1, -1, 0, 0, 1, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
    {0, 0, 0, 1, 0, 0, -1, 0, 0},
    {-1, 1, 0, 1, 0, 0, 0, -1, 0},
    {-1, 0, 1, 1, 0, 0, 0, 0, -1},
    {1, -1, 0, 0, 1, 0, -1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, -1, 0},
    {0, -1, 1, 0, 1, 0, 0, 0, -1},
    {1, 0, -1, 0, 0, 1, -1, 0, 0},
    {0, 1, -1, 0, 0, 1, 0, -1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, -1},
};
int Vrs_Calc[81][9] = {
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, -1, 0, 1, 0, 1, -1},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, 0, 1, -1, -1, 0, 1},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, -1, 0, 1, 0, 1, -1},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, 0, 1, -1, -1, 0, 1},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, -1, 0, 1, 0, 1, -1},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 0, 0, 0, 1, -1, -1, 0, 1},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {-1, 0, 1, 0, 0, 0, 0, 1, -1},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {-1, 0, 1, 0, 0, 0, 0, 1, -1},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {-1, 0, 1, 0, 0, 0, 0, 1, -1},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 1, -1, 0, 0, 0, -1, 0, 1},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 1, -1, 0, 0, 0, -1, 0, 1},
    {0, 0, 0, 0, 0, 0, -1, 1, 0},
    {0, 1, -1, 0, 0, 0, -1, 0, 1},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {-1, 0, 1, 0, 1, -1, 0, 0, 0},
    {-1, 0, 1, 0, 1, -1, 0, 0, 0},
    {-1, 0, 1, 0, 1, -1, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 0, 0, -1, 1, 0, 0, 0, 0},
    {0, 1, -1, -1, 0, 1, 0, 0, 0},
    {0, 1, -1, -1, 0, 1, 0, 0, 0},
    {0, 1, -1, -1, 0, 1, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 0, 0, 0, 0, 0, 0, 0},
};
int Vst_Calc[81][9] = {
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, 0, 0, 0, 0, 0, 0 - 1, 1},
    {0, 0, 0, 0, 0, 0, 0 - 1, 1},
    {0, 0, 0, 0, 0, 0, 0 - 1, 1},
    {0, 0, 0, 0, 0, 0, 0 - 1, 1},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, 0, 0, 1, -1, 0, -1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, 0, 0, -1, 0, 1, 1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, -1, 0, 1},
    {0, 0, 0, 0, 0, 0, -1, 0, 1},
    {0, 0, 0, -1, 0, 1, 1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, 0, 0, -1, 0, 1, 1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {1, -1, 0, 0, 0, 0, -1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {1, -1, 0, 0, 0, 0, -1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {1, -1, 0, 0, 0, 0, -1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {-1, 0, 1, 0, 0, 0, 1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {-1, 0, 1, 0, 0, 0, 1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {-1, 0, 1, 0, 0, 0, 1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, -1, 1},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {1, -1, 0, -1, 0, 1, 0, 0, 0},
    {1, -1, 0, -1, 0, 1, 0, 0, 0},
    {1, -1, 0, -1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {-1, 0, 1, 1, -1, 0, 0, 0, 0},
    {-1, 0, 1, 1, -1, 0, 0, 0, 0},
    {-1, 0, 1, 1, -1, 0, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, 0, 0, 0, -1, 1, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0},
};

int lp[81][9] = {
    {1, 0, 0, 1, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 1, 1},
    {0, 1, 0, 1, 0, 0, 1, 1, 1},
    {0, 1, 0, 0, 1, 0, 1, 1, 1},
    {0, 1, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 1, 1, 0, 0, 1, 1, 1},
    {0, 0, 1, 0, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 1, 1},
    {1, 0, 0, 1, 0, 1, 1, 1, 0},
    {1, 0, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1, 0, 1, 0, 1},
    {0, 1, 0, 1, 1, 0, 0, 1, 1},
    {0, 1, 0, 1, 0, 1, 1, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 1},
    {0, 1, 0, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 1, 1, 0, 1},
    {0, 0, 1, 1, 1, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 1, 1, 0, 1, 0, 1, 1},
    {0, 0, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 1, 1, 0, 1, 0},
    {1, 0, 0, 1, 1, 1, 0, 0, 1},
    {0, 1, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 1, 1, 1, 0, 0, 1},
    {0, 0, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 1, 0, 1, 0, 0, 1, 0, 1},
    {1, 1, 0, 1, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 0, 0, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 1, 0, 1, 1},
    {1, 0, 1, 1, 0, 0, 1, 1, 0},
    {1, 0, 1, 1, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0},
    {1, 0, 1, 0, 1, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 1, 1, 1, 0},
    {1, 0, 1, 0, 0, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 0, 1, 1, 0},
    {0, 1, 1, 1, 0, 0, 1, 0, 1},
    {0, 1, 1, 0, 1, 0, 1, 1, 0},
    {0, 1, 1, 0, 1, 0, 1, 0, 1},
    {0, 1, 1, 0, 0, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0, 1, 1, 0, 0},
    {1, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1, 1, 1, 0, 0},
    {1, 1, 0, 0, 1, 1, 0, 1, 0},
    {1, 1, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 0},
    {1, 0, 1, 1, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 1, 0, 1, 0},
    {1, 0, 1, 0, 1, 1, 0, 0, 1},
    {0, 1, 1, 1, 1, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 0, 0, 1, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 0, 0, 1, 0, 1, 0},
    {1, 1, 1, 0, 0, 1, 0, 0, 1},
};

int erros[91][2] = {
    {1, 4},
    {4, 2},
    {4, 4},
    {5, 2},
    {6, 2},
    {7, 4},
    {10, 4},
    {11, 4},
    {12, 4},
    {13, 4},
    {16, 2},
    {16, 4},
    {17, 2},
    {17, 4},
    {18, 2},
    {18, 4},
    {19, 2},
    {19, 4},
    {20, 2},
    {21, 2},
    {22, 4},
    {23, 4},
    {24, 4},
    {25, 4},
    {28, 4},
    {29, 4},
    {30, 4},
    {31, 2},
    {31, 4},
    {32, 2},
    {32, 4},
    {33, 2},
    {33, 4},
    {34, 4},
    {35, 4},
    {36, 4},
    {37, 2},
    {37, 4},
    {37, 7},
    {38, 2},
    {38, 4},
    {39, 2},
    {40, 2},
    {41, 2},
    {42, 2},
    {43, 4},
    {44, 4},
    {49, 2},
    {49, 4},
    {50, 2},
    {50, 4},
    {51, 2},
    {52, 2},
    {53, 2},
    {54, 2},
    {55, 2},
    {55, 4},
    {56, 2},
    {56, 4},
    {57, 2},
    {57, 4},
    {58, 2},
    {59, 2},
    {60, 2},
    {61, 4},
    {62, 4},
    {63, 4},
    {67, 2},
    {67, 4},
    {68, 2},
    {68, 4},
    {69, 2},
    {69, 4},
    {70, 2},
    {70, 4},
    {71, 2},
    {71, 4},
    {72, 2},
    {72, 4},
    {73, 2},
    {73, 4},
    {74, 2},
    {74, 4},
    {75, 2},
    {75, 4},
    {76, 2},
    {77, 2},
    {78, 2},
    {79, 2},
    {80, 2},
    {81, 2}};

int Idx1, Idx2, Periodo;

int VinL[3], VoutL[3];
int pos_vec_in = 0, pos_vec_out = 0;
int first_time = 0;
int curto = 0;
int t11;

// int *xls_p;

array_double_t cap_errors;
double Tss;

// Função custo
array_curto_size_t index_lista_ES;
array_curto_size_t z;
int first_time2 = 0;
int value_curto = 0;
int VL[4];
int xs[9];
result_cost_t result_cost;

////////
int rs_matriz1 = 0, rs_matriz2 = 0, rs_matriz3 = 0, rs_matriz4 = 0, rs_matriz5 = 0, rs_matriz6 = 0, rs_matriz7 = 0, rs_matriz8 = 0, rs_matriz9 = 0;
int firsttimeEver = 0;
vars_for_modules_t I;
vec_t vec;
vec_array_t vec_L;
array_t xls_p = {.array = {0, 0, 0, 0, 0, 0, 0, 0, 0}};
array_lines_t lines_array;

int j5,l,m,n,i,A1,ii,j,i1;
svm_t SVM;

void solveX(int a[4][5], int *x1, int *x2 , int *x3, int *x4)
{
   

    int n=4,i,j,k;
    int  x[4];        //declare an array to store the elements of augmented-matrix
    /*for (i=0;i<n;i++)
        for (j=0;j<=n;j++)
            //cin>>a[i][j];    //input the elements of array
            a[i][j] = matriz[i][j];*/

    
          

    for (i=0;i<n;i++)                    //Pivotisation
        for (k=i+1;k<n;k++)
            if (abs(a[i][i])<abs(a[k][i]))
                for (j=0;j<=n;j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }

    /*ssPrintf("\n");
    for (int i = 0; i < 4; i++)
    {
       for (int k = 0; k < 5; k++)
       {
          ssPrintf("%d",a[i][k]);          
       }        
    }    */          
    /*cout<<"\nThe matrix after Pivotisation is:\n";
    for (i=0;i<n;i++)            //print the new matrix
    {
        for (j=0;j<=n;j++)
            cout<<a[i][j];
        cout<<"\n";
    }*/
    for (i=0;i<n-1;i++)            //loop to perform the gauss elimination
        for (k=i+1;k<n;k++)
        {
            double t=a[k][i]/a[i][i];
            for (j=0;j<=n;j++)
                a[k][j]=a[k][j]-t*a[i][j];    //make the elements below the pivot elements equal to zero or elimnate the variables
        }

    /*cout<<"\n\nThe matrix after gauss-elimination is as follows:\n";
    for (i=0;i<n;i++)            //print the new matrix
    {
        for (j=0;j<=n;j++)
            cout<<a[i][j];
        cout<<"\n";
    }*/
    for (i=n-1;i>=0;i--)                //back-substitution
    {                        //x is an array whose values correspond to the values of x,y,z..
        x[i]=a[i][n];                //make the variable to be calculated equal to the rhs of the last equation
        for (j=i+1;j<n;j++)
            if (j!=i)            //then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
                x[i]=x[i]-a[i][j]*x[j];
        x[i]=x[i]/a[i][i];            //now finally divide the rhs by the coefficient of the variable to be calculated
    }
    //////////////////
    /*ssPrintf("X1-");
    ssPrintf("%d\n",x[0]);
    ssPrintf("\n");
    ssPrintf("X2-");
    ssPrintf("%d\n",x[1]);
    ssPrintf("\n");
    ssPrintf("X3-");
    ssPrintf("%d\n",x[2]);
    ssPrintf("\n");
    ssPrintf("X4-");
    ssPrintf("%d\n",x[3]);
    ssPrintf("\n");*/

    /*if (abs(x[0]) > 6 || abs(x[1]) > 6 || abs(x[2]) > 6 || abs(x[3]) > 6)
    {
        *x1 = 0;
        *x2 = 0;
        *x3 = 0;
        *x4 = 0;
    }*/
    //else
    //{
        if(x[0] == 0)
        {
            *x1 = 15;
        }        
        else
        {
            *x1 = x[0];
        }
        //////////////////
        if(x[1] == 0)
        {
            *x2 = 15;
        }        
        else
        {
            *x2 = x[1];
        }
        //////////////////
        if(x[2] == 0)
        {
            *x3 = 15;
        }        
        else
        {
            *x3 = x[2];
        }

        //////////////////
        if(x[3] == 0)
        {
            *x4 = 15;
        }        
        else
        {
            *x4 = x[3];
        }
    //}
    

}


/*
* Function: findMin
* ----------------------------
*   Returns the minimal value from a vector
*
*   vec: int vector   
*
*   returns: minimal value from vec 
*/
static int findMin(int vec[3])
{
    int min = 10e4;
    int pos;

    for ( j5 = 0; j5 < 3; j5++)
    {
        if (vec[j5] < min)
        {
            min = vec[j5];
            pos = j5;
        }
    }
    return pos;
}

static int findMax(array_double_t vec)
{
    int max = -10e4;
    int pos;

    for ( j5 = 0; j5 < 9; j5++)
    {
        if (vec.array[j5] > max)
        {
            max = vec.array[j5];
            pos = j5;
        }
    }
    
    
    return pos;
}

    /*
 * Function: solve_pwm
 * ----------------------------
 *   Returns the value to the nine modules of converter
 *
 *   curto: int value that represents the curto of sistem 
 *   VinL:  input voltages
 *   VoutL: output voltages   
 *
 *   returns: value of level to nine modules 
 */
void solve_pwm(int curto, int VinL[3], int VoutL[3], int Value2Curto, array_t *xls)
{
    int cont_vars = 0, never_enterVab = 0, never_enterVbc = 0, never_enterVrs = 0, never_enterVst = 0;
    int Vab[9], Vbc[9], Vrs[9], Vst[9], linhaVars[9];
    int vars_Used[9];
    int matrix[4][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    //int xsl[9] = {0,0,0,0,0,0,0,0,0};
    int var1 = 0, var2 = 0, var3 = 0, var4 = 0;

    //int Value2Subs = 0; //value to choose

    for ( l = 0; l < 9; ++l)
    {
        Vab[l] = Vab_Calc[0][l];
        Vbc[l] = Vbc_Calc[0][l];
        Vrs[l] = Vrs_Calc[0][l];
        Vst[l] = Vst_Calc[0][l];
        linhaVars[l] = lp[0][l];

        if ((lp[0][l] == 1) && (l != curto))
        { // salva qual vão ser as variaveis depois sem o curto
            vars_Used[cont_vars] = l;
            cont_vars++;
        }
    }
    // clear var matriz
    /*for (int i = 0; i < 4; i++){
    for (int k = 0; k < 5; k++){
        matrix[i][k]= 0;
    }        
    }*/

        for ( m = 0; m < 9; ++m)
        {
            if ((Vab[m] != 0))
            {
                /*
        * se for o curto quero definir um valor pra ele, passa para depois do = negativo.
        * Esse valor pode ser qualquer um, é isso que quero testar pra ver sse ajuda na modulação
        * O maximo desse valor é o número de niveis do conversor 
        */
                if (m == curto)
                {
                    matrix[0][4] = VinL[0] - Value2Curto;
                    never_enterVab = 1;
                }
                else
                {
                    for ( l = 0; l < 4; ++l)
                    {
                        if (m == vars_Used[l])
                            matrix[0][l] = Vab[m];
                    }
                }
            }

            if (Vbc[m] != 0)
            {
                if (m == curto)
                {
                    matrix[1][4] = VinL[1] - Value2Curto;
                    never_enterVbc = 1;
                }
                else
                {
                    for ( l = 0; l < 4; ++l)
                    {
                        if (m == vars_Used[l])
                            matrix[1][l] = Vbc[m];
                    }
                }
            }

            if ((Vrs[m] != 0))
            {
                if (m == curto)
                {
                    matrix[2][4] = VoutL[0] - Value2Curto;
                    never_enterVrs = 1;
                }
                else
                {
                    for ( l = 0; l < 4; ++l)
                    {
                        if (m == vars_Used[l])
                            matrix[2][l] = Vrs[m];
                    }
                }
            }

            if ((Vst[m] != 0))
            {
                if (m == curto)
                {
                    matrix[3][4] = VoutL[1] - Value2Curto;
                    never_enterVst = 1;
                }
                else
                {
                    for ( l = 0; l < 4; ++l)
                    {
                        if (m == vars_Used[l])
                            matrix[3][l] = Vst[m];
                    }
                }
            }
        }

        if (never_enterVab == 0)
            matrix[0][4] = VinL[0];
        if (never_enterVbc == 0)
            matrix[1][4] = VinL[1];
        if (never_enterVrs == 0)
            matrix[2][4] = VoutL[0];
        if (never_enterVst == 0)
            matrix[3][4] = VoutL[1];

        solveX(matrix, &var1, &var2, &var3, &var4);

        for ( i = 0; i < 9; i++)
        {
            xls->array[i] = 0;
        }
        xls->array[vars_Used[0]] = var1;
        xls->array[vars_Used[1]] = var2;
        xls->array[vars_Used[2]] = var3;
        xls->array[vars_Used[3]] = var4;
        /*if (var1 ==0 && var2 ==0 && var3 ==0 && var4 ==0){
        xls->array[curto] = 0;
    }
    else{
        xls->array[curto] = 15;
    }*/
    if (Value2Curto == 0)
    {
        xls->array[curto] = 15;
    }
    else
    {
        xls->array[curto] = Value2Curto;
    }
}


/*
 * Function: Idx2vec
 * ----------------------------
 *   Returns vector based on Idxs
 *
 *   idx_1: Idx from the input 
 *   idx_2:  Idx from the output
 *   svm_values: signal from the modulation   
 *
 *   returns: vec the represent the value atual to use em calculus 
 */
void Idx2vec(int idx_1, int idx_2, svm_t *svm_values, vec_t *vec)
{
    if (idx_1 == 2)
    {
        vec->in.a = svm_values->CA1;
        vec->in.b = svm_values->CA2;
        vec->in.c = svm_values->CA3;
    }
    else if (idx_1 == 1)
    {
        vec->in.a = svm_values->CB1;
        vec->in.b = svm_values->CB2;
        vec->in.c = svm_values->CB3;
    }
    else if (idx_1 == 0)
    {
        vec->in.a = svm_values->CC1;
        vec->in.b = svm_values->CC2;
        vec->in.c = svm_values->CC3;
    }

    if ((idx_2 == 2)) // || (idx_2 == 3))
    {
        vec->out.a = svm_values->DA1;
        vec->out.b = svm_values->DA2;
        vec->out.c = svm_values->DA3;
    }
    else if ((idx_2 == 1))
    {
        vec->out.a = svm_values->DB1;
        vec->out.b = svm_values->DB2;
        vec->out.c = svm_values->DB3;
    }
    else if ((idx_2 == 0)) // || (idx_2 == 4))
    {
        vec->out.a = svm_values->DC1;
        vec->out.b = svm_values->DC2;
        vec->out.c = svm_values->DC3;
    }
}



void cost_calc(array_lines_t lines_array, int pos_curto_u, int curto_value, vec_array_t vec_L, vars_for_modules_t I, double ts, array_double_t cap_errors ,result_cost_t *result_cost )
    {
        int line=0, a=0;
        //int index_lista_ES_durty[5265];
        int  cont_index = 0, line_cont = 0;
        double min_Es = 1e20, Es = 0, C = 0;
        double  DeltaV[9], Isub_cal[9];
        //double lista_ES_fixa[5265],lista_ES[5265],
        int max_N =6;
        int cont=0,t11;
        int curto, curto_v;
        int index_error_cap=0;
        array_double_t cx;
        array_t xls;
        result_cost_t result_cost_inter;
        //int array_size= 405;
        cont = 0;
        int curto_v_Min =0;
        int curto_v_Max =0;
        //curto_v =0;
        //curto = 1;

        index_error_cap = findMax(cap_errors);
        if (index_error_cap == 0 || index_error_cap ==1 || index_error_cap == 2)
        {
            if (I.A > 0)
            {
                curto_v_Min =0;
                curto_v_Max =6;
            }
            else
            {
                curto_v_Min =-6;
                curto_v_Max =-1;
            }     
            
        }
        else if (index_error_cap == 3 || index_error_cap == 4 || index_error_cap == 5)
        {
            if (I.B > 0)
            {
                curto_v_Min =0;
                curto_v_Max =6;
            }
            else
            {
                curto_v_Min =-6;
                curto_v_Max =-1;
            }            
        }
        else if (index_error_cap == 6 || index_error_cap == 7 || index_error_cap == 8)
        {
            if (I.C > 0)
            {
                curto_v_Min =0;
                curto_v_Max =6;
            }
            else
            {
                curto_v_Min =-6;
                curto_v_Max =-1;
            } 
        }


        for (curto_v = curto_v_Min;curto_v <= curto_v_Max; curto_v++)
        {
                   
            for (curto = 0; curto < 1; curto++)
            {               

                curto = index_error_cap;
                t11 = 0;
                for ( A1 = 0; A1 < 81; A1++)
                {
                    if ((lines_array.array[A1][curto] == 1))
                    {
                        z.array[t11] = A1;
                        t11++;
                    }
                }

                for ( n = 0; n < 45; ++n)
                {
                    line = z.array[n];
                                    

                    /////////////////////////////////////////////////////////////////////////
                    acharxs(line, curto, curto_v, vec_L.in.array[0], vec_L.in.array[1], vec_L.out.array[0], vec_L.out.array[1], &xls.array[0], &xls.array[1], &xls.array[2], &xls.array[3], &xls.array[4], &xls.array[5], &xls.array[6], &xls.array[7], &xls.array[8]);
                    if (((xls.array[0] > max_N) && (xls.array[0] != 1555)) || ((xls.array[1] > max_N) && (xls.array[1] != 1555)) || ((xls.array[2] > max_N) && (xls.array[2] != 1555)) || ((xls.array[3] > max_N) && (xls.array[3] != 1555)) || ((xls.array[4] > max_N) && (xls.array[4] != 1555)) || ((xls.array[5] > max_N) && (xls.array[5] != 1555)) || ((xls.array[6] > max_N) && (xls.array[6] !=1555)) || ((xls.array[7] > max_N) && (xls.array[7] != 1555)) || ((xls.array[8] > max_N) & (xls.array[8] != 1555)) || (xls.array[0] < -max_N) || (xls.array[1] < -max_N) || (xls.array[2] < -max_N) || (xls.array[3] < -max_N) || (xls.array[4] < -max_N) || (xls.array[5] < -max_N) || (xls.array[6] < -max_N) || (xls.array[7] < -max_N) || (xls.array[8] < -max_N))
                    {
                        Es = 1e20;
                    }
                    else
                    {
                        for ( i1 = 0; i1 < 9; ++i1)
                        {
                            if (xls.array[i1] == 1555)
                                xls.array[i1] = 0; 
                        }
                        C = 3 * 680e-6;
                        Es = 0;

                        correntes(line, I.A, I.B, I.C, I.U, I.V, I.W, &cx.array[0], &cx.array[1], &cx.array[2], &cx.array[3], &cx.array[4], &cx.array[5], &cx.array[6], &cx.array[7], &cx.array[8]);
                        for ( i = 0; i < 9; i++)
                        {
                            Isub_cal[i] = cx.array[i] * (xls.array[i]);
                        }
                                        
                        for ( i1 = 0; i1 < 9; ++i1)
                        {
                            DeltaV[i1] = (Isub_cal[i1] * ts) / C;
                            Es = Es + pow(((cap_errors.array[i1]) + DeltaV[i1]), 2);
                        } 
                        
                    }
                                        

                    //lista_ES[cont] = Es;
                    //lista_ES_fixa[cont] = Es;
                    if (Es <= min_Es )
                    {
                        min_Es = Es;
                        //pos_Es = n;
                        result_cost_inter.curto_pos = curto;
                        result_cost_inter.curto_value = curto_v;
                        result_cost_inter.line = line;
                    }
                    //cont = cont+1;
                
                }
            }
        }
        
       
      /* for (int i1 = 0; i1 < array_size; ++i1)
        {
            for (int j5 = i1 + 1; j5 < array_size; ++j5)
            {
                if (lista_ES[i1] > lista_ES[j5])
                {
                    a = lista_ES[i1];
                    lista_ES[i1] = lista_ES[j5];
                    lista_ES[j5] = a;
                }
            }
        }*/

        /*pegar em ordem os indices
      */
        /*cont_index = 0;
        for (int i1 = 0; i1 < array_size; ++i1)
        {
            for (int k1 = 0; k1 < array_size; ++k1)
            {
                if (lista_ES[i1] == lista_ES_fixa[k1])
                {

                    //index_lista_ES->array[cont_index] = k1;
                    index_lista_ES_durty[cont_index] = k1;
                    cont_index = cont_index + 1;
                }
            }
        }*/

        /*for (int i = 0; i < 45; i++)
        {
            result_cost->array[i] = index_lista_ES_durty[i];
        }*/

        result_cost->curto_pos = result_cost_inter.curto_pos;
        result_cost->curto_value = result_cost_inter.curto_value;
        result_cost->line = result_cost_inter.line;
        
    }


void correntes(int line,double Ia,double Ib,double Ic,double Iu,double Iv,double Iw, double *cx1, double *cx2, double *cx3, double *cx4, double *cx5, double *cx6, double *cx7,double *cx8,double *cx9)
{
	switch (line)
	{
    case 0:

            *cx1=Ia;
            *cx2=0;
            *cx3=0;
            *cx4=Ib;
            *cx5=0;
            *cx6=0;
            *cx7=-Ia-Ib-Iu;
            *cx8=-Iv;
            *cx9=-Iw;
         break;

    case 1:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Ia-Iu;
        *cx8=-Ib-Iv;
        *cx9=-Iw;
     break;

    case 2:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Ia-Iu;
        *cx8=-Iv;
        *cx9=-Ib-Iw;
     break;

    case 3:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ib-Iu;
        *cx8=-Ia-Iv;
        *cx9=-Iw;
     break;

    case 4:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Iu;
        *cx8=-Ia-Ib-Iv;
        *cx9=-Iw;
     break;

    case 5:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Iu;
        *cx8=-Ia-Iv;
        *cx9=-Ib-Iw;
     break;

    case 6:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ib-Iu;
        *cx8=-Iv;
        *cx9=-Ia-Iw;
     break;

    case 7:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Iu;
        *cx8=-Ib-Iv;
        *cx9=-Ia-Iw;
     break;

    case 8:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Iu;
        *cx8=-Iv;
        *cx9=-Ia-Ib-Iw;
     break;


     case 9:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=Ib+Iv;
        *cx5=-Iv;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv;
        *cx8=0;
        *cx9=-Iw;
     break;

    case 10:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=-Ia-Iu;
        *cx5=Ia+Ib+Iu;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv;
        *cx9=-Iw;
     break;

    case 11:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=Ib+Iw;
        *cx5=0;
        *cx6=-Iw;
        *cx7=-Ia-Ib-Iu-Iw;
        *cx8=-Iv;
        *cx9=0;
     break;
    case 12:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=-Ia-Iu;
        *cx5=0;
        *cx6=Ia+Ib+Iu;
        *cx7=0;
        *cx8=-Iv;
        *cx9=-Ia-Ib-Iu-Iw;
      break;

    case 13:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=0;
        *cx5=Ib+Iw;
        *cx6=-Iw;
        *cx7=-Ia-Iu;
        *cx8=-Ib-Iv-Iw;
        *cx9=0;
     break;

    case 14:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=0;
        *cx5=-Iv;
        *cx6=Ib+Iv;
        *cx7=-Ia-Iu;
        *cx8=0;
        *cx9=-Ib-Iv-Iw;
     break;

    case 15:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=Ia+Ib+Iv;
        *cx5=-Ia-Iv;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv;
        *cx8=0;
        *cx9=-Iw;
     break;

    case 16:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=-Iu;
        *cx5=Ib+Iu;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv;
        *cx9=-Iw;
     break;

    case 17:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=Ib+Iw;
        *cx5=0;
        *cx6=-Iw;
        *cx7=-Ib-Iu-Iw;
        *cx8=-Ia-Iv;
        *cx9=0;
     break;

    case 18:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=-Iu;
        *cx5=0;
        *cx6=Ib+Iu;
        *cx7=0;
        *cx8=-Ia-Iv;
        *cx9=Ib-Iu-Iw;
     break;

    case 19:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=0;
        *cx5=Ib+Iw;
        *cx6=-Iw;
        *cx7=-Iu;
        *cx8=-Ia-Ib-Iv-Iw;
        *cx9=0;
     break;

    case 20:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=0;
        *cx5=-Ia-Iv;
        *cx6=Ia+Ib+Iv;
        *cx7=-Iu;
        *cx8=0;
        *cx9=-Ia-Ib-Iv-Iw;
     break;

     case 21:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=Ib+Iv;
        *cx5=-Iv;
        *cx6=0;
        *cx7=-Ib-Iu-Iv;
        *cx8=0;
        *cx9=-Ia-Iw;
     break;

    case 22:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=-Iu;
        *cx5=Ib+Iu;
        *cx6=0;
        *cx7=0;
        *cx8=-Ib-Iu-Iv;
        *cx9=-Ia-Iw;
     break;

    case 23:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=Ia+Ib+Iw;
        *cx5=0;
        *cx6=-Ia-Iw;
        *cx7=-Ia-Ib-Iu-Iw;
        *cx8=-Iv;
        *cx9=0;
     break;

    case 24:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=-Iu;
        *cx5=0;
        *cx6=Ib+Iu;
        *cx7=0;
        *cx8=-Iv;
        *cx9=-Ia-Ib-Iu-Iw;
         break;
    case 25:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=0;
        *cx5=Ia+Ib+Iw;
        *cx6=-Ia-Iw;
        *cx7=-Iu;
        *cx8=-Ia-Ib-Iv-Iw;
        *cx9=0;
         break;
    case 26:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=0;
        *cx5=-Iv;
        *cx6=Ib+Iv;
        *cx7=-Iu;
        *cx8=0;
        *cx9=-Ia-Ib-Iv-Iw;
         break;
    case 27:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=Ib+Iv+Iw;
        *cx5=-Iv;
        *cx6=-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 28:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=-Ia-Iu;
        *cx5=Ia+Ib+Iu+Iw;
        *cx6=-Iw;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 29:

        *cx1=Ia;
        *cx2=0;
        *cx3=0;
        *cx4=-Ia-Iu;
        *cx5=-Iv;
        *cx6=Ia+Ib+Iu+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 30:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=Ia+Ib+Iv+Iw;
        *cx5=-Ia-Iv;
        *cx6=-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
      case 31:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=-Iu;
        *cx5=Ib+Iu+Iw;
        *cx6=-Iw;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 32:

        *cx1=0;
        *cx2=Ia;
        *cx3=0;
        *cx4=-Iu;
        *cx5=-Ia-Iv;
        *cx6=Ia+Ib+Iu+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 33:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=Ia+Ib+Iv+Iw;
        *cx5=-Iv;
        *cx6=-Ia-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 34:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=-Iu;
        *cx5=Ia+Ib+Iu+Iw;
        *cx6=-Ia-Iw;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 35:

        *cx1=0;
        *cx2=0;
        *cx3=Ia;
        *cx4=-Iu;
        *cx5=-Iv;
        *cx6=Ib+Iu+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 36:

        *cx1=Ia+Iv;
        *cx2=-Iv;
        *cx3=0;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv;
        *cx8=0;
        *cx9=-Iw;
         break;
    case 37:

        *cx1=-Ib-Iu;
        *cx2=Ia+Ib+Iu;
        *cx3=0;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv;
        *cx9=-Iw;
         break;
    case 38:

        *cx1=Ia+Ib+Iv;
        *cx2=-Ib-Iv;
        *cx3=0;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv;
        *cx8=0;
        *cx9=-Iw;
         break;
    case 39:

        *cx1=-Iu;
        *cx2= Ia+Iu;
        *cx3=0;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv;
        *cx9=-Iw;
         break;
    case 40:

        *cx1=Ia+Iv;
        *cx2=-Iv;
        *cx3=0;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Ia-Iu-Iv;
        *cx8=0;
         break;
     case 41:

        *cx1=-Iu;
        *cx2=Ia+Iu;
        *cx3=0;
        *cx4=0;
        *cx5=0;
        *cx6=-Ia-Iu-Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ib-Iw;
         break;
    case 42:

        *cx1=Ia+Iw;
        *cx2=0;
        *cx3=-Iw;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iw;
        *cx8=-Iv;
        *cx9=0;
         break;
    case 43:

        *cx1=-Ib-Iu;
        *cx2=0;
        *cx3=Ia+Ib+Iu;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=0;
        *cx8=-Iv;
        *cx9=-Ia-Ib-Iu-Iw;
         break;
    case 44:

        *cx1=Ia+Iw;
        *cx2=0;
        *cx3=-Iw;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Ia-Iu-Iw;
        *cx8=-Ib-Iv;
        *cx9=0;
         break;
    case 45:

        *cx1=-Iu;
        *cx2=0;
        *cx3=Ia+Iu;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=0;
        *cx8=-Ib-Iv;
        *cx9=-Ia-Iu-Iw;
         break;
    case 46:

        *cx1=Ia+Ib+Iw;
        *cx2=0;
        *cx3=-Ib-Iw;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Ia-Ib-Iu-Iw;
        *cx8=-Iv;
        *cx9=0;
         break;
    case 47:

        *cx1=-Iu;
        *cx2=0;
        *cx3=Ia+Iu;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=0;
        *cx8=-Iv;
        *cx9=-Ia-Ib-Iu-Iw;
         break;
    case 48:

        *cx1=0;
        *cx2=Ia+Iw;
        *cx3=-Iw;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ib-Iu;
        *cx8=-Ia-Iv-Iw;
        *cx9=0;
         break;
    case 49:

        *cx1=0;
        *cx2=-Iv;
        *cx3=Ia+Iv;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ib-Iu;
        *cx8=0;
        *cx9=-Ia-Iv-Iw;
         break;
    case 50:

        *cx1=0;
        *cx2=Ia+Iw;
        *cx3=-Iw;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Iu;
        *cx8=-Ia-Ib-Iv-Iw;
        *cx9=0;
         break;
     case 51:

        *cx1=0;
        *cx2=-Ib-Iv;
        *cx3=Ia+Ib+Iv;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Iu;
        *cx8=0;
        *cx9=-Ia-Ib-Iv-Iw;
         break;
     case 52:

        *cx1=0;
        *cx2=Ia+Ib+Iw;
        *cx3=-Ib-Iw;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Iu;
        *cx8=-Ia-Ib-Iv-Iw;
        *cx9=0;
         break;
    case 53:

        *cx1=0;
        *cx2=-Iv;
        *cx3=Ia+Iv;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Iu;
        *cx8=0;
        *cx9=-Ia-Ib-Iv-Iw;
         break;
    case 54:

        *cx1=Ia+Iv;
        *cx2=-Iv;
        *cx3=0;
        *cx4=Ib+Iw;
        *cx5=0;
        *cx6=-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 55:

        *cx1=-Ib-Iu-Iw;
        *cx2=Ia+Ib+Iu+Iw;
        *cx3=0;
        *cx4=Ib+Iw;
        *cx5=0;
        *cx6=-Iw;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 56:

        *cx1=Ia+Ib;
        *cx2=-Iv;
        *cx3=0;
        *cx4=-Ia-Iu-Iv;
        *cx5=0;
        *cx6=Ia+Ib+Iu+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 57:

        *cx1=Ia+Ib+Iv+Iw;
        *cx2=-Ib-Iv-Iw;
        *cx3=0;
        *cx4=0;
        *cx5=Ib+Iw;
        *cx6=-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 58:

        *cx1=-Iu;
        *cx2=Ia+Iu;
        *cx3=0;
        *cx4=0;
        *cx5=Ib+Iw;
        *cx6=-Iw;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 59:

        *cx1=-Iu;
        *cx2=Ia+Iu;
        *cx3=0;
        *cx4=0;
        *cx5=-Ia-Ib-Iv;
        *cx6=Ia+Ib+Iu+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 60:

        *cx1=Ia+Iw;
        *cx2=0;
        *cx3=-Iw;
        *cx4=Ib+Iv;
        *cx5=-Iv;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
     case 61:

        *cx1=Ia+Iw;
        *cx2=0;
        *cx3=-Iw;
        *cx4=-Ia-Iu-Iw;
        *cx5=Ia+Ib+Iu+Iw;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 62:

        *cx1=-Ib-Iu-Iv;
        *cx2=0;
        *cx3=Ia+Ib+Iu+Iv;
        *cx4=Ib+Iv;
        *cx5=-Iv;
        *cx6=0;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 63:

        *cx1=Ia+Ib+Iv+Iw;
        *cx2=0;
        *cx3=-Ib-Iv-Iw;
        *cx4=0;
        *cx5=-Iv;
        *cx6=Ib+Iv;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 64:

        *cx1=-Iu;
        *cx2=0;
        *cx3=Ia+Iu;
        *cx4=0;
        *cx5=Ia+Ib+Iu+Iw;
        *cx6=0;
        *cx7=-Ia-Iu-Iw;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 65:

        *cx1=-Iu;
        *cx2=0;
        *cx3=Ia+Iu;
        *cx4=0;
        *cx5=-Iv;
        *cx6=Ib+Iv;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 66:

        *cx1=0;
        *cx2=Ia+Iw;
        *cx3=-Iw;
        *cx4=Ia+Ib+Iv+Iw;
        *cx5=-Ia-Iv-Iw;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
     case 67:

        *cx1=0;
        *cx2=Ia+Iw;
        *cx3=-Iw;
        *cx4=-Iu;
        *cx5=Ib+Iu;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
     case 68:

        *cx1=0;
        *cx2=-Ib-Iu-Iv;
        *cx3=Ia+Ib+Iu+Iv;
        *cx4=-Iu;
        *cx5=Ib+Iu;
        *cx6=0;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
     case 69:

        *cx1=0;
        *cx2=-Iv;
        *cx3=Ia+Iv;
        *cx4=Ia+Ib+Iv+Iw;
        *cx5=0;
        *cx6=-Ia-Iv-Iw;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 70:

        *cx1=0;
        *cx2=Ia+Ib+Iu+Iw;
        *cx3=-Ib-Iu-Iw;
        *cx4=-Iu;
        *cx5=0;
        *cx6=Ib+Iu;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
     case 71:

        *cx1=0;
        *cx2=-Iv;
        *cx3=Ia+Iv;
        *cx4=-Iu;
        *cx5=0;
        *cx6=Ib+Iu;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 72:

        *cx1=Ia+Iv+Iw;
        *cx2=-Iv;
        *cx3=-Iw;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 73:

        *cx1=-Ib-Iu;
        *cx2=Ia+Ib+Iu+Iw;
        *cx3=-Iw;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 74:

        *cx1=-Ib-Iu;
        *cx2=-Iv;
        *cx3=Ia+Ib+Iu+Iv;
        *cx4=Ib;
        *cx5=0;
        *cx6=0;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 75:

        *cx1=Ia+Ib+Iv+Iw;
        *cx2=-Ib-Iv;
        *cx3=-Iw;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
         break;
    case 76:

        *cx1=-Iu;
        *cx2=Ia+Iu+Iw;
        *cx3=-Iw;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=0;
        *cx8=-Ia-Ib-Iu-Iv-Iw;
        *cx9=0;
         break;
    case 77:

        *cx1=-Iu;
        *cx2=-Ib-Iv;
        *cx3=Ia+Ib+Iu+Iv;
        *cx4=0;
        *cx5=Ib;
        *cx6=0;
        *cx7=0;
        *cx8=0;
        *cx9=-Ia-Ib-Iu-Iv-Iw;
         break;
    case 78:

        *cx1=Ia+Ib+Iv+Iw;
        *cx2=-Iv;
        *cx3=-Ib-Iw;
        *cx4=0;
        *cx5=0;
        *cx6=Ib;
        *cx7=-Ia-Ib-Iu-Iv-Iw;
        *cx8=0;
        *cx9=0;
        break;

    case 79:

       	       *cx1=-Iu;
               *cx2=Ia+Ib+Iu+Iw;
               *cx3=-Ib-Iw;
               *cx4=0;
               *cx5=0;
               *cx6=Ib;
               *cx7=0;
               *cx8=-Ia-Ib-Iu-Iv-Iw;
               *cx9=0;
            break;

    case 80:

             *cx1=-Iu;
             *cx2=-Iv;
             *cx3=Ia+Iu+Iv;
             *cx4=0;
             *cx5=0;
             *cx6=Ib;
             *cx7=0;
             *cx8=0;
          break;



    default:
        	   *cx1=0;
               *cx2=0;
               *cx3=0;
               *cx4=0;
               *cx5=0;
               *cx6=0;
               *cx7=0;
               *cx8=0;
               *cx9=0;
            break;

}
}    


void acharxs(int line, int curto1, int value_curto, int rs2, int rs3, int rs4, int rs5, int *x1, int *x2, int *x3, int *x4, int *x5, int *x6, int *x7, int *x8, int *x9)
{
	switch (line)
	{
		case 0: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 1: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 2: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 3: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 4: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 5: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 6: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 7: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 8: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 9: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 10: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 11: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 12: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 13: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 14: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 15: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 16: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 17: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 18: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 19: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 20: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 21: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 22: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 23: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 24: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 25: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 26: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 27: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 28: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 29: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 30: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 31: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 32: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 33: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 34: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 35: 
		if (curto1 ==2)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 36: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 37: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 38: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 39: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 40: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 41: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 42: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 43: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 44: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;

		case 45: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 46: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto - rs5;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs5 - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =rs5 - rs3 - rs2 + value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 + rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =rs5 - rs3 + value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + rs5 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 - rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 - rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 - rs4 - rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 47: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 =rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5;  if(*x8==0) *x8=1555;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 48: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 49: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 50: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 51: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 52: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 =rs4 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4;  if(*x7==0) *x7=1555;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 53: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =rs4 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs5 - rs4;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 54: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 55: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 56: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs5 - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs5 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs4 - rs5 - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs5;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs5 - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 + rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 + rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 =rs3 + rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 57: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 58: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 59: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 = 0;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 60: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 61: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 62: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 63: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 64: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 65: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5;  if(*x5==0) *x5=1555;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 = 0;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 66: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 67: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 68: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 = 0;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4;  if(*x4==0) *x4=1555;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 69: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 70: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 = 0;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 71: 
		if (curto1 ==1)  {
		*x1 = 0;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 = 0;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 = 0;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 = 0;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs5 - rs4;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 = 0;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 72: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 73: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 74: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto - rs4 - rs5 - rs2;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==3)  {
		*x1 =rs2 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 =rs3 - rs4 - rs5 + value_curto;  if(*x4==0) *x4=1555;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 75: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto - rs4 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + rs4 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 76: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 77: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs4 - rs2 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto - rs5 - rs2;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==4)  {
		*x1 =rs2 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 =rs3 - rs5 + value_curto;  if(*x5==0) *x5=1555;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 78: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs3 - rs4 - rs5 - rs2;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto - rs4 - rs5 - rs3;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else if (curto1 ==6)  {
		*x1 =rs2 + rs3 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs4 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 =value_curto;  if(*x7==0) *x7=1555;
		*x8 = 0;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 79: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =rs4 - rs3 - rs2 + value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs3 - rs5 - rs2;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto - rs5 - rs3;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else if (curto1 ==7)  {
		*x1 =rs2 + rs3 - rs4 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 =value_curto;  if(*x8==0) *x8=1555;
		*x9 = 0;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;
		case 80: 
		if (curto1 ==0)  {
		*x1 =value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs4 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs4 + rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs4 - rs2 + rs5 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs4 - rs3 - rs2 + rs5 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==1)  {
		*x1 =value_curto - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs5 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs5 - rs2 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =rs5 - rs3 - rs2 + value_curto;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==2)  {
		*x1 =value_curto - rs5 - rs4;  if(*x1==0) *x1=1555;
		*x2 =value_curto - rs5;  if(*x2==0) *x2=1555;
		*x3 =value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto - rs2;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3 - rs2;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==5)  {
		*x1 =rs2 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto - rs3;  if(*x9==0) *x9=1555;
		}
		else if (curto1 ==8)  {
		*x1 =rs2 + rs3 - rs4 - rs5 + value_curto;  if(*x1==0) *x1=1555;
		*x2 =rs2 + rs3 - rs5 + value_curto;  if(*x2==0) *x2=1555;
		*x3 =rs2 + rs3 + value_curto;  if(*x3==0) *x3=1555;
		*x4 = 0;
		*x5 = 0;
		*x6 =rs3 + value_curto;  if(*x6==0) *x6=1555;
		*x7 = 0;
		*x8 = 0;
		*x9 =value_curto;  if(*x9==0) *x9=1555;
		}
		else {
		*x1=0;
		*x2=0;
		*x3=0;
		*x4=0;
		*x5=0;
		*x6=0;
		*x7=0;
		*x8=0;
		*x9=0;
		}
		break;

	default:

		*x1 = 0;
		*x2 = 0;
		*x3 = 0;
		*x4 = 0;
		*x5 = 0;
		*x6 = 0;
		*x7 = 0;
		*x8 = 0;
		*x9 = 0;
		break;
	}
}