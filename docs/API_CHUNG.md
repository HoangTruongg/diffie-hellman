# API chung - da chot cho 3 thanh vien

> **Kieu so:** `uint512_t` (8 `uint64_t`); `digits[0]` la 64 bit thap nhat; `get_bit(x, 0)` la bit thap nhat. C++14. Ban dau chi `bitsize == 512`.

## TV1 - So hoc lon va modular

File mau goc `project_01_source/u512_sample.h` da khai bao:

```cpp
uint512_t operator+(const uint512_t& a, const uint512_t& b);
uint512_t operator-(const uint512_t& a, const uint512_t& b);
bool operator==(const uint512_t& a, const uint512_t& b);
bool operator<(const uint512_t& a, const uint512_t& b);
bool operator>(const uint512_t& a, const uint512_t& b);
bool operator>=(const uint512_t& a, const uint512_t& b);
bool operator<=(const uint512_t& a, const uint512_t& b);
```

Khai bao bo sung trong `u512_utils.h` (khong sua file mau goc):

```cpp
uint512_t from_u64(uint64_t value);
bool get_bit(const uint512_t& x, size_t bit_index);
uint512_t shift_right_one(const uint512_t& x);
std::string to_hex(const uint512_t& x);
```

Khai bao trong `modular.h`:

```cpp
uint512_t Mod(const uint512_t& x, const uint512_t& y);
uint512_t AddMod(const uint512_t& x, const uint512_t& y, const uint512_t& p);
uint512_t MultMod(const uint512_t& x, const uint512_t& y, const uint512_t& p);
uint512_t ExpMod(const uint512_t& x, const uint512_t& y, const uint512_t& p);
```

Ham cua de trong `dh_sample.h`, **giữ đúng chữ ký**; TV1 hiện thực trong `modular.cpp`:

```cpp
uint512_t modular_exponentiation(
    const uint512_t& base, const uint512_t& exp, const uint512_t& mod);
```

## TV2 - So nguyen to

Khai bao `prime.h`:

```cpp
bool is_probable_prime(prng_ctx* ctx, const uint512_t& n, int rounds = 32);
```

Ham co san trong `dh_sample.h`, TV2 cai dat trong `prime.cpp`:

```cpp
uint512_t generate_safe_prime(prng_ctx* ctx, size_t bitsize = 512);
```

Chu y Miller-Rabin la phep thu **xac suat**; can nhieu vong va test. `p=2q+1` va ca 2 so phai qua kiem tra.

## TV3 - Giao thuc Diffie-Hellman

Ham mau co san trong `dh_sample.h`, TV3 cai dat trong `dh.cpp`:

```cpp
uint512_t generate_private_key(prng_ctx* ctx, const uint512_t& p);
```

Khai bao `dh.h`:

```cpp
uint512_t choose_generator(const uint512_t& p);
DHResult run_diffie_hellman(prng_ctx* ctx, size_t bitsize = 512);
```

`DHResult` dinh nghia tai `dh.h` theo cac field p, g, a_private, b_private, A_public, B_public, alice_shared, bob_shared.

## Quy tac va phu thuoc

- Chuan **C++14**, build **Linux/WSL g++** (bo PRNG mau dung `getrandom`; MSVC khong ho tro nguyen trang).
- `Mod(x, 0)`, modular p=0, ctx null, bitsize khac 512: bao loi ro rang (`std::invalid_argument`).
- TV1 hoan thanh so hoc va `ExpMod` -> TV2 goi vao Miller-Rabin -> TV3 ghep giao thuc.
- TV3 sinh khoa rieng **deu** trong `[2, p-2]`, nen dung rejection sampling, khong rut gon truc tiep bang `%` neu gay bias.
- TV3 chon g dua tren `q=(p-1)/2`, kiem `g^2 mod p != 1` va `g^q mod p != 1` voi safe prime p (g thuoc nhom nhan modulo p).
- Khong dung seed co dinh trong chuong trinh thuc, khong log khoa rieng.
- Cac ham dang `TODO` se throw `std::logic_error`: **build thanh cong khong co nghia do an da hoan thanh**.
- Thay doi ten ham/field phai duoc nhom dong y truoc khi merge.
