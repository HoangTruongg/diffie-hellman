#ifndef LAB01_DH_H
#define LAB01_DH_H

#include "dh_sample.h"
#include <cstddef>

// TV3: safe-prime generator choice (given p=2q+1, q prime).
uint512_t choose_generator(const uint512_t& p);

// TV3: a small value object to make cross-module integration explicit.
struct DHResult {
    uint512_t p;
    uint512_t g;
    uint512_t a_private;
    uint512_t b_private;
    uint512_t A_public;
    uint512_t B_public;
    uint512_t alice_shared;
    uint512_t bob_shared;
};

DHResult run_diffie_hellman(prng_ctx* ctx, size_t bitsize = 512);

#endif
