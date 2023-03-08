#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Address {
	string street;
	int house;
	int apatment;
};

//описання класа автовласники
class CarOwner {
	private:
		string surname, name, patronymic;//ПІб автовласника
		Address address;//адрес
		string modelCar;//модель авто
		int number;//номер

    public:
		CarOwner();
		CarOwner(string S, string N, string P, Address A, string M, int NUM);
		~CarOwner();

		//потрібні методи

		void Print();
		void SetParametrs(string S, string N, string P, Address A, string M, int NUM);

		//отримання параметрів
		string Getsurname() { return surname; };
		string Getname() { return name; };
		string GetPatronymic() { return patronymic; };
		Address GetAddress() { return address; };
		string GetModelCAr() { return modelCar; };
		int GetNum() { return number; };
		void AddToFile(string NameF);
		void AddToFile1(string NameF);
};
