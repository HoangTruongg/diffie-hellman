#include "u512_utils.h"
#include <stdexcept>

// TV1: complete all unsigned 512-bit arithmetic according to docs/API_CHUNG.md.
// DO NOT replace TODO with hard-coded zero/false: this must pass real arithmetic tests.

uint512_t operator+(const uint512_t& a, const uint512_t& b) {
    (void)a; (void)b;
    throw std::logic_error("TODO(TV1): operator+");
}
uint512_t operator-(const uint512_t& a, const uint512_t& b) {
    (void)a; (void)b;
    throw std::logic_error("TODO(TV1): operator-");
}
bool operator==(const uint512_t& a, const uint512_t& b) {
    (void)a; (void)b;
    throw std::logic_error("TODO(TV1): operator==");
}
bool operator<(const uint512_t& a, const uint512_t& b) {
    (void)a; (void)b;
    throw std::logic_error("TODO(TV1): operator<");
}
bool operator>(const uint512_t& a, const uint512_t& b) {
    (void)a; (void)b;
    throw std::logic_error("TODO(TV1): operator>");
}
bool operator>=(const uint512_t& a, const uint512_t& b) {
    (void)a; (void)b;
    throw std::logic_error("TODO(TV1): operator>=");
}
bool operator<=(const uint512_t& a, const uint512_t& b) {
    (void)a; (void)b;
    throw std::logic_error("TODO(TV1): operator<=");
}
uint512_t from_u64(uint64_t value) {
    (void)value;
    throw std::logic_error("TODO(TV1): from_u64");
}
bool get_bit(const uint512_t& x, size_t bit_index) {
    (void)x; (void)bit_index;
    throw std::logic_error("TODO(TV1): get_bit");
}
uint512_t shift_right_one(const uint512_t& x) {
    (void)x;
    throw std::logic_error("TODO(TV1): shift_right_one");
}
std::string to_hex(const uint512_t& x) {
    (void)x;
    throw std::logic_error("TODO(TV1): to_hex");
}
