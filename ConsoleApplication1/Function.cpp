//�������� �������

#include"Function.h"



int KolElFromFile(string nameFile) {
	ifstream fin(nameFile);//���� ��� ������� � �����
	string n;
	int k;
	k = atoi(n.c_str());

	if (fin.is_open()) {//���� ��������
		fin >> k;//������
	}
	else
		cout << "������� �������� �����\n";
	fin.close();
	return k;
}

void ReadFromFileAboutCarOwner(CarOwner *C,string nameFile) {
	ifstream fin(nameFile);//���� ��� ������� �����

	int k;
	string S, N, P;
	Address D;
	string M;
	int Num;

	if (fin.is_open()) {//���� ���� ����������� �� �������

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
		cout << "������� �������� �����.\n";
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

	cout << "������ ��� ��������� ������ ���� ����:\n";

	if (fin.is_open()) {

		fin >> k;
		cout << "��䳿 ������������ �� 1 �� " << n << endl;
		cout << "������ ������ ���������� ������ ��� �������, ������ ��� �� ������.\n(1/0) -> (������/�� �����)\n\n";

		for (int i = 0; i < k; i++) {
			cout << "*_*_*_*_*_*_*_*_*_*\n";
				cout << "����� �" << i + 1 << ": \n";

			for (int j = 0; j < n; j++) {
				cout << "����������� �" << j + 1 << "������ �� ��������������?(1/0): ";
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
	    cout << "������� �������� �����.\n";
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
		cout << "������� �������� ����� \"OutputApartment.txt\".\n";
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
		cout << "������� �������� ����� \"OutputApartment.txt\".\n";
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
		cout << "������� �������� ����� \"OutputApartment.txt\".\n";
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
		cout << "������� �������� �����.\n";
	}
	fout.close();
}