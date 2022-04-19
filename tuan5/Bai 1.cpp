// Câu 1: Xây dựng lớp Gồm các thành phần Họ tên và Năm sinh. Viết các phương thức của lớp như nhập, hiển thị dữ liệu.
// Xây dựng lớp Thí sinh kế thừa lớp này, trong lớp Thí sinh có số báo danh và Điểm các môn toán, lý, hóa. 
//Hãy xây dựng thêm các phương thức nhập, xuất và khai báo mảng có kiểu là Thisinh để quản lý danh sách các thí nghiệm.
 //Viết chương trình với các công việc sau:
// - Import into a list have n thí sinh
// - Hiển thị danh sách thí sinh có tổng điểm ba môn tăng dần;
// - Tìm một thí sinh khi biết danh sách báo cáo.
// - Thống kê xem có bao nhiêu phần thí sinh đạt yêu cầu (cả ba môn đều có điểm lớn hơn hoặc bằng 5).





#include<iostream>
using namespace std;
class people{
private:
char hoten[30];
int nam;
public:
void nhap(){
    cout<<"Nhap ho ten ";   cin.getline(hoten,30);
    cout<<"nhap nam sinh: ";    cin>>nam;
}
void xuat(){
    cout<<"Ho ten: "<<hoten<<endl;
    cout<<"\nNam sinh: "<<nam<<endl;

}
};
class thisinh : public people{
    private:
    int sbd;
    float toan,ly,hoa;
    public:
    void nhap(){
        people ::nhap();
        cout<<"\nNhap SBD: ";cin>>sbd;
        cout<<"\nNhap diem toan: ";cin>>toan;
        cout<<"\nNhap diem ly: ";cin>>ly;
        cout<<"\nNhap diem hoa: ";cin>>hoa;
     

    }
    void xuat(){
      
        people ::xuat();
        cout<<"\nSBD: "<<sbd<<endl;
        cout<<"\nDiem toan: "<<toan<<endl;
        cout<<"\nDiem ly: "<<ly<<endl;
        cout<<"\nDiem hoa: "<<hoa<<endl;
    }

    void timkiem(thisinh a[], int n) {
        int sbd1;
        cout << "\n-Nhap sbd thi sinh muon tim: "; cin >> sbd1;
        for (int i = 0; i < n; i++) {
            if (a[i].sbd==sbd1) {
                a[i].xuat();

            }
        }
        
    }
    void thongke(thisinh a[], int n) {
       int dem = 0;
       for (int i = 0; i < n; i++) {
           float dtb = (a[i].toan + a[i].hoa + a[i].ly) / 3;
           if (dtb >= 5) dem++;
       }
       cout << "\n-So Thi sinh dat yeu cau la: "<<dem << endl;
    }
};


int main(){
    int n;
    cout<<"\nNhap so luong thi sinh: ";cin>>n;
    thisinh a[1000];
  
    for(int i = 0 ;i< n;i++){  
        cin.ignore();
        cout<<"\nNhap thi sinh: "<<i+1<<endl;
        a[i].nhap();
    }
    cout << "-Danh sach thi sinh" << endl;
    for(int i=0 ;i<n;i++){

        cout<<"\nThi sinh thu: "<<i + 1<<endl;
        a[i].xuat();
    }
    a->timkiem(a, n);
    a->thongke(a, n);
return 0;
}