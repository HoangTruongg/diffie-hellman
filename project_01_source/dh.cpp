#include "dh.h"
#include "modular.h"
#include "u512_utils.h"
#include <stdexcept>

// TV3: uniform rejection sampling in [2, p-2]; NEVER use a fixed private key.
uint512_t generate_private_key(prng_ctx* ctx, const uint512_t& p) {
    (void)ctx; (void)p;
    throw std::logic_error("TODO(TV3): generate_private_key");
}

// TV3: choose g only after checking generator conditions for safe p=2q+1.
uint512_t choose_generator(const uint512_t& p) {
    (void)p;
    throw std::logic_error("TODO(TV3): choose_generator");
}

// Integration flow. Currently stops at TODO in generate_safe_prime.
DHResult run_diffie_hellman(prng_ctx* ctx, size_t bitsize) {
    if (ctx == nullptr) {
        throw std::invalid_argument("PRNG context must not be null");
    }
    if (bitsize != 512) {
        throw std::invalid_argument("Starter supports exactly 512-bit p");
    }

    DHResult result;
    result.p = generate_safe_prime(ctx, bitsize);
    result.g = choose_generator(result.p);

    result.a_private = generate_private_key(ctx, result.p);
    result.b_private = generate_private_key(ctx, result.p);

    result.A_public = modular_exponentiation(result.g, result.a_private, result.p);
    result.B_public = modular_exponentiation(result.g, result.b_private, result.p);

    result.alice_shared = modular_exponentiation(result.B_public, result.a_private, result.p);
    result.bob_shared   = modular_exponentiation(result.A_public, result.b_private, result.p);

    if (!(result.alice_shared == result.bob_shared)) {
        throw std::runtime_error("Alice and Bob produced different shared secrets");
    }
    return result;
}
