#include "modular.h"
#include "dh_sample.h"
#include <stdexcept>

// TV1: finish these in dependency order: Mod -> AddMod -> MultMod -> ExpMod.
uint512_t Mod(const uint512_t& x, const uint512_t& y) {
    (void)x; (void)y;
    throw std::logic_error("TODO(TV1): Mod");
}
uint512_t AddMod(const uint512_t& x, const uint512_t& y, const uint512_t& p) {
    (void)x; (void)y; (void)p;
    throw std::logic_error("TODO(TV1): AddMod");
}
uint512_t MultMod(const uint512_t& x, const uint512_t& y, const uint512_t& p) {
    (void)x; (void)y; (void)p;
    throw std::logic_error("TODO(TV1): MultMod");
}
uint512_t ExpMod(const uint512_t& x, const uint512_t& y, const uint512_t& p) {
    (void)x; (void)y; (void)p;
    throw std::logic_error("TODO(TV1): ExpMod");
}

// Exact signature retained from the lecturer's dh_sample.h.
uint512_t modular_exponentiation(const uint512_t& base,
                                 const uint512_t& exp,
                                 const uint512_t& mod) {
    return ExpMod(base, exp, mod);
}
