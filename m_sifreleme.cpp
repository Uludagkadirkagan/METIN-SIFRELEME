

// KADÝR KAÐAN ULUDAÐ 28/02/2024 01:43


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    const char* girisDosyasiAdi = "metinn.txt";
    const char* cikisDosyasiAdi = "metin2.txt";

    ifstream girisDosyasi(girisDosyasiAdi);

    string temizMetin;
    string satir;
    while (getline(girisDosyasi, satir)) {
        for (char c : satir) {
            if (!isspace(c)) {
                temizMetin += c;
            }
        }
    }

    girisDosyasi.close();

    ofstream cikisDosyasi(cikisDosyasiAdi);
    cikisDosyasi << temizMetin;
    cikisDosyasi.close();

    cout << "Temizlenmis metin " << cikisDosyasiAdi << " dosyasina yazildi." << endl;
    cout << temizMetin << endl;

    int uzunluk = temizMetin.length();
    cout << "Metnin uzunlugu: " << uzunluk << endl;

    int m = floor(sqrt(uzunluk));
    int n = ceil(sqrt(uzunluk));

    if (m * n >= uzunluk) {
        cout << "m yani satir sayisi: " << m << endl;
        cout << "n yani sutun sayisi: " << n << endl;
    }
    else {
        m = m++;
        cout << "m yani satir sayisi: " << m << endl;
        cout << "n yani sutun sayisi: " << n << endl;
    }

    vector<vector<char>> matrix(m, vector<char>(n, ' '));
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (index < uzunluk) {
                matrix[i][j] = temizMetin[index++];
            }
            else {
                break;
            }
        }
    }

    cout << "Sifreli metin: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}

