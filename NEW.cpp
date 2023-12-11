#include <iostream>

using namespace std;

const int MAX_AKUN = 3, MAX_HISTORY_SIZE = 20;

struct Akun {
    int saldo;
    int history[MAX_HISTORY_SIZE];
};

Akun daftarAkun[MAX_AKUN];
int menu, setor, tarik, indexkontrol = 0, penggunaAktif = 0;
char jawab;

// Function prototypes
void menuutama();
void buatAkun();
int pilihAkun();
int menupenyetoran();
void menusaldo();
int menupenarikan();
void menusaldotidakcukup();
void tambahhistorysaldo(int s);
void menuhistorysaldo();

// New function prototypes
void sortingHistory();
int searchHistory(int target);
void processStackQueue();

int main() {
    buatAkun();

    do {
        menuutama();
        cin >> menu;

        switch (menu) {
            case 1:
                setor = menupenyetoran();
                daftarAkun[penggunaAktif].saldo += setor;
                menusaldo();
                tambahhistorysaldo(setor);
                break;
            case 2:
                tarik = menupenarikan();
                if (daftarAkun[penggunaAktif].saldo - tarik < 50000) {
                    menusaldotidakcukup();
                } else {
                    daftarAkun[penggunaAktif].saldo -= tarik;
                    menusaldo();
                    tambahhistorysaldo(-tarik);
                }
                break;
            case 3:
                menusaldo();
                break;
            case 4:
                menuhistorysaldo();
                break;
            case 5:
                penggunaAktif = pilihAkun();
                break;
            case 6:
                break ;
            case 7:
                sortingHistory();
                break;
            case 8:
                int target;
                cout << "Enter value to search in history: ";
                cin >> target;
                int result = searchHistory(target);
                if (result != -1) {
                    cout << "Value found at index " << result << endl;
                } else {
                    cout << "Value not found in history" << endl;
                }
                break;
        }

        cout << "\nKembali ke Menu Utama(Y/T)? : ";
        cin >> jawab;
    } while (jawab == 'Y' || jawab == 'y');

    cout << "\n****** Terima Kasih ******\n";
    return 0;
}

void menuutama() {
    cout << "|===========================|\n";
    cout << "|       PT. BANKPERAN       |\n";
    cout << "|===========================|\n";
    cout << "  Akun : " << penggunaAktif + 1;
    cout << "\n|===========================|\n";
    cout << "|       Menu Transaksi      |\n";
    cout << "|===========================|\n";
    cout << "| 1. Setor Tabungan         |\n";
    cout << "| 2. Ambil Tabungan         |\n";
    cout << "| 3. Cek Saldo              |\n";
    cout << "| 4. History transaksi      |\n";
    cout << "| 5. Ganti Akun             |\n";
    cout << "| 6. Exit                   |\n";
    cout << "|===========================|\n";
    cout << " Pilih Menu (1/2/3/4/5/6) ? : ";
}

void buatAkun() {
    for (int i = 0; i < MAX_AKUN; i++) {
        daftarAkun[i].saldo = 0;
    }
    penggunaAktif = 0;
}

int pilihAkun() {
    int index;
    cout << "Pilih akun (1-" << MAX_AKUN << "): ";
    cin >> index;
    if (index > MAX_AKUN || index < 1) {
        cout << "Masukkan hanya angka 1-" << MAX_AKUN << endl;
        return pilihAkun(); // Rekursif untuk memastikan input valid
    }
    return index - 1;
}

int menupenyetoran() {
    cout << "|=================================|\n";
    cout << "|           Menu Penyetoran       |\n";
    cout << "|=================================|\n";
    int jumlahSetor;
    cout << "Jumlah Setor    :Rp. ";
    cin >> jumlahSetor;
    return jumlahSetor;
}

void menusaldo() {
    cout << "|=================================|\n";
    cout << "|               Saldo             |\n";
    cout << "|=================================|\n";
    cout << " Saldo Anda      :Rp. " << daftarAkun[penggunaAktif].saldo << endl;
}

int menupenarikan() {
    cout << "|=====================================|\n";
    cout << "|            Menu Penarikan           |\n";
    cout << "| (Penarikan harus diatas Rp. 50.000) |\n";
    cout << "|=====================================|\n";
    int jumlahPenarikan;
    cout << "Jumlah Penarikan :Rp. ";
    cin >> jumlahPenarikan;
    if (jumlahPenarikan < 50000) {
        cout << "Penarikan minimal Rp. 50.000. Silakan ulangi.\n";
        return menupenarikan(); // Rekursif untuk memastikan penarikan valid
    }
    return jumlahPenarikan;
}

void menusaldotidakcukup() {
    cout << "|=================================|\n";
    cout << "| Maaf Saldo Anda Tidak Mencukupi |\n";
    cout << "|      Saldo Minimal Rp.10000     |\n";
    cout << "|===========Terima Kasih==========|\n";
}

void tambahhistorysaldo(int s) {
    daftarAkun[penggunaAktif].history[indexkontrol] = s;
    indexkontrol++;
}

void menuhistorysaldo() {
    cout << "|=================================|\n";
    cout << "|          History Saldo          |\n";
    cout << "|=================================|\n";

    for (int j = 0; j < indexkontrol; j++) {
        cout << j + 1 << ". Id Transaksi = " << &daftarAkun[penggunaAktif].history[j] << " jumlah: " << daftarAkun[penggunaAktif].history[j] << endl;
    }

    cout << endl;
}

void sortingHistory() {
    // Bubble sort implementation for sorting history
    for (int i = 0; i < indexkontrol - 1; i++) {
        for (int j = 0; j < indexkontrol - i - 1; j++) {
            if (daftarAkun[penggunaAktif].history[j] > daftarAkun[penggunaAktif].history[j + 1]) {
                // Swap the elements if they are in the wrong order
                int temp = daftarAkun[penggunaAktif].history[j];
                daftarAkun[penggunaAktif].history[j] = daftarAkun[penggunaAktif].history[j + 1];
                daftarAkun[penggunaAktif].history[j + 1] = temp;
            }
        }
    }

    cout << "History sorted in ascending order.\n";
}

int searchHistory(int target) {
    // Linear search implementation for searching history
    for (int i = 0; i < indexkontrol; i++) {
        if (daftarAkun[penggunaAktif].history[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

void processStackQueue() {
    // Using a simple combination of stack and queue
    int stack[MAX_HISTORY_SIZE];
    int queue[MAX_HISTORY_SIZE];
    int stackTop = -1; // Top of the stack
    int queueFront = 0; // Front of the queue
    int queueRear = -1; // Rear of the queue

    // Push history elements onto the stack
    for (int i = 0; i < indexkontrol; i++) {
        stack[++stackTop] = daftarAkun[penggunaAktif].history[i];
    }

    // Pop elements from the stack and enqueue them
    while (stackTop != -1) {
        queue[++queueRear] = stack[stackTop--];
    }

    // Dequeue and print elements from the queue
    cout << "Processing history using a combination of stack and queue:\n";
    while (queueFront <= queueRear) {
        cout << "Transaction " << queue[queueFront++] << " processed.\n";
    }
}

