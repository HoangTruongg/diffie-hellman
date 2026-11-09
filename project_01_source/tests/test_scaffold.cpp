#include "u512_sample.h"
#include "u512_utils.h"
#include "modular.h"
#include "prime.h"
#include "dh.h"
#include "prng.h"

#include <cassert>
#include <cstdint>
#include <iostream>

int main() {
    // Only a setup smoke test. Does NOT assert modular math or DH correctness.
    static_assert(sizeof(uint512_t) == 64, "uint512_t must be 64 bytes");
    uint512_t zero;
    for (size_t i = 0; i < 8; ++i) { assert(zero.digits[i] == 0); }

    uint8_t seed[32] = {0};
    for (size_t i = 0; i < sizeof(seed); ++i) { seed[i] = static_cast<uint8_t>(i); }
    prng_ctx ctx1, ctx2;
    prng_seed(&ctx1, seed, sizeof(seed));
    prng_seed(&ctx2, seed, sizeof(seed));
    assert(prng_next_u64(&ctx1) == prng_next_u64(&ctx2));

    std::cout << "PASS: scaffold header/zero-init/PRNG smoke tests ONLY\n";
    std::cout << "TODO: add TV1 arithmetic, TV2 primality, TV3 DH correctness tests.\n";
    return 0;
}
