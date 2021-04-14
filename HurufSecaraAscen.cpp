#include <iostream>
#include <cstring>
#include <string>

using namespace std;
int jum = 0, posisi[100]; 
int main()
{
    cout << "masukkan Kalimat Anda = "; // masukkan kalimat
    string kalimat;

    getline(cin, kalimat);
    char satuan[100], cari; // mengcopy kalimat string menjadi char

    strcpy_s(satuan, kalimat.c_str());

    int  panjang = kalimat.length(); // mengambil huruf pada kalimat
    cout << "Susunan Per Huruf = " << endl; // output susunan huruf pada kalimat

    for (int x = 0; x < panjang; x++) { // loop semua huruf pada kalimat

        if (isspace(satuan[x])) { 
            cout << "huruf ke " << x + 1 << " = <spasi>" << endl;
        }
        else {
            cout << "huruf ke " << x + 1 << " = " << satuan[x] << endl;
        }
    }
    cout << "masukkan Huruf Yang Ingin Anda Cari = "; // huruf yang ingin dicari pada kalimat
    cin >> cari;
    for (int x = 0; x < panjang; x++) {
        if (satuan[x] == cari) {
            jum += 1;
            posisi[jum - 1] = x + 1;
        }
    }
    cout << "Huruf " << cari << " Ditemukan Sebanyak " << jum << " Kali !" << endl; // jumlah huruf yang dicari
    for (int x = 0; x < jum; x++) {
        cout << x + 1 << ". Yaitu Pada Huruf ke-" << posisi[x] << endl; // hasil huruf yang dicari
    }
}