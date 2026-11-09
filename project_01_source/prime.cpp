#include "prime.h"
#include "modular.h"
#include "u512_utils.h"
#include <stdexcept>

// TV2: implement Miller-Rabin, random candidate generation and safe-prime search.
bool is_probable_prime(prng_ctx* ctx, const uint512_t& n, int rounds) {
    (void)ctx; (void)n; (void)rounds;
    throw std::logic_error("TODO(TV2): is_probable_prime");
}

// Exact signature kept from dh_sample.h (default argument only in header).
uint512_t generate_safe_prime(prng_ctx* ctx, size_t bitsize) {
    (void)ctx; (void)bitsize;
    throw std::logic_error("TODO(TV2): generate_safe_prime");
}
