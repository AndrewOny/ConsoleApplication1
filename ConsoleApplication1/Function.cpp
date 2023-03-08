//описання функцій

#include"Function.h"



int KolElFromFile(string nameFile) {
	ifstream fin(nameFile);//щбєкт для читання з файлу
	string n;
	int k;
	k = atoi(n.c_str());

	if (fin.is_open()) {//якщо відкрився
		fin >> k;//читаємо
	}
	else
		cout << "Помилка відкриття файлу\n";
	fin.close();
	return k;
}

void ReadFromFileAboutCarOwner(CarOwner *C,string nameFile) {
	ifstream fin(nameFile);//обєкт для читання файлу

	int k;
	string S, N, P;
	Address D;
	string M;
	int Num;

	if (fin.is_open()) {//якщо файл відкривається то зчитуємо

		fin >> k;
		for (int i = 0; i < k; i++) {
			fin >> S >> N >> P;
			fin >> D.street >> D.house >> D.apatment;
			fin >> M;
			fin >> Num;

			C[i].SetParametrs(S, N, P, D, M, Num);

		}
	}
	else {
		cout << "Помилка відкриття файлу.\n";
	}
	fin.close();
}

void ReadFromFileAboutViolationLog(ViolationLog* V, CarOwner* C, int n, string nameFile) {
	ifstream fin(nameFile);

	int k;
	Date D;
	string Vi, S = "", N = "", P = "";
	int Ss;
	Address A;
	int* index = new int[n];
	CarOwner* c = new CarOwner[n];
	bool w;

	cout << "Вкажіть яке порушення вчинив який водій:\n";

	if (fin.is_open()) {

		fin >> k;
		cout << "Водії пронумеровані від 1 до " << n << endl;
		cout << "Дальше будуть перечислені номера всіх штрафів, вкажіть хто іх вчинив.\n(1/0) -> (вчинив/не вчиив)\n\n";

		for (int i = 0; i < k; i++) {
			cout << "*_*_*_*_*_*_*_*_*_*\n";
				cout << "Штраф №" << i + 1 << ": \n";

			for (int j = 0; j < n; j++) {
				cout << "Автовласник №" << j + 1 << "вчинив це правопорушення?(1/0): ";
				cin >> w;
				if (w) {
					c[j].SetParametrs(C[j].Getsurname(), C[j].Getname(), C[j].GetPatronymic(), C[j].GetAddress(), C[j].GetModelCAr(), C[j].GetNum());
				}
				else {
					A.apatment = 0; A.house = 0; A.street = "";
					c[j].SetParametrs(S, N, P, A, S, 0);
				}
			}
			fin >> D.day >> D.month >> D.yers;
			    fin >> Vi;
				fin >> Ss;

			TypeOfViolation T(Vi, Ss);

			V[i].SetParametrs(D, T, c, n);
		}
	}
   else {
	    cout << "Помилка відкриття файлу.\n";
	}
	fin.close();
}

void WriteInFileCarOwner(string nameF, CarOwner *C, int n) {
	ofstream fout(nameF, std::ios::out);
	if (fout.is_open()) {
		for (int i = 0; i < n; i++) {
			C[i].AddToFile(nameF);
		}
	}
	else {
		cout << "Помилка відкриття файлу \"OutputApartment.txt\".\n";
	}
	fout.close();
}

void WriteInFileInputCarOwner(string nameF, CarOwner *C, int n) {
	ofstream fout(nameF, std::ios::out);
	if (fout.is_open()) {
		fout << n - 1 << endl;
		for (int i = 0; i < n; i++) {
			C[i].AddToFile1(nameF);
		}
	}
	else {
		cout << "Помилка відкриття файлу \"OutputApartment.txt\".\n";
	}
	fout.close();
}

void WriteInFileInputCarOwner(int n, string nameF, CarOwner *C) {
	ofstream fout(nameF, std::ios::out);
	if (fout.is_open()) {
		fout << n << endl;
		for (int i = 0; i < n; i++) {
			C[i].AddToFile1(nameF);
		}
	}
	else {
		cout << "Помилка відкриття файлу \"OutputApartment.txt\".\n";
	}
	fout.close();
}

void WriteInFileViolationLog(string nameF, ViolationLog *V, int n, int m) {
	ofstream fout(nameF, std::ios::app);

	if (fout.is_open()) {
		for (int i = 0; i < n; i++) {
			V[i].AddToFile(nameF, m);
		}
	}
	else {
		cout << "Помилка відкриття файлу.\n";
	}
	fout.close();
}