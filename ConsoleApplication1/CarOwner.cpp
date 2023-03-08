//описання методів класа автовласники 

#include"CarOwner.h"//підключаємо описання файлу

CarOwner::CarOwner() {
	//створюємо пустий обєкт
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
	//видаляємо обєкт
}

void CarOwner::Print(){
	if (surname != "") {
		cout << "ПІБ: " << surname << "  " << name << "  " << patronymic << endl;
		cout << "Адрес: " << address.street << " вул., " << address.house << " д, " << address.apatment << " кв.\n";
		cout << "Модель авто: " << modelCar << endl;
		cout << "Номер: " << number << endl;
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
		fout << "ПІБ: " << surname << "  " << name << "  " << patronymic << endl;
		fout << "Адрес: " << address.street << " вул., " << address.house << " д, " << address.apatment << " кв.\n";
		fout << "Модель авто: " << modelCar << endl;
		fout << "Номер: " << number << endl;
		fout << "--------------------\n";
	}
	else {
		cout << "Помилка відкриття файлу.\n";
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
			cout<< "Помилка відкриття файлу.\n";
	}
	fout.close();
}