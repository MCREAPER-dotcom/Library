#include<iostream>
#include <string>
#include<vector>
using namespace std;
class book {
public:
	string  L;
	string I;
	string N;
	int Y;
	int K;
};
void create(vector<book>& a, int size) {
	for (int i = 0; i < size; i++) {
		book library;
		char s[10]; char u[10]; char n[10]; int y; int k;
		cout << "Input year of book" << endl;
		cin >> y;
		library.Y = y;
		cout << "Input quantity of book " << endl;
		cin >> k;
		library.K = k;
		cout << "Input last name (10 simbol)" << endl;
		cin >> s;
		library.L = s;
		cout << "Input short name (10 simbol)" << endl;
		cin >> u;
		library.I = u;
		cout << "Input name of book (10 simbol)" << endl;
		cin >> n;
		library.N = n;
		a.push_back(library);
	}
}
void print(vector<book>& a, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Last name " << a[i].L << endl;
		cout << "Short name " << a[i].I << endl;
		cout << "Name of book " << a[i].N << endl;
		cout << "Year of book " << a[i].Y << endl;
		cout << "Quantity of book " << a[i].K << endl;
	}
}
void del(vector<book>& a, int& size) {
	cout << "Input name of book for delete" << endl;
	char t[10];
	cin >> t;
	string t2 = t;
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (t2 == a[i].N) {
			k = i;
		}
	}
	if (k > 0) {
		a.erase(a.begin() + k);
		size--;
	}
}
void OUTL(vector<book>& a, int size) {
	for (int j = 0; j < size; j++)
		for (int i = 0; i < size - 1; i++) {
			if (a[i].L >= a[i + 1].L)
			{
				book temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	print(a, size);
}
void OUTY(vector<book>& a, int size) {
	for (int j = 0; j < size; j++)
		for (int i = 0; i < size - 1; i++) {
			if (a[i].Y >= a[i + 1].Y)
			{
				book temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	print(a, size);
}
int main()
{
	int size = 0, k = 0;
	char ask = 'Y';
	cout << "Input start quantity of position" << endl;
	cin >> size;
	if (size < 0) { cout << "Erorr: incorrect data" << endl; return 0; }
	vector<book>Library;
	create(Library, size);
	do {
		cout << "Chouse the doing (1 create|| 2 Out at Last name|| 3 Out at year|| 4 out all|| 5 delete elment)" << endl;
		cin >> k;
		if (k == 4)
			print(Library, size);
		else if (k == 2)
			OUTL(Library, size);
		else if (k == 3)
			OUTY(Library, size);
		else if (k == 1) {
			cout << "Input quantity of position" << endl;
			cin >> size;
			create(Library, size);
		}
		else if (k == 5) {
			del(Library, size);
		}
		cout << "Do you want to continue ?(Y/N)" << endl;
		cin >> ask;
		if (ask == 'N' || ask == 'n')break;
		if (ask != 'N' || ask != 'n' || ask != 'Y' || ask != 'y') {
			while (ask != 'N' && ask != 'n' && ask != 'Y' && ask != 'y') {
				cout << "Erorr" << endl;
				cout << "Do you want to continue ?(Y/N)" << endl;
				cin >> ask;
			}
		}
	} while (ask == 'Y' || ask == 'y');
}
