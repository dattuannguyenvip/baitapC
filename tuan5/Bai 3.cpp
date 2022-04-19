//Câu 3: Xây dựng lớp Ấn phẩm  gồm :
//+Thuộc tính : tên, giá thành.
//+ Phương thức : nhập, hiển thị.
//Xây dựng lớp Sách kế thừa từ lớp Ấn phẩm  và bổ sung thêm :
//+Thuộc tính : Số trang.
//+ Phương thức : nhập, hiển thị.
//Xây dựng lớp Đĩa CD kế thừa từ lớp Ấn phẩm và bổ sung thêm :
//+Thuộc tính : Số phút.
//+ Phương thức : nhập, hiển thị.
//Chương trình chính thực hiện :
//+Khai báo danh sách n quyển sách(n nguyên dương nhập từ bàn phím), nhập danh sách và hiển thị những quyển sách có số trang > 500.
//+ Khai báo danh sách n đĩa CD(n nguyên dương nhập từ bàn phím), nhập danh sách và hiển thị đĩa CD được tìm theo tên(tên cần tìm nhập từ bàn phím).


#include<iostream>
using namespace std;
class sp {
private:
	
	char ten[30];
	int gia;
public:
	void nhap() {
		
		cout << "\nNhap ten san pham: "; cin.getline(ten,30);
	
		cout << "\nNhap gia san pham: "; cin >> gia;
	}
	void xuat() {
	
		cout << "\n Ten : " << ten << endl;
		cout << "\n Gia  : " << gia << endl;
	}

	void tim(sp a[], int n) {
		char cd1[20];
		cout << "\nNhap san pham can tim: "; cin.getline( cd1,20);
		for (int i = 0; i < n; i++) {


			if (strcmp(a[i].ten, cd1) == 0) a[i].xuat();
		}
	}
	void timm() {
		char cd1[20];
		cout << "\nNhap san pham can tim: "; cin.getline(cd1, 20);
		if (strcmp(ten, cd1) == 0)xuat();

	}
};
class book :public sp {
private:

	int trang;
public:
	void nhap()
	{
		sp::nhap();
		cout << "\nNhap so trang: "; cin >> trang;
	}
	void xuat() {
		sp::xuat();
		cout << "\nso trang: " << trang << endl;

	}
	void trang500(book a[], int n) {
		for (int i = 0; i < n; i++) {
			if (a[i].trang > 500) a[i].xuat();
		 }

	}

};
class cd :sp {
private:
	int phut;
public:
	void nhap() {
		sp::nhap();
		cout << "\nNhap so phut: "; cin >> phut;
		
	}
	void xuat() {
		sp::xuat();
		cout << "So phut: " << phut << endl;
		
	}
	
 void tim(cd b[], int n) {
		
			sp::timm();
			cout << "\nSo phut: " << phut<<endl;
		
	}

};
int main() {
	int n, m;
	/*cout << "Nhap n: "; cin >> n;

	book a[1000];
	cout << "====Nhap thong tin sach" << endl;
	for (int i = 0; i < n; i++) {
		cin.ignore();
		cout << "\n-Nhap cuon sach thu: " << i + 1 << endl;
		a[i].nhap();
	}
	cout << "\nXuat thong tin sach " << endl;
	for (int i = 0; i < n; i++) {
		cout << "\n-Cuon sach thu: " << i + 1 << endl;
		a[i].xuat();
	}
	a->trang500(a, n);*/
	cd b[1000];

	cout << "Nhap so luong dia cd: "; cin >> m;
	cout << "====Nhap thong tin dia" << endl;
	for (int i = 0; i < m; i++) {
		cin.ignore();
		cout << "\n-Dia thu: " << i + 1 << endl;
		b[i].nhap();
	}
	cout << "\nXuat thong tin dia cd" << endl;
	for (int i = 0; i < m; i++) {
		cout << "\n-Dia cd thu: " << i + 1 << endl;
		b[i].xuat();
		
	}
	
	for (int i = 0; i < m; i++) {
		cout << "\n-Dia cd can tim: " << i + 1 << endl;
		b[i].tim(b,m);
	}

	

}