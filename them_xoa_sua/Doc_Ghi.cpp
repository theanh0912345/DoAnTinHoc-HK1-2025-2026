#include"Header.h"

int main() {
	NODE ds;
	quanLySach sach;
	ds = NULL;
	int choice;
	while (true)
	{
		cout << "hay chon chuc nang ban muon.\n";
		cout << "0.Thoat chuong trinh.\n";
		cout << "1.Doc File co dinh dang CSV.\n";
		cout << "2.Ghi File co dinh dang CSV.\n";
		cout << "3.Hien du lieu danh sach.\n";
		cout << "4.Them sach vao du lieu.\n";
		cout << "5.Xoa sach khoi du lieu.\n";
		cout << "6.Sua sach trong du lieu.\n";
		cout << "7.tim sach trong du lieu.\n";
		cout << "8.hien du lieu theo vi tri.\n";
		cin >> choice;
		switch (choice)
		{
		case 0:
			return 0;

		case 1:
			try {
				docFile("thuvien.csv", ds);
				cout << "Da doc file thanh cong!\n" << endl;
			}
			catch (const exception& e) {
				cerr << "Loi khi doc file: " << e.what() << endl;
			}
			break;
		case 2:
			try {

				ghiFile("duLieuThuVien.CSV", ds);
				cout << "Da ghi file thanh cong!\n" << endl;
			}
			catch (const exception& e) {
				cerr << "Loi khi ghi file: " << e.what() << endl;
			}
			
			break;
		case 3:
			xuatDuLieu(ds);
			break;
		case 4:
			themSach(ds);
			cout << "du lieu sau khi them.\n";
			xuatDuLieu(ds);
			break;
		case 5:
		{
			int so;
			bool flag = true;
			int vitri;
			char* maSach=new char[10];
			while (flag) {
				cout << "Hay chon phuong thuoc xoa.\n";
				cout << "1.Xoa theo vi tri.\n";
				cout << "2.Xoa theo ma sach.\n";
				cin >> so;
				switch (so)
				{
				case 1:
					cout << "hay nhap vi tri ban muon xoa: ";
					cin >> vitri;
					xoaSachTaiViTri(ds, vitri);
					flag = false;
					cout << "da xoa thanh cong.\n";
					break;
				case 2:
					cin.ignore();
					cout << "Hay nhap ma sach ban muon xoa sach: ";
					cin.getline(maSach, 10);
					xoaSachTheoMaSach(ds, maSach);
					flag = false;
					cout << "da xoa thanh cong.\n";
					break;
				default:
					cout << "ban da chon khong dung phuong thuc.\n";
					cout << "xin hay nhap lai phuong thuc ban muon xoa.\n";
					break;

				}
			}
			break;
		}
		case 6:
		{
			char* maSach = new char[10];
			cin.ignore();
			cout << "hay nhap ma sach ban can tim de sua du lieu.";
			cin.getline( maSach,10);
			suaDuLieu(ds, maSach);
			cout << "du lieu cua ban da duoc sua.\n";
			break;
		}
		case 7:
		{
			NODE sach ;
			sach = NULL;
			char* loai=new char[MAX];
			cin.ignore();
			cout << "hay nhap loai sach ma ban muon tim: ";
			cin.getline(loai,MAX);
			timSachTheoLoai(ds, sach, loai);
			cout << "sach sau khi tim duoc la.\n";
			xuatDuLieu(sach);
			break;
		}
		case 8:
		{
			int viTriDau;
			int viTriCuoi;
			cout << "hay nhap vi tri dau: ";
			cin >> viTriDau;
			cout << "hay nhap vi tri cuoi: ";
			cin >> viTriCuoi;
			xuatTheoluachon(ds, viTriDau, viTriCuoi);
			break;	
		}
		default:
			cout << "Chuc nang ban vua nhap khong co.\n";
			cout << "Xin hay nhap lai chuc nang ban muon.\n";
			break;
		
		}


	}

}