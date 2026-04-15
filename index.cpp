#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Kode warna ANSI
#define RESET   "\033[0m"
#define GREEN   "\033[32m"

// Struktur untuk menyimpan informasi makanan
struct Makanan {
    string namaMakanan;    // Nama makanan
    int hargaPerPorsi;     // Harga per porsi
    int jumlahStok;        // Jumlah stok yang  
};

// Konstanta untuk jumlah maksimal menu
const int MAX_MENU_ITEMS = 24; // Total menu makanan dan minuman
const int MAX_SEATS = 10;      // Kapasitas tempat makan

Makanan daftarMenu[MAX_MENU_ITEMS] = {
    {"Soto", 5000, 20},
    {"Timlo Komplit", 8000, 15},
    {"Nasi Bandeng", 5000, 10},
    {"Nasi Usus", 7000, 5},
    {"Nasi Ati Lombok Ijo", 7000, 8},
    {"Nasi Oseng / Sayur", 5000, 10},
    {"Nasi Ayam", 11000, 10},
    {"Mie Rebus / Goreng", 5000, 10},
    {"Mie Rebus / Goreng + Telur", 8000, 5},
    {"Gorengan", 1000, 30},
    {"Air Es", 1000, 50},
    {"Air Mineral", 3000, 30},
    {"Teh Panas", 2000, 25},
    {"Es Teh", 2500, 20},
    {"Jeruk Es / Panas", 3000, 20},
    {"Nutrisari Es", 3000, 20}, 
    {"Milo Panas / Es", 3500, 20},
    {"Cappuccino Panas / Es", 3500, 20},
    {"Beng Beng Panas / Es", 3500, 20},
    {"White Coffee Panas / Es", 3000, 20},
    {"Good Day Panas / Es", 3000, 25}, 
    {"Susu Panas / Es", 3000, 25},
    {"Pop Ice", 3000, 15},
    {"Kopi Hitam", 3000, 20}
};

int jumlahTempatTerisi = 0; // Menghitung jumlah tempat yang terisi

// Fungsi untuk menampilkan daftar menu makanan
void tampilkanMenuMakanan() {
    cout << endl;
    cout << "============ DAFTAR MENU MAKANAN ============" << endl;
    cout << setw(5) << left << "No." << setw(30) << "Menu Makanan" << setw(10) << "Harga" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < 10; i++) { // 10 makanan
        cout << setw(5) << left << (i + 1) << setw(30) << left << daftarMenu[i].namaMakanan 
             << setw(10) << daftarMenu[i].hargaPerPorsi << endl;
    }
}

// Fungsi untuk menampilkan daftar menu minuman
void tampilkanMenuMinuman() {
    cout << "============ DAFTAR MENU MINUMAN ============" << endl;
    cout << setw(5) << left << "No." << setw(30) << "Menu Minuman" << setw(10) << "Harga" << endl;
    cout << string(45, '-') << endl;

    for (int i = 10; i < MAX_MENU_ITEMS; i++) { // 14 minuman
        cout << setw(5) << left << (i + 1) << setw(30) << left << daftarMenu[i].namaMakanan 
             << setw(10) << daftarMenu[i].hargaPerPorsi << endl;
    }
}

// Fungsi untuk menampilkan semua menu
void tampilkanSemuaMenu() {
    tampilkanMenuMakanan();
    cout << endl; // Baris kosong
    tampilkanMenuMinuman();
}

// Fungsi untuk menginput makanan yang dibeli
void inputMakananYangDibeli(vector<int>& pilihanMenu, vector<int>& jumlahBeli) {
    int nomorMenu, jumlahPesan;
    char lanjut;
    do {
        cout << "Masukkan nomor menu yang dipilih: ";
        cin >> nomorMenu;
        cout << "Masukkan jumlah yang ingin dibeli: ";
        cin >> jumlahPesan;
        
        pilihanMenu.push_back(nomorMenu);
        jumlahBeli.push_back(jumlahPesan);

        cout << "Apakah Anda ingin membeli menu lain? (y/n): ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');
}

// Fungsi untuk memeriksa ketersediaan stok
bool validasiKetersediaanStok(const vector<int>& pilihanMenu, const vector<int>& jumlahBeli) {
    for (size_t i = 0; i < pilihanMenu.size(); i++) {
        if (daftarMenu[pilihanMenu[i] - 1].jumlahStok < jumlahBeli[i]) {
            return false;  // Jika stok tidak mencukupi
        }
    }
    return true;  // Jika stok mencukupi
}

// Fungsi untuk menghitung total harga makanan
int hitungTotalHargaMakanan(const vector<int>& pilihanMenu, const vector<int>& jumlahBeli) {
    int totalHarga = 0;
    for (size_t i = 0; i < pilihanMenu.size(); i++) {
        totalHarga += daftarMenu[pilihanMenu[i] - 1].hargaPerPorsi * jumlahBeli[i];
    }
    return totalHarga;
}

// Fungsi untuk menerapkan diskon pada total harga
double terapkanDiskon(int totalHarga, const vector<int>& jumlahBeli) {
    // Diskon Rp 2000 jika membeli lebih dari 5 porsi
    int totalPorsi = 0;
    for (size_t i = 0; i < jumlahBeli.size(); i++) {
        totalPorsi += jumlahBeli[i];
    }
    if (totalPorsi > 5) {
        totalHarga -= 2000; // Diskon Rp 2000
    }
    return totalHarga;  // Tidak ada diskon lainnya
}

// Fungsi untuk mencetak struk pembelian
void cetakStrukPembelian(const vector<int>& pilihanMenu, const vector<int>& jumlahBeli, double totalHarga, double diskon, double uangDibayar) {
    cout << "\n===========================\n";
    cout << "\tWAROENG SSS";
    cout << "\n===== Struk Pembelian =====\n";
    for (size_t i = 0; i < pilihanMenu.size(); i++) {
        cout << "Makanan: " << daftarMenu[pilihanMenu[i] - 1].namaMakanan << "\n";
        cout << "Jumlah: " << jumlahBeli[i] << "\n";
    }
    cout << "\n===========================\n";
    cout << "Total Harga: Rp " << totalHarga << endl;
    cout << "Diskon: Rp " << diskon << endl;
    cout << "Total yang harus dibayar setelah diskon: Rp " << (totalHarga - diskon) << endl; // Menampilkan total setelah diskon
    cout << "\n===========================\n";
}

// Fungsi untuk memeriksa tempat makan yang kosong
bool cekTempatMakanTersedia() {
    return jumlahTempatTerisi < MAX_SEATS; // Cek apakah masih ada tempat kosong
}

// Fungsi untuk menampilkan jumlah meja yang tersisa
void tampilkanMejaTersisa() {
    int sisaMeja = MAX_SEATS - jumlahTempatTerisi;
    cout << "\nMeja yang tersisa: " << sisaMeja << endl;
}

// Fungsi untuk melakukan pembayaran
void lakukanPembayaran(double totalHarga, double uangDibayar) {
    // Memeriksa apakah uang yang dibayarkan cukup
    if (uangDibayar >= totalHarga) {
        double kembalian = uangDibayar - totalHarga;
        cout << "Pembayaran berhasil!" << endl;
        cout << "Kembalian: Rp " << kembalian << endl;
    } else {
        cout << "Uang yang dibayarkan tidak cukup. Anda masih kekurangan: Rp " 
             << (totalHarga - uangDibayar) << endl;
    }
}

int main() {
    // Menampilkan judul dengan warna hijau
    cout << GREEN << "=============================================================\n" << RESET;
    cout << GREEN << " _       __                                     _______________\n" << RESET;
    cout << GREEN << "| |     / /___ __________  ___  ____  ____ _   / ___/ ___/ ___/\n" << RESET;
    cout << GREEN << "| | /| / / __ `/ ___/ __ \\/ _ \\/ __ \\/ __ `/   \\__ \\\\__ \\\\__ \\\n" << RESET;
    cout << GREEN << "| |/ |/ / /_/ / /  / /_/ /  __/ / / / /_/ /   ___/ /__/ /__/ /\n" << RESET;
    cout << GREEN << "|__/|__/\\__,_/_/   \\____/\\___/_/ /_/\\__, /   /____/____/____/  \n" << RESET;
    cout << GREEN << "                                   /____/                       \n" << RESET;
    cout << GREEN << "=============================================================\n\n" << RESET;

    char pilihan;
    
    cout << "Apakah Anda ingin makan di sini? (y/n): ";
    cin >> pilihan;

    if (pilihan != 'y' && pilihan != 'Y' && pilihan != 'n' && pilihan != 'N') {
        cout << "Input tidak valid. Program akan keluar." << endl;
        return 1; // Keluar dari program
    }

    if (pilihan == 'y' || pilihan == 'Y') {
        if (!cekTempatMakanTersedia()) {
            cout << "Maaf tempat makan kami sedang penuh, apakah Anda jadi membeli di sini? (y/n): ";
            cin >> pilihan;
            if (pilihan == 'y' || pilihan == 'Y') {
                cout << "Daftar Menu Waroeng SSS:\n";
                tampilkanSemuaMenu();
            } else {
                return 0; // Keluar dari program
            }
        } else {
            cout << "Daftar Menu Waroeng SSS:\n";
            tampilkanSemuaMenu();
            jumlahTempatTerisi++; // Menandai bahwa satu tempat telah terisi
            tampilkanMejaTersisa(); // Menampilkan meja yang tersisa
        }
    } else {
        cout << "Daftar Menu Waroeng SSS:\n";
        tampilkanSemuaMenu();
    }

    // Konfirmasi sebelum melanjutkan
    cout << "Apakah Anda yakin ingin beli disini? (y/n): ";
    cin >> pilihan;
    if (pilihan != 'y' && pilihan != 'Y') {
        cout << "Pembelian dibatalkan." << endl;
        return 0; // Keluar dari program
    }

    // Proses pemesanan
    vector<int> pilihanMenu;
    vector<int> jumlahBeli;

    inputMakananYangDibeli(pilihanMenu, jumlahBeli); // Input makanan yang dibeli

    if (validasiKetersediaanStok(pilihanMenu, jumlahBeli)) {
        for (size_t i = 0; i < pilihanMenu.size(); i++) {
            daftarMenu[pilihanMenu[i] - 1].jumlahStok -= jumlahBeli[i];  // Kurangi stok
        }

        int totalHarga = hitungTotalHargaMakanan(pilihanMenu, jumlahBeli);
        double diskon = 0; // Inisialisasi diskon
        double totalDenganDiskon = terapkanDiskon(totalHarga, jumlahBeli);  // Terapkan diskon
        
        // Hitung diskon yang diterapkan
        if (totalHarga > totalDenganDiskon) {
            diskon = totalHarga - totalDenganDiskon;
        }

        // Tampilkan total harga dan diskon sebelum pembayaran
        cout << "\nTotal Harga: Rp " << totalHarga << endl;
        cout << "Diskon: Rp " << diskon << endl;
        cout << "Total yang harus dibayar setelah diskon: Rp " << (totalHarga - diskon) << endl;

        double uangDibayar;
        cout << "Masukkan jumlah uang yang dibayarkan: Rp ";
        cin >> uangDibayar;

        // Cetak struk pembelian dengan informasi baru
        cetakStrukPembelian(pilihanMenu, jumlahBeli, totalHarga, diskon, uangDibayar);

        // Lakukan pembayaran
        lakukanPembayaran(totalHarga - diskon, uangDibayar); // Pass total setelah diskon ke fungsi ini
    } else {
        cout << "Stok tidak mencukupi untuk pesanan Anda." << endl;
    }

    return 0; // Mengakhiri program
}
