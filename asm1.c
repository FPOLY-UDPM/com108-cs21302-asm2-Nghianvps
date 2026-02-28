/******************************************************************************
 * Họ và tên: [NGUYỄN VĂN NGHĨA]
 * MSSV:      [PS43782]
 * Lớp:       [COM108]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>

// Ham kiem tra so nguyen
int laSoNguyen(float x)
{
    return (x == (int)x);
}

// Ham xu ly chuc nang 1
void chucNang1_KiemTraSoNguyen()
{
    float x;
    printf("Nhap mot so: ");
    scanf("%f", &x);

    if (laSoNguyen(x))
        printf("%.2f la so nguyen\n", x);
    else
        printf("%.2f khong phai la so nguyen\n", x);
}

// Ham xu ly chuc nang 2
int UCLN(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void chucNang2_UCLN_BCNN()
{
    int a, b;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);

    int ucln = UCLN(a, b);
    int bcnn = (a * b) / ucln;

    printf("UCLN = %d\n", ucln);
    printf("BCNN = %d\n", bcnn);
}

// Ham xu ly chuc nang 3
void tinhTienKaraoke()
{
    int gioBatDau, gioKetThuc;
    int soGio;
    float tongTien = 0;
    const int GIA_GIO = 150000;

    printf("Nhap gio bat dau (12 - 23): ");
    scanf("%d", &gioBatDau);

    printf("Nhap gio ket thuc (12 - 23): ");
    scanf("%d", &gioKetThuc);

    // Kiểm tra hợp lệ
    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc)
    {
        printf("Gio nhap khong hop le!\n");
        return;
    }

    soGio = gioKetThuc - gioBatDau;

    // Trường hợp bắt đầu trước 17h
    if (gioBatDau < 17)
    {
        if (soGio <= 3)
        {
            tongTien = soGio * GIA_GIO * 0.7; // giảm 30%
        }
        else
        {
            tongTien = 3 * GIA_GIO * 0.7;      // 3 giờ đầu giảm
            tongTien += (soGio - 3) * GIA_GIO; // giờ còn lại
        }
    }
    else
    {
        tongTien = soGio * GIA_GIO;
    }

    printf("So gio hat: %d gio\n", soGio);
    printf("Tong tien phai tra: %.0f VND\n", tongTien);
}

// Ham xu ly chuc nang 4
void chucNang4_TinhTienDien()
{
    int soDien;
    float tien = 0;

    printf("Nhap so kWh: ");
    scanf("%d", &soDien);

    if (soDien <= 50)
        tien = soDien * 1678;
    else if (soDien <= 100)
        tien = 50 * 1678 + (soDien - 50) * 1734;
    else if (soDien <= 200)
        tien = 50 * 1678 + 50 * 1734 + (soDien - 100) * 2014;
    else
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (soDien - 200) * 2536;

    printf("Tien dien = %.0f VND\n", tien);
}

// Ham xu ly chuc nang 5
void chucNang5_DoiTien()
{
    int tien;
    printf("Nhap so tien: ");
    scanf("%d", &tien);

    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 9; i++)
    {
        if (tien >= menhGia[i])
        {
            printf("%d to %d\n", tien / menhGia[i], menhGia[i]);
            tien %= menhGia[i];
        }
    }
}

// Ham xu ly chuc nang 6
void chucNang6_VayTraGop()
{
    float tienVay;
    printf("Nhap so tien vay: ");
    scanf("%f", &tienVay);

    float lai = 0.05;
    float gocHangThang = tienVay / 12;

    for (int i = 1; i <= 12; i++)
    {
        float laiThang = tienVay * lai;
        float tong = gocHangThang + laiThang;

        printf("Thang %d: Goc=%.0f Lai=%.0f Tong=%.0f\n",
               i, gocHangThang, laiThang, tong);

        tienVay -= gocHangThang;
    }
}

// Ham xu ly chuc nang 7
void chucNang7_VayMuaXe()
{
    float giaXe, traTruoc;

    printf("Nhap gia xe: ");
    scanf("%f", &giaXe);

    printf("Nhap so tien tra truoc: ");
    scanf("%f", &traTruoc);

    float vay = giaXe - traTruoc;
    float lai = 0.07;

    printf("So tien can vay: %.0f\n", vay);
    printf("Tien lai sau 1 nam: %.0f\n", vay * lai);
}

// Ham xu ly chuc nang 8
void chucNang8_SapXepSinhVien()
{
    int n;
    printf("Nhap so SV: ");
    scanf("%d", &n);

    float diem[n];

    for (int i = 0; i < n; i++)
    {
        printf("Nhap diem SV %d: ", i + 1);
        scanf("%f", &diem[i]);
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (diem[i] > diem[j])
            {
                float temp = diem[i];
                diem[i] = diem[j];
                diem[j] = temp;
            }

    printf("Danh sach sau sap xep:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f\n", diem[i]);
}

// Ham xu ly chuc nang 9
void chucNang9_Lott()
{
    int soDuDoan, soTrung = rand() % 100;

    printf("Nhap so du doan (0-99): ");
    scanf("%d", &soDuDoan);

    printf("So trung = %d\n", soTrung);

    if (soDuDoan == soTrung)
        printf("Trung giai!\n");
    else
        printf("Chuc ban may man lan sau!\n");
}

// Ham xu ly chuc nang 10
int UCLN_PS(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void chucNang10_PhanSo()
{
    int tu, mau;
    printf("Nhap tu so: ");
    scanf("%d", &tu);
    printf("Nhap mau so: ");
    scanf("%d", &mau);

    int u = UCLN_PS(tu, mau);

    printf("Phan so rut gon: %d/%d\n", tu / u, mau / u);
}

int main() {
    int chonChucNang;

    do {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang) {
            case 1:
                // Gọi hàm kiểm tra số nguyên
                printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
                chucNang1_KiemTraSoNguyen();
                break;
            case 2:
                // Gọi hàm tìm Ước số chung và bội số chung
                printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
                chucNang2_UCLN_BCNN();
                break;
            case 3:
                // Gọi hàm tính tiền cho quán Karaoke
                printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
                tinhTienKaraoke();
                break;
            case 4:
                // Gọi hàm tính tiền điện
                printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
                chucNang4_TinhTienDien();
                break;
            case 5:
                // Gọi hàm đổi tiền
                printf("DA CHON CHUC NANG 5: DOI TIEN\n");
                chucNang5_DoiTien();
                break;
            case 6:
                // Gọi hàm tính lãi suất vay ngân hàng
                printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
                chucNang6_VayTraGop();
                break;
            case 7:
                // Gọi hàm vay tiền mua xe
                printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
                chucNang7_VayMuaXe();
                break;
            case 8:
                // Gọi hàm sắp xếp thông tin sinh viên
                printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
                chucNang8_SapXepSinhVien();
                break;
            case 9:
                // Gọi hàm game FPOLY-LOTT
                printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
                chucNang9_Lott();
                break;
            case 10:
                // Gọi hàm tính toán phân số
                printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
                chucNang10_PhanSo();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);

    return 0;
}