Fungsi iniliasinya:
1. *Deklarasi dan Inisialisasi Struktur Data:*
   - const int MAX_AKUN = 3, MAX_HISTORY_SIZE = 20;: Mendeklarasikan konstanta untuk batas maksimum jumlah akun dan ukuran riwayat transaksi.
   - struct Akun { ... };: Membuat struktur data Akun yang mencakup saldo, riwayat transaksi, stack, dan queue.

2. *Deklarasi dan Inisialisasi Variabel Global:*
   - Akun daftarAkun[MAX_AKUN];: Membuat array dari struktur Akun untuk menyimpan informasi setiap akun.
   - int indexkontrol = 0, penggunaAktif = 0;: Variabel global yang digunakan untuk mengontrol indeks dan akun pengguna aktif.

3. *Prototipe Fungsi:*
   - void menuutama(); ... void processStackQueue();: Mendeklarasikan prototipe fungsi-fungsi yang akan diimplementasikan kemudian.

4. *Fungsi-fungsi Utama:*
   - main(): Fungsi utama program. Melibatkan logika utama program, seperti pengolahan menu, transaksi, dan pemrosesan stack/queue.
   - menuutama(): Menampilkan menu utama pada layar.
   - buatAkun(): Inisialisasi semua akun dengan saldo awal dan mengatur pointer pada akun pengguna aktif.
   - pilihAkun(): Meminta pengguna memilih akun.
   - menupenyetoran(): Menampilkan menu penyetoran dan mengembalikan jumlah yang disetor.
   - menusaldo(): Menampilkan saldo akun pengguna aktif.
   - menupenarikan(): Menampilkan menu penarikan dan mengembalikan jumlah yang ditarik.
   - menusaldotidakcukup(): Menampilkan pesan jika saldo tidak mencukupi.
   - tambahhistorysaldo(int s): Menambahkan transaksi ke riwayat, stack, dan queue.
   - menuhistorysaldo(): Menampilkan riwayat saldo, stack, dan queue.
   - sortingHistory(): Mengurutkan riwayat transaksi menggunakan metode bubble sort.
   - searchHistory(int target): Mencari nilai tertentu di riwayat transaksi menggunakan pencarian linear.
   - processStackQueue(): Placeholder untuk proses stack dan queue.

5. *Loop Utama dan Interaksi Pengguna:*
   - Program berjalan dalam loop do-while yang meminta input pengguna untuk memilih menu dan melakukan operasi tertentu. Loop berlanjut selama pengguna memilih untuk tetap berada dalam program.

6. *Tambahan:*
   - Program menggunakan stack dan queue untuk menyimpan riwayat transaksi.
   - Pada setiap operasi transaksi, riwayat transaksi ditambahkan ke array history, stack, dan queue untuk keperluan pemrosesan lebih lanjut.
  
     
sub sub dari fungsi:
Ya, program di atas menggunakan beberapa konsep dasar dalam pemrograman C++, termasuk Array, Struct, Pointer, Sorting, Searching, dan kombinasi Stack & Queue. Berikut adalah penjelasan secara rinci:

1. *Array:*
   - int history[MAX_HISTORY_SIZE]; digunakan untuk menyimpan riwayat transaksi pada setiap akun.
   - int stack[MAX_HISTORY_SIZE]; dan int queue[MAX_HISTORY_SIZE]; digunakan sebagai implementasi stack dan queue untuk menyimpan riwayat transaksi.

2. *Struct:*
   - Struktur Akun digunakan untuk menyimpan informasi terkait akun, seperti saldo, riwayat transaksi, dan implementasi stack dan queue.

3. *Pointer:*
   - Dalam beberapa fungsi, seperti pushToStack, popFromStack, enqueue, dan dequeue, terdapat penggunaan pointer untuk mengakses dan memodifikasi elemen-elemen dalam stack dan queue.

4. *Sorting:*
   - Fungsi sortingHistory mengimplementasikan algoritma bubble sort untuk mengurutkan riwayat transaksi pada akun tertentu.

5. *Searching:*
   - Fungsi searchHistory menggunakan algoritma pencarian linear untuk mencari nilai tertentu dalam riwayat transaksi pada akun tertentu.

6. *Kombinasi Stack & Queue:*
   - stack dan queue pada struktur Akun digunakan untuk menyimpan riwayat transaksi. Transaksi baru ditambahkan ke stack dan queue menggunakan fungsi pushToStack dan enqueue, sedangkan transaksi yang akan diambil atau diproses diambil dari stack dan queue menggunakan fungsi popFromStack dan dequeue.

Program ini telah mencakup semua konsep yang disebutkan, dan ini adalah contoh implementasi sederhana dari beberapa konsep dasar tersebut dalam konteks sistem perbankan.
