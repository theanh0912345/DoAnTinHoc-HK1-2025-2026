#define _CRT_SECURE_NO_WARNINGS 
#include<fstream>
#include<iostream>
#include"string.h"
using namespace std;
const int MAX = 100;
struct quanLySach
{
	char Book_ID[10];
	char Title[MAX];
	char Author[MAX];
	char Category[MAX];
	int Cabinet;
	int Rack;
	int Row;
	double Signal_Strength;
	char Timestamp[MAX];
	char Status[MAX];
};

struct Node
{
	quanLySach data;
	Node* link;
};
typedef Node* NODE;
NODE taoNode(quanLySach sach);
void themCuoi(NODE& ds, quanLySach sach);
void docFile(const char* Filename, NODE& ds);
void ghiFile(const char* Filename, NODE ds);
void xuatDuLieu(NODE ds);
long demNode(NODE ds);
void themSach(NODE& ds);
bool kiemTraMaSach(NODE ds, char* maSach);
void xoaSachTaiViTri(NODE& ds, long viTri);
void xoaSachTheoMaSach(NODE& ds, char* maSach);
void suaDuLieu(NODE& ds, char* maSach);
void timSachTheoLoai(NODE& ds, NODE& sach, char* loai);
bool kiemTraLoaiSach(NODE ds, char* loai);
bool soSanhMaSach(NODE ds, char* maSachNhap);
bool soSanhLoaiSach(NODE ds, char* loaiSach);
void xuatTheoluachon(NODE ds, long dau, long cuoi);
void sapXepTheoTu(NODE& ds);
void locDuLieuTrung(NODE ds, NODE& dsl);
bool kiemTraDuLieu(NODE ds, int x);
void demSoLuongSachTheoTheLoai(NODE ds, long& dem, char* loai);
long demSoLuongSachHienCo(NODE ds);
struct demDuLieuTrung
{
	int data;
	int soLuongTrung;
};
struct NODE1
{
	demDuLieuTrung data;
	NODE1* link;
};
NODE1* taoNODE1(demDuLieuTrung dem);
void themcuoi1(NODE1*& dem, demDuLieuTrung dem1);
NODE1* demSoLuongTrung(NODE ds, NODE dsl, NODE1*& dem);
NODE1* NodeTrungNhieuNhat(NODE1* ds, NODE1* q);