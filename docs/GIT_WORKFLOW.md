# Huong dan GitHub cho nhom 3 nguoi

## Buoc 1 - Tao repo va push khung

Tao repository rong tren GitHub. Trong folder goc cua bo khung (co `README.md`):

```bash
git init -b main
git add .
git commit -m "chore: initialize Lab01 project skeleton"
git remote add origin https://github.com/<USERNAME>/<REPO>.git
git push -u origin main
```

Doi `<USERNAME>` va `<REPO>` thanh thong tin GitHub that.

## Buoc 2 - Moi thanh vien

Repo -> Settings -> Collaborators -> Add people. Moi hai thanh vien con lai, moi nguoi clone va tao branch rieng.

## Buoc 3 - Lam viec theo branch

| Nguoi | Branch | File nen sua |
|---|---|---|
| TV1 | `feat/tv1-bigint-modular` | `u512.cpp`, `modular.cpp`, test phep toan |
| TV2 | `feat/tv2-prime-prng` | `prime.cpp`, test nguyen to, PRNG neu can |
| TV3 | `feat/tv3-diffie-hellman` | `dh.cpp`, `main.cpp`, test DH, report |

Moi nguoi chay (vi du TV1):

```bash
git clone https://github.com/<USERNAME>/<REPO>.git
cd <REPO>
git switch -c feat/tv1-bigint-modular
# code va test
git add .
git commit -m "feat(tv1): implement big integer operations"
git push -u origin feat/tv1-bigint-modular
```

Tao Pull Request tu branch vao `main`, review va merge. Tranh ba nguoi cung sua `main.cpp` hoac mau header goc.

## Buoc 4 - Chuan bi nop

- Tich hop code, thay TODO, chay bo kiem thu **thuat toan** (khong chi scaffold smoke test).
- Bao cao PDF hoan chinh trong `project_01_report/`.
- Nén hai thư mục `project_01_source/` và `project_01_report/` thành ZIP theo thứ tự MSSV do đề bài yêu cầu.
- `README.md`, `docs/`, `.github/` phuc vu GitHub; neu de yeu cau cau truc ZIP chinh xac thi chi dong goi 2 thu muc bai nop.
