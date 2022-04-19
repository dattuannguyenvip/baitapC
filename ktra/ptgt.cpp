#include<iostream.h>
class PTGT {
private:
	char Mapt[8];
	char hangsx[20];
	int  ngayxx;
	float gtc;
public:
	void nhap()
	{
		cout << "\nNhap Ma Phuong Tien: ";
		cin.getline(Mapt, 8);
		cout << "\nNhap Hang san xuat: ";
		cin.getline(hangsx, 20);
		cout << "\nNhap Ngay xuat xuong: ";
		cin >> ngayxx;
		cout << "\nNhap Gia chua thue: ";
		cin >> gtc;
		fflush(stdin);

	}
	void xuat()
	{
		cout << "\nMa Phuong Tien: " << Mapt
			<< "\nHang san xuat : " << hangsx
			<< "\nNgay xuat xuong :" << ngayxx
			<< "\nGia chua thue: " << gtc << endl;

	}
	~PTGT() {
		cout << "\nHam huy duoc goi" << endl;
	}
};

int main()
{
	int n;
	cout << "\nNhap so luong phuong tien giao thong: ";
	cin >> n;
	PTGT a[n];
	fflush(stdin);
	cout << "\n\t\tNHAP THONG TIN PHUONG TIEN " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\nPhuong tien thu " << i + 1 << endl;
		a[i].nhap();
	}
	cout << "\n\t\t\tTHONG TIN PHUONG TIEN: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\nPhuong tien thu: " << i + 1 << endl;
		a[i].xuat();
	}
}