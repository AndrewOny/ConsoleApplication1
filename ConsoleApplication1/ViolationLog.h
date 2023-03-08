#pragma once

#include<string>
#include<iostream>

#include"TypeOfViolation.h"
#include"CarOwner.h"

using namespace std;

//структура дати
struct Date {
	int day, month, yers;
};

//описання класа журнал правопорушень
class ViolationLog {

private:
	Date date;
	string *surname, *name, *patronymic;
	TypeOfViolation type;

public:
	ViolationLog();
	ViolationLog(Date D, TypeOfViolation T, CarOwner *C, int n);
	~ViolationLog();

	//методи
	void Print(int n);
	//отримання параметрів
	Date GetDate() { return date; };
	string *GetSurname() { return surname; };
	string *Getname() { return name; };
	string *GetPatronymic() { return patronymic; };
	TypeOfViolation GetType() { return type; };
	void SetParametrs(Date D, TypeOfViolation T, CarOwner* C, int n);
	void AddToFile(string nameF, int n);
};
