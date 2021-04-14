// 20.11.3336 Felda Putri Widya Rachmawati

#include <iostream>
using namespace std;


int binary_search(int a[], int l, int r, int key) { 
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (key == a[m])
			return m;
		else if (key < a[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}

int* bubble_sort(int a[], int n) {
	int p; // 
	int y = n - 2;
	while (y >= 0) {
		int i = 0; // indeks
		while (i <= y) {
			if (a[i] > a[i + 1]) {
				p = a[i];
				a[i] = a[i + 1];
				a[i + 1] = p;

			}
			i++;
		}
		y--;
	}
	return a;
}
int main(int argc, char const* argv[]) {
	int n;
	int	key; 
	int j, k, temp; // temp Untuk wadah sementara pada saat pertukaran angka
	int jmax; 
	int u; // u sebagai privot
	cout << "Masukan banyak array: "; // masukkan banyak array
	cin >> n; 
	cout << endl;
	int* a = new int[n];

	for (int i = 0; i < n; i++) { 
		cout << "INPUTKAN DATA KE- [" << i << "]:"; // masukkan array ke berapa misal 1,2,3
		cin >> a[i];
	}
	cout << "\nDATA YANG DIINPUTKAN :" << endl; // hasil array yang diinputkan 
	for (int i = 0; i < n; i++) {
		cout << a[i] << "   ";
	}
	u = n - 1;

	for (j = 0; j < n; j++) { 
		jmax = 0;
		for (k = 1; k <= u; k++) // intinya ini adalah pengkondisian untuk menentukan angka terbesar
			if (a[k] < a[jmax])
				jmax = k; // kalau udah ditemukan angka terkecilnya disimpan di variable jmin
		
		temp = a[u]; // ini untuk penukarannya, sesuai penjelasan variable temp
		a[u] = a[jmax];
		a[jmax] = temp;
		u--;

		cout << "\nHasil Proses ke-" << j + 1 << " =  "; // output proses pencarian array
		for (k = 0; k < n; k++) {
			cout << a[k] << "   ";
		}
		cout << endl;
		cout << "\nDATA SETELAH DIURUTKAN :" << endl; // setelah di urutkan 
		for (int i = 0; i < n; i++) {
			cout << a[i] << "    ";
		}

		cout << endl << "Masukan angka yang ingin dicari : "; // hasil array yang dicari
		cin >> key;

		a = bubble_sort(a, n);
		int res = binary_search(a, 0, n - 1, key);
		if (res != -1)
			std::cout << key << "ditemukan " << endl;
		else
			std::cout << key << "tidak ditemukan" << endl;
		return 0;
	}
}