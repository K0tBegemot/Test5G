#include <stdint.h>
#include <stdlib.h>

#define PSS_SUBCARRIER_LENGTH 127   //PSS length in frequency domain
#define PSS_INITIAL_LENGTH 7        //length for initial sequence x
#define PSS_INITIAL_VALUES {0, 1, 1, 0, 1, 1, 1}
#define PSS_X_MODULO 2;
#define N_ID_2_MIN_VALUE 0
#define N_ID_2_MAX_VALUE 2

typedef struct sync_signal_param_t
{
    uint16_t cell_id_shift;                  //N_ID^(2) from 3GPP TS 38.211 7.4.2.1
    uint16_t offset_to_start_syncro_block;   //K_SSB from 
    uint16_t offset_to_point_A;             //offsetToPointA from 
    uint16_t size_of_FFT;                   //size of FFT
    uint16_t numerology_number;              //numerology from
}sync_signal_param_t;

typedef struct mapped_sync_signal_t
{

}mapped_sync_signal_t;

mapped_sync_signal_t* generatePSSSignal(sync_signal_param_t* parameters);
int searchPSSSignal();