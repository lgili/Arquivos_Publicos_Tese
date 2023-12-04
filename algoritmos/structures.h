
#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct {
  int CA1;
  int CA2;
  int CA3;
  int CB1;
  int CB2;
  int CB3;
  int CC1;
  int CC2;
  int CC3;
  int DA1;
  int DA2;
  int DA3;
  int DB1;
  int DB2;
  int DB3;
  int DC1;
  int DC2;
  int DC3;
}svm_t ;

typedef struct {
    float um;
    float dois;
}idx_number_t;

typedef struct {
    idx_number_t A;
    idx_number_t B;
}idx_t;

typedef struct {
  int sm1;
  int sm2;
  int sm3;
  int sm4;
  int sm5;
  int sm6;
  int sm7;
  int sm8;
  int sm9;
}pwm_t;

typedef struct {
  float aux1;
  float aux2;
  float aux3;
  float aux4;
  float aux5;
  float aux6;
  float aux7;
  
}aux_t;

typedef struct {
    float A;
    float B;
    float C;
}voltage_t;

typedef struct{
    int L;
    int G;    
}vls_t;

typedef struct{
    float lu;
    float ul;
    float zero;    
}duty_cycle_t;

typedef struct{
    float A;
    float B;
    float C;  
    float U;
    float V;
    float W;   
}vars_for_modules_t;

typedef struct{
    int a;
    int b;
    int c;       
}gen_types_t;

typedef struct{
    gen_types_t in;
    gen_types_t out;      
}vec_t;

typedef struct{
    int array[9] ;     
}array_t;

typedef struct{
    int array[45] ;     
}array_curto_size_t;

typedef struct{
    int array[3] ;     
}array_gen_types_t;

typedef struct{
    array_gen_types_t in;
    array_gen_types_t out;      
}vec_array_t;

typedef struct{
    double array[9] ;     
}array_double_t;

typedef struct{
    double array[81][9] ;     
}array_lines_t;

typedef struct{
    int line ;
    int curto_pos;
    int curto_value;     
}result_cost_t;

// ------------------------------------------------------------------------
// Methods inverter 
// ------------------------------------------------------------------------

/*
typedef enum _invFsmState_t_{
    inv_fsm_stop,
    inv_fsm_init,
    inv_fsm_onGrid,
    inv_fsm_openLoopInv,
    inv_fsm_chargingCaps,
    inv_fsm_ramp
}invFsmState_t;

typedef struct _invFsm_t_{
    // State 
    invFsmState_t  state;
    //Triggers 
    long stopToInit_vBusMin;
    long stopToInit_vBusMax;
    long stopToInit_vGridMin;
    long stopToInit_vGridMax;
    long initToOnGrid_vBusMin;
    long initToOnGrid_vBusMax;
    long mpptToStop_vBusMin;
    long mpptToStop_vBusMax;
    long mpptToStop_vGridMin;
    long mpptToStop_vGridMax;
}invFsm_t;

typedef struct _invInfosBits_t_{
    unsigned int isInvEnabled           :1;
    unsigned int isFsmAuto              :1;
    unsigned int isClearErrorAuto       :1;
    unsigned int rsvd                   :29;
}invInfosBits_t;

typedef union _invInfos_t_{
    unsigned int        all;
    invInfosBits_t      bit;
}invInfos_t;

typedef struct _invGridInfo_t_{
    long gridFrequency;
    long gridVoltage;
}invGridInfo_t;

typedef enum _invGridCycleState_t_{
    inv_gridCycle_zero,
    inv_gridCycle_positive,
    inv_gridCycle_negative
}invGridCycleState_t;

typedef struct _invReferences_t_{
    // Bus Voltage 
    long vBus;
    // Grid Power 
    long pGrid;
    // Grid Current 
    long iGrid;
    long iGridSin;
    // Output Control 
    long d;
    // Grid Cycle 
    invGridCycleState_t gridCycle;
    // Auxiliary 
    long deadTimeZeroCross;
    long deadTimeZeroCross_x4;
}invReferences_t;

typedef struct _invMeasurements_t_{
    // Bus Voltage 
    vars_for_modules_t * I;
    // Grid Voltage 
    vars_for_modules_t * Iref;
    long * vGridRms;
    // Grid Current 
    long * iGrid;
    long * iGridRms;
    // Grid Power 
    long * pGrid;
    // Out Voltage 
    long * vOut;
    long * vOutRms;
    // Out Current 
    long * iOut;
    long * iOutRms;
    // Out Power 
    long * pOut;
}invMeasurements_t;

typedef struct _invLimits_t_{
    // Bus Voltage 
    long vBusMax;
    long vBusMin;
    // Grid Voltage 
    long vGridMax;
    // Grid Current 
    long iGridMax;
    // Grid Power 
    long pGridMax;
    // Output Control 
    long dMax;
    long dMin;
}invLimits_t;

// Inverter Structure 
typedef struct _invVar_t_{
    // FSM 
    invFsm_t fsm;
    // General Info 
    invInfos_t generalInfo;
    // Grid Info 
    invGridInfo_t gridInfo;
    // References 
    invReferences_t references;
    // Controllers 
    
    long currentCtrlOut;
    long proportional;
    long proportionalOut;
    long voltageFeedForward;
    // Measurements 
    invMeasurements_t measurements;
    // Limits 
    invLimits_t limits;
    //Test Only 
    long dummySin;
    long dummySinPeriod;
    long dummySinCounter;
    long dummySinStep;
}invVar_t;

typedef struct _inv_t_
{
    // Variables 
    invVar_t var;
    // Methods
    void(*run)(invVar_t * invVar);
}inv_t;

extern inv_t inv;

void invInit(inv_t * inv, invMeasurements_t invMeasurements);
*/
// ------------------------------------------------------------------------
// Methods Sistema Supervisori
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// Structures
// ------------------------------------------------------------------------

typedef enum
{
    M3CSystem_uninitialized,
    M3CSystem_structuresInit,
    M3CSystem_peripheralsInit,
    M3CSystem_communicationInit,
    M3CSystem_measurementsInit,
    M3CSystem_protectionsInit,
    M3CSystem_fsmInit,
    M3CSystem_running,
    M3CSystem_reset,
    M3CSystem_error
}M3CSystemStates_t;

typedef struct
{
    M3CSystemStates_t state;
}M3CSystem_t;

typedef enum
{
    M3CPe_stop,
    M3CPe_onGridPreLoad1,
    M3CPe_onGridPreLoad2,
    M3CPe_onGrid,
    M3CPe_error
}M3CPeStates_t;

typedef struct
{
    M3CPeStates_t state;
}M3CPe_t;

typedef struct
{
    M3CSystem_t inverter;
    M3CPe_t     pe;
}M3C_t;

#endif