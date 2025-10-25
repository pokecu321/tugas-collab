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
    ofstream bacafilesiswa("data.txt",ios::app);//baca file dalam mode append
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

            //hitung nilai rata rata
            data[i].Nilai.rata = (0.4 * data[i].Nilai.Mtk) + (0.3 * data[i].Nilai.IPA) + (0.2 * data[i].Nilai.Big) + (0.2 * data[i].Nilai.BIn);
            
            // input data ke data.txt
            bacafilesiswa << "nama : " << data[i].nama <<endl;
            bacafilesiswa << "nisn : "<< data[i].NISN << endl;
            bacafilesiswa << "jurusan : "<< data[i].jurusan << endl;
            bacafilesiswa << "nilai:"<<endl;
            bacafilesiswa << "matematika : "<< data[i].Nilai.Mtk << endl;
            bacafilesiswa << "bahasa indonesia : "<< data[i].Nilai.BIn << endl;
            bacafilesiswa << "bahasa inggris : "<< data[i].Nilai.Big << endl;
            bacafilesiswa << "ipa : "<< data[i].Nilai.IPA << endl ;
            bacafilesiswa << "nilai akhir : "<< data[i].Nilai.rata <<endl << endl ;
        } 
        bacafilesiswa.close();
        cout << "file berhasil di tulis" << endl;
    }
    
}

// menpilkan data dari data.txt
void tampilDataSiswa(siswa data[],int n){
    ifstream tulisfilesiswa("data.txt");//tulis file
    string baris;
    // tulis file
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
    ifstream tulisfilesiswa("data.txt");//mengambil data dari data.txt
    if (tulisfilesiswa.is_open())
    {
        cout << endl <<" nilai akhir "<<endl;
        string baris;
        //output
        while (getline(tulisfilesiswa,baris))
        {
            size_t posisinm = baris.find("nama");//pencarian dengan kata kunci nama
            if (posisinm != string::npos) //pengecekan apakah benar benar ada "nama"
            {
                string barisstring = baris.substr(posisinm);//memotong kata karena (posisinm),jadi hanya mengambil kata itu(full satu baris)
                cout << barisstring << endl;
            }
            size_t posisi = baris.find("nilai akhir");//pencarian dengan kata kunci nama
            if (posisi != string::npos)//pengecekan apakah benar benar ada "nama"
            {
                string barisstring = baris.substr(posisi);//memotong kata karena (posisinm),jadi hanya mengambil kata itu(full satu baris)
                cout << barisstring << endl;
                cout <<endl;
            }
            
        }
        
    }
    else
    {
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