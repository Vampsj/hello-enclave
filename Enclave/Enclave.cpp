#include "Enclave_t.h"
#include "sgx_tae_service.h"
#include "sgx_trts.h"

int generate_random_number() {
    ocall_print("Processing random number generation...");
    uint32_t val;
    int rand;
    int *input_a0[100] = new int[100];
    for (int i = 0; i<100; i++){
        sgx_read_rand((unsigned char*)&val, 4);
        rand = (short) val;
        input_a0[i] = rand;
    }
    return input_a0[42];
}
