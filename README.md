# Lab01 - So nguyen to & trao doi khoa Diffie-Hellman

> **Repo khoi tao / chua phai bai nop hoan chinh.** Ma nguon co san cac khai bao va khung noi module; cac ham BigInt, modular, Miller-Rabin, safe prime, sinh khoa rieng hien **CHUA cai dat**. Moi ham chua lam se `throw std::logic_error("TODO(...)")` thay vi tra gia tri gia.

## 1. Yeu cau va tai lieu

- Mon: Nhap mon ma hoa mat ma - Lab01.
- Ngon ngu: **C++14**; phien ban khung: dung `uint512_t` co dinh 512 bit.
- De bai: `Lab01.pdf` (giao vien cung cap); ma gia: `pseudocode-modular-operation.pdf`; bo mau: `prng_sample.zip`.
- Khong them cac binary `bin/`, file seed hoac khoa rieng vao Git.
- **Moi truong khuyen nghi:** Linux / WSL Ubuntu voi `g++` va `make`. Phan PRNG mau dung `getrandom` va `uint512_t` mau dung `__uint128_t`, khong biên dich nguyen trang bang MSVC.

## 2. Phan cong

| Nguoi | Phu trach | File chu yeu |
|---|---|---|
| TV1 | `uint512_t`, `Mod`, `AddMod`, `MultMod`, `ExpMod`, `modular_exponentiation` | `u512.cpp`, `modular.cpp` |
| TV2 | PRNG, Miller-Rabin, `generate_safe_prime` | `prime.cpp`, `lib/fips202/` |
| TV3 | `generate_private_key`, `choose_generator`, Diffie-Hellman, main, tich hop | `dh.cpp`, `main.cpp` |

Chi tiet: [docs/PHAN_CONG.md](docs/PHAN_CONG.md). Hop dong API: [docs/API_CHUNG.md](docs/API_CHUNG.md).

## 3. Cau truc thu muc

```text
.
├── README.md
├── .gitignore
├── .github/workflows/build.yml          # CI: compile va kiem tra khung
├── docs/
│   ├── API_CHUNG.md
│   ├── PHAN_CONG.md
│   └── GIT_WORKFLOW.md
├── project_01_source/
│   ├── Makefile
│   ├── u512_sample.h                    # Giu ban goc cua giang vien
│   ├── u512_utils.h                     # Khai bao helpers duoc nhom bo sung
│   ├── u512.cpp                         # TV1
│   ├── modular.h / modular.cpp          # TV1
│   ├── prime.h / prime.cpp              # TV2
│   ├── dh_sample.h                      # Giu ban goc cua giang vien
│   ├── dh.h / dh.cpp                    # TV3
│   ├── main.cpp                         # TV3
│   ├── lib/fips202/                     # Ban goc PRNG giang vien
│   ├── tests/test_scaffold.cpp          # Chi test khoi tao, CHUA test thuat toan
│   └── examples/main_prng_sample.cpp    # Vi du goc, khong build chung main
└── project_01_report/
    └── README.md                        # Huong dan dat PDF (chua co report)
```

> Giữ nguyên hai file mẫu `.h`. Để không chỉnh sửa mã của giảng viên, các hàm bổ sung `from_u64`, `get_bit`, `shift_right_one`, `to_hex` được khai báo trong `u512_utils.h` thay vì thêm trực tiếp vào `u512_sample.h`. Chữ ký 3 hàm có sẵn trong `dh_sample.h` **không đổi**.

## 4. Bien dich / chay khung

```bash
cd project_01_source
make                # Bien dich, chua chay Diffie-Hellman hoan chinh
make test           # Test PRNG + khoi tao/headers + smoke, CHUA la test tinh dung DH
make run            # In huong dan, thong bao TODO
./bin/lab01 --help
./bin/lab01 --check-prng
./bin/lab01 --demo # Hien tai tra loi TODO; chi chay duoc sau khi hoan thanh module
```

**Vi sao --demo chua chay?** Vi `generate_safe_prime` va nhieu ham dang la placeholder. Chuc nang chi duoc xem la hoan thanh khi test thuat toan + trao doi khoa Alice/Bob deu dat.

## 5. Day len GitHub

1. Tao **repo rong** tren GitHub, vi du `lab01-diffie-hellman` (khong chon auto README neu dung README nay).
2. Mo terminal trong **thu muc goc** (`Lab01_Diffie_Hellman_GitHub_Starter`), chay:

```bash
git init -b main
git add .
git commit -m "chore: initialize Lab01 Diffie-Hellman scaffold"
git remote add origin https://github.com/<USERNAME>/<REPO>.git
git push -u origin main
```

3. Moi 2 ban con lai vao GitHub repo. Moi nguoi tao branch rieng va mo pull request sau khi code/test.

Huong dan Git chi tiet: [docs/GIT_WORKFLOW.md](docs/GIT_WORKFLOW.md).

## 6. Luu y noi dung do an

- Safe prime `p` la so nguyen to, `q=(p-1)/2` la so nguyen to. Miller-Rabin la phep thu xac suat.
- Khoa rieng Alice/Bob can ngau nhien va nam trong `[2, p-2]`.
- `g` phai duoc kiem tra hop le (khong mac dinh `g=2` la phan tu sinh).
- Can kiem tra `A=g^a mod p`, `B=g^b mod p`, va `B^a mod p == A^b mod p`.
- Khung nay chi ho tro `bitsize == 512` theo thoa thuan. Tham so lon hon can mo rong kieu so truoc.
- 512 bit dung de dap ung bai tap, **khong phu hop cho trien khai mat ma thuc te**.
- Khi nop, dong goi theo de: `project_01_source/` + `project_01_report/*.pdf` trong ZIP duoc dat ten theo MSSV.
