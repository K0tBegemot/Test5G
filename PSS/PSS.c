#include "PSS.h"

mapped_sync_signal_t* generatePSSSignal(sync_signal_param_t* parameters)
{
    mapped_sync_signal_t* pssSignal = (mapped_sync_signal_t*)calloc(1, sizeof(mapped_sync_signal_t));
    if(parameters->size_of_FFT <= PSS_SUBCARRIER_LENGTH)
    {

    }
    if(parameters->cell_id_shift < N_ID_2_MIN_VALUE && parameters->cell_id_shift > N_ID_2_MAX_VALUE)
    {

    }
    uint16_t PSSPattern[PSS_SUBCARRIER_LENGTH]; //d_PSS from 3GPP TS 38.211 7.4.2.2
    uint16_t PSSAdditionPattern[PSS_SUBCARRIER_LENGTH]; //x rom 3GPP TS 38.211 7.4.2.2
    const uint16_t PSSAdditionPatternInitial[PSS_INITIAL_LENGTH] = PSS_INITIAL_VALUES;
    for(uint16_t i = 0; i < PSS_SUBCARRIER_LENGTH; i++)
    {
        PSSAdditionPattern[i] = PSSAdditionPatternInitial[i];
    }
    for(uint16_t i = 0; i < PSS_SUBCARRIER_LENGTH - PSS_INITIAL_LENGTH; i++)
    {
        PSSAdditionPattern[i + PSS_INITIAL_LENGTH] = (PSSAdditionPattern[i + 4] + PSSAdditionPattern[i]) % PSS_X_MODULO;
    }
    for(uint16_t i = 0; i < PSS_SUBCARRIER_LENGTH; i++)
    {
        uint16_t m = (i + 43 * parameters->cell_id_shift) % (PSS_SUBCARRIER_LENGTH);
        PSSPattern[i] = 1 - 2 * PSSAdditionPattern[m];
    }
    
}