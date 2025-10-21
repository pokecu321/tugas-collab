#include <iostream>
#include<fstream>
using namespace std;
ofstream filesiswa("data.txt",ios::app);
struct nilai{
    float Mtk;
    float BIn;
    float Big;
    float IPA;
};
struct siswa{
    string nama;
    string NISN;
    string jurusan;
    nilai Nilai; // struct in struct
};
void tambahDataSiswa(siswa data,int n);//menambahkan data pada file siswa.txt
/*void tampilDataSiswa();//membaca data dari file siswa.txt dan ditampilkan
void cariSiswa();// berdasarkan NISN
float nilaiAkhir();// nilai akhir = 40%matematika+30%IPA+20%B indonesia +20%B Inggris
void ranking(); // menampilkan data siswa berdasarkan peringkatnya*/

void tambahdatasiswa(siswa data,int n){
    if (filesiswa.is_open())
    {
        cout << "Menambahkan data siswa ke file data.txt" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Masukkan nama siswa: ";
            cin >> data.nama;
            cout << "Masukkan NISN siswa: ";
            cin >> data.NISN;
            cout << "Masukkan jurusan siswa: ";
            cin >> data.jurusan;
            cout << "Masukkan nilai Matematika: ";
            cin >> data.Nilai.Mtk;
            cout << "Masukkan nilai Bahasa Indonesia: ";
            cin >> data.Nilai.BIn;
            cout << "Masukkan nilai Bahasa Inggris: ";
            cin >> data.Nilai.Big;
            cout << "Masukkan nilai IPA: ";
            cin >> data.Nilai.IPA;

            filesiswa << data.nama << "," << data.NISN << "," << data.jurusan << "," 
                      << data.Nilai.Mtk << "," << data.Nilai.BIn << "," 
                      << data.Nilai.Big << "," << data.Nilai.IPA << endl;
        } 
    }
    
}

int main()
{
    siswa data;
    int n;
    cout << "input jumlah siswa : ";
    cin >>n;
    tambahDataSiswa(data,n); 
     
}
