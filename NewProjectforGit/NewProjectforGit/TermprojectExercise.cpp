#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

class TextEditor {



};

int main() {

	
	vector<vector<string>> vec;
	vector<string> v;
	vector<string> store;

	ifstream file("D:/�б�/2-2/��ü���⼳��/2020 ��������Ʈ/test.txt");
	
	if (file.is_open()) {
		string str;
		while (getline(file, str, ' ')) {
			v.push_back(str);
		}
	}

	
	bool control = true;

	while (control) {

		int lineSize = 0;	// ���ٴ� ũ��
		int numOfline = 1;	// �� ����
		store.clear();

		for (int i = 0; i < v.size(); i++) {	// vec�� ��� �ܾ� ���κ��� ����
			lineSize += v[i].size();

			if (lineSize <= 75) {
				if (lineSize == 75) {
					store.push_back(v[i]);
				}
				else {
					store.push_back(v[i]);
					lineSize += 1;
				}
			}
			else {
				vec.push_back(store);
				store.clear();

				numOfline += 1;

				lineSize = 0;

				store.push_back(v[i]);

				lineSize += v[i].size();
				lineSize += 1;
			}

			if (i == v.size() - 1) {
				vec.push_back(store);
			}
		}

		


		for (int i = 0; i < vec.size(); i++) {	// 20�ٱ��� ���
			for (int j = 0; j < vec[i].size(); j++) {
				cout << vec[i][j] + " ";
			}
			cout << endl;
		}

		for (int i = 0; i <= 80; i++) {	// ������
			cout << "-";
			if (i == 80) {
				cout << endl;
			}
		}

		cout << "n:����������,  p:����������,  i:����,  d:����,  c:����,  s:ã��,  t:����������" << endl;

		for (int i = 0; i <= 80; i++) {	// ���� ��
			cout << "-";
			if (i == 80) {
				cout << endl;
			}
		}

		cout << "(�ָܼ޽���)  " << endl;

		for (int i = 0; i <= 80; i++) {	// ���� ��
			cout << "-";
			if (i == 80) {
				cout << endl;
			}
		}

		char cinput[80];
		cout << "�Է�: ";
		cin >> cinput;

		char* ptr = strtok(cinput, ",()");	// ���ڿ� ����
		char* job = ptr;	// �۾� ����
		vector<char*> param;	// �Ű����� vec

		


		switch (*job) {

		case'n':
			// ���������� ����

			break;

		case'p':
			// ���������� ����

			break;

		case'i':
			while (ptr != NULL) {
				ptr = strtok(NULL, ",()");
				if (ptr != NULL) {
					param.push_back(ptr);
				}
			}
			
			vec[atoi(param[0]) - 1].insert(vec[atoi(param[0]) - 1].begin() + atoi(param[1]), param[2]);
			v.clear();
			for (int i = 0; i < vec.size(); i++) {	
				for (int j = 0; j < vec[i].size(); j++) {
					v.push_back(vec[i][j]);
				}
			}
			vec.clear();

			break;

		case'd':
			while (ptr != NULL) {
				ptr = strtok(NULL, ",()");
				if (ptr != NULL) {
					param.push_back(ptr);
				}
			}

			// vector�� �߰��� ���� ����
			vec[atoi(param[0]) - 1].erase(vec[atoi(param[0]) - 1].begin() + atoi(param[1]) - 1);
			v.clear();
			for (int i = 0; i < vec.size(); i++) {
				for (int j = 0; j < vec[i].size(); j++) {
					v.push_back(vec[i][j]);
				}
			}
			vec.clear();
			break;

		case'c':
			// ��� �ܾ ���� ����
			while (ptr != NULL) {
				ptr = strtok(NULL, ",()");
				if (ptr != NULL) {
					param.push_back(ptr);
				}
			}

			for (int i = 0; i < vec.size(); i++) {
				for (int j = 0; j < vec[i].size(); j++) {
					if (!strcmp(param[0], (vec[i][j]).c_str())) {
						vec[i][j] = param[1];
					}
				}
			}
			v.clear();
			for (int i = 0; i < vec.size(); i++) {
				for (int j = 0; j < vec[i].size(); j++) {
					v.push_back(vec[i][j]);
				}
			}
			vec.clear();

			break;

		case's':
			while (ptr != NULL) {
				ptr = strtok(NULL, ",()");
				if (ptr != NULL) {
					param.push_back(ptr);
				}
			}

			for (int i = 0; i < vec.size(); i++) {
				for (int j = 0; j < vec[i].size(); j++) {
					if (!strcmp(param[0], (vec[i][j]).c_str())) {
						vector<string> temp = vec[i];
						vec.erase(vec.begin() + i);
						vec.insert(vec.begin(), temp);

						i = vec.size();
						break;
					}
				}
			}

			v.clear();
			for (int i = 0; i < vec.size(); i++) {
				for (int j = 0; j < vec[i].size(); j++) {
					v.push_back(vec[i][j]);
				}
			}
			vec.clear();

			break;

		case't':
			// ���� ���� ���Ͽ� ���� �� ����
			ofstream out("D:/�б�/2-2/��ü���⼳��/2020 ��������Ʈ/test.txt", ios::out);
			for (int i = 0; i < vec.size(); i++) {
				for (int j = 0; j < vec[i].size(); j++) {
					if ((i == vec.size() - 1) && (j == vec[i].size() - 1)) {
						out << vec[i][j];
					}
					else {
						out << vec[i][j] << +" ";
					}
				}
			}
			control = false;

			break;

		}




	}


	return 0;
}