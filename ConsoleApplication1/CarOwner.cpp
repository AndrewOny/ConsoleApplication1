//�������� ������ ����� ������������ 

#include"CarOwner.h"//��������� �������� �����

CarOwner::CarOwner() {
	//��������� ������ ����
	surname = "";
	name = "";
	patronymic = "";
	address.apatment = 0;
	address.house = 0;
	address.street = "";
	modelCar = "";
	number = 0;
}

CarOwner::CarOwner(string S, string N, string P, Address A, string M, int NUM) {
	surname = S;
	name = N;
	patronymic = P;
	address.apatment = A.apatment;
	address.house = A.house;
	address.street = A.street;
	modelCar = M;
	number = NUM;
}

CarOwner::~CarOwner() {
	//��������� ����
}

void CarOwner::Print(){
	if (surname != "") {
		cout << "ϲ�: " << surname << "  " << name << "  " << patronymic << endl;
		cout << "�����: " << address.street << " ���., " << address.house << " �, " << address.apatment << " ��.\n";
		cout << "������ ����: " << modelCar << endl;
		cout << "�����: " << number << endl;
	}
}

void CarOwner::SetParametrs(string S, string N, string P, Address A, string M, int NUM) {
	surname = S;
	name = N;
	patronymic = P;
	address.apatment = A.apatment;
	address.house = A.house;
	address.street = A.street;
	modelCar = M;
	number = NUM;
}

void CarOwner::AddToFile(string NameF) {
	ofstream fout(NameF, std::ios::app);

	if (fout.is_open()) {
		fout << "ϲ�: " << surname << "  " << name << "  " << patronymic << endl;
		fout << "�����: " << address.street << " ���., " << address.house << " �, " << address.apatment << " ��.\n";
		fout << "������ ����: " << modelCar << endl;
		fout << "�����: " << number << endl;
		fout << "--------------------\n";
	}
	else {
		cout << "������� �������� �����.\n";
	}
	fout.close();
}

void CarOwner::AddToFile1(string NameF) {
	ofstream fout(NameF, std::ios::app);

	if (fout.is_open()) {
		if (surname != "") {
			fout << surname << " " << name << " " << patronymic << endl;
			fout << address.street << " " << address.house << " " << address.apatment << " \n";
			fout << modelCar << endl;
			fout << number << endl;
		}
	}
	else {
			cout<< "������� �������� �����.\n";
	}
	fout.close();
}