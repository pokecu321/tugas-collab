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
        if (n > 0)
        {
            cout << "--== input data ==--"<<endl;
            cout << "Menambahkan data siswa ke file data.txt" << endl;
            for (int i = 0; i < n; i++)
            {
                // input data
                cout << "input siswa ke "<<i+1<<endl;
                cout << "Masukkan nama siswa ~$ ";
                cin.ignore();
                getline(cin,data[i].nama);
                cout << "Masukkan NISN siswa ~$ ";
                getline(cin,data[i].NISN);
                cout << "Masukkan jurusan siswa ~$ ";
                getline(cin,data[i].jurusan);
                cout << "Masukkan nilai Matematika ~$ ";
                cin >> data[i].Nilai.Mtk;
                cout << "Masukkan nilai Bahasa Indonesia ~$ ";
                cin >> data[i].Nilai.BIn;
                cout << "Masukkan nilai Bahasa Inggris ~$ ";
                cin >> data[i].Nilai.Big;
                cout << "Masukkan nilai IPA ~$ ";
                cin >> data[i].Nilai.IPA;
                cout <<endl;

                //hitung nilai rata rata
                data[i].Nilai.rata = (0.4 * data[i].Nilai.Mtk) + (0.3 * data[i].Nilai.IPA) + (0.2 * data[i].Nilai.Big) + (0.2 * data[i].Nilai.BIn);
                
                // input data atau menyimpan atau membaca file ke data.txt
                bacafilesiswa << "nisn : "<< data[i].NISN << endl;
                bacafilesiswa << "nama : " << data[i].nama <<endl;
                bacafilesiswa << "jurusan : "<< data[i].jurusan << endl;
                bacafilesiswa << "~ nilai ~"<<endl;
                bacafilesiswa << "matematika : "<< data[i].Nilai.Mtk << endl;
                bacafilesiswa << "bahasa indonesia : "<< data[i].Nilai.BIn << endl;
                bacafilesiswa << "bahasa inggris : "<< data[i].Nilai.Big << endl;
                bacafilesiswa << "ipa : "<< data[i].Nilai.IPA << endl ;
                bacafilesiswa << "nilai akhir : "<< data[i].Nilai.rata <<endl << endl ;
            } 
            bacafilesiswa.close();
            cout << "file berhasil di tulis" << endl; 
        }
        else
        {
            cout << "user menginput nilai 0,jadi di anggap tidak menambah file"<<endl
                <<"lanjut ke fungsi selanjut nyaa"<<endl;
        }
        
        
        
    }
    
    else
    {
        cout << "file gagal di buka"<<endl;
    }
    
}

// menpilkan data dari data.txt
void tampilDataSiswa(siswa data[],int n){
    ifstream tulisfilesiswa("data.txt");//tulis file
    string baris;
    // tulis file
    if (tulisfilesiswa.is_open()){
        cout << endl << "--== data siswa ==--"<<endl;
        while (getline(tulisfilesiswa,baris))//menulis file lalu di simpan di variabel baris
        {
            cout << baris<< endl;
        }
        
        tulisfilesiswa.close();
    }
    else{
        cout << "Gagal membuka file!" << endl;
    }
}

// searching tanpa sorting(menggunakan find = sebuah systax yang berfungsi untuk mencari kata,sepaham saya)
void carisiswa(siswa data[],int n){

    ifstream tulisfilesiswa("data.txt");//tulis file
    if (tulisfilesiswa.is_open())
    {
        string nisn;
        string baris;
        bool ditemukan = false;

        cout << endl <<"--== pencarian ==--"<<endl;
        cout << "input nisn : ";
        cin >> nisn;

        //output
        while (getline(tulisfilesiswa,baris))
        {
            size_t posisi = baris.find(nisn);//pencarian dengan kata kunci "nisn"
            if (posisi != string::npos) //pengecekan apakah benar benar ada "nisn"
            {
                
                ditemukan = true;
                cout << endl<<" > data ditemukan XD "<<endl;
                cout <<endl;

                // tampilkan 8 baris berikutnya(karena tiap siswa punya 8 baris data)
                for (int i = 0; i < 8 && getline(tulisfilesiswa, baris); i++) {
                cout << baris << endl;
                
                }
                cout <<endl;
                break;//mengakhiri loop karena data ditemukan
            }

            
        }
        if (!ditemukan)
        {
            cout << " > data tidak ditemukan :( "<<endl;
        }
        
        tulisfilesiswa.close();
    }
        
    
    else{
        cout << "Gagal membuka file!" << endl;     
    }
}

