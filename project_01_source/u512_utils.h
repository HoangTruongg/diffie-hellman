#ifndef U512_UTILS_H
#define U512_UTILS_H

#include "u512_sample.h"
#include <cstddef>
#include <cstdint>
#include <string>

// Added API for the team, separate from the lecturer's original u512_sample.h.
// digits[0] is the least-significant 64-bit limb; bit 0 is the least-significant bit.
uint512_t from_u64(uint64_t value);
bool get_bit(const uint512_t& x, size_t bit_index); // 0..511
uint512_t shift_right_one(const uint512_t& x);
std::string to_hex(const uint512_t& x);

#endif
