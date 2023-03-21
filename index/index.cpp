#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void Nhap(SinhVien* arr, int& length)
{
    cin >> length;
    cin.ignore();

    for (int i = 0; i < length; i++)
    {
        cin.getline(arr[i].MASV, 10);
        cin.getline(arr[i].HoTen, 100);
        cin.getline(arr[i].NgaySinh, 12);
        cin >> arr[i].GioiTinh;
        cin >> arr[i].DiemToan >> arr[i].DiemLy >> arr[i].DiemHoa;
        cin.ignore();
    }
}

void SapXepGiamTheoMASV(SinhVien* arr, int& length)
{
    SinhVien temp;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (strcmp(arr[i].MASV, arr[j].MASV) < 0)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Xuat(SinhVien* arr, int& length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i].DTB = 1.0 * (arr[i].DiemToan + arr[i].DiemHoa + arr[i].DiemLy) / 3;
        cout << arr[i].MASV << "\t";
        cout << arr[i].HoTen << "\t";
        cout << arr[i].NgaySinh << "\t";
        cout << arr[i].GioiTinh << "\t";

        cout << std::setprecision(3) << arr[i].DiemToan << "\t";
        cout << std::setprecision(3) << arr[i].DiemLy << "\t";
        cout << std::setprecision(3) << arr[i].DiemHoa << "\t";
        cout << std::setprecision(3) << arr[i].DTB << endl;
    }
}

int main() {
    SinhVien A[MAXN];
    int n;
    Nhap(A, n);
    SapXepGiamTheoMASV(A, n);
    Xuat(A, n);
    return 0;
}