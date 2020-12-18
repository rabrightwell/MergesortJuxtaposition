#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Mergesort
void sort(int a[], int n);
void merge(int a[], int a1[], int a2[], int n);
void sort(string a[], int n);
void merge(string a[], string a1[], string a2[], int n);

//Compare Function
void compare(int a1[], int a2[], int n1, int n2);
void compare(string a1[], string a2[], int n1, int n2);

int main(int argc, char** argv) {
	//Input Variables
	char* dataType = argv[1]; //i if integer, s if string

	//Filling dynamic arrays:

	//Dyanmic Array Accounting
	int capacity1 = 100;
	int capacity2 = 100;
	int size1 = 0;
	int size2 = 0;

	int* ifile1 = new int[capacity1] {0};
	int* ifile2 = new int[capacity2] {0};
	string* sfile1 = new string[capacity2]{ "" };
	string* sfile2 = new string[capacity2]{ "" };


	//Importing Files
	ifstream fin1;
	ifstream fin2;

	//Integer Case
	if (*dataType == 'i') {
		//File1
		fin1.open(argv[2]);

		//Reading as String
		int i = 0;
		while (fin1 >> ifile1[i]) {
			size1++;
			i++;

			//Conditioning for Array Size
			if (size1 > capacity1) {
				capacity1 *= 2;
				int* ifile1new = new int[capacity1];
				for (int i = 0; i < capacity1 / 2; i++) {
					ifile1new[i] = ifile1[i];
				}
				ifile1 = ifile1new;
			}
		}

		fin1.close();

		//File2
		fin2.open(argv[3]);

		//Reading as String
		i = 0;
		while (fin2 >> ifile2[i]) {
			size2++;
			i++;
			//Conditioning for Array Size
			if (size2 > capacity2) {
				capacity2 *= 2;
				int* ifile2new = new int[capacity2];
				for (int i = 0; i < capacity2 / 2; i++) {
					ifile2new[i] = ifile2[i];
				}
				ifile2 = ifile2new;
			}
		}

		fin2.close();
	}

	//String Case
	if (*dataType == 's') {
		//File1
		fin1.open(argv[2]);

		//Reading as String
		int i = 0;
		while (fin1 >> sfile1[i]) {
			size1++;
			i++;
			//Conditioning for Array Size
			if (size1 > capacity1 - 1) {
				capacity1 *= 2;
				string* sfile1new = new string[capacity1];
				for (int i = 0; i < capacity1 / 2; i++) {
					sfile1new[i] = sfile1[i];
				}
				sfile1 = sfile1new;
			}
		}

		fin1.close();

		//File2
		fin2.open(argv[3]);

		//Reading as String
		i = 0;
		while (fin2 >> sfile2[i]) {
			size2++;
			i++;
			//Conditioning for Array Size
			if (size2 > capacity2 - 1) {
				capacity2 *= 2;
				string* sfile2new = new string[capacity2];
				for (int i = 0; i < capacity2 / 2; i++) {
					sfile2new[i] = sfile2[i];
				}
				sfile2 = sfile2new;
			}
		}

		fin2.close();
	}

	//Sorting
	switch (*dataType) {
	case 'i':
		sort(ifile1, size1);
		sort(ifile2, size2);
		break;
	case 's':
		sort(sfile1, size1);
		sort(sfile2, size2);
		break;
	}

	//Comparing and Outputting Values
	switch (*dataType) {
	case 'i':
		compare(ifile1, ifile2, size1, size2);
		break;
	case 's':
		compare(sfile1, sfile2, size1, size2);
		break;
	}

	return 0;
}

//Mergesort Algorithms
void sort(int a[], int n) {
	if (n <= 1) return;
	int* a1 = new int[n / 2];
	int* a2 = new int[n - (n / 2)];
	for (int i = 0; i < n / 2; i++)
		a1[i] = a[i];
	for (int i = n / 2; i < n; i++)
		a2[i - n / 2] = a[i];
	sort(a1, n / 2);
	sort(a2, n - n / 2);
	merge(a, a1, a2, n);
}

void sort(string a[], int n) {
	if (n <= 1) return;
	string* a1 = new string[n / 2];
	string* a2 = new string[n - (n / 2)];
	for (int i = 0; i < n / 2; i++)
		a1[i] = a[i];
	for (int i = n / 2; i < n; i++)
		a2[i - n / 2] = a[i];
	sort(a1, n / 2);
	sort(a2, n - n / 2);
	merge(a, a1, a2, n);
}

void merge(int a[], int a1[], int a2[], int n) {
	int n1 = n / 2, n2 = n - n / 2;
	int p1 = 0, p2 = 0, i = 0;
	while (p1 < n1 && p2 < n2)
		a[i++] = a1[p1] < a2[p2] ? a1[p1++] : a2[p2++];
	while (p1 < n1) a[i++] = a1[p1++];
	while (p2 < n2) a[i++] = a2[p2++];
}

void merge(string a[], string a1[], string a2[], int n) {
	int n1 = n / 2, n2 = n - n / 2;
	int p1 = 0, p2 = 0, i = 0;
	while (p1 < n1 && p2 < n2)
		a[i++] = a1[p1] < a2[p2] ? a1[p1++] : a2[p2++];
	while (p1 < n1) a[i++] = a1[p1++];
	while (p2 < n2) a[i++] = a2[p2++];
}

void compare(int a1[], int a2[], int n1, int n2) { 
	//Creating "pointers"
	int i1 = 0;
	int i2 = 0;
	int out = 999999;
	int lastout = 99999;
	while ((i1 < n1) && (i2 < n2)) { //While both pointers are less than their respective size
		if (a1[i1] == a2[i2]) {
			out = a1[i1];
			//Lastout and out checked to make sure that they are not equal (only want unique elements in output)
			if (lastout != out) {
				cout << out << endl;
				lastout = out;
			}
			i1++;
			i2++;
			
		}
		else if (a1[i1] < a2[i2]) {
			i1++;
		}
		else if (a1[i1] > a2[i2]) {
			i2++;
		}
		
	}
}

void compare(string a1[], string a2[], int n1, int n2) {
	int i1 = 0;
	int i2 = 0;
	string out;
	string lastout;
	while ((i1 < n1) && (i2 < n2)) {
		if (a1[i1] == a2[i2]) {
			out = a1[i1];
			if (lastout != out) {
				cout << out << endl;
				lastout = out;
			}
			i1++;
			i2++;
		}
		else if (a1[i1] < a2[i2]) {
			i1++;
		}
		else if (a1[i1] > a2[i2]) {
			i2++;
		}
	}
}