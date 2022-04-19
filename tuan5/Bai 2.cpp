//Câu 2: Xây dựng Sản phẩm lớp bao gồm : Mã sản phẩm, Tên sản phẩm, Năm sản phẩm và các phương thức nhập, xuất.
//Build of the class TV is more than Chiều dài thuộc tính, Chiều rộng của màn hình.Hãy xây dựng tích hợp tính năng của màn hình TV lớp.
//Viết chương trình nhập vào các đối tượng của Tivi lớp, sau đó sắp xếp tăng dần theo diện tích màn hình của các đối tượng này.


#include<iostream>
using namespace std;
class sp {
private:
	char msp[20];
	char ten[30];
	int nam;
public:
	void nhap() {
		cout << "\nNhap ma san pham: "; cin >> msp;
		cout << "\nNhap ten san pham: "; cin >> ten;
		cin.ignore();
		cout << "\nNhap nam san xuat: "; cin >> nam;
	}
	void xuat() {
		cout << "\n ma san pham: "<< msp<<endl;
		cout << "\n ten san pham: "<< ten<<endl;
		cout << "\n nam san xuat: "<< nam<<endl;
	}

};
class tivi : sp
{
private:
	float dai, rong,S = dai * rong;
public:
	void nhap() {
		sp::nhap();
		cout << "\nNhap chieu dai: "; cin >> dai;
		cout << "\nNhap chieu rong: "; cin >> rong;
	}
	void xuat() {
		sp::xuat();
		cout << "\n chieu dai: "<<dai<<endl;
		cout << "\n chieu rong: "<< rong<<endl;
	}

	int S1()
	{
		return S;
	}

	bool operator > (tivi& a)
	{
		return (this->S > a.S1());
	}


};

int  main() {


	int n;
	cout << "Nhap n: "; cin >> n;
	cin.ignore();
	tivi a[1000];

	for (int i = 0; i < n; i++) {
		cout << "\nNhap san pham " << i + 1 << endl;
		a[i].nhap();
	}
	for (int i = 0; i < n; i++) {
		cout << "\nxuat san pham " << i + 1 << endl;
		a[i].xuat();
	}
	cout << "Danh sach san pham sau khi sap xep=====" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			
				if (a[i] > a[j])
				{
					swap(a[i], a[j]);
				}
			
		}
		a[i].xuat();
	
	}

	return 0;
}