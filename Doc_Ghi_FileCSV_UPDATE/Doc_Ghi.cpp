#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include<utility>
#include<sstream>
#include<stdexcept>

using namespace std;

void ghiFileCSV(const string& filename, const vector<vector<string>>& data) {
	ofstream file(filename);
	if (!file.is_open()) {
		throw runtime_error("Khong the mo file de ghi.");
	}

	for (size_t i = 0; i < data.size(); i++) {
		for (size_t j = 0; j < data[i].size(); j++) {
			file << data[i][j];
			if (j < data[i].size() - 1)
				file << " , ";
		}
		file << "\n";
	}

	file.close();
}


vector<vector<string>> docFileCSV(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		throw runtime_error("Khong the mo file de doc.");
	}

	vector<vector<string>> data;
	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		string cell;
		vector<string> row;
		while (getline(ss, cell, ',')) {
			row.push_back(cell);
		}
		data.push_back(row);
	}
	file.close();
	return data;
}


int main() {
	vector<vector< string>> dataset_in;


	try {
		dataset_in = docFileCSV("library_dataset_random.csv");
		cout << "Da doc file thanh cong! Du lieu:" << endl;

		for (size_t i = 0; i < dataset_in.size(); i++) {
			for (size_t j = 0; j < dataset_in[i].size(); j++) {
				cout << dataset_in[i][j] << " | ";
			}
			cout << endl;
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