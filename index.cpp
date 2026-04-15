#include <iostream>
#include <iomanip>

#include <vector>
using namespace std;

// Struktur untuk menyimpan informasi makanan
struct Makanan {
    string namaMakanan;    // Nama makanan
    int hargaPerPorsi;     // Harga per porsi
    int jumlahStok;        // Jumlah stok yang tersedia
};

// Konstanta untuk jumlah maksimal menu
const int MAX_MENU_ITEMS = 25; // Total menu makanan dan minuman
const int MAX_SEATS = 10;      // Kapasitas tempat makan

Makanan daftarMenu[MAX_MENU_ITEMS] = {
    {"Soto", 5000, 20},
    {"Timlo Komplit", 8000, 25},
    {"Nasi Bandeng", 5000, 20},
    {"Nasi Usus", 7000, 25},
    {"Nasi Ati Lombok Ijo", 7000, 20},
    {"Nasi Oseng", 5000, 20},
    {"Nasi Sayur", 5000, 20},
    {"Nasi Ayam", 11000, 20},
    {"Mie Rebus / Goreng", 5000, 20},
    {"Mie Rebus / Goreng + Telur", 8000, 25},
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
    {"Pop Ice", 3000, 25},
    {"Kopi Hitam", 3000, 20}
};

int jumlahTempatTerisi = 0; // Menghitung jumlah tempat yang terisi

// Fungsi untuk menampilkan daftar menu makanan
void tampilkanMenuMakanan() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << setw(5) << left << "NO" << setw(30) << "DAFTAR MENU MAKANAN" << setw(10) << "HARGA" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < 10; i++) { // 10 makanan
        cout << setw(5) << left << (i + 1) << setw(30) << left << daftarMenu[i].namaMakanan 
             << setw(10) << daftarMenu[i].hargaPerPorsi << endl;
    }
}

