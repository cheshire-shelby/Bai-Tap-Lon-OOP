/*
Nhom Truong: Vu Thai Son-K185480106048

Các thành viên trong nhóm:
Nguyen Thi Duyen
Tran Van Ngoan
Vuong Thu Hoai
Le Thuy Nga

De tai 6:
*/
#include <iostream>
#include <string>
//#include <vector>
using namespace std;

string info[5] = {"Male", "Female", "Other", "Good", "Bad"};

int thang31[7] = {1, 3, 5, 7, 8, 10, 12};
int thang30[5] = {4, 6, 9, 11};

class Tieuhoc;
class Truongthanh;

// vi Library Vector khong su dung duoc trong DevC nen nhom em se tu tao kieu du lieu vector,
// cach khai bao vector <data_type> vector_name
// co cac ham:
//  size() de tinh so luong phan tu
//  empty() check xem vector = Null hay khong
//  push_back() push data vao trong vector

template <typename DataType>
class vector // dinh nghia kieu du lieu vector
{

    DataType *ArrayData;
    int length, capacity;

public:
    vector()
    {
        ArrayData = new DataType[1];
        capacity = 1;
        length = 0;
    }

    int size()
    {
        return length;
    }

    bool empty()
    {
        if (length == 0)
            return true;
        else
            return false;
    }

    DataType &operator[](int index)
    {
        if (index >= length)
        {
            cout << "Error: Array index out of bound";
            exit(0);
        }

        // else return value at that index
        return ArrayData[index];
    }

    void push_back(DataType data)
    {
        // neu so luong phan tu == dung luong (capacity)
        // ta gap doi dung luong
        if (length == capacity)
        {
            DataType *temp = new DataType[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = ArrayData[i]; // copy data tu array cu
            }
            delete[] ArrayData;      // xoa array cu
            capacity = capacity * 2; // gap doi dung luong
            ArrayData = temp;        // gan temp vao ArrayData
        }
        ArrayData[length] = data;
        length++;
    };
};

vector<Tieuhoc> Childlist;     // danh sach tre con
vector<Truongthanh> Adultlist; // danh sach nguoi lon

// Tao kieu ngay thang nam sinh ( date of birth)
struct dob 
{
    int ngay;
    int thang;
    int nam;
};

// Ham kiem tra thoi gian nhap co hop le khong 
bool checkDateTime(dob Datetime)
{
    if ((Datetime.nam % 400 == 0) || (Datetime.nam % 4 == 0 && Datetime.nam % 100 != 0))
    {
        if (Datetime.thang == 2 && Datetime.ngay <= 29)
            return true;
        else
        {
            for (int i = 0; i < 7; i++)
            {
                if (Datetime.thang == thang31[i])
                {
                    if (Datetime.ngay <= 31 && Datetime.ngay > 0)
                        return true;
                }
                if (Datetime.thang == thang30[i])
                {
                    if (Datetime.ngay <= 30 && Datetime.ngay > 0)
                        return true;
                }
            }
        }
    }
    else
    {
        if (Datetime.thang == 2 && Datetime.ngay <= 28)
            return true;
        else
        {
            for (int i = 0; i < 7; i++)
            {
                if (Datetime.thang == thang31[i])
                {
                    if (Datetime.ngay <= 31 && Datetime.ngay > 0)
                        return true;
                }
                if (Datetime.thang == thang30[i])
                {
                    if (Datetime.ngay <= 30 && Datetime.ngay > 0)
                        return true;
                }
            }
        }
    }
}


// Ham check tuoi xem truong thanh ( tuoi >= 18) hay tieu hoc (<18)
// Lay thoi diem hien tai la 20-9-2020
bool checkAdult(dob birthdate) // birthdate: ngay sinh, Adult: nguoi lon
{
    dob DateRightNow; // thoi gian hien tai
    DateRightNow.ngay = 20;
    DateRightNow.thang = 9;
    DateRightNow.nam = 2020;
    if (DateRightNow.nam - birthdate.nam > 18 || DateRightNow.nam - birthdate.nam == 18 && DateRightNow.thang > birthdate.thang)
        return true;
    else if (DateRightNow.nam - birthdate.nam == 18 && DateRightNow.thang == birthdate.thang)
    {
        if (DateRightNow.ngay >= birthdate.ngay)
            return true;
        else
            return false;
    }
    else
        return false;
}

//check tuoi == 18 chua de di NVQS
bool Equal18(string sex, string con, dob birthdate)
{
    dob DateRightNow;
    DateRightNow.thang = 9;
    DateRightNow.nam = 2020;

    //info = {"Male", "Female", "Other", "Good", "Bad"};
    if (sex == info[0] && con == info[3])
    {
        if (DateRightNow.nam - birthdate.nam == 18 && DateRightNow.thang >= birthdate.thang)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}


// in xem du toi di hoc chua (aka >= 6 tuoi)
bool checkDiHoc(dob birthdate)
{
    dob DateRightNow;
    DateRightNow.thang = 9;
    DateRightNow.nam = 2020;
    if (DateRightNow.nam - birthdate.nam > 6 ||
        DateRightNow.nam - birthdate.nam == 6 && DateRightNow.thang >= birthdate.thang)
        return true;
    else
        return false;
}


class Nhankhau
{
protected:
    int SoThuTu, PersonalCode; // Personal Code: chung minh nhan dan, ma so cong dan
    int SoLuong;

    //info = {"Male", "Female", "Other", "Good", "Bad"};
    string Name, DiaChi;
    string GioiTinh;
    Nhankhau *nhankhau;

public:
    dob NgaySinh;
    friend void NhapTieuHoc(Nhankhau Household); //Household: nhan khau
    friend void NhapTruongThanh(Nhankhau Household);
    
    // Y tuong: Nhap ngay thang nam sinh cua Nhan khau, neu
    // >= 18 thi se chay ham NhapTruongThanh(),
    // < 18 thi se chay ham NhapTieuHoc()
    void InputInfo()
    {
        cout << "So luong nhan khau: ";
        cin >> SoLuong;
        nhankhau = new Nhankhau[SoLuong];
        for (int i = 0; i < SoLuong; i++)
        {
        jump:
            cout << "\nNgay thang nam sinh (Nhap dang dd/mm/yyyy): " << endl;
            cin >> nhankhau[i].NgaySinh.ngay >> nhankhau[i].NgaySinh.thang >> nhankhau[i].NgaySinh.nam;
            if (checkDateTime(nhankhau[i].NgaySinh) == true)
            {
                if (checkAdult(nhankhau[i].NgaySinh) == true)
                {
                    NhapTruongThanh(nhankhau[i]);
                }
                else
                {
                    NhapTieuHoc(nhankhau[i]);
                }
            }
            else
            {
                cout << "Invalid Date and Time, please input again" << endl; // thong bao ngay thang khong hop le
                goto jump;
            }
        }
    }
};

class Tieuhoc : public Nhankhau
{
protected:
    dob ngaysinh; //dob: date of birth: ngay sinh

public:
    friend void NhapTieuHoc(Nhankhau Household);

    // ham in du lieu
    void PrintChild() 
    {
        if (Childlist.empty() == true)
        {
            cout << "\n"
                 << "-------------------------------------------------------------" << endl;
            cout << "Khong co nhan khau tieu hoc"
                 << "\n"
                 << "-------------------------------------------------------------"
                 << "\n\n";
        }

        else
        {

            cout << "----------------- Thông tin nhân khẩu tiểu học ---------------------" << endl;
            for (int i = 0; i < Childlist.size(); i++)
            {

                cout << "Tên: " << Childlist[i].Name << endl;

                cout << "Mã Số Công Dân: " << Childlist[i].PersonalCode << endl;

                cout << "Địa Chỉ: " << Childlist[i].DiaChi << endl;

                cout << "Giới tính: " << Childlist[i].GioiTinh << endl;

                cout << "Ngày tháng năm sinh: "
                     << Childlist[i].ngaysinh.ngay << " / "
                     << Childlist[i].ngaysinh.thang << " / "
                     << Childlist[i].ngaysinh.nam << endl;
                cout << "-------------------------------------------------------------------"
                     << "\n\n";
            }
        }
    }

    void printDiHoc()
    {
        if (Childlist.empty() == true)
        {
            cout << "\n"
                 << "-------------------------------------------------------------" << endl;
            cout << "Khong co ai trong do tuoi di hoc"
                 << "\n"
                 << "-------------------------------------------------------------"
                 << "\n\n";
        }
        else
        {

            for (int i = 0; i < Childlist.size(); i++)
            {

                if (checkDiHoc(Childlist[i].ngaysinh) == true) // tuoi >= 6
                {
                    cout << "\n"
                         << "---------------------Ca nhan du tuoi di hoc: --------------" << endl;
                    cout << "Tên: " << Childlist[i].Name << endl;

                    cout << "Mã Số Công Dân: " << Childlist[i].PersonalCode << endl;

                    cout << "Địa Chỉ: " << Childlist[i].DiaChi << endl;

                    cout << "Giới tính: " << Childlist[i].GioiTinh << endl;

                    cout << "Ngày tháng năm sinh: "
                         << Childlist[i].ngaysinh.ngay << " / "
                         << Childlist[i].ngaysinh.thang << " / "
                         << Childlist[i].ngaysinh.nam << endl;
                    cout << "-------------------------------------------------------------"
                         << "\n\n";
                }
            }
        }
    }
};

class Truongthanh : public Nhankhau
{
protected:
    dob ngaysinh;
    string Condition; // tinh trang suc khoe

public:
    friend void NhapTruongThanh(Nhankhau Household);

    void PrintAdult()
    {
        if (Adultlist.empty() == true)
        {
            cout << "\n"
                 << "-------------------------------------------------------------" << endl;
            cout << "Khong co ca nhan truong thanh"
                 << "\n"
                 << "-------------------------------------------------------------"
                 << "\n\n";
        }
        else
        {
            cout << "-----------------Thong tin nhan khau truong thanh ---------------------" << endl;
            for (int i = 0; i < Adultlist.size(); i++)
            {

                cout << "Tên: " << Adultlist[i].Name << endl;

                cout << "Giới tính: " << Adultlist[i].GioiTinh << endl;

                cout << "Tình trạng sức khoẻ: " << Adultlist[i].Condition << endl;

                cout << "Mã số công dân: " << Adultlist[i].PersonalCode << endl;

                cout << "Địa chỉ: " << Adultlist[i].DiaChi << endl;

                cout << "Ngày tháng năm sinh: "
                     << Adultlist[i].ngaysinh.ngay << " / "
                     << Adultlist[i].ngaysinh.thang << " / "
                     << Adultlist[i].ngaysinh.nam << endl;
                cout << "----------------------------------------------------------------------"
                     << "\n\n";
            }
        }
    }

    // ham thong ke du lieu
    void ThongKeNhapNgu() // tuoi = 18, suc khoe =  Good, gioi tinh  = Male (Nam)
    {
        if (Adultlist.empty() == true)
        {
            cout << "\n"
                 << "-------------------------------------------------------------" << endl;
            cout << "Khong co ai trong do tuoi nhap ngu"
                 << "\n"
                 << "-------------------------------------------------------------"
                 << "\n\n";
        }
        else
        {
            cout << "\n"
                 << "--------------------------------- Nguoi trong do tuoi nhap ngu ---------------------" << endl;
            for (int i = 0; i < Adultlist.size(); i++)
            {
                if (Equal18(Adultlist[i].GioiTinh, Adultlist[i].Condition, Adultlist[i].ngaysinh) == true)
                {
                    cout << "Tên: " << Adultlist[i].Name << endl;

                    cout << "Giới tính: " << Adultlist[i].GioiTinh << endl;

                    cout << "Tình trạng sức khoẻ: " << Adultlist[i].Condition << endl;

                    cout << "Mã số công dân: " << Adultlist[i].PersonalCode << endl;

                    cout << "Địa chỉ: " << Adultlist[i].DiaChi << endl;

                    cout << "Ngày tháng năm sinh: "
                         << Adultlist[i].ngaysinh.ngay << " / "
                         << Adultlist[i].ngaysinh.thang << " / "
                         << Adultlist[i].ngaysinh.nam << endl;
                    cout << "\n\n";
                }
            }
            cout << "------------------------------------------------------------------------------------"
                 << "\n\n";
        }
    }
};

void NhapTieuHoc(Nhankhau Household) // Household : nhan khau
{

    Tieuhoc Child;
    char sex;

    Child.ngaysinh = Household.NgaySinh;

    //info = {"Male", "Female", "Other", "Good", "Bad"};
    
    cout << "\nNhập tên: ";
    cin.ignore();
    getline(cin, Child.Name);

jump:
    cout << "Giới Tính (F/M/O): ";
    cin >> sex;
    if (sex == 'M' || sex == 'm')
        Child.GioiTinh = info[0];

    else if (sex == 'F' || sex == 'f')
        Child.GioiTinh = info[1];

    else if (sex == 'O' || sex == 'o')
        Child.GioiTinh = info[2];
    else
    {
        cout << "Please input Gender again with M as Male, F as Female, O as Other" << endl;
        goto jump;
    }

    cout << "Mã Số Công Dân: ";
    cin >> Child.PersonalCode;

    cout << "Địa Chỉ: ";
    cin.ignore();
    getline(cin, Child.DiaChi);

    cout << "\n";

    Childlist.push_back(Child); // vector Childlist
}

void NhapTruongThanh(Nhankhau Household)
{

    Truongthanh Adult;
    char sex;
    char condition;

    Adult.ngaysinh = Household.NgaySinh;

    cout << "\nNhập tên: ";
    cin.ignore();
    getline(cin, Adult.Name);

jump1:
    cout << "Giới Tính (F/M/O): ";
    cin >> sex;

    if (sex == 'M' || sex == 'm')
        Adult.GioiTinh = info[0];

    else if (sex == 'F' || sex == 'f')
        Adult.GioiTinh = info[1];

    else if (sex == 'O' || sex == 'o')
        Adult.GioiTinh = info[2];

    else
    {
        cout << "Please input Gender again with M as Male, F as Female, O as Other" << endl;
        goto jump1;
    }

    //vector<string> info = {"Male", "Female", "Other", "Good", "Bad"};

jump2:
    cout << "Tình trạng sức khoẻ (G/B) :";
    cin >> condition;

    if (condition == 'G' || condition == 'g')
        Adult.Condition = info[3];
    else if (condition == 'B' || condition == 'b')
        Adult.Condition = info[4];
    else
    {
        cout << "Please input condition again with G as Good, B as Bad" << endl;
        goto jump2;
    }
    cout << "Mã Số Công Dân: ";
    cin >> Adult.PersonalCode;

    cout << "Địa Chỉ: ";
    cin.ignore();
    getline(cin, Adult.DiaChi);

    cout << "\n";

    Adultlist.push_back(Adult);
}

int main()
{
    Nhankhau Household;
    Tieuhoc Child;
    Truongthanh Adult;

    Household.InputInfo();

    Child.PrintChild();
    Child.printDiHoc();

    Adult.PrintAdult();
    Adult.ThongKeNhapNgu();
}
