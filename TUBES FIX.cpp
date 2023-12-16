#include <iostream>
#include <windows.h>

using namespace std;

const int maksimal_tumpukan = 3;
const int maksimal_antrian = 5;
bool keluar = false;
char ya_tidak;
int pilihan;
string jenis_sampah, data_masuk;
string nama_sampah, nama_user[10], alamat[20];
int berat_sampah, no_telp[30];
float total_bayar_item;
float total_pembayaran = 0;

struct antrian{

    int depan;
    int belakang;
    string nama[maksimal_antrian];
}pengguna;

void nilai_awal(){
    pengguna.depan = -1;
    pengguna.belakang = -1;
}

bool antrian_penuh(){
    if(pengguna.belakang == maksimal_antrian-1){
        return true;
    }else{
        return false;
    }
}

bool antrian_kosong(){
    if(pengguna.depan == -1 && pengguna.belakang == -1){
        return true;
    }else{
        return false;
    }
}

void enqueue_antrian(string dataMasukkan){
    if(antrian_kosong() == true){
        pengguna.depan = 0;
        pengguna.belakang = 0;
        pengguna.nama[pengguna.belakang] = dataMasukkan;
    }else if(antrian_penuh() == false){
        pengguna.belakang++;
        pengguna.nama[pengguna.belakang] = dataMasukkan;
    }else{
        cout<<"Antrian pengambilan sampah sudah penuh"<<endl;
    }
}

void dequeue_antrian(){
    if(antrian_kosong() == false){
        for(int x = pengguna.depan; x <= pengguna.belakang; x++){
            pengguna.nama[x] = pengguna.nama[x+1];
        }
        pengguna.belakang--;
    }else{
        cout<<"Tidak ada data pada antrian"<<endl;
    }
}

void tampil_data(){
    if(antrian_kosong() == false){
        for(int z = pengguna.depan; z <= pengguna.belakang; z++){
            cout<<pengguna.nama[z]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"Tidak ada data pada antrian"<<endl;
    }
}

struct tumpukan{
     int posisi;
     string jenis_sampah[maksimal_tumpukan];
     string nama_sampah[maksimal_tumpukan];
     int berat_sampah[maksimal_tumpukan];
     float total_bayar_item[maksimal_tumpukan];
     float total_pembayaran[maksimal_tumpukan];
};
tumpukan sampah;

void inisialisasi(){
     sampah.posisi = -1;
}

bool kosong(){
     if(sampah.posisi == -1){
       return true;
     }else{
        return false;
     }
}

bool penuh(){
    if(sampah.posisi == maksimal_tumpukan - 1){
           return true;

    }else{
           return false;
     }
}

void push_tumpukan(string jenis_sampah,float total_pembayaran){
    if(kosong() == true){
          cout<<endl;
          cout<<"Berhasil memasukkan data :"<<endl;
          cout<<"jenis sampah :"<<jenis_sampah<<endl;
          cout<<"nama sampah :"<<nama_sampah<<endl;
          cout<<"berat sampah : " <<berat_sampah<<endl ;
          cout<<"total bayar per item : "<<berat_sampah*5000<< endl;
          sampah.posisi++;
          sampah.jenis_sampah[sampah.posisi] = jenis_sampah;
          sampah.nama_sampah[sampah.posisi] = nama_sampah;
          sampah.berat_sampah[sampah.posisi]= berat_sampah;
          sampah.total_bayar_item[sampah.posisi]=total_bayar_item;
          sampah.total_pembayaran[sampah.posisi]= total_pembayaran;

    }else if(penuh() == false){
          sampah.posisi++;
          cout<<endl;
          cout<<"Berhasil memasukkan data :"<<endl;
          cout<<"jenis sampah :"<<jenis_sampah<<endl;
          cout<<"nama sampah :"<<nama_sampah<<endl;
          cout<<"berat sampah (kg) : " <<berat_sampah<<endl;
          cout<<"total bayar per item : "<<berat_sampah*5000<< endl<<endl;
          sampah.jenis_sampah[sampah.posisi] = jenis_sampah;
          sampah.nama_sampah[sampah.posisi] = nama_sampah;
          sampah.berat_sampah[sampah.posisi]= berat_sampah;
          sampah.total_pembayaran[sampah.posisi]= total_pembayaran;
     }else{
          cout<<"!!! TUMPUKAN SAMPAH SUDAH PENUH !!!"<<endl;
     }
}

void pop_tumpukan(){
      if(kosong() == true){
        cout<<"Tidak ada tumpukan sampah"<<endl;
      }else{
        sampah.posisi--;
        cout<<"Sampah " << nama_sampah << " telah diambil "<<endl;
     }
}

void tampil_data_tumpukan(){
    if(kosong() == true){
       cout<<"Tidak ada data"<<endl;
    }else{
        for(int c = 0; c <= sampah.posisi; c++){
           cout<<"jenis sampah :"<< sampah.jenis_sampah[c]<<endl;
           cout<<"nama sampah :"<< sampah.nama_sampah[c]<<endl;
           cout<<"berat sampah : " << sampah.berat_sampah[c]<<endl ;
           cout<<"total bayar item : "<< sampah.berat_sampah[c]*5000<< endl;
           cout<<"---------------------------------------"<<endl;

        }
        cout<<"total pembayaran : "<<berat_sampah*5000*3<<endl;
        cout<<"pilih jenis Pembayaran"<<endl;
        cout<<" 1. Tunai "<<endl;
        cout<<" 2. M-banking "<<endl;
        cout<<" 3. E-Money "<<endl;
            if(pilihan != 0){
                cout<<"Cantumkan kode pembayaran pada saat akan membayar!"<<endl;
                cout<<"Kode pembayaran Anda 000" << data_masuk <<endl;
            }else{
                cout<<"Pilihan tidak tersedia..."<<endl;
            }
    }
}

void antrian(){
nilai_awal();
    do{
        cout<<"\t"<<"Input Data Antrian Pengambilan Sampah"<<endl;
        cout<<"1. Masukkan data"<<endl;
        cout<<"2. Hapus data dari Antrian"<<endl;
        cout<<"3. Tampilkan data pada Antrian"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Silahkan pilih (1-4) : ";
        cin>>pilihan;

        switch(pilihan){

        case 1 :
        cout<<"Silahkan masukkan kode antrian Anda : ";
        cin>>data_masuk;
        enqueue_antrian(data_masuk);
        cout<<"Keluar (y/t) ? ";
        cin>>ya_tidak;
        if(ya_tidak == 'y' || ya_tidak == 'Y'){
            cout<<" Terima Kasih "<<endl;
            keluar = true;
        }else{
            system("cls");
        }
        break;

        case 2 :
        dequeue_antrian();
        cout<<"No Antrian " << data_masuk << " sudah tidak ada"<<endl;
        cout<<"Keluar (y/t) ? ";
        cin>>ya_tidak;
        if(ya_tidak == 'y' || ya_tidak == 'Y'){
            cout<<" Terima kasih"<<endl;
            keluar = true;
        }else{
            system("cls");
        }
        break;

        case 3 :
        tampil_data();
        cout<<"Keluar (y/t) ? ";
        cin>>ya_tidak;
        if(ya_tidak == 'y' || ya_tidak == 'Y'){
            cout<<" Terima kasih"<<endl;
            keluar = true;
        }else{
            system("cls");
        }
        break;

        case 4 :
        cout<<"Yakin ingin keluar (y/t) ? ";
        cin>>ya_tidak;
        if(ya_tidak == 'y' || ya_tidak == 'Y'){
            cout<<" Terima kasih"<<endl;
            keluar = true;
        }
        system("cls");
        break;

        default :
        cout<<"Pilihan tidak tersedia..."<<endl;
        cout<<"Keluar (y/t) ? ";
        cin>>ya_tidak;
        if(ya_tidak == 'y' || ya_tidak == 'Y'){
            cout<<" Terima kasih"<<endl;
            keluar = true;
        }else{
            system("cls");
        }
    }

    }while(keluar == false);
}

int main()
{
    struct sampah {
        char nama[10];
        char alamat[20];
        char no_telp[30];
    };
   inisialisasi();
   int i;
   string user, pass;
   bool login = true;
   string username = "nama";
   string password = "123";

   do{
       cout<<"\t"<<"===================================="<<endl;
       cout<<"\t"<<"APLIKASI PEMBUANGAN SAMPAH BERBAYAR"<<endl;
       cout<<"\t"<<"===================================="<<endl<<endl;
       cout<<"\t"<<"---Silahkan login terlebih dahulu---"<<endl;


       cout<<"\tMasukkan username : "; cin>>user;
       cout<<"\tMasukkan password : "; cin>>pass;
        if(user == username && pass == password){
            cout<<"\t\t| Login Berhasil |"<<endl<<endl;
            sampah bio;
            cin.getline(bio.nama, 10);
            cout<<"\tMasukkan nama Anda : ";
            cin.getline(bio.nama, 10);

            cout<<"\tMasukkan alamat rumah Anda : ";
            cin.getline(bio.alamat, 20);

            cout<<"\tMasukkan no handphone Anda : ";
            cin.getline(bio.no_telp, 30);
            cout<<endl;
            system("cls");
            antrian();
            system("cls");
            do{
                keluar=false;
                cout<<"===================================="<<endl;
                cout<<"APLIKASI PEMBUANGAN SAMPAH BERBAYAR"<<endl;
                cout<<"===================================="<<endl<<endl;
                cout<<"Silahkan pilih menu di bawah ini"<<endl;
                cout<<"1. Rincian data pembuangan sampah"<<endl;
                cout<<"2. Pengambilan Sampah"<<endl;
                cout<<"3. Tampilkan data tumpukan sampah"<<endl;
                cout<<"4. Keluar"<<endl;
                cout<<"Silahkan pilih (1-4) : ";
                cin>>pilihan;
                cout<<endl;
                if(pilihan==1){
                   cout<<"1. Alat elektronik"<<endl;
                   cout<<"2. Perabot rumah tangga"<<endl;
                   cout<<"3. Kendaraan bekas"<<endl;
                   cout<<"-------------------------------------------------"<<endl;
                   cout<<"Silahkan pilih jenis sampah"<<endl;
                   cout<<"masukkan jenis sampah : ";
                   cin>> jenis_sampah;
                   cout<<"masukkan nama sampah yang dibuang : ";
                   cin>>nama_sampah;
                   cout<<"masukkan berat sampah (kg): ";
                   cin>>berat_sampah;
                   cout<<"total bayar item : "<<berat_sampah*5000<< endl;

                   push_tumpukan(jenis_sampah,berat_sampah);
                   cout<<"Keluar (y/t) ? ";
                   cin>>ya_tidak;
                   if(ya_tidak == 'y' || ya_tidak == 'Y'){
                      cout<<" Terima Kasih "<<endl;
                      keluar = true;
                   }else{
                        keluar= false;
                     system("cls");
                   }
                }else if(pilihan==2){
                     pop_tumpukan();
                     cout<<"Keluar (y/t) ? ";
                     cin>>ya_tidak;
                     if(ya_tidak == 'y' || ya_tidak == 'Y'){
                           cout<<" Terima kasih"<<endl;
                    keluar = true;
                     }else{
                         keluar= false;
                       system("cls");
                     }
                }else if(pilihan==3){
                    tampil_data_tumpukan();
                    cout<<"Keluar (y/t) ? ";
                    cin>>ya_tidak;
                    if(ya_tidak == 'y' || ya_tidak == 'Y'){
                      cout<<" Terima kasih"<<endl;
                      keluar = true;
                    }else{
                        keluar= false;
                       system("cls");
                    }
                }else if(pilihan==4){
                    cout<<"Yakin ingin keluar (y/t) ? ";
                    cin>>ya_tidak;
                    if(ya_tidak == 'y' || ya_tidak == 'Y'){
                       cout<<" Terima kasih"<<endl;
                       keluar = true;
                    }else{
                        system("cls");
                    }
                } else {
                    cout<<"Pilihan tidak tersedia..."<<endl;
                    cout<<"Keluar (y/t) ? ";
                    cin>>ya_tidak;
                    if(ya_tidak == 'y' || ya_tidak == 'Y'){
                       cout<<" Terima kasih"<<endl;
                       keluar = true;
                    }else{
                        system("cls");
                    }
                }
        } while(keluar == false);

        }else{
            cout<<"\t!!! Username atau Password salah !!!"<<endl<<endl;
            i = i+1;
        }
    }while (i <= 3);
    if(login == false){
        cout<<" "<<endl;
    }


           return 0;
    }