// Fungsi untuk menampilkan daftar menu minuman
void tampilkanMenuMinuman() {
    cout << "=============================================" << endl;
    cout << setw(5) << left << "NO" << setw(30) << "DAFTAR MENU MINUMAN" << setw(10) << "HARGA" << endl;
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
        cout << "Pilih menu (No. menu)  : ";
        cin >> nomorMenu;
        cout << "Atur jumlahnya (Angka) : ";
        cin >> jumlahPesan;
        
        pilihanMenu.push_back(nomorMenu);
        jumlahBeli.push_back(jumlahPesan);

        cout << endl;
        cout << "Apakah Anda ingin membeli menu yang lain? (y/n) : ";
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
double terapkanDiskon(int totalHarga) {
    double diskon = 0; // Inisialisasi diskon

    if (totalHarga > 50000) {
        diskon = 7000; // Diskon Rp 7000 jika total harga lebih dari 50000
    } else if (totalHarga > 30000) {
        diskon = 5000; // Diskon Rp 5000 jika total harga lebih dari 30000
    } else if (totalHarga > 10000) {
        diskon = 2000; // Diskon Rp 2000 jika total harga lebih dari 10000
    }

    return diskon; // Mengembalikan nilai diskon
}

// Fungsi untuk menghitung pajak PPN
double hitungPPN(int totalHarga) {
    const double PPN_RATE = 0.11; // Tarif PPN 11%
    return totalHarga * PPN_RATE; // Menghitung total pajak
}

// Fungsi untuk mencetak struk pembelian
void cetakStrukPembelian(const vector<int>& pilihanMenu, const vector<int>& jumlahBeli, double totalHarga, double diskon, double ppn, double uangDibayar) {
    cout << "\n ===========================\n";
    cout << "      WAROENG MAKAN SSS     " << endl;
    cout << "  Jl. Singopuran, Kartasura ";
    cout << "\n ---------------------------\n";
    for (size_t i = 0; i < pilihanMenu.size(); i++) {
        cout << " " << daftarMenu[pilihanMenu[i] - 1].namaMakanan << endl;
        cout << " " << jumlahBeli[i] << " X " << daftarMenu[pilihanMenu[i] - 1].hargaPerPorsi << "\t   " << jumlahBeli[i]*daftarMenu[pilihanMenu[i] - 1].hargaPerPorsi << endl;
    }
    cout << "\n ---------------------------\n";
    cout << " Total Harga   : Rp" << totalHarga << endl;
    cout << " Total Diskon  : Rp" << diskon << endl;
    cout << " PPN 11%       : Rp" << ppn << endl; // Menampilkan total pajak
    cout << " ---------------------------\n";
    cout << " Total Belanja : Rp" << (totalHarga - diskon + ppn) << endl; // Menampilkan total setelah diskon dan pajak
    cout << " Uang Tunai    : Rp" << uangDibayar << endl;
}

// Fungsi untuk memeriksa tempat makan yang kosong
bool cekTempatMakanTersedia() {
    return jumlahTempatTerisi < MAX_SEATS; // Cek apakah masih ada tempat kosong
}

// Fungsi untuk memilih meja
int pilihMeja() {
    int meja;
    do {
        cout << "Pilih nomor meja (1 - " << MAX_SEATS << ") : ";
        cin >> meja;
        if (meja < 1 || meja > MAX_SEATS) {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        } else if (meja <= jumlahTempatTerisi) {
            cout << "Meja sudah terisi. Silakan pilih meja lain." << endl;
            meja = -1; // Set meja tidak valid
        }
    } while (meja < 1 || meja > MAX_SEATS);
    return meja;
}

// Fungsi untuk melakukan pembayaran
void lakukanPembayaran(double totalHarga, double uangDibayar) {
    // Memeriksa apakah uang yang dibayarkan cukup
    if (uangDibayar >= totalHarga) {
        double kembalian = uangDibayar - totalHarga;
        cout << " Kembalian     : Rp" << kembalian;
        cout << "\n ---------------------------\n";
        cout << " Pembayaran berhasil!" << endl;
        cout << " Terima kasih atas pembelian Anda" << endl;
    } else {
        cout << " Kembalian     : Rp" << (totalHarga - uangDibayar);
        cout << "\n ---------------------------\n";
        cout << " Uang Anda tidak cukup!" << endl;
    }
}

// Fungsi untuk mencari harga terendah dalam daftar menu
int cariHargaTerendah(const Makanan daftarMenu[], int n) {
    int hargaTerendah = daftarMenu[0].hargaPerPorsi; // Inisialisasi dengan harga pertama
    for (int i = 1; i < n; i++) {
        if (daftarMenu[i].hargaPerPorsi < hargaTerendah) {
            hargaTerendah = daftarMenu[i].hargaPerPorsi; // Update jika ditemukan harga lebih rendah
        }
    }
    return hargaTerendah;
}

// Fungsi untuk mencari harga tertinggi dalam daftar menu
int cariHargaTertinggi(const Makanan daftarMenu[], int n) {
    int hargaTertinggi = daftarMenu[0].hargaPerPorsi; // Inisialisasi dengan harga pertama
    for (int i = 1; i < n; i++) {
        if (daftarMenu[i].hargaPerPorsi > hargaTertinggi) {
            hargaTertinggi = daftarMenu[i].hargaPerPorsi; // Update jika ditemukan harga lebih tinggi
        }
    }
    return hargaTertinggi;
}

int main() {
    // Menampilkan judul
    cout << " +===================================================================================================+" << endl;
    cout << " |                                                                                                   |" << endl;
    cout << " |      _____      _                       _     _____        _                          _ _         |" << endl;
    cout << " |     / ____|    | |                     | |   |  __ \\      | |                        | (_)        |" << endl;
    cout << " |    | (___   ___| | __ _ _ __ ___   __ _| |_  | |  | | __ _| |_ __ _ _ __   __ _    __| |_         |" << endl;
    cout << " |     \\___ \\ / _ \\ |/ _` | '_ ` _ \\ / _` | __| | |  | |/ _` | __/ _` | '_ \\ / _` |  / _` | |        |" << endl;
    cout << " |     ____) |  __/ | (_| | | | | | | (_| | |_  | |__| | (_| | || (_| | | | | (_| | | (_| | |        |" << endl;
    cout << " |    |_____/ \\___|_|\\__,_|_| |_| |_|\\__,_|\\__| |_____/ \\__,_|\\__\\__,_|_| |_|\\__, |  \\__,_|_|        |" << endl;
    cout << " |                                                                            __/ |                  |" << endl;
    cout << " |                                                                           |___/                   |" << endl;
    cout << " |                                                                                                   |" << endl;
    cout << " | __          __                                __  __       _                  _____ _____ _____   |" << endl;
    cout << " | \\ \\        / /                               |  \\/  |     | |                / ____/ ____/ ____|  |" << endl;
    cout << " |  \\ \\  /\\  / /_ _ _ __ ___   ___ _ __   __ _  | \\  / | __ _| | ____ _ _ __   | (___| (___| (___    |" << endl;
    cout << " |   \\ \\/  \\/ / _` | '__/ _ \\ / _ \\ '_ \\ / _` | | |\\/| |/ _` | |/ / _` | '_ \\   \\___ \\\\___ \\\\___ \\   |" << endl;
    cout << " |    \\  /\\  / (_| | | | (_) |  __/ | | | (_| | | |  | | (_| |   < (_| | | | |  ____) |___) |___) |  |" << endl;
    cout << " |     \\/  \\/ \\__,_|_|  \\___/ \\___|_| |_|\\__, | |_|  |_|\\__,_|_|\\_\\__,_|_| |_| |_____/_____/_____/   |" << endl;
    cout << " |                                        __/ |                                                      |" << endl;
    cout << " |                                       |___/                                                       |" << endl;
    cout << " |                                                                                                   |" << endl;
    cout << " +===================================================================================================+" << endl;

    char pilihan;
    
    cout << endl;
    cout << " Apakah Anda ingin makan di sini? (y/n) : ";
    cin >> pilihan;
    
    system("cls");

    if (pilihan != 'y' && pilihan != 'Y' && pilihan != 'n' && pilihan != 'N') {
        cout << "Input tidak valid! Program akan keluar secara paksa" << endl;
        return 1; // Keluar dari program
    }

    if (pilihan == 'y' || pilihan == 'Y') {
        if (!cekTempatMakanTersedia()) {
            cout << "Tempat makan sudah penuh!" << endl;
            return 0; // Keluar dari program
        } else {
            int mejaDipilih = pilihMeja(); // Memilih meja
            tampilkanSemuaMenu();
            jumlahTempatTerisi++; // Menandai bahwa satu tempat telah terisi
        }
    } else {
        tampilkanSemuaMenu();
    }

    // Menampilkan harga terendah dan tertinggi
    int hargaTerendah = cariHargaTerendah(daftarMenu, MAX_MENU_ITEMS);
    int hargaTertinggi = cariHargaTertinggi(daftarMenu, MAX_MENU_ITEMS);
    
    cout << endl;
    cout << "Harga terendah         : Rp" << hargaTerendah << endl;
    cout << "Harga tertinggi        : Rp" << hargaTertinggi << endl;
    cout << endl;

    // Konfirmasi sebelum melanjutkan
    cout << "Apakah Anda yakin ingin beli disini? (y/n) : ";
    cin >> pilihan;
    if (pilihan != 'y' && pilihan != 'Y') {
        cout << "Pembelian dibatalkan" << endl;
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
        double diskon = terapkanDiskon(totalHarga);  // Terapkan diskon
        double ppn = hitungPPN(totalHarga - diskon); // Hitung pajak PPN
        
        // Tampilkan total harga dan diskon sebelum pembayaran
        cout << endl;
        cout << "Total Harga            : Rp" << totalHarga << endl;
        cout << "Total Diskon           : Rp" << diskon << endl;
        cout << "Total Belanja          : Rp" << (totalHarga - diskon + ppn) << endl;
        cout << "Harga di atas sudah termasuk PPN sebesar 11%" << endl; // Menambahkan teks
        cout << endl;
        double uangDibayar;
        cout << "Masukkan uang tunai    : Rp";
        cin >> uangDibayar;

        system("cls");
        
        // Cetak struk pembelian dengan informasi baru
        cetakStrukPembelian(pilihanMenu, jumlahBeli, totalHarga, diskon, ppn, uangDibayar);

        // Lakukan pembayaran
        lakukanPembayaran(totalHarga - diskon + ppn, uangDibayar);
    } else {
        cout << "Maaf, stok tidak mencukupi untuk pesanan Anda." << endl;
    }

    return 0; // Keluar dari program
}
