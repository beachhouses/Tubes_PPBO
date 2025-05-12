// pesanan.cpp
#include "MoodBites.h"

void MoodBites::buatPesanan() {
    tampilkanMenu();
    int pilih, qty, harga;
    string namaMenu;

    cout << KUNING << "\nMasukkan nomor menu yang dipilih: " << RESET;
    cin >> pilih;
    cout << KUNING << "Jumlah yang dipesan: " << RESET;
    cin >> qty;

    if (mood == 1) {
        string menu[] = {"Es Krim Coklat","Brownies Lumer","Milk Tea","Roti Bakar Keju Coklat","Honey Waffle"};
        int hargaMenu[] = {15000,18000,13000,17000,20000};
        namaMenu = menu[pilih-1];
        harga = hargaMenu[pilih-1];
    } else if (mood == 2) {
        string menu[] = {"Burger Jumbo","Mojito","Dimsum Mentai","Tteokbokki Mozarella","Es Teler"};
        int hargaMenu[] = {25000,15000,22000,23000,14000};
        namaMenu = menu[pilih-1];
        harga = hargaMenu[pilih-1];
    } else if (mood == 3) {
        string menu[] = {"Seblak Jeletet","Bakso Mercon","Mie Level","Soda Gembira","Pangsit Meledak"};
        int hargaMenu[] = {20000,22000,18000,12000,16000};
        namaMenu = menu[pilih-1];
        harga = hargaMenu[pilih-1];
    } else if (mood == 4) {
        string menu[] = {"Nasi Bakar Seafood","Rice Bowl Katsu","Korean Toast","Thai Tea","Mie Yamin Pedas Manis"};
        int hargaMenu[] = {25000,22000,15000,13000,20000};
        namaMenu = menu[pilih-1];
        harga = hargaMenu[pilih-1];
    }

    Item item = {namaMenu, harga, qty};
    daftarPesanan[jumlahPesanan] = item;
    jumlahPesanan++;
    totalHarga += harga * qty;
}

void MoodBites::periksaPesanan() {
    cout << KUNING << "\n+============================================+\n";
    cout << "|         PESANAN KAMU                       |\n";
    cout << "+============================================+\n" << RESET;

    for (size_t i = 0; i < jumlahPesanan; i++) {
        cout << KUNING << "| " << setw(2) << i+1 << ". " << setw(22) << left << daftarPesanan[i].namaMenu
            << " x" << daftarPesanan[i].jumlah << " = "
            << daftarPesanan[i].harga * daftarPesanan[i].jumlah << "      |\n";
    }

    cout << KUNING << "+--------------------------------------------+\n";
    cout << KUNING << "| Total: " << totalHarga << setw(19) << " " << "            |\n" << RESET;
    cout << KUNING << "+--------------------------------------------+\n";

    char edit;
    cout << BOLD << "Apakah ingin hapus/edit pesanan? (y/n): " << RESET;
    cin >> edit;
    if (edit == 'y' || edit == 'Y') {
        int no;
        cout << KUNING << "Masukkan nomor pesanan yang ingin dihapus: ";
        cin >> no;
        totalHarga -= daftarPesanan[no-1].harga * daftarPesanan[no-1].jumlah;
        for (int i = no-1; i < jumlahPesanan-1; i++) {
            daftarPesanan[i] = daftarPesanan[i+1];
        }
        jumlahPesanan--;
    }
}

void MoodBites::pembayaran() {
    int bayar;
    do {
        cout << KUNING << "\n+-------------------------------------+\n";
        cout << "| Total yang harus dibayar: " << setw(7) << totalHarga << "   |\n";
        cout << "+-------------------------------------+\n";
        cout << RESET << KUNING << BOLD << "Masukkan nominal bayar: " << RESET;
        cin >> bayar;
        if (bayar < totalHarga) {
            cout << MERAH << "Uang tidak cukup, silahkan masukkan nominal yang sesuai.\n" << RESET;
        }
    } while (bayar < totalHarga);

    int kembali = bayar - totalHarga;
    cetakBon(bayar, kembali);

    cout << KUNING << "\n+-----------------------------------+\n";
    cout << "| Kembalian: " << setw(22) << kembali << "|\n";
    cout << "+-----------------------------------+\n" << RESET;
}

void MoodBites::cetakBon(int bayar, int kembali) {
    ofstream bon("bon.txt");
    time_t now = time(0);
    tm *ltm = localtime(&now);

    bon << "__________________________________________\n";
    bon << "            MoodBites                     \n";
    bon << "     Jl. Rasa No. 88, Medan               \n";
    bon << "__________________________________________\n";
    bon << "Tanggal  : " << 1900 + ltm->tm_year << " - " << 1 + ltm->tm_mon << " - " << ltm->tm_mday << "\n";
    bon << "Pelanggan: " << namaCustomer << "\n";
    bon << "__________________________________________\n";
    bon << left << setw(24) << "Barang" << setw(6) << "Qty" << setw(14) << "Harga" << "\n";
    bon << "------------------------------------------\n";

    for (int i = 0; i < jumlahPesanan; i++) {
        bon << left << setw(24) << daftarPesanan[i].namaMenu
            << setw(6) << daftarPesanan[i].jumlah
            << setw(14) << daftarPesanan[i].harga * daftarPesanan[i].jumlah << "\n";
    }

    bon << "------------------------------------------\n";
    bon << left << setw(24) << "Total" << setw(6) << "" << setw(14) << totalHarga << "\n";
    bon << left << setw(24) << "Tunai" << setw(6) << "" << setw(14) << bayar << "\n";
    bon << left << setw(24) << "Kembalian" << setw(6) << "" << setw(14) << kembali << "\n";
    bon << "__________________________________________\n";
    bon << "   Pesan Lagi, klik MoodBites             \n";
    bon << "     www.moodbites.cafe.id                \n";
    bon << "__________________________________________\n";
    bon << "  Terima kasih telah jajan!               \n";

    bon.close();
    cout << KUNING << "\nBon berhasil dicetak ke 'bon.txt'!\n" << RESET;
}
