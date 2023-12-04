#include "svm.h"

void calculate_SVM(double* Vin, duty_cycle_t *d, svm_t *PWM){
  float result[23] = {0,0,0};
  vls_t Vul, Vlu, Vuu, Vu, Vec3;
  float sinal=0;  
  int t1=0, t2=0, t3=0;
  int index1[100], index2[100], index3[100];
  int A;
  int cmv1 = 20, cmv2 = 20, cmv3 = 20;  
  int new_index1=0, new_index2=0, new_index3=0;
  int TM=1335;
  int i, j;

  for (i = 0; i < 2; ++i){ // zerando vertor result
    result[i] = 0;
  }    

  for (  i = 0; i < 3; i++) {
    for ( j = 0; j < 3; j++) {
          result[i]  += TT[j][i] * Vin[j];
    }
  }

  Vul.L = ceil(result[0]) ;
  Vul.G = floor(result[1]) ;

  Vlu.L = floor(result[0]) ;
  Vlu.G = ceil(result[1]) ;

  Vuu.L = ceil(result[0]) ;
  Vuu.G = ceil(result[1]) ;

  Vu.L = floor(result[0]) ;
  Vu.G = floor(result[1]) ;

  sinal = (result[0] + result[1]) - (Vul.L + Vul.G);
  if(sinal>=0) {
    Vec3.L = Vuu.L;
    Vec3.G = Vuu.G;
      
    d->ul=-( result[0] - Vuu.L);
    d->lu=-( result[1] - Vuu.G);
    //du= 1 - dul -dlu;
  }
  else {
    Vec3.L = Vu.L;
    Vec3.G = Vu.G;

    d->ul=result[0] - Vu.L;
    d->lu=result[1] - Vu.G;
    //du= 1 - dul -dlu;
  }
  

  for ( A = 0; A < TM ; A++) {
    if ((Vetor_lgL[A][0] ==  Vul.L) & (Vetor_lgL[A][1] ==  Vul.G)){
      index1[t1] = A;
      t1++;
    }
    if ((Vetor_lgL[A][0] == Vlu.L) & (Vetor_lgL[A][1] ==  Vlu.G)){
      index2[t2] = A;
      t2++;
    }
    if ((Vetor_lgL[A][0] == Vec3.L) & (Vetor_lgL[A][1] ==  Vec3.G)){
      index3[t3] = A;
      t3++;
    }
  }  

  for ( i = 0; i < t1; ++i){
    if (Vetor_lgL[index1[i]][3]< cmv1){
      new_index1 = index1[i];
    }
  }
  
  for ( i = 0; i < t2; ++i){
    if (Vetor_lgL[index2[i]][3]< cmv2){
      new_index2 = index2[i];
    }
  }
  
  for ( i = 0; i < t3; ++i){
    if (Vetor_lgL[index3[i]][3]< cmv3){
      new_index3 = index3[i];
    }
  }

  PWM->CA1 = VSI3N[new_index1][0];
  PWM->CA2 = VSI3N[new_index1][1];
  PWM->CA3 = VSI3N[new_index1][2];

  PWM->CB1 = VSI3N[new_index2][0];
  PWM->CB2 = VSI3N[new_index2][1];
  PWM->CB3 = VSI3N[new_index2][2];

  PWM->CC1 = VSI3N[new_index3][0];
  PWM->CC2 = VSI3N[new_index3][1];
  PWM->CC3 = VSI3N[new_index3][2];

  /*CA1 = VSI3[index1[0]][0];
  CA2 = VSI3[index1[0]][1];
  CA3 = VSI3[index1[0]][2];

  CB1 = VSI3[index2[0]][0];
  CB2 = VSI3[index2[0]][1];
  CB3 = VSI3[index2[0]][2];

  CC1 = VSI3[index3[0]][0];
  CC2 = VSI3[index3[0]][1];
  CC3 = VSI3[index3[0]][2];*/

  /*CA1 = Vabcg[index1[0]][0];
  CA2 = Vabcg[index1[0]][1];
  CA3 = Vabcg[index1[0]][2];

  CB1 = Vabcg[index2[0]][0];
  CB2 = Vabcg[index2[0]][1];
  CB3 = Vabcg[index2[0]][2];

  CC1 = Vabcg[index3[0]][0];
  CC2 = Vabcg[index3[0]][1];
  CC3 = Vabcg[index3[0]][2];*/
}