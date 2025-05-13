// menu.cpp
#include "MoodBites.h"

MoodBites::MoodBites() {
    totalHarga = 0;
    jumlahPesanan = 0;
}

void MoodBites::setNamaCustomer(string nama) {
    namaCustomer = nama;
}

string MoodBites::getNamaCustomer() {
    return namaCustomer;
}

void MoodBites::tampilkanJudul() {
    cout << MAGENTA;
    cout << "############################################\n";
    cout << "#                                          #\n";
    cout << "#           WELCOME TO MOODBITES!          #\n";
    cout << "#                                          #\n";
    cout << "############################################\n";
    cout << RESET;
}

void MoodBites::pilihMood() {
    cout << MAGENTA;
    cout << "\nHai " << namaCustomer << ", mood kamu hari ini gimana nih?\n";
    cout << KUNING;
    cout << "+------------------------+\n";
    cout << "|     PILIH MOOD KAMU     |\n";
    cout << "+------------------------+\n";
    cout << "| 1. Sedih                |\n";
    cout << "| 2. Senang               |\n";
    cout << "| 3. Marah                |\n";
    cout << "| 4. Biasa Aja            |\n";
    cout << "+------------------------+\n";
    cout << KUNING << BOLD << "Masukkan pilihan: " << RESET;
    cin >> mood;

    if (mood == 1) {
        cout << CYAN << "Yaah, kamu lagi sedih ya? Kami punya menu yang bisa bikin kamu lebih baik!\n" << RESET;
    } else if (mood == 2) {
        cout << PINK << "Ciee lagi senang ya? Yuk coba menu-menu yang bikin mood kamu makin top!\n" << RESET;
    } else if (mood == 3) {
        cout << MERAH << "Gak apa-apa kok kalo lagi marah, tenangin diri dan coba deh menu-menu ini!\n" << RESET;
    } else if (mood == 4) {
        cout << HIJAU << "Mungkin kamu lagi biasa aja, tapi ada menu yang pasti bikin kamu jadi luar biasa!\n" << RESET;
    }
}

void MoodBites::tampilkanMenu() {
    string menu[5];
    int hargaMenu[5];
    string warnaTabel;

    // Daftar menu dan harga sesuai mood
    if (mood == 1) {
        menu[0] = "Es Krim Coklat"; hargaMenu[0] = 15000;
        menu[1] = "Brownies Lumer"; hargaMenu[1] = 18000;
        menu[2] = "Milk Tea"; hargaMenu[2] = 13000;
        menu[3] = "Roti Bakar Keju Coklat"; hargaMenu[3] = 17000;
        menu[4] = "Honey Waffle"; hargaMenu[4] = 20000;
    } else if (mood == 2) {
        menu[0] = "Burger Jumbo"; hargaMenu[0] = 25000;
        menu[1] = "Mojito"; hargaMenu[1] = 15000;
        menu[2] = "Dimsum Mentai"; hargaMenu[2] = 22000;
        menu[3] = "Tteokbokki Mozarella"; hargaMenu[3] = 23000;
        menu[4] = "Es Teler"; hargaMenu[4] = 14000;
    } else if (mood == 3) {
        menu[0] = "Seblak Jeletet"; hargaMenu[0] = 20000;
        menu[1] = "Bakso Mercon"; hargaMenu[1] = 22000;
        menu[2] = "Mie Level"; hargaMenu[2] = 18000;
        menu[3] = "Soda Gembira"; hargaMenu[3] = 12000;
        menu[4] = "Pangsit Meledak"; hargaMenu[4] = 16000;
    } else if (mood == 4) {
        menu[0] = "Nasi Bakar Seafood"; hargaMenu[0] = 25000;
        menu[1] = "Rice Bowl Katsu"; hargaMenu[1] = 22000;
        menu[2] = "Korean Toast"; hargaMenu[2] = 15000;
        menu[3] = "Thai Tea"; hargaMenu[3] = 13000;
        menu[4] = "Mie Yamin Pedas Manis"; hargaMenu[4] = 20000;
    }

    if (mood == 1) warnaTabel = CYAN;
    else if (mood == 2) warnaTabel = PINK;
    else if (mood == 3) warnaTabel = MERAH;
    else if (mood == 4) warnaTabel = HIJAU;

    cout << MAGENTA << "\nIni nih menu yang sesuai dengan mood kamu!\n";
    cout << warnaTabel << "+=======================================================+\n";
    for (int i = 0; i < 5; ++i) {
        cout << warnaTabel
            << "| " << i+1 << ". " << setw(30) << left << menu[i]
            << " | Harga: Rp" << setw(7) << hargaMenu[i] << " |\n";
    }
    cout << warnaTabel << "+=======================================================+\n" << RESET;
}
