//Câu 1: Xây dựng lớp khách hàng KH gồm các thuộc tính họ tên ht(kiểu char[30]), ngày sinh ns(kiểu struct NS(ngày, tháng, năm)), số chứng minh thư cmt(kiểu char[10]), hộ khẩu k(kiểu char[50]) là các thuộc tính riêng.Trong lớp có định nghĩa các hàm công cộng sau :
//-Hàm toán tử nhập >> đi với cin để nhập dữ liệu cho các thông tin trên của 1 khách hàng
//- Hàm toán tử xuất << đi với cout để xuất các thông tin trên của khách hàng ra màn hình
//- Hàm toán tử “ > ” so sánh 2 khách hàng(khách hàng lớn hơn  là khách hàng có tuổi lớn hơn)
//Viết chương trình nhập vào n(n nguyên dương nhập từ bàn phím) khách hàng.In ra màn hình :
//-Danh sách các khách hàng có hộ khẩu “Hà Nội”.
//- Danh sách khách hàng đã sắp xếp theo thứ tự giảm dần của tuổi.
#include<iostream>
using namespace std;
class lopkhachhang {
private:
	char ht[30];
	int ngay;
	int thang;
	int nam;
	char socmnd[10];
	char hokhau[50];
	int tuoi;
public:
	friend istream& operator >>(istream& nhap, lopkhachhang& kh) {
		cout << "nhap ten : ";
		nhap.getline(kh.ht, 30);
		cout << "nhap ngay sinh : ";
		nhap >> kh.ngay;
		cout << "nhap thang sinh : ";
		nhap >> kh.thang;
		cout << "nhap nam sinh : ";
		nhap >> kh.nam;
		cin.ignore();
		cout << "nhap so cmnd : ";
		nhap.getline(kh.socmnd, 10);
		cout << "nhap ho khau : ";
		nhap.getline(kh.hokhau, 50);
		return nhap;
	}

	friend ostream& operator <<(ostream& xuat, lopkhachhang& kh) {
		cout << " | Ho ten : " << kh.ht << endl
			<< " | Ngay sinh : " << kh.ngay << endl
			<< " | Thang sinh : " << kh.thang << endl
			<< " | Nam sinh : " << kh.nam << endl
			<< " | So cmnd : " << kh.socmnd << endl
			<< " | Ho khau : " << kh.hokhau << endl;
		return xuat;
	}
	friend void hn(lopkhachhang a[], int n) {
		for (int i = 0; i < n; i++) {
			if (strcmp(a[i].hokhau, "ha noi") == 0) {
				cout << " Stt" << i + 1 << " | Ho ten : " << a[i].ht << endl;

			}
		}
	}
	friend void tt(lopkhachhang a[], int n) {
		for (int i = 0; i < n; i++) {
			a[i].tuoi = 2022 - a[i].nam;
		}
	}
	void sosanh(lopkhachhang a[], int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i].tuoi > a[j].tuoi) {
					lopkhachhang tg = a[i];
					a[i] = a[j];
					a[j] = tg;
				}
			}
		}
	}
	friend void xuatten(lopkhachhang a[], int n) {
		for (int i = 0; i < n; i++) {
			cout << " | Ho ten : " << a[i].ht << endl;
		}
	}
	friend void xuatt(lopkhachhang a[], int n) {
		for (int i = 0; i < n; i++) {
			a[i].sosanh(a, n);
			cout << " | Ho ten : " << a[i].ht << endl;
		}
	}

};
int main() {
	int n, i;
	cout << "nhap vao so luong khach hang la : ";
	cin >> n;
	lopkhachhang a[100];
	cin.ignore();
	cout << "\n\tNHAP THONG TIN KHACH HANG : ";
	for (int i = 0; i < n; i++) {
		cout << " \n\tSTT " << i + 1 << endl;
		cin >> a[i];
	}
	cout << "\n\tXUAT THONG TIN KHAH HANG : ";
	for (int i = 0; i < n; i++) {
		cout << " \n\tSTT " << i + 1 << endl;
		cout << a[i];
	}
	cout << "\n\tKHACH HANG HO KHAU HA NOI : " << endl;
	hn(a, n);
	cout << "\n\tDANH SACH GIAM DAN CUA TUOI : " << endl;
	xuatt(a, n);
	return 0;
}