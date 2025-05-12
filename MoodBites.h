// MoodBites.h
#ifndef MOODBITES_H
#define MOODBITES_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

// Warna ANSI Cantik
#define RESET   "\033[0m"
#define MERAH   "\033[38;5;196m"
#define KUNING  "\033[38;5;226m"
#define BOLD    "\033[1m"

struct Item {
    string namaMenu;
    int harga;
    int jumlah;
};

class MoodBites {
private:
    string namaCustomer;
    int mood;
    Item daftarPesanan[10];
    int totalHarga;
    int jumlahPesanan;

public:
    MoodBites();
    void setNamaCustomer(string nama);
    string getNamaCustomer();
    void tampilkanJudul();
    void pilihMood();
    void tampilkanMenu();
    void buatPesanan();
    void periksaPesanan();
    void pembayaran();
    void cetakBon(int bayar, int kembali);

    ~MoodBites() {
    cout << MERAH << "\nHave a nice day!\n" << RESET;
    }
};

#endif
