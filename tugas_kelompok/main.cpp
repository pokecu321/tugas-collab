#include <iostream>
#include<fstream>
using namespace std;
fstream filesiswa("data.txt",ios::app);
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
//tes
//void tambahDataSiswa(siswa data,int n);//menambahkan data pada file siswa.txt
/*void tampilDataSiswa();//membaca data dari file siswa.txt dan ditampilkan
void cariSiswa();// berdasarkan NISN
float nilaiAkhir();// nilai akhir = 40%matematika+30%IPA+20%B indonesia +20%B Inggris
void ranking(); // menampilkan data siswa berdasarkan peringkatnya*/

void tambahdatasiswa(siswa data[],int n){
    if (filesiswa.is_open())
    {
        cout << "Menambahkan data siswa ke file data.txt" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "input siswa ke "<<i+1<<endl;
            cout << "Masukkan nama siswa: ";
            cin >> data[i].nama;
            cout << "Masukkan NISN siswa: ";
            cin >> data[i].NISN;
            cout << "Masukkan jurusan siswa: ";
            cin >> data[i].jurusan;
            cout << "Masukkan nilai Matematika: ";
            cin >> data[i].Nilai.Mtk;
            cout << "Masukkan nilai Bahasa Indonesia: ";
            cin >> data[i].Nilai.BIn;
            cout << "Masukkan nilai Bahasa Inggris: ";
            cin >> data[i].Nilai.Big;
            cout << "Masukkan nilai IPA: ";
            cin >> data[i].Nilai.IPA;
            cout <<endl;

            filesiswa << data[i].nama << endl << data[i].NISN << endl << data[i].jurusan << endl 
                      << data[i].Nilai.Mtk << endl << data[i].Nilai.BIn << endl 
                      << data[i].Nilai.Big << endl << data[i].Nilai.IPA << endl;
        } 
        filesiswa.close();
    }
    
}
void tampilDataSiswa(siswa data[],int n){
    //ifstream file("data.txt");
    string baris;
    if (!filesiswa.is_open()){
        cout << "Gagal membuka file!" << endl;
    }
    else{
        while (getline(filesiswa,baris))
        {
            cout << baris;
        }
        
        filesiswa.close();
    }
}
int main()
{
    int n;
    cout << "input jumlah siswa : ";
    cin >>n;
    siswa data[n];
    tambahdatasiswa(data,n);
    tampilDataSiswa(data,n);
     
}
