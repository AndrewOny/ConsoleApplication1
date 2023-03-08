#pragma once

#include<string>
#include<iostream>

using namespace std;

//описання класу тип правопорушення
class TypeOfViolation {

private:
	string violation;//порушення
	int sizeFine;//розмір штрафа

public:
	//обовязкові методи 
	TypeOfViolation();
	TypeOfViolation(string V, int S);
	~TypeOfViolation();

	void Print();

	string GetViolation() { return violation; };
	int GetSF() { return sizeFine; };

	void SetParametrs(string v, int S);
};