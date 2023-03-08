#include"ViolationLog.h"

ViolationLog::ViolationLog() {
	date.day = 0;
	date.month = 0;
	date.yers = 0;
}

ViolationLog::ViolationLog(Date D, TypeOfViolation T, CarOwner *C, int n) {
	surname = new string[n];
	name = new string[n];
	patronymic = new string[n];
	date.day = D.day;
	date.month = D.month;
	date.yers = D.yers;
	for (int i = 0; i < n; i++) {
		surname[i] = C[i].Getsurname();
		name[i] = C[i].Getname();
		patronymic[i] = C[i].GetPatronymic();
	}
	type.SetParametrs(T.GetViolation(), T.GetSF());
}

ViolationLog::~ViolationLog() {
}

void ViolationLog::SetParametrs(Date D, TypeOfViolation T, CarOwner* C, int n) {
	surname = new string[n];
	name = new string[n];
	patronymic = new string[n];
	date.day = D.day;
	date.month = D.month;
	date.yers = D.yers;
	for (int i = 0; i < n; i++) {
		surname[i] = C[i].Getsurname();
		name[i] = C[i].Getname();
		patronymic[i] = C[i].GetPatronymic();
	}
	type.SetParametrs(T.GetViolation(), T.GetSF());
}

void ViolationLog::Print(int n) {
	cout << "Дата правопорушення: " << date.day << "дд. " << date.month << "мм. " << date.yers << "гг. " << endl;
	for (int i = 0; i < n; i++) {
		if (surname[i] != "")
			cout << "ПІБ правопорушника №" << i + 1 << " :" << surname[i] << " " << name[i] << " " << patronymic[i] << endl;
	}
	type.Print();
}

void ViolationLog::AddToFile(string nameF, int n) {
	ofstream fout(nameF, std::ios::app);

	if (fout.is_open()) {
		fout << "дата правопорушення: " << date.day << "дд. " << date.month << "мм. " << date.yers << "гг. " << endl;
		for (int i = 0; i < n; i++) {
			if (surname[i] != "")
				fout << "ПІБ правопорушника №" << i + 1 << " :" << surname[i] << " " << name[i] << " " << patronymic[i] << endl;
		}
		fout << "Тип правопорушення: " << type.GetViolation() << endl;
		fout << "Розмір штрафу: " << type.GetSF() << " грн" << endl;
		fout << "_____________________\n";
	}
	else
		cout << "Помилка відкриття файла.\n";

	fout.close();
}