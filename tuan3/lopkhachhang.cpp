//Câu 1: Xây dựng lớp khách hàng KH gồm các thuộc tính họ tên ht (kiểu char[30]), 
// ngày sinh ns (kiểu struct NS(ngày, tháng, năm)), số chứng minh thư cmt (kiểu char[10]), hộ khẩu k (kiểu char[50]) là các thuộc tính riêng. 
// Trong lớp có định nghĩa các hàm công cộng sau:
//-Hàm nhập dữ liệu cho các thông tin trên của 1 khách hàng
//- Hàm xuất các thông tin trên của khách hàng ra màn hình
//Viết chương trình nhập vào n(n nguyên dương nhập từ bàn phím) khách hàng.In ra màn hình :
//-Danh sách khách hàng theo thứ tự tăng dần của họ tên.
//- Danh sách các khách hàng có sinh nhật tháng 12.
#include<iostream>
using namespace std;
class lopkhachhang {
private:
	char hoten[30];
	int ngay;
	int thang;
	int nam;
	char socmnd[10];
	char hokhau[50];
public:
	void nhap() {
		cin.ignore();
		cout << "nhap ho ten khach hang la : ";
		cin.getline(hoten, 30);
		cout << "nhap ngay sinh khach hang la : ";
		cin >> ngay;
		cout << "nhap thang sinh khach hang la : ";
		cin >> thang;
		cout << "nhap nam sinh khach hang la : ";
		cin >> nam;
		cin.ignore();
		cout << "nhap so chung minh nhan dan khach hang la : ";
		cin.getline(socmnd, 10);
		cout << "nhap ho khau khach hang la : ";
		cin.getline(hokhau, 50);

	}
	void xuat() {
		cout << "ho ten khach hang : " << hoten << endl
			<< "ngay sinh khach hang : " << ngay << endl
			<< "thang sinh khach hang : " << thang << endl
			<< "nam sinh khach hang : " << nam << endl
			<< "so cmnd khach hang : " << socmnd << endl
			<< "ho khau khach hang : " << hokhau << endl;
	}
	friend void xuatten(lopkhachhang a[], int n) {


		for (int i = 0; i < n; i++) {
			cout << "ho ten khach hang la " << a[i].hoten << endl;
		}
	}
	void sosanh(lopkhachhang a[], int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (strlen(a[i].hoten) < strlen(a[j].hoten)) {
					lopkhachhang tg = a[i];
					a[i] = a[j];
					a[j] = tg;
				}
			}
		}

	}
	friend void xuatteen(lopkhachhang a[], int n) {
		for (int i = 0; i < n; i++) {
			a[i].sosanh(a, n);

		}xuatten(a, n);
	}
	friend void thang12(lopkhachhang a[], int n) {

		for (int i = 0; i < n; i++) {
			if (a[i].thang == 12) {

				cout << a[i].hoten << endl;
			}
		}
	}

};


int main() {
	int n;
	cout << "NHAP SO LUONG KHACH HANG LA : ";
	cin >> n;
	lopkhachhang a[100];
	fflush;
	cout << "\n\tNHAP THONG TIN KHACH HANG LA : " << endl;
	for (int i = 0; i < n; i++) {
		cout << "\tKhach hang thu " << i + 1 << endl;
		a[i].nhap();
	}
	cout << "\n\tXUAT THONG TIN KHACH HANG LA : " << endl;
	for (int i = 0; i < n; i++) {
		cout << "\tKhach hang thu " << i + 1 << endl;
		a[i].xuat();
	}
	cout << "\n\tKHACH HANG THEO THU TU TANG DAN CUA HO TEN : " << endl;
	xuatteen(a, n);
	cout << "\n\tCAC KHACH HANG CO SINH NHAT THANG 12 LA : " << endl;
	thang12(a, n);
	return 0;
}