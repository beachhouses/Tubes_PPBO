// main.cpp
#include "MoodBites.h"

int main() {
    MoodBites resto;
    string nama;
    int pilihan;

    resto.tampilkanJudul();

    cout << KUNING << BOLD << "Halo selamat datang di MoodBites!\n";
    cout << "Masukkan nama kamu: ";
    getline(cin, nama); 
    resto.setNamaCustomer(nama);

    resto.pilihMood();

    do {
        cout << MERAH << "\n===== Menu Utama =====\n";
        cout << KUNING << "1. Lihat Menu\n";
        cout << "2. Buat Pesanan\n";
        cout << "3. Periksa Pesanan\n";
        cout << "4. Pembayaran\n";
        cout << "5. Keluar\n";
        cout << MERAH << "======================\n";
        cout << RESET << KUNING << "Masukkan pilihanmu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                resto.tampilkanMenu();
                break;
            case 2:
                resto.buatPesanan();
                break;
            case 3:
                resto.periksaPesanan();
                break;
            case 4:
                resto.pembayaran();
                break;
            case 5:
                cout << KUNING << "Terima kasih sudah mampir di MoodBites! Sampai jumpa lagi!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
