#ifndef LAB01_MODULAR_H
#define LAB01_MODULAR_H

#include "u512_sample.h"

// TV1: implementations based on pseudocode-modular-operation.pdf.
// Precondition: y != 0 for Mod, p != 0 for modular arithmetic.
// Invalid input: throw std::invalid_argument.
uint512_t Mod(const uint512_t& x, const uint512_t& y);
uint512_t AddMod(const uint512_t& x, const uint512_t& y, const uint512_t& p);
uint512_t MultMod(const uint512_t& x, const uint512_t& y, const uint512_t& p);
uint512_t ExpMod(const uint512_t& x, const uint512_t& y, const uint512_t& p);

#endif
