//Câu 2: Xây dựng lớp giáo viên GV gồm các thuộc tính họ tên ht(kiểu char[30]), tuổi t(kiểu số nguyên), bằng cấp cao nhất được đào tạo bc(kiểu char[15]), chuyên ngành(kiểu char[20]), bậc lương bl(kiểu float) là các thuộc tính riêng.Trong lớp có định nghĩa các hàm công cộng sau :
//-Hàm nhập dữ liệu cho các thông tin trên của 1 giáo viên
//- Hàm xuất các thông tin trên của giáo viên ra màn hình
//- Hàm tính tiền lương cơ bản lcb biết rằng lcb = bl * 610
//Viết chương trình nhập vào n(n nguyên dương nhập từ bàn phím) giáo viên.In ra màn hình :
//-Danh sách các giáo viên có tiền lương nhỏ hơn 2000.
//- Danh sách giáo viên sắp xếp theo chuyên ngành.
#include<iostream>
#include<string.h>
using namespace std;
class lopgiaovien {
private:
	char hoten[30];
	int tuoi;
	char bc[15];
	char cn[20];
	float bluong;
	int luongcoban;
public:
	void nhap() {
		cin.ignore();
		cout << "nhap ho ten giao vien la :";
		cin.getline(hoten, 30);
		cout << "nhap vao tuoi giao vien la :";
		cin >> tuoi;
		cin.ignore();
		cout << "nhap bang cap giao vien la :";
		cin.getline(bc, 15);
		cout << "nhap chuyen nganh giao vien la :";
		cin.getline(cn, 20);
		cout << "nhap bac luong giao vien :";
		cin >> bluong;

	}
	void tt() {//- Hàm tính tiền lương cơ bản lcb biết rằng lcb = bl * 610
		luongcoban = bluong * 610;
	}
	void xuat() {
		cout << "ho ten giao vien la : " << hoten << endl
			<< "tuoi giao vien la : " << tuoi << endl
			<< "bang cap giao vien la : " << bc << endl
			<< "chuyen nganh gia vien la : " << cn << endl
			<< "bac luong giao vien la : " << bluong << endl
			<< "luong co ban cua giao vien la : " << luongcoban << endl;
	}
	friend void ten_nganh(lopgiaovien a[] ,int n) {
		for (int i = 0; i < n; i++) {
			cout << "ho ten giao vien " << a[i].hoten <<" nganh " << a[i].cn << endl;
		}
	}
	friend void ten(lopgiaovien a[], int n) {
		for (int i = 0; i < n; i++) {
			cout << "ho ten giao vien " << a[i].hoten  << endl;
		}
	}
	void sosanh(lopgiaovien  a[], int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (strlen(a[i].cn) < strlen(a[j].cn)) {
					lopgiaovien tg = a[i];
					a[i] = a[j];
					a[j] = tg;

				}

			}
		}
	}
	friend void xuatten_nganh(lopgiaovien a[],int n) {
		for (int i = 0 ; i < n ; i++) {
			a[i].sosanh(a, n);

		}ten_nganh(a, n);
	}
	void xuatt() {
		tt();
		xuat();
	}
	friend void luong2000(lopgiaovien a[], int n) {

		for (int i = 0; i < n; i++) {
			if (a[i].luongcoban < 2000) {
				cout << "Giao vien thu " << i + 1 << " : " << a[i].hoten << endl;
			}
		}
	}



};
int main() {
	int n;
	cout << "nhap vao so giao vien la : ";
	cin >> n;
	lopgiaovien a[100];
	cout << "\n\tnhap lop giao vien : ";
	for (int i = 0; i < n; i++) {
		cout << "\n\tgiao vien thu  " << i + 1 << endl;
		a[i].nhap();
	}
	cout << "\n\txuat lop giao vien : ";
	for (int i = 0; i < n; i++) {
		cout << "\n\tgiao vien thu  " << i + 1 << endl;
		a[i].xuatt();
	}
	cout << "\n\tdanh sach giao vien luong nho hon 2000 =========================" << endl;
	luong2000(a, n);
	cout << " \n\tdanh sach giao vien sap xep tang dan cua chuyen nganh " << endl;
	xuatten_nganh(a, n);


	return  0;
}