#include <iostream>
#include <string>
using namespace std;

struct dob
{
    int ngay;
    int thang;
    int nam;
};

string info[5] = {"Male", "Female", "Other", "Good", "Bad"};

class Nhankhau
{

public:
    // ham nhap du lieu
    int SoLuong, sothutu, MSCD;
    string Ten, DiaChi;
    string GioiTinh;
    Nhankhau nhap()
    {
        Nhankhau nhankhau;
        cout << "STT: ";
        cin >> nhankhau.sothutu;

        cout << "MSCD: ";
        cin >> nhankhau.MSCD;

        cout << "Ten: ";
        cin.ignore();
        getline(cin, nhankhau.Ten);

        cout << "Dia chi: ";
        cin.ignore();
        getline(cin, nhankhau.DiaChi);

        return nhankhau;
    }

    // ham in du lieu
    void in(Nhankhau nhankhau)
    {
        cout << "\n*******************\n";

        cout << "STT: " << nhankhau.sothutu;
        cout << "\nMSCD: " << nhankhau.MSCD;
        cout << "\nTen: " << nhankhau.Ten;
        cout << "\nDia chi: " << nhankhau.DiaChi;
    }
};

class Tieuhoc : public Nhankhau
{
protected:
    dob ngaysinh;
    Tieuhoc *tieuhoc;
    int soluongTH;

public:
    void nhap()
    {
        cout << "nhap so luong nhan khau tieu hoc: ";
        cin >> soluongTH;
        tieuhoc = new Tieuhoc[soluongTH];
        for (int i = 0; i < soluongTH; i++)
        {
            Nhankhau household; // dung de luu tru thong tin da nhap vao
            household = Nhankhau::nhap();
            tieuhoc[i].DiaChi = household.DiaChi;
            tieuhoc[i].Ten = household.Ten;
            tieuhoc[i].sothutu = household.sothutu;
            tieuhoc[i].MSCD = household.MSCD;
            cout << "Nam sinh: ";
            cin >> tieuhoc[i].ngaysinh.nam;
            do
            {
                cout << "Thang sinh: ";
                cin >> tieuhoc[i].ngaysinh.thang;
            } while (tieuhoc[i].ngaysinh.thang < 1 || tieuhoc[i].ngaysinh.thang > 12);

            switch (tieuhoc[i].ngaysinh.thang)
            {
            case 2:
            {
                if ((tieuhoc[i].ngaysinh.nam % 400 == 0) || (tieuhoc[i].ngaysinh.nam % 4 == 0 && tieuhoc[i].ngaysinh.nam % 100 != 0))
                {
                    do
                    {
                        cout << "Ngay ngay: ";
                        cin >> tieuhoc[i].ngaysinh.ngay;
                    } while (tieuhoc[i].ngaysinh.ngay < 1 || tieuhoc[i].ngaysinh.ngay > 29);
                }
                else
                    do
                    {
                        cout << "Ngay sinh: ";
                        cin >> tieuhoc[i].ngaysinh.ngay;
                    } while (tieuhoc[i].ngaysinh.ngay < 1 || tieuhoc[i].ngaysinh.ngay > 28);
            }
            break;
            case 4:
            case 6:
            case 9:
            case 11:
            {
                do
                {
                    cout << "Ngay sinh: ";
                    cin >> tieuhoc[i].ngaysinh.ngay;
                } while (tieuhoc[i].ngaysinh.ngay < 1 || tieuhoc[i].ngaysinh.ngay > 30);
                break;
            }
            default:
            {
                do
                {
                    cout << "Ngay sinh: ";
                    cin >> tieuhoc[i].ngaysinh.ngay;
                } while (tieuhoc[i].ngaysinh.ngay < 1 || tieuhoc[i].ngaysinh.ngay > 31);
                break;
            }
            }
        }
    }

    void in()
    {
        for (int i = 0; i < soluongTH; i++)
        {

            cout << "STT" << tieuhoc[i].sothutu << endl;
            cout << "MSCD" << tieuhoc[i].MSCD << endl;
            cout << "ten: " << tieuhoc[i].Ten << endl;
            cout << "Dia chi: " << tieuhoc[i].DiaChi << endl;
            cout << "\nNgay sinh: "
                 << tieuhoc[i].ngaysinh.ngay
                 << "/" << tieuhoc[i].ngaysinh.thang
                 << "/" << tieuhoc[i].ngaysinh.nam << endl;
        }
    }
    void indsdihoc()
    {
        for (int i = 0; i < soluongTH; i++)
            if (2020 - tieuhoc[i].ngaysinh.nam == 6 && tieuhoc[i].ngaysinh.thang <= 9)
            {
                cout << "\n*******************\n";

                cout << "STT" << tieuhoc[i].sothutu << endl;
                cout << "MSCD" << tieuhoc[i].MSCD << endl;
                cout << "ten: " << tieuhoc[i].Ten << endl;
                cout << "Dia chi: " << tieuhoc[i].DiaChi << endl;
                cout << "\nNgay sinh: "
                     << tieuhoc[i].ngaysinh.ngay
                     << "/" << tieuhoc[i].ngaysinh.thang
                     << "/" << tieuhoc[i].ngaysinh.nam << endl;
            }
    }
};

class Truongthanh : public Nhankhau
{
protected:
    dob ngaysinh;
    string Condition;
    int SoLuongTruongThanh;
    Truongthanh *Adult;
    string sex;

public:
    void nhap()
    {
        char sex;
        char condition;
        cout << "So Luong Truong Thanh: ";
        cin >> SoLuongTruongThanh;
        Adult = new Truongthanh[SoLuongTruongThanh];
        for (int i = 0; i < SoLuongTruongThanh; i++)
        {
            Nhankhau household;
            household = Nhankhau::nhap();
            Adult[i].DiaChi = household.DiaChi;
            Adult[i].Ten = household.Ten;
            Adult[i].sothutu = household.sothutu;
            Adult[i].MSCD = household.MSCD;
            cout << "Giới Tính (F/M/O): ";
            cin >> sex;
            if (sex == 'M' || sex == 'm')
                Adult[i].GioiTinh = info[0];
            else if (sex == 'F' || sex == 'F')
                Adult[i].GioiTinh = info[1];
            else if (sex == 'O' || sex == 'o')
                Adult[i].GioiTinh = info[2];
            else
                cout << "Nhập không đúng, xin hãy nhập F/M/O";

            //vector<string> info = {"Male", "Female", "Other", "Good", "Bad"};
            cout << "Tình trạng sức khoẻ (G/B) :";
            cin >> condition;
            if (condition == 'G' || condition == 'g')
                Adult[i].Condition = info[3];
            else if (condition == 'B' || condition == 'b')
                Adult[i].Condition = info[4];
            else
                cout << "Nhập không đúng, xin hãy nhập G/B";

            cout << "Nam sinh: ";
            cin >> Adult[i].ngaysinh.nam;
            do
            {
                cout << "Thang sinh: ";
                cin >> Adult[i].ngaysinh.thang;
            } while (Adult[i].ngaysinh.thang < 1 || Adult[i].ngaysinh.thang > 12);

            switch (Adult[i].ngaysinh.thang)
            {
            case 2:
            {
                if ((Adult[i].ngaysinh.nam % 400 == 0) || (Adult[i].ngaysinh.nam % 4 == 0 && Adult[i].ngaysinh.nam % 100 != 0))
                {
                    do
                    {
                        cout << "Ngay ngay: ";
                        cin >> Adult[i].ngaysinh.ngay;
                    } while (Adult[i].ngaysinh.ngay < 1 || Adult[i].ngaysinh.ngay > 29);
                }
                else
                    do
                    {
                        cout << "Ngay sinh: ";
                        cin >> Adult[i].ngaysinh.ngay;
                    } while (Adult[i].ngaysinh.ngay < 1 || Adult[i].ngaysinh.ngay > 28);
            }
            break;
            case 4:
            case 6:
            case 9:
            case 11:
            {
                do
                {
                    cout << "Ngay sinh: ";
                    cin >> Adult[i].ngaysinh.ngay;
                } while (Adult[i].ngaysinh.ngay < 1 || Adult[i].ngaysinh.ngay > 30);
                break;
            }
            default:
            {
                do
                {
                    cout << "Ngay sinh: ";
                    cin >> Adult[i].ngaysinh.ngay;
                } while (Adult[i].ngaysinh.ngay < 1 || Adult[i].ngaysinh.ngay > 31);
                break;
            }

                // dien tiep code vao day
            }
        }
    }

    void in()
    {
        char sex;
        char condition;
        for (int i = 0; i < SoLuongTruongThanh; i++)
        {

            cout << "STT" << Adult[i].sothutu << endl;
            cout << "MSCD" << Adult[i].MSCD << endl;
            cout << "ten: " << Adult[i].Ten << endl;
            cout << "Dia chi: " << Adult[i].DiaChi << endl;

            cout << "\nNgay sinh: "
                 << Adult[i].ngaysinh.ngay
                 << "/"
                 << Adult[i].ngaysinh.thang
                 << "/"
                 << Adult[i].ngaysinh.nam;
            cout << "Gioi tinh: " << Adult[i].GioiTinh;
            cout << "Tinh trang suc khoe: " << Adult[i].Condition;
        }
    }
    // ham thong ke du lieu
    int thongke()
    {
        int dem = 0;
        for (int i = 0; i < SoLuongTruongThanh; i++)
        {

            if (2020 - Adult[i].ngaysinh.nam == 18 && (9 >= Adult[i].ngaysinh.thang))
            {
                if (Adult[i].GioiTinh == info[0] && Adult[i].Condition == info[3])
                {
                    dem++;
                }
            }
            return dem;
        }
    }
}

;
int main()
{
    Tieuhoc Child;
    Truongthanh Adult;

    Child.nhap();
    // Adult.nhap();

    cout << "\n=====================danh sach nhan khau tieu hoc!!!!!==================";
    Child.in();

    cout << "\n========================== danh sach nhung nguoi di hoc tieu hoc la !!!!!=======================";
    Child.indsdihoc();

    cout << "\n=====================danh sach nhan khau truong thanh!!!!!==================";
    Adult.in();

    cout << "\n=====================so nhan khau truong thanh du tuoi di quan su!!!!!==================";
    cout << Adult.thongke();

    return 0;
}