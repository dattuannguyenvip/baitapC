//Câu 2: Xây dựng lớp giáo viên GV gồm các thuộc tính họ tên ht(kiểu char[30]),
//tuổi t(kiểu số nguyên), bằng cấp cao nhất được đào tạo bc(kiểu char[15]), chuyên ngành(kiểu char[20]),
//bậc lương bl(kiểu float) là các thuộc tính riêng.Trong lớp có định nghĩa các hàm công cộng sau :
//-Hàm toán tử nhập >> đi với cin để nhập dữ liệu cho các thông tin trên của 1 giáo viên
//- Hàm toán tử xuất << đi với cout để xuất các thông tin trên của giáo viên ra màn hình
//- Hàm tính tiền lương cơ bản lcb biết rằng lcb = bl * 610
//- Hàm toán tử “ == ”so sánh 2 GV, 2 giáo viên bằng nhau nếu có bằng cấp cao nhất giống nhau
//Viết chương trình nhập vào n(n nguyên dương nhập từ bàn phím) giáo viên.In ra màn hình :
//-Danh sách giáo viên sắp xếp theo bằng cấp.
#include<iostream>
#include<iomanip>
using namespace std;

class giaovien {
private:
	char ht[30];
	char cn[20];
	char bc[15];
	int tuoi;
	float bl;
	float  lcb;
	int bac;

public:
	friend istream& operator >>(istream& nhap, giaovien& a) {
		nhap.ignore();
		cout << "Nhap ho ten: "; nhap.getline(a.ht, 30);
		cout << "\nNhap chuyen nganh: "; nhap.getline(a.cn, 20);
		cout << "\nNhap bang cap: "; nhap.getline(a.bc, 15);
		cout << "\nNhap bac luong: "; nhap >> a.bl;
		cout << "\nNhap tuoi: "; nhap >> a.tuoi;

		//	a.lcb = a.bl * 610;
		return nhap;
	}

	void tt() {


		lcb = bl * 610;

		cout << lcb << endl;
	}
	friend ostream& operator<<(ostream& xuat, giaovien& a) {
		xuat << "- Ho ten: " << a.ht << endl;
		xuat << "-Chuyen nganh: " << a.cn << endl;
		xuat << "-Bang cap: " << a.bc << endl;
		xuat << "-Bac luong: " << a.bl << endl;
		xuat << "-Luong co ban: " << a.lcb << endl;
		return xuat;
	}
	void sscn(giaovien a[], int n) {

		for (int i = 1; i <= n; i++) {
			if (a[i].bc == "gioi")
				a[i].bac = 10;

			if (a[i].bc == "kha")
				a[i].bac = 8;

			if (a[i].bc == "trung binh")
				a[i].bac = 6;
		}



	}



};


int main() {
	int n;
	cout << "Nhap so luong giao vien: "; cin >> n;
	giaovien a[100];



	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin giao vien thu " << i + 1 << endl;

		cin >> a[i];
		a[i].sscn(a, n);
	}
	cout << "\n========XUAT THONG TIN===========" << endl;
	for (int i = 0; i < n; i++) {

		cout << a[i];

	}
	cout << "========Sap xep =====" << endl;


}
system("pause");
return 0;
}