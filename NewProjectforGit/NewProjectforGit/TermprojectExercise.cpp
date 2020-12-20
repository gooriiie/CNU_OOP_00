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

	ifstream file("D:/학교/2-2/객체지향설계/2020 텀프로젝트/test.txt");
	
	if (file.is_open()) {
		string str;
		while (getline(file, str, ' ')) {
			v.push_back(str);
		}
	}

	
	bool control = true;

	while (control) {

		int lineSize = 0;	// 한줄당 크기
		int numOfline = 1;	// 줄 개수
		store.clear();

		for (int i = 0; i < v.size(); i++) {	// vec에 모든 단어 라인별로 삽입
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

		


		for (int i = 0; i < vec.size(); i++) {	// 20줄까지 출력
			for (int j = 0; j < vec[i].size(); j++) {
				cout << vec[i][j] + " ";
			}
			cout << endl;
		}

		for (int i = 0; i <= 80; i++) {	// 구분줄
			cout << "-";
			if (i == 80) {
				cout << endl;
			}
		}

		cout << "n:다음페이지,  p:이전페이지,  i:삽입,  d:삭제,  c:변경,  s:찾기,  t:저장후종료" << endl;

		for (int i = 0; i <= 80; i++) {	// 구분 줄
			cout << "-";
			if (i == 80) {
				cout << endl;
			}
		}

		cout << "(콘솔메시지)  " << endl;

		for (int i = 0; i <= 80; i++) {	// 구분 줄
			cout << "-";
			if (i == 80) {
				cout << endl;
			}
		}

		char cinput[80];
		cout << "입력: ";
		cin >> cinput;

		char* ptr = strtok(cinput, ",()");	// 문자열 구분
		char* job = ptr;	// 작업 종류
		vector<char*> param;	// 매개변수 vec

		


		switch (*job) {

		case'n':
			// 다음페이지 구현

			break;

		case'p':
			// 이전페이지 구현

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

			// vector의 중간값 삭제 구현
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
			// 모든 단어를 변경 구현
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
			// 변경 내용 파일에 저장 후 종료
			ofstream out("D:/학교/2-2/객체지향설계/2020 텀프로젝트/test.txt", ios::out);
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