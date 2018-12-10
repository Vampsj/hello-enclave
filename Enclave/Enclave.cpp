#include "Enclave_t.h"
#include "sgx_tae_service.h"
#include "sgx_trts.h"

int generate_random_number() {
    ocall_print("Processing random number generation...");
    uint32_t val;
    int rand;
    int sum = 0;
    int *input_a0 = new int[100];
    int *input_a1 = new int[100];
    for (int i = 0; i<100; i++){
        sgx_read_rand((unsigned char*)&val, 4);
        rand = (short) val;
        input_a0[i] = rand;
        input_a1[i] = rand;
    }
    for (int i = 0; i <100;i++){
        sum = sum + input_a0[i] * input_a1[i];
    }
    
    return sum;
}
