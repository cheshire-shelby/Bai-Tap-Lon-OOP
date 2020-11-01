/*
hướng làm bài sau khi tổng hợp các cách làm của bạn
- tạo 3 class như trong đề bài giao 
- tạp 2 mảng để lưu trữ dữ liệu cho 2 class tiểu học và trưởng thành (vì những người trong class tiểu học và trưởng thành đều
nằm trong class nhân khẩu)
- viết hàm check, với những người có tuôỉ trên 18 thì lưu vào mảng trưởng thành, nhỏ hơn thì lưu vào
mảng tiểu học 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> info = {"Male", "Female", "Other", "Good", "Bad"};
int thang31[7] = {1, 3, 5, 7, 8, 10, 12};
int thang30[5] = {2, 3, 6, 9, 11};

class Tieuhoc;
class Truongthanh;

struct dob
{
    int ngay;
    int thang;
    int nam;
};

vector<Tieuhoc> Childlist;
vector<Truongthanh> Adultlist;

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

//check tuoi xem truong thanh hay tieu hoc
bool checkAdult(dob birthdate)
{
    dob DateRightNow;
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

//check xem 18 chua
bool check18(string sex, string con, dob birthdate)
{
    dob DateRightNow;
    DateRightNow.thang = 9;
    DateRightNow.nam = 2020;
    if (sex == info[0] && con == info[3])
    {
        if (DateRightNow.nam - birthdate.nam == 18 && DateRightNow.thang == birthdate.thang)
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
    int SoThuTu, PersonalCode, SoLuong;
    string Name, DiaChi;
    string GioiTinh;
    Nhankhau *nhankhau;

public:
    dob NgaySinh;
    friend void NhapTieuHoc(Nhankhau Household);
    friend void NhapTruongThanh(Nhankhau Household);

    void InputInfo()
    {
        cout << "Nhập số lượng nhân khẩu: ";
        cin >> SoLuong;
        nhankhau = new Nhankhau[SoLuong];
        for (int i = 0; i < SoLuong; i++)
        {
            cout << "Ngày tháng năm sinh, nhập dạng dd/mm/yyyy: " << endl;
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
                cout << "Ngày tháng năm không hợp lệ" << endl;
            }
        }
    }
};

class Tieuhoc : public Nhankhau
{
protected:
    dob ngaysinh;

public:
    friend void NhapTieuHoc(Nhankhau Household);

    // ham in du lieu
    void PrintChild()
    {
        if (Childlist.empty() == true)
        {
            cout << "\n"
                 << "-------------------------------------------------------------" << endl;
            cout << "Không có nhân khẩu tiểu học"
                 << "\n"
                 << "-------------------------------------------------------------"
                 << "\n\n";
        }

        else
        {

            cout << "----------------- Thông tin nhân khẩu tiểu học ------------------------" << endl;
            for (int i = 0; i < Childlist.size(); i++)
            {

                cout << "Tên: " << Childlist.at(i).Name << endl;

                cout << "Mã Số Công Dân: " << Childlist[i].PersonalCode << endl;

                cout << "Địa Chỉ: " << Childlist[i].DiaChi << endl;

                cout << "Giới tính: " << Childlist[i].GioiTinh << endl;

                cout << "Ngày tháng năm sinh: "
                     << Childlist[i].ngaysinh.ngay << " / "
                     << Childlist[i].ngaysinh.thang << " / "
                     << Childlist[i].ngaysinh.nam << endl;
                cout << "--------------------------------------------------------------------"
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
            cout << "Không có ai trong độ tuổi đi học"
                 << "\n"
                 << "-------------------------------------------------------------"
                 << "\n\n";
        }
        else
        {

            for (int i = 0; i < Childlist.size(); i++)
            {

                if (checkDiHoc(Childlist[i].ngaysinh) == true)
                {
                    cout << "\n"
                         << "---------------------Cá nhân đủ tuổi vào tiểu học: --------------" << endl;
                    cout << "Tên: " << Childlist.at(i).Name << endl;

                    cout << "Mã Số Công Dân: " << Childlist[i].PersonalCode << endl;

                    cout << "Địa Chỉ: " << Childlist[i].DiaChi << endl;

                    cout << "Giới tính: " << Childlist[i].GioiTinh << endl;

                    cout << "Ngày tháng năm sinh: "
                         << Childlist[i].ngaysinh.ngay << " / "
                         << Childlist[i].ngaysinh.thang << " / "
                         << Childlist[i].ngaysinh.nam << endl;
                    cout << "--------------------------------------------------------------------"
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
    string Condition;

public:
    friend void NhapTruongThanh(Nhankhau Household);

    void PrintAdult()
    {
        if (Adultlist.empty() == true)
        {
            cout << "\n"
                 << "-------------------------------------------------------------" << endl;
            cout << "Không có nhân khẩu trưởng thành "
                 << "\n"
                 << "-------------------------------------------------------------"
                 << "\n\n";
        }
        else
        {
            cout << "----------------- Thông tin nhân khẩu trưởng thành ---------------------" << endl;
            for (int i = 0; i < Adultlist.size(); i++)
            {

                cout << "Tên: " << Adultlist.at(i).Name << endl;

                cout << "Giới tính: " << Adultlist[i].GioiTinh << endl;

                cout << "Tình trạng sức khoẻ: " << Adultlist[i].Condition << endl;

                cout << "Mã số công dân: " << Adultlist[i].PersonalCode << endl;

                cout << "Địa chỉ: " << Adultlist[i].DiaChi << endl;

                cout << "Ngày tháng năm sinh: "
                     << Adultlist[i].ngaysinh.ngay << " / "
                     << Adultlist[i].ngaysinh.thang << " / "
                     << Adultlist[i].ngaysinh.nam << endl;
                cout << "------------------------------------------------------------------------------------------"
                     << "\n\n";
            }
        }
    }

    // ham thong ke du lieu
    void ThongKeNhapNgu()
    {
        if (Adultlist.empty() == true)
        {
            cout << "\n"
                 << "-------------------------------------------------------------" << endl;
            cout << "Không có ai trong độ tuổi nhập ngũ"
                 << "\n"
                 << "-------------------------------------------------------------"
                 << "\n\n";
        }
        else
        {
            for (int i = 0; i < Adultlist.size(); i++)
            {
                if (check18(Adultlist[i].GioiTinh, Adultlist[i].Condition, Adultlist[i].ngaysinh) == true)
                {
                    cout << "\n"
                         << "--------------------------------- Người có đủ tuổi nhập ngũ ---------------------" << endl;
                    cout << "Tên: " << Adultlist.at(i).Name << endl;

                    cout << "Giới tính: " << Adultlist[i].GioiTinh << endl;

                    cout << "Tình trạng sức khoẻ: " << Adultlist[i].Condition << endl;

                    cout << "Mã số công dân: " << Adultlist[i].PersonalCode << endl;

                    cout << "Địa chỉ: " << Adultlist[i].DiaChi << endl;

                    cout << "Ngày tháng năm sinh: "
                         << Adultlist[i].ngaysinh.ngay << " / "
                         << Adultlist[i].ngaysinh.thang << " / "
                         << Adultlist[i].ngaysinh.nam << endl;
                    cout << "--------------------------------------------------------------------------------------------------"
                         << "\n\n";
                }
            }
        }
    }
};

void NhapTieuHoc(Nhankhau Household)
{

    Tieuhoc Child;
    char sex;

    Child.ngaysinh = Household.NgaySinh;
    //vector<string> info = {"Male", "Female", "Other", "Good", "Bad"};
    cout << "Nhập tên: ";
    cin.ignore();
    getline(cin, Child.Name);

    cout << "Giới Tính (F/M/O): ";
    cin >> sex;
    if (sex == 'M' || sex == 'm')
        Child.GioiTinh = info[0];
    else if (sex == 'F' || sex == 'f')
        Child.GioiTinh = info[1];
    else if (sex == 'O' || sex == 'o')
        Child.GioiTinh = info[2];
    else
        cout << "Nhập không đúng, xin hãy nhập F/M/O";

    cout << "Mã Số Công Dân: ";
    cin >> Child.PersonalCode;

    cout << "Địa Chỉ: ";
    cin.ignore();
    getline(cin, Child.DiaChi);

    cout << "\n";

    Childlist.push_back(Child);
}

void NhapTruongThanh(Nhankhau Household)
{

    Truongthanh Adult;
    char sex;
    char condition;

    Adult.ngaysinh = Household.NgaySinh;

    cout << "Nhập tên: ";
    cin.ignore();
    getline(cin, Adult.Name);

    cout << "Giới Tính (F/M/O): ";
    cin >> sex;
    if (sex == 'M' || sex == 'm')
        Adult.GioiTinh = info[0];
    else if (sex == 'F' || sex == 'F')
        Adult.GioiTinh = info[1];
    else if (sex == 'O' || sex == 'o')
        Adult.GioiTinh = info[2];
    else
        cout << "Nhập không đúng, xin hãy nhập F/M/O";

    cout << "Tình trạng sức khoẻ (G/B) :";
    cin >> condition;
    if (condition == 'G' || condition == 'g')
        Adult.Condition = info[3];
    else if (condition == 'B' || condition == 'b')
        Adult.Condition = info[4];
    else
        cout << "Nhập không đúng, xin hãy nhập G/B";

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