//menampilkan nilai akhir caranya juga menggunakan find
float nilaiakhir(siswa data[],int n){
    ifstream tulisfilesiswa("data.txt");//mengambil data dari data.txt
    if (tulisfilesiswa.is_open())
    {
        cout << endl <<"--== nilai akhir ==--"<<endl;
        string baris;
        //output
        while (getline(tulisfilesiswa,baris))
        {
            size_t posisinm = baris.find("nama");//pencarian dengan kata kunci "nama"
            if (posisinm != string::npos) //pengecekan apakah benar benar ada "nama"
            {
                string barisstring = baris.substr(posisinm);//memotong kata karena (posisinm),jadi hanya mengambil kata itu(full satu baris)
                cout << barisstring << endl;
            }
            size_t posisi = baris.find("nilai akhir");//pencarian dengan kata kunci "nilai akhir"
            if (posisi != string::npos)//pengecekan apakah benar benar ada "nilai akhir"
            {
                string barisstring = baris.substr(posisi);//memotong kata karena (posisi),jadi hanya mengambil kata itu(full satu baris)
                cout << barisstring << endl;
                cout <<endl;
            }
            
        }
        
        tulisfilesiswa.close();
    }
    else
    {
        cout << "gagal membuka file!"<<endl;
    }
    
    return 0;
}

//menpilkan ranking semua siswa(ascending)
void ranking(siswa data[],int n){
    ifstream tulisfilesiswa("data.txt");
    if (tulisfilesiswa.is_open())
    {
        string baris,nama[100];//nilai arr 100 karena jika nilai nya n, seumpama user input n 0 maka array akan bernilai 0
        float nilai[100];
        int jumlah = 0;//sebagai index saat menambah data

        while (getline(tulisfilesiswa,baris))
        {
            if (baris.find("nama") != string::npos) //kondisi berisi pencarian kata kunci "nama"
            {
                nama[jumlah] = baris.substr(baris.find(":")+1);//mengambil nilai setelah kata kunci ":"
                while (nama[jumlah][0] == ' '){//mengapus spasi di awal kalimat supaya rapi
                    nama[jumlah].erase(0,1);
                }
                
            }
            if (baris.find("nilai akhir") != string::npos) //kondisi berisi pencarian kata kunci "nilai akhir"
            {
                string tmp = baris.substr(baris.find(":")+1);//mengambil nilai setelah kata kunci ":"
                nilai[jumlah] = atof(tmp.c_str());//convert dari string ke float
                jumlah++; //increment
                
            }
            
            
        }

        tulisfilesiswa.close();
        
        // bb sort simpel(memakai swap)
        for (int i = 0; i < jumlah - 1; i++)
        {
            for (int j = 0 ; j < jumlah - i - 1;j++)
            {
                if (nilai[j + 1] > nilai[j])
                {
                    swap(nilai[j],nilai[j + 1]);
                    swap(nama[j],nama[j+1]);
                }
                
            }
            
        }
        // output
        cout << "--== ranking siswa ==--"<<endl;
        for (int i = 0; i < jumlah; i++)
        {
            cout << i + 1 << " . " 
                << nama[i]<< " - nilai akhir : "
                << nilai[i]<< endl;
        }
        
    }
    
    else
    {
        cout << "file gagal di buka"<<endl;
    }
    
}

//kode utama
int main()
{
    int n;
    cout << "input jumlah siswa ~$ ";
    cin >>n;//jika tidak ingin menambah file isi dengan 0!,owkey??
    siswa data[n];
    tambahdatasiswa(data,n);
    tampilDataSiswa(data,n);
    carisiswa(data,n); 
    nilaiakhir(data,n);
    ranking(data,n);
}