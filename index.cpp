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
    cout << "========================================" << endl;
    cout << setw(5) << left << "No" << setw(30) << "Daftar Menu Makanan" << setw(10) << "Harga" << endl;
    cout << string(40, '-') << endl;

    for (int i = 0; i < 10; i++) { // 10 makanan
        cout << setw(5) << left << (i + 1) << setw(30) << left << daftarMenu[i].namaMakanan 
             << setw(10) << daftarMenu[i].hargaPerPorsi << endl;
    }
}

// Fungsi untuk menampilkan daftar menu minuman
void tampilkanMenuMinuman() {
    cout << "========================================" << endl;
    cout << setw(5) << left << "No" << setw(30) << "Daftar Menu Minuman" << setw(10) << "Harga" << endl;
    cout << string(40, '-') << endl;

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
        cout << "Masukkan menu yang dipilih (nomor menu)    : ";
        cin >> nomorMenu;
        cout << "Masukkan jumlah yang ingin dibeli (angka)  : ";
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
double terapkanDiskon(int totalHarga, const vector<int>& jumlahBeli) {
    // Diskon Rp 2000 jika membeli lebih dari 5 porsi
    int totalPorsi = 0;
    for (size_t i = 0; i < jumlahBeli.size(); i++) {
        totalPorsi += jumlahBeli[i];
    }
    if (totalPorsi > 5) {
        totalHarga -= 2000; // Diskon Rp2000
    }
    return totalHarga;  // Tidak ada diskon lainnya
}

// Fungsi untuk mencetak struk pembelian
void cetakStrukPembelian(const vector<int>& pilihanMenu, const vector<int>& jumlahBeli, double totalHarga, double diskon, double uangDibayar) {
    cout << "\n===========================\n";
    cout << "\tWAROENG SSS";
    cout << "\n===== Struk Pembelian =====\n";
    for (size_t i = 0; i < pilihanMenu.size(); i++) {
        cout << "Makanan : " << daftarMenu[pilihanMenu[i] - 1].namaMakanan << "\n";
        cout << "Jumlah  : " << jumlahBeli[i] << "\n";
    }
    cout << "\n===========================\n";
    cout << "Total Harga : Rp" << totalHarga << endl;
    cout << "Diskon      : Rp" << diskon << endl;
    cout << "Total bayar : Rp" << (totalHarga - diskon) << endl; // Menampilkan total setelah diskon
    cout << "\n===========================\n";
}

// Fungsi untuk memeriksa tempat makan yang kosong
bool cekTempatMakanTersedia() {
    return jumlahTempatTerisi < MAX_SEATS; // Cek apakah masih ada tempat kosong
}

// Fungsi untuk menampilkan jumlah meja yang tersisa
void tampilkanMejaTersisa() {
    int sisaMeja = MAX_SEATS - jumlahTempatTerisi;
    cout << endl;
    cout << "Jumlah meja yang tersedia  : " << sisaMeja << endl;
}

// Fungsi untuk melakukan pembayaran
void lakukanPembayaran(double totalHarga, double uangDibayar) {
    // Memeriksa apakah uang yang dibayarkan cukup
    if (uangDibayar >= totalHarga) {
        double kembalian = uangDibayar - totalHarga;
        cout << "Pembayaran berhasil!" << endl;
        cout << "Kembalian : Rp" << kembalian << endl;
    } else {
        cout << "Uang Anda tidak cukup! Anda masih kekurangan : Rp" 
             << (totalHarga - uangDibayar) << endl;
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

    cout << "+===============================================================================+" << endl;
    cout << "|\t _       __                                     _______________\t\t|" << endl;
    cout << "|\t| |     / /___ __________  ___  ____  ____ _   / ___/ ___/ ___/\t\t|" << endl;
    cout << "|\t| | /| / / __ `/ ___/ __ \\/ _ \\/ __ \\/ __ `/   \\__ \\\\__ \\\\__ \\\t\t|" << endl;
    cout << "|\t| |/ |/ / /_/ / /  / /_/ /  __/ / / / /_/ /   ___/ /__/ /__/ /\t\t|" << endl;
    cout << "|\t|__/|__/\\__,_/_/   \\____/\\___/_/ /_/\\__, /   /____/____/____/  \t\t|" << endl;
    cout << "|\t                                   /____/                     \t\t|" << endl;
    cout << "+===============================================================================+" << endl;
    cout << endl;

cout << "+===============================================================================+" << endl;
    cout << " _        _                                 _  _       _                 __ __ __" << endl;  
    cout << " \ \      / /_ _ _ _ __   _ _ _   _ _  |  \/  | _ _| | __ _ _ _   / _/ _/ _| " << endl;
    cout << "  \ \ /\ / / ` | '/ _ \ / _ \ ' \ / ` | | |\/| |/ _` | |/ / _` | ' \  \_ \_ \_ \ " << endl;
    cout << "   \ V  V / (| | | | () |  _/ | | | (| | | |  | | (| |   < (| | | | |  _) |_) |_) |" << endl;
    cout << "    \/\/ \_,||  \_/ \_|| ||\, | ||  ||\,||\\_,|| || |_/_/__/ " << endl;
    cout << "                                      |_/                                                  " << endl;
    cout << "+===============================================================================+" << endl;
    
    cout << "+==============================================================================================+" << endl;
	cout << "   _____      __                      __     ____        __                           ___ " << endl;
	cout << "  / ___/___  / /___ _____ ___  ____ _/ /_   / __ ___ _/ /_____ _____  ____ _   ____/ (_)" << endl;
	cout << "  \__ \/ _ \/ / __ `/ __ `__ \/ __ `/ __/  / / / / __ `/ __/ __ `/ __ \/ __ `/  / __  / / " << endl;
	cout << " ___/ /  __/ / /_/ / / / / / / /_/ / /_   / /_/ / /_/ / /_/ /_/ / / / / /_/ /  / /_/ / /  " << endl;
	cout << "/____/\___/_/\__,_/_/ /_/ /_/\__,_/\__/  /_____/\__,_/\__/\__,_/_/ /_/\__, /   \__,_/_/   " << endl;
	cout << "                                                                     /____/               " << endl;
	cout << "                                                                                                " << endl;
	cout << " _       __                                     __  ___      __                  _______________" << endl;
	cout << "| |     / /___ __________  ___  ____  ____ _   /  |/  /___ _/ /______ _____     / ___/ ___/ ___/" << endl;
	cout << "| | /| / / __ `/ ___/ __ \/ _ \/ __ \/ __ `/  / /|_/ / __ `/ //_/ __ `/ __ \    \__ \\__ \\__ \ " << endl;
	cout << "| |/ |/ / /_/ / /  / /_/ /  __/ / / / /_/ /  / /  / / /_/ / ,< / /_/ / / / /   ___/ /__/ /__/ / " << endl;
	cout << "|__/|__/\__,_/_/   \____/\___/_/ /_/\__, /  /_/  /_/\__,_/_/|_|\__,_/_/ /_/   /____/____/____/  " << endl;
	cout << "                                   /____/                                                       " << endl;
    cout << "+==============================================================================================+" << endl;
    
    char pilihan;
    
    cout << "Apakah Anda ingin makan di sini? (y/n) : ";
    cin >> pilihan;
    
	system("cls");

    if (pilihan != 'y' && pilihan != 'Y' && pilihan != 'n' && pilihan != 'N') {
        cout << "Input tidak valid! Program akan keluar secara paksa" << endl;
        return 1; // Keluar dari program
    }

        if (pilihan == 'y' || pilihan == 'Y') {
        if (!cekTempatMakanTersedia()) {
            // ... (penanganan tempat penuh)
        } else {
            tampilkanSemuaMenu();
            jumlahTempatTerisi++; // Menandai bahwa satu tempat telah terisi
            tampilkanMejaTersisa(); // Menampilkan meja yang tersisa
        }
    } else {
        tampilkanSemuaMenu();
    }

    // Menampilkan harga terendah dan tertinggi
    int hargaTerendah = cariHargaTerendah(daftarMenu, MAX_MENU_ITEMS);
    int hargaTertinggi = cariHargaTertinggi(daftarMenu, MAX_MENU_ITEMS);
    
    cout << endl;
    cout << "Harga terendah dalam menu  : Rp" << hargaTerendah << endl;
    cout << "Harga tertinggi dalam menu : Rp" << hargaTertinggi << endl;
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
        double diskon = 0; // Inisialisasi diskon
        double totalDenganDiskon = terapkanDiskon(totalHarga, jumlahBeli);  // Terapkan diskon
        
        // Hitung diskon yang diterapkan
        if (totalHarga > totalDenganDiskon) {
            diskon = totalHarga - totalDenganDiskon;
        }

        // Tampilkan total harga dan diskon sebelum pembayaran
        cout << endl;
        cout << "Total Harga           : Rp" << totalHarga << endl;
        cout << "Diskon                : Rp" << diskon << endl;
        cout << "Total bayar           : Rp" << (totalHarga - diskon) << endl;

        double uangDibayar;
        cout << "Masukkan nominal uang : Rp";
        cin >> uangDibayar;

		system("cls");
		
        // Cetak struk pembelian dengan informasi baru
        cetakStrukPembelian(pilihanMenu, jumlahBeli, totalHarga, diskon, uangDibayar);

        // Lakukan pembayaran
        lakukanPembayaran(totalHarga - diskon, uangDibayar); // Pass total setelah diskon ke fungsi ini
    } else {
        cout << "Stok tidak mencukupi untuk pesanan Anda" << endl;
    }

    return 0; // Mengakhiri program
}
