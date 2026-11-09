#ifndef LAB01_PRIME_H
#define LAB01_PRIME_H

#include "dh_sample.h"

// TV2: probabilistic primality check using the shared PRNG and ExpMod.
// rounds must be positive; ctx must not be null.
bool is_probable_prime(prng_ctx* ctx, const uint512_t& n, int rounds = 32);

// generate_safe_prime(prng_ctx*, size_t) is already declared in dh_sample.h.
#endif
