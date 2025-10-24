#include <iostream>
#include<fstream>
#include<string>
using namespace std;
//struktur
struct nilai{
    float Mtk;
    float BIn;
    float Big;
    float IPA;
    float rata;
};
struct siswa{
    string nama;
    string NISN;
    string jurusan;
    nilai Nilai; // struct in struct
};
//tugas!!
//void tambahDataSiswa(siswa data,int n);//menambahkan data pada file siswa.txt
/*void tampilDataSiswa();//membaca data dari file siswa.txt dan ditampilkan
void cariSiswa();// berdasarkan NISN
float nilaiAkhir();// nilai akhir = 40%matematika+30%IPA+20%B indonesia +20%B Inggris
void ranking(); // menampilkan data siswa berdasarkan peringkatnya*/

//input data
void tambahdatasiswa(siswa data[],int n){
    ofstream bacafilesiswa("data.txt",ios::app);
    if (bacafilesiswa.is_open())
    {
        cout << "Menambahkan data siswa ke file data.txt" << endl;
        for (int i = 0; i < n; i++)
        {
            // input data
            cout << "input siswa ke "<<i+1<<endl;
            cout << "Masukkan nama siswa: ";
            cin.ignore();
            getline(cin,data[i].nama);
            cout << "Masukkan NISN siswa: ";
            getline(cin,data[i].NISN);
            cout << "Masukkan jurusan siswa: ";
            getline(cin,data[i].jurusan);
            cout << "Masukkan nilai Matematika: ";
            cin >> data[i].Nilai.Mtk;
            cout << "Masukkan nilai Bahasa Indonesia: ";
            cin >> data[i].Nilai.BIn;
            cout << "Masukkan nilai Bahasa Inggris: ";
            cin >> data[i].Nilai.Big;
            cout << "Masukkan nilai IPA: ";
            cin >> data[i].Nilai.IPA;
            cout <<endl;
            
            // input data ke data.txt
            bacafilesiswa << "nama : " << data[i].nama <<endl
                    << "nisn : "<< data[i].NISN << endl
                    << "jurusan : "<< data[i].jurusan << endl
                    << "nilai:"<<endl
                    << "matematika : "<< data[i].Nilai.Mtk << endl
                    << "bahasa indonesia : "<< data[i].Nilai.BIn << endl
                    << "bahasa inggris : "<< data[i].Nilai.Big << endl
                    << "ipa : "<< data[i].Nilai.IPA << endl 
                    << "nilai akhir : "<< data[i].Nilai.rata <<endl
                    <<endl ;
        } 
        bacafilesiswa.close();
    }
    
}

// menpilkan data dari data.txt
void tampilDataSiswa(siswa data[],int n){
    ifstream tulisfilesiswa("data.txt");
    string baris;
    if (tulisfilesiswa.is_open()){
        while (getline(tulisfilesiswa,baris))
        {
            cout << baris<< endl;
        }
        
        tulisfilesiswa.close();
    }
    else{
        cout << "Gagal membuka file!" << endl;
    }
}

// searching + sorting
/*void carisiswa(siswa data[],int n){ //masih pusing

    ifstream tulisfilesiswa("data.txt");
    string baris;
    string temp;
    if (tulisfilesiswa.is_open())
    {
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if(stoi(data[j].NISN) > stoi(data[j + 1].NISN)){
                    temp = data[j].NISN;
                    data[j].NISN = data[j + 1].NISN;
                    data[j + 1].NISN = temp;
                }
            }
                
        }
        // buat tes bb sort
        for (int i = 0; i < n; i++)
        {
            cout << data[i].NISN <<endl;
        }
        
        // filesiswa.close();
    }
        
    
    else{
        cout << "Gagal membuka file!" << endl;     
    }
}*/

float nilaiakhir(siswa data[],int n){
    ofstream bacafile("data.txt",ios::app);
    if(bacafile.is_open()){
        for (int i = 0; i < n; i++)
        {
            data[i].Nilai.rata = (0.4 * data[i].Nilai.Mtk) + (0.3 * data[i].Nilai.IPA) + (0.2 * data[i].Nilai.Big) + (0.2 * data[i].Nilai.BIn);
            
            bacafile << data[i].Nilai.rata;
            
        }
        bacafile.close();
        
    }
    else{
        cout << "gagal membuka file!"<<endl;
    }
    
    
    ifstream tulisfilesiswa("data.txt");
    if(tulisfilesiswa.is_open())
    {
        int idx = 0;
        string baris;
        while (tulisfilesiswa >> data[idx].Nilai.rata)
        {
            cout << data[idx].Nilai.rata << endl;
            idx++;
        }
        tulisfilesiswa.close();
    }
    else{
        cout << "gagal membuka file!"<<endl;
    }
    return 0;
}

int main()
{
    int n;
    cout << "input jumlah siswa : ";
    cin >>n;
    siswa data[n];
    tambahdatasiswa(data,n);
    tampilDataSiswa(data,n);
    // carisiswa(data,n); masih pusing jadi belum lanjut
    nilaiakhir(data,n);
}
