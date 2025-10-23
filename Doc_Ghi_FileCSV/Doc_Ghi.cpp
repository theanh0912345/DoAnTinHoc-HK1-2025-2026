#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include<utility>
#include<sstream>
#include<stdexcept>

using namespace std;

void ghiFileCSV(const string& filename, const vector<pair<string, string>>& dataset) {
	ofstream file(filename);
	if (!file.is_open()) {
		throw runtime_error("Khong the mo file de ghi.");
	}
	for (int j = 0; j < dataset.size(); j++) {
		file << dataset.at(j).first;
		if (j != dataset.size() - 1) {
			file << ","; // Dấu phẩy giữa các cột
		}
	}
	file << "\n";

	if (dataset.empty() || dataset.at(0).second.empty()) {
		file.close();
		return;
	}

	for (int i = 0; i < dataset.at(0).second.size(); i++) {
		for (int j = 0; j < dataset.size(); j++) {
			if (i < dataset.at(j).second.size()) {
				file << dataset.at(j).second[i];
			}
			if (j != dataset.size() - 1) {
				file << ","; // Dấu phẩy giữa các cột
			}
		}
		file << "\n";
	}
	file.close();
}

vector<pair<string, string>> docFileCSV(const string& filename) {
	vector<pair<string, string>> duLieu;
	ifstream file(filename);
	if (!file.is_open()) {
		throw runtime_error("Khong the mo file de doc.");
	}
	string Line, tenCot;
	string duLieuDong; 

	if (file.good()) {
		getline(file, Line);
		stringstream ss(Line);
		while (getline(ss, tenCot, ',')) {
			duLieu.push_back({ tenCot, "" });
		}
	}

	while (getline(file, Line)) {
		stringstream ss(Line);
		int index = 0;

		while (getline(ss, duLieuDong, ',')) {
			if (index < duLieu.size()) {
				duLieu.at(index).second += duLieuDong;
			}
			index++;
		}
	}

	file.close();
	return duLieu;
}

int main() {
	vector<pair<string, string>> dataset_in;


	try {
		dataset_in = docFileCSV("duLieuThuVien.CSV");
		cout << "Da doc file thanh cong! Du lieu:" << endl;

		for (const auto& p : dataset_in) {
			cout << "Ten cot: " << p.first << " | Du lieu cot: " << p.second << endl;
		}

	}
	catch (const exception& e) {
		cerr << "Loi khi doc file: " << e.what() << endl;
	}
try {
		
		ghiFileCSV("duLieuThuVien.CSV", dataset_in);
		cout << "Da ghi file thanh cong!" << endl;
	}
	catch (const exception& e) {
		cerr << "Loi khi ghi file: " << e.what() << endl;
	}
	return 0;
}