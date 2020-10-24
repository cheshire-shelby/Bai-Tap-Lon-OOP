#include <iostream>
#include <string>
using namespace std;

//tao class hoac struct ngay thang nam sinh, nen de la struct cho gon va tien, phan nay Duyen lam
struct dob
{
	int ngay;
	int thang;
	int nam;
};

//tao kieu du lieu liet ke ten la gioi tinh (gender)
enum gender
{
    Male,
    Female
}; // Nam va Nu

//tao kieu du lieu liet ke ten la tinh trang (condition)
enum conditions
{
    Good,
    Bad
};

// tao class nhan khau
class Nhankhau
{
protected:
    int sothutu, MSCD;
    string ten, diachi;
    gender sex;

public:
    // ham nhap du lieu
    void nhap()
    {
    	cout<<"Moi nhap thong tin:\n";
        cout<<"STT: ";cin>>sothutu;
        cout<<"MSCD: ";cin>>MSCD;
        cout<<"Ten: ";	fflush(stdin);
        getline(cin,ten);
        cout<<"Dia chi: ";	fflush(stdin);
        getline(cin,diachi);
        
    }

    // ham in du lieu
    void in()
    {
    	cout<<"\n*******************\n";
    	cout<<"STT: "<<sothutu;
        cout<<"\nMSCD: "<<MSCD;
        cout<<"\nTen: "<<ten;
        cout<<"\nDia chi: "<<diachi;
    }
};

class Tieuhoc : public Nhankhau
{
protected:
    dob ngaysinh;

public:
    void nhap()
    {
        Nhankhau::nhap();
		cout<<"Nam sinh: ";cin>>ngaysinh.nam;
		do{
			cout<<"Thang sinh: ";cin>>ngaysinh.thang;	
		}while(ngaysinh.thang<1 || ngaysinh.thang>12);	
	
		switch(ngaysinh.thang){
			case 2:
			{
				if((ngaysinh.nam%400==0) ||(ngaysinh.nam%4==0 && ngaysinh.nam%100!=0)){
					do{
						cout<<"Ngay ngay: ";cin>>ngaysinh.ngay;
					}
					while(ngaysinh.ngay<1 ||ngaysinh.ngay>29);}
				else
					do{
						cout<<"Ngay sinh: ";cin>>ngaysinh.ngay;
					}
					while(ngaysinh.ngay<1 || ngaysinh.ngay>28);
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
			{
				do{
					cout<<"Ngay sinh: ";
					cin>>ngaysinh.ngay;
				}
				while(ngaysinh.ngay<1 ||ngaysinh.ngay>30);
				break;
			}
			default:
			{
				do{
					cout<<"Ngay sinh: ";
					cin>>ngaysinh.ngay;
				}
				while(ngaysinh.ngay<1 || ngaysinh.ngay>31);
				break;
			}	
		}
        // dien tiep code vao day
    }

    void in()
    {
        Nhankhau::in();
        cout<<"\nNgay sinh: "<<ngaysinh.ngay<<"/"<<ngaysinh.thang<<"/"<<ngaysinh.nam;
        // viet tiep code vao day
    }
    void indsdihoc(){
    if(2020 - ngaysinh.nam == 6 && ngaysinh.thang <= 9){
            cout<<"\n*******************\n";
    	    cout<<"STT: "<<sothutu;
            cout<<"\nMSCD: "<<MSCD;
            cout<<"\nTen: "<<ten;
            cout<<"\nDia chi: "<<diachi;
        }
    }
};

class Truongthanh : public Nhankhau
{
protected:
    dob ngaysinh;
    conditions suckhoe;

public:
    void nhap()
    {
        Nhankhau::nhap();
        cout<<"Nam sinh: ";cin>>ngaysinh.nam;
		do{
			cout<<"Thang sinh: ";cin>>ngaysinh.thang;	
		}while(ngaysinh.thang<1 || ngaysinh.thang>12);	
	
		switch(ngaysinh.thang){
			case 2:
			{
				if((ngaysinh.nam%400==0) ||(ngaysinh.nam%4==0 && ngaysinh.nam%100!=0)){
					do{
						cout<<"Ngay ngay: ";cin>>ngaysinh.ngay;
					}
					while(ngaysinh.ngay<1 ||ngaysinh.ngay>29);}
				else
					do{
						cout<<"Ngay sinh: ";cin>>ngaysinh.ngay;
					}
					while(ngaysinh.ngay<1 || ngaysinh.ngay>28);
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
			{
				do{
					cout<<"Ngay sinh: ";
					cin>>ngaysinh.ngay;
				}
				while(ngaysinh.ngay<1 ||ngaysinh.ngay>30);
				break;
			}
			default:
			{
				do{
					cout<<"Ngay sinh: ";
					cin>>ngaysinh.ngay;
				}
				while(ngaysinh.ngay<1 || ngaysinh.ngay>31);
				break;
			}	
		}
        // dien tiep code vao day
    }

    void in()
    {
        Nhankhau::in();
        cout<<"\nNgay sinh: "<<ngaysinh.ngay<<"/"<<ngaysinh.thang<<"/"<<ngaysinh.nam;
    }

    // ham thong ke du lieu
    int thongke()
    {

    }
};
int main(){
    Tieuhoc a[100];
	int n;
    cin>>n;
	cout<<"\n=====================moi ban nhap danh sach "<<n<< " nhan khau!!!!!==================";
		for (int i = 0; i < n; i++) {
			a[i].nhap();
		}
	cout<<"\n========================== danh sach nhung nguoi di hoc tieu hoc la !!!!!=======================";
		for (int i = 0; i < n; i++) {
			a[i].indsdihoc();
		}
	Tieuhoc th;
	th.nhap();
	th.in();
	Truongthanh tH;
	tH.nhap();
	tH.in();
	return 0;
}
