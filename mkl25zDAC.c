#include "MKL25Z4.h"

void Dac.init(){
    SIM->SCGC2 |= SIM_SCGC2_DAC0_MASK
    DAC0->C0 = DAC_C0_DACEN_MASK | DAC_C0_DACRFS_MASK;
}

void Dac.write(float volt){
    int data = volt * 19.859;
    if(data > 255){
        DAC0->DAT[0].DATH = DAC_DATH_DATA1((data/257) >> 8);
        DAC0->DAT[0].DATL = DAC_DATL_DATA0(0 & 0xFF);
    }else{
        DAC0->DAT[0].DATH = DAC_DATH_DATA1(0 >> 8);
        DAC0->DAT[0].DATL = DAC_DATL_DATA0(data & 0xFF);
    }
}

