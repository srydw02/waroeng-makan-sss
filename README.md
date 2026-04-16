# 🍽️ Waroeng Makan SSS - CLI Cashier System

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![CLI](https://img.shields.io/badge/CLI-Terminal-black?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

**Waroeng Makan SSS** adalah program simulasi kasir dan *Point of Sale* (POS) berbasis *Command Line Interface* (CLI) yang ditulis menggunakan C++. Program interaktif ini mensimulasikan operasional restoran secara *real-time* dengan fitur manajemen pesanan *multi-item*, validasi stok, perhitungan PPN 11%, dan diskon bertingkat secara otomatis.

---

## ✨ Fitur Unggulan

Program ini dilengkapi dengan berbagai fitur komprehensif untuk menyimulasikan sistem kasir dunia nyata:

* **🎨 Interactive ASCII Art:** Menampilkan *banner* selamat datang berbentuk *ASCII Art* yang menarik saat program pertama kali dieksekusi.
* **🪑 Dine-in & Takeaway Logic:** Mendukung pilihan makan di tempat (*Dine-in*) dengan sistem pemilihan nomor meja (kapasitas 1-10 meja) atau dibungkus (*Takeaway*).
* **🛒 Multi-Item Dynamic Ordering:** Pengguna dapat memesan lebih dari satu jenis menu dalam satu transaksi secara dinamis berkat penggunaan `std::vector`.
* **📦 Real-time Stock Validation:** Sistem mengecek ketersediaan stok sebelum memproses pembayaran. Stok akan otomatis berkurang jika pesanan berhasil.
* **🏷️ Smart Discount System:** Potongan harga otomatis berdasarkan total belanja:
    * Belanja > Rp50.000 ➔ Diskon Rp7.000
    * Belanja > Rp30.000 ➔ Diskon Rp5.000
    * Belanja > Rp10.000 ➔ Diskon Rp2.000
* **🧾 Auto-Generated Receipt:** Mencetak struk belanja yang rapi menggunakan manipulasi *string* (`<iomanip>`), menampilkan rincian pesanan, harga total, diskon, PPN 11%, uang tunai, dan kembalian.

---

## 🛠️ Teknologi & Struktur Data

Proyek ini dibangun menggunakan pustaka standar C++:
* **Bahasa:** C++
* **Library:** `<iostream>`, `<iomanip>`, `<vector>`, `<string>`
* **Struktur Data:**
    * `struct Makanan`: Mengelola entitas menu (Nama, Harga, Stok).
    * `std::vector<int>`: Menyimpan riwayat pesanan pengguna secara dinamis.
    * `Array of Struct`: Sebagai database lokal untuk 25 daftar menu makanan dan minuman.

---

## 🚀 Cara Menjalankan Program

Untuk menjalankan program ini di komputer Anda, pastikan *compiler* C++ (seperti GCC/MinGW) sudah terinstal.

1.  **Clone repository ini:**
    ```bash
    git clone [https://github.com/srydw02/waroeng-makan-sss.git](https://github.com/srydw02/waroeng-makan-sss.git)
    ```
2.  **Masuk ke direktori proyek:**
    ```bash
    cd waroeng-makan-sss
    ```
3.  **Compile kode sumber:**
    ```bash
    g++ index.cpp -o waroeng_sss
    ```
4.  **Jalankan program:**
    * **Windows:** `waroeng_sss.exe`
    * **Linux / Mac:** `./waroeng_sss`

---

## 🔄 Alur Penggunaan

1.  Program menampilkan *banner* utama.
2.  Pengguna memilih opsi makan di tempat atau bawa pulang.
3.  Sistem menampilkan tabel menu beserta analisis harga.
4.  Pengguna memasukkan **Nomor Menu** dan **Jumlah Porsi** secara berulang hingga selesai.
5.  Sistem memvalidasi stok dan menghitung total tagihan (termasuk diskon dan PPN).
6.  Pengguna melakukan pembayaran tunai.
7.  Sistem mencetak **Struk Pembelian** resmi.

---

<p align="center">
  <i>Dibuat oleh Kelompok SSS menggunakan C++ | Proyek Simulasi Kasir</i>
</p>