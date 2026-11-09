# Sample provided by lecturer

`main_prng_sample.cpp` is kept **as provided** in `prng_sample.zip` for reference, and it is **NOT** included in `Makefile` builds (it has another `main`).

**Warning:** the sample only initializes a few bytes of `seed[32]` using `memcpy`. It is not safe to treat all 32 seed bytes as initialized. `main.cpp` in this repo instead initializes the full seed array and obtains entropy with `randombytes()` from the OS (Linux/WSL).
