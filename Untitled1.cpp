#include <iostream>
using namespace std;

// ================= FUNGSI CETAK =================
void tampil34(int M[3][4]) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<4;j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void tampil23(int M[2][3]) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<3;j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void tampil24(int M[2][4]) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<4;j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

// ================= MAIN =================
int main() {

    // matriks
    int A[3][4], B[3][4], HasilTambah[3][4];
    int C[2][3], D[3][4], HasilKali[2][4];

    // penanda apakah sudah diisi
    bool isiA=false, isiB=false, isiC=false, isiD=false;

    int pilihan;

    do {

        cout << "\n===== MENU PROGRAM MATRIX =====\n";
        cout << "1. Input Matriks\n";
        cout << "2. Cetak Matriks\n";
        cout << "3. Perkalian Matriks\n";
        cout << "4. Penjumlahan Matriks\n";
        cout << "5. Diagonal Matriks\n";
        cout << "6. Segitiga Bawah\n";
        cout << "7. Segitiga Atas\n";
        cout << "8. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {

        // ====================================
        case 1:

            cout << "\nInput Matriks A (3x4)\n";
            for(int i=0;i<3;i++) {
                for(int j=0;j<4;j++) {
                    cin >> A[i][j];
                }
            }
            isiA=true;

            cout << "\nInput Matriks B (3x4)\n";
            for(int i=0;i<3;i++) {
                for(int j=0;j<4;j++) {
                    cin >> B[i][j];
                }
            }
            isiB=true;

            cout << "\nInput Matriks C (2x3)\n";
            for(int i=0;i<2;i++) {
                for(int j=0;j<3;j++) {
                    cin >> C[i][j];
                }
            }
            isiC=true;

            cout << "\nInput Matriks D (3x4)\n";
            for(int i=0;i<3;i++) {
                for(int j=0;j<4;j++) {
                    cin >> D[i][j];
                }
            }
            isiD=true;

            cout << "\nSemua matriks berhasil diinput!\n";
            break;

        // ====================================
        case 2:

            if(!isiA || !isiB || !isiC || !isiD) {
                cout << "\nERROR: Ada matriks yang belum diinput!\n";
                break;
            }

            cout << "\nMatriks A\n";
            tampil34(A);

            cout << "\nMatriks B\n";
            tampil34(B);

            cout << "\nMatriks C\n";
            tampil23(C);

            cout << "\nMatriks D\n";
            tampil34(D);

            break;

        // ====================================
        case 3:

            if(!isiC || !isiD) {
                cout << "\nERROR: Matriks perkalian belum diinput!\n";
                break;
            }

            // perkalian C x D
            for(int i=0;i<2;i++) {
                for(int j=0;j<4;j++) {

                    HasilKali[i][j]=0;

                    for(int k=0;k<3;k++) {
                        HasilKali[i][j] += C[i][k] * D[k][j];
                    }
                }
            }

            cout << "\nHasil Perkalian C x D\n";
            tampil24(HasilKali);

            break;

        // ====================================
        case 4:

            if(!isiA || !isiB) {
                cout << "\nERROR: Matriks penjumlahan belum diinput!\n";
                break;
            }

            for(int i=0;i<3;i++) {
                for(int j=0;j<4;j++) {
                    HasilTambah[i][j] = A[i][j] + B[i][j];
                }
            }

            cout << "\nHasil Penjumlahan A + B\n";
            tampil34(HasilTambah);

            break;

        // ====================================
        case 5:

            if(!isiA) {
                cout << "\nERROR: Matriks belum diinput!\n";
                break;
            }

            cout << "\nDiagonal Matriks A:\n";

            for(int i=0;i<3;i++) {
                for(int j=0;j<4;j++) {

                    if(i==j)
                        cout << A[i][j] << "\t";
                    else
                        cout << "0\t";
                }
                cout << endl;
            }

            break;

        // ====================================
        case 6:

            if(!isiA) {
                cout << "\nERROR: Matriks belum diinput!\n";
                break;
            }

            cout << "\nSegitiga Bawah Matriks A:\n";

            for(int i=0;i<3;i++) {
                for(int j=0;j<4;j++) {

                    if(i>=j)
                        cout << A[i][j] << "\t";
                    else
                        cout << "0\t";
                }
                cout << endl;
            }

            break;

        // ====================================
        case 7:

            if(!isiA) {
                cout << "\nERROR: Matriks belum diinput!\n";
                break;
            }

            cout << "\nSegitiga Atas Matriks A:\n";

            for(int i=0;i<3;i++) {
                for(int j=0;j<4;j++) {

                    if(i<=j)
                        cout << A[i][j] << "\t";
                    else
                        cout << "0\t";
                }
                cout << endl;
            }

            break;

        // ====================================
        case 8:
            cout << "\nProgram selesai.\n";
            break;

        default:
            cout << "\nPilihan tidak valid!\n";
        }

    } while(pilihan != 8);

    return 0;
}
