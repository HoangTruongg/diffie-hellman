# Phan cong nhom - Lab01

| Thanh vien | Can lam gi | Code o dau | Bao cao |
|---|---|---|---|
| **TV1** | Hoan thien cac phep toan `uint512_t`; `from_u64`, `get_bit`, `shift_right_one`, `to_hex`; `Mod`, `AddMod`, `MultMod`, `ExpMod`, `modular_exponentiation` | `project_01_source/u512.cpp`, `project_01_source/modular.cpp`; tham khao `u512_sample.h` va pseudocode modular | So lon va phep toan mo-dun |
| **TV2** | Dung PRNG SHAKE128 mau; cai dat Miller-Rabin; sinh safe prime `p=2q+1` 512 bit | `project_01_source/prime.cpp`, `prime.h`, `lib/fips202/` | Miller-Rabin, safe prime, PRNG |
| **TV3** | Sinh khoa rieng; chon g hop le; tich hop Alice/Bob; dieu khien `main`; kiem thu dau-cuoi | `project_01_source/dh.cpp`, `dh.h`, `main.cpp` | Diffie-Hellman, huong dan chay, ket qua, tong hop |

**Chung:** tu kiem thu phan minh, review code, ghep bao cao PDF, dong goi theo ten MSSV trong de.

**Ghi nho:** khong thay doi chu ky ham da co trong `dh_sample.h`. Xem [API_CHUNG.md](API_CHUNG.md).
