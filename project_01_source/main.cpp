#include "dh.h"
#include "u512_utils.h"
#include "prng.h"

#include <cstdint>
#include <exception>
#include <iostream>
#include <string>

namespace {
void help() {
    std::cout
        << "Lab01 - Diffie-Hellman (STARTER / NOT IMPLEMENTED YET)\n"
        << "  --help         Print this help\n"
        << "  --check-prng   Smoke-test the lecturer's PRNG (not a DH test)\n"
        << "  --demo         Run DH after team implements TODOs (512-bit only)\n";
}
void init_prng(prng_ctx& ctx) {
    uint8_t seed[32] = {0};
    // This function is from the lecturer's Linux/WSL PRNG sample.
    randombytes(seed, static_cast<uint8_t>(sizeof(seed)));
    prng_seed(&ctx, seed, sizeof(seed));
    for (auto& byte : seed) { byte = 0; }
}
} // namespace

int main(int argc, char* argv[]) {
    try {
        if (argc == 1 || (argc == 2 && std::string(argv[1]) == "--help")) {
            help();
            return 0;
        }
        if (argc != 2) {
            help();
            return 1;
        }
        std::string arg(argv[1]);
        prng_ctx ctx;
        init_prng(ctx);
        if (arg == "--check-prng") {
            std::cout << "PRNG smoke check: " << prng_next_u64(&ctx) << "\n";
            std::cout << "NOTE: This verifies PRNG startup only, not cryptographic strength.\n";
            return 0;
        }
        if (arg == "--demo") {
            DHResult result = run_diffie_hellman(&ctx, 512);
            std::cout << "p = 0x" << to_hex(result.p) << "\n";
            std::cout << "g = 0x" << to_hex(result.g) << "\n";
            std::cout << "Alice/Bob shared = 0x" << to_hex(result.alice_shared) << "\n";
            // Do not print private keys in a real cryptographic application.
            return 0;
        }
        help();
        return 1;
    } catch (const std::exception& ex) {
        std::cerr << "ERROR: " << ex.what() << "\n";
        std::cerr << "This is an initial skeleton. Complete assigned TODOs first.\n";
        return 2;
    }
}
