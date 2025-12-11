#include"Header.h"

NODE taoNode(quanLySach sach)
{
	NODE ds = new Node;
	ds->data = sach;
	ds->link = NULL;
	return ds;
}
void themCuoi(NODE& ds, quanLySach sach)
{
	NODE newList = taoNode(sach);
	if (ds == NULL)
		ds = newList;
	else
	{
		NODE temp = ds;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = newList;
	}

}
void docFile(const char* Filename, NODE& ds)
{
	ifstream File(Filename);
	if (!File.is_open())
		throw runtime_error("khong the mo File de doc.");
	quanLySach sach;
	char  line[256];
	File.getline(line, 256);
	while (File.getline(line, 256))
	{


		char* duLieu = strtok(line, ",");
		strcpy(sach.Book_ID, duLieu);

		duLieu = strtok(NULL, ",");
		strcpy(sach.Title, duLieu);

		duLieu = strtok(NULL, ",");
		strcpy(sach.Author, duLieu);

		duLieu = strtok(NULL, ",");
		strcpy(sach.Category, duLieu);

		duLieu = strtok(NULL, ",");
		sach.Cabinet = atoi(duLieu);

		duLieu = strtok(NULL, ",");
		sach.Rack = atoi(duLieu);

		duLieu = strtok(NULL, ",");
		sach.Row = atoi(duLieu);

		duLieu = strtok(NULL, ",");
		sach.Signal_Strength = atof(duLieu);

		duLieu = strtok(NULL, ",");
		strcpy(sach.Timestamp, duLieu);

		duLieu = strtok(NULL, ",");
		strcpy(sach.Status, duLieu);


		themCuoi(ds, sach);

	}File.close();
}
void ghiFile(const char* Filename, NODE ds)
{
	ofstream File(Filename);
	if (!File.is_open())
		throw runtime_error("khong the mo File de ghi.");
	long stt = 1;
	File << "STT,Book_ID,Title,Author,Category,Cabinet,Rack,Row,Signal_Strength,Timestamp,Status\n";

	NODE p = ds;
	while (p != NULL)
	{
		File << stt << ", "
			<< p->data.Book_ID << ", "
			<< p->data.Title << ", "
			<< p->data.Author << ", "
			<< p->data.Category << ", "
			<< p->data.Cabinet << ", "
			<< p->data.Rack << ", "
			<< p->data.Row << ", "
			<< p->data.Signal_Strength << ", "
			<< p->data.Timestamp << ", "
			<< p->data.Status << "\n";
		p = p->link;
		stt++;
	}
	File.close();
}
void xuatDuLieu(NODE ds)
{
	long stt = 1;
	cout << "Danh sach sach: \n";
	cout << "stt,Book_ID,Title,Author,Category,Cabinet,Rack,Row,Signal_Strength,Timestamp,Status\n";
	NODE p = ds;
	while (p != NULL)
	{
		cout << stt << ", "
			<< p->data.Book_ID << ", "
			<< p->data.Title << ", "
			<< p->data.Author << ", "
			<< p->data.Category << ", "
			<< p->data.Cabinet << " ,"
			<< p->data.Rack << ", "
			<< p->data.Row << ", "
			<< p->data.Signal_Strength << ", "
			<< p->data.Timestamp << ", "
			<< p->data.Status << "\n";
		p = p->link;
		stt++;
	}
}
bool kiemTraMaSach(NODE ds, char* maSach)
{
	NODE temp = ds;
	while (temp != NULL)
	{
		if (strcmp(temp->data.Book_ID, maSach) == 0)
			return true;
		temp = temp->link;
	}
	return false;
}
void themSach(NODE& ds)
{
	quanLySach sach;
	long soLuong;
	cout << "hay nhap so luong sach ban muon them (toi da dc nhap 5 sach): ";
	cin >> soLuong;
	while (soLuong < 0 || soLuong>5)
	{
		if (soLuong < 0)
		{
			cout << "so luong sach khong the am, xin hay nhap lai.\n";
			cout << "hay nhap so luong sach ban muon them vao: ";
			cin >> soLuong;
		}
		else if (soLuong > 5)
		{
			cout << "hay nhap dung so luong da quy dinh,xin hay nhap lai.\n ";
			cout << "hay nhap so luong ban muon them: ";
			cin >> soLuong;
		}
	}
	cin.ignore();
	for (int i = 0; i < soLuong; i++)
	{
		cout << "hay nhap ma sach: ";
		cin.getline(sach.Book_ID, 10);
		while (kiemTraMaSach(ds, sach.Book_ID))
		{
			cout << "ma sach ban nhap da co, xin hay nhap lai ma sach chua co.\n";
			cout << "hay nhap ma sach: ";
			cin.getline(sach.Book_ID, 10);
		}
		cout << "Hay nhap ten sach: ";
		cin.getline(sach.Title, MAX);
		cout << "Hay nhap ten tac gia: ";
		cin.getline(sach.Author, MAX);
		cout << "Hay nhap loai sach: ";
		cin.getline(sach.Category, MAX);
		cout << "hay nhap so cua tu: ";
		cin >> sach.Cabinet;
		cout << "hay nhap so cua gia do: ";
		cin >> sach.Rack;
		cout << "hay nhap so hang ngang: ";
		cin >> sach.Row;
		cout << "hay nhap cuong do tin hieu: ";
		cin >> sach.Signal_Strength;
		cin.ignore();
		cout << "Hay nhap ngay, thang, nam va gio: ";
		cin.getline(sach.Timestamp, MAX);
		cout << "Hay nhap trang thai cua sach: ";
		cin.getline(sach.Status, MAX);
		themCuoi(ds, sach);
	}
}
long demNode(NODE ds)
{
	long count = 0;
	NODE p = ds;
	while (p != NULL)
	{
		count++;
		p = p->link;
	}
	return count;
}
long demSoLuongSachHienCo(NODE ds)
{
	long count = 0;
	NODE p = ds;
	while (p != NULL)
	{
		count++;
		p = p->link;
	}
	return count;
}


void xoaSachTaiViTri(NODE& ds, long viTri)
{
	long soLuongSach = demNode(ds);
	while (viTri<0 || viTri>soLuongSach - 1)
	{
		cout << "vi tri khong co trong danh sach.";
		cout << "\nxin hay nhap lai vi tri: ";
		cin >> viTri;
	}
	NODE p = ds;
	NODE q = new Node;
	if (viTri == 0)
	{
		ds = ds->link;
		delete p;
	}
	else {
		for (int i = 0; i < viTri - 1; i++)
		{
			p = p->link;
		}
		q = p->link;
		p->link = q->link;
		delete q;
	}
}
bool soSanhMaSach(NODE ds, char* maSachNhap)
{
	char* temp = ds->data.Book_ID;
	if (strcmp(temp, maSachNhap) == 0)
		return false;
	else
		return true;

}
void xoaSachTheoMaSach(NODE& ds, char* maSach)
{
	while (!kiemTraMaSach(ds, maSach))
	{
		cout << "ma sach vua nhap khong co trong du lieu.";
		cout << "\nxin hay nhap lai ma sach: ";
		cin.getline(maSach, 10);
	}
	NODE p = ds;
	NODE q = p->link;
	if (strcmp(ds->data.Book_ID, maSach) == 0)
	{
		ds = p->link;
		delete p;
		return;
	}
	else {
		while (soSanhMaSach(q, maSach))
		{

			p = q;
			q = q->link;
		}
		p->link = q->link;
		delete q;
	}
}
void suaDuLieu(NODE& ds, char* maSach)
{
	quanLySach sach;
	while (!kiemTraMaSach(ds, maSach))
	{
		cout << "ma sach bn nhap khong co trong du lieu.\n";
		cout << "xin hay nhap lai ma sach can tim: ";
		cin.getline(maSach, 10);
	}
	NODE temp = ds;
	while (soSanhMaSach(temp, maSach))
		temp = temp->link;

	cout << "hay nhap ma sach ban muon sua: ";
	cin.getline(sach.Book_ID, 10);
	while (kiemTraMaSach(ds, sach.Book_ID))
	{
		cout << "ma sach ban nhap da co, xin hay nhap lai ma sach chua co.\n";
		cout << "hay nhap ma sach ban muon sua: ";
		cin.getline(sach.Book_ID, 10);
	}
	cout << "Hay nhap ten sach ban muon sua: ";
	cin.getline(sach.Title, MAX);
	cout << "Hay nhap ten tac gia ban muon sua: ";
	cin.getline(sach.Author, MAX);
	cout << "Hay nhap loai sach ban muon sua: ";
	cin.getline(sach.Category, MAX);
	cout << "hay nhap so cua tu ban muon sua: ";
	cin >> sach.Cabinet;
	cout << "hay nhap so cua gia do ban muon sua: ";
	cin >> sach.Rack;
	cout << "hay nhap so hang ngang ban muon sua: ";
	cin >> sach.Row;
	cout << "hay nhap cuong do tin hieu ban muon sua: ";
	cin >> sach.Signal_Strength;
	cin.ignore();
	cout << "Hay nhap ngay, thang, nam va gio ban muon sua: ";
	cin.getline(sach.Timestamp, MAX);
	cout << "Hay nhap trang thai cua sach ban muon sua: ";
	cin.getline(sach.Status, MAX);
	temp->data = sach;
}
bool kiemTraLoaiSach(NODE ds, char* loai)
{
	NODE TEMP = ds;
	while (TEMP != NULL)
	{
		if (strcmp(TEMP->data.Category, loai) == 0)
			return true;
		TEMP = TEMP->link;
	}
	return false;
}
bool soSanhLoaiSach(NODE ds, char* loaiSach)
{
	char* temp = ds->data.Category;
	if (strcmp(temp, loaiSach) == 0)
		return true;
	else
		return false;
}
void timSachTheoLoai(NODE& ds, NODE& sach, char* loai)
{
	NODE temp = ds;
	while (!kiemTraLoaiSach(ds, loai))
	{

		cout << "loai sach ban nhap khong co trong du lieu.\n";
		cout << "xin hay nhap lai loai sach can tim: ";
		cin.getline(loai, MAX);
	}
	while (temp != NULL)
	{
		if (soSanhLoaiSach(temp, loai))
			themCuoi(sach, temp->data);
		temp = temp->link;
	}
}
void demSoLuongSachTheoTheLoai(NODE ds, long& dem, char* loai)
{
	NODE temp = ds;
	while (!kiemTraLoaiSach(ds, loai))
	{

		cout << "loai sach ban nhap khong co trong du lieu.\n";
		cout << "xin hay nhap lai loai sach can tim: ";
		cin.getline(loai, MAX);
	}
	while (temp != NULL)
	{
		if (soSanhLoaiSach(temp, loai))
			dem++;
		temp = temp->link;
	}
}

void xuatTheoluachon(NODE ds, long dau, long cuoi)
{
	while (dau<0 || dau>cuoi) {
		cout << "hay nhap lai vi tri dau.(vi tri khong am va nho hon vi tri cuoi): ";
		cin >> dau;
	}
	while (cuoi<0 || dau>cuoi) {
		cout << "hay nhap lai vi tri cuoi.(vi tri khong am va lon hon vi tri dau): ";
		cin >> cuoi;
	}
	long stt = 1;
	cout << "Danh sach sach: \n";
	cout << "stt,Book_ID,Title,Author,Category,Cabinet,Rack,Row,Signal_Strength,Timestamp,Status\n";
	NODE temp = ds;
	for (int i = 0; i < dau; i++)
		temp = temp->link;
	for (dau; dau < cuoi; dau++)
	{
		cout << stt << ", "
			<< temp->data.Book_ID << ", "
			<< temp->data.Title << ", "
			<< temp->data.Author << ", "
			<< temp->data.Category << ", "
			<< temp->data.Cabinet << " ,"
			<< temp->data.Rack << ", "
			<< temp->data.Row << ", "
			<< temp->data.Signal_Strength << ", "
			<< temp->data.Timestamp << ", "
			<< temp->data.Status << "\n";
		temp = temp->link;
		stt++;
	}

}
void sapXepTheoTu(NODE& ds)
{
	NODE min, temp, p;
	temp = ds;
	while (temp != NULL)
	{
		min = temp;
		p = temp->link;
		while (p != NULL)
		{


			if (min->data.Cabinet > p->data.Cabinet)
				min = p;
			p = p->link;
		}
		swap(temp->data, min->data);
		temp = temp->link;
	}
}
bool kiemTraDuLieu(NODE ds, int x)
{
	NODE temp = ds;
	while (temp != NULL)
	{
		if (temp->data.Cabinet == x)
			return true;
		temp = temp->link;
	}
	return false;
}
NODE1* taoNODE1(demDuLieuTrung dem)
{
	NODE1* ds = new NODE1;
	ds->data = dem;
	ds->link = NULL;
	return ds;
}
void themcuoi1(NODE1* &dem, demDuLieuTrung dem1)
{
	NODE1* newList = taoNODE1(dem1);
	if (dem == NULL)
		dem = newList;
	else
	{
		NODE1* temp = dem;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = newList;
	}
}
void locDuLieuTrung(NODE ds, NODE& dsl)
{
	NODE temp = ds;
	if (dsl == NULL)
		dsl = taoNode(ds->data);
	NODE p = new Node;
	while (temp != NULL)
	{
		p = dsl;
		if (!kiemTraDuLieu(p, temp->data.Cabinet))
			themCuoi(dsl, temp->data);
		temp = temp->link;
	}
}
NODE1* demSoLuongTrung(NODE ds, NODE dsl, NODE1*& dem)
{
	demDuLieuTrung DEM;
	NODE temp = dsl;
	int count = demNode(temp);
	int demSoTrung;
	for (int i = 1; i <= count; i++)
	{	
		NODE p = ds;
		demSoTrung = 0;
		while (p != NULL)
		{
			if (p->data.Cabinet == i)
				demSoTrung++;
			p = p->link;
		}
		DEM.data = i;
		DEM.soLuongTrung = demSoTrung;
		themcuoi1(dem, DEM);

	}
	return dem;
}
NODE1* NodeTrungNhieuNhat(NODE1* ds, NODE1* q)
{
	NODE1* p = ds;
	int Max = 0;
	int NodeSo = 0;
	while (p != NULL)
	{
		if (Max < p->data.soLuongTrung)
		{
			Max = p->data.soLuongTrung;
			NodeSo = p->data.data;
		}
		p = p->link;
	}
	q->data.data = NodeSo;
	q->data.soLuongTrung = Max;
	q->link = NULL;
	return q;
}