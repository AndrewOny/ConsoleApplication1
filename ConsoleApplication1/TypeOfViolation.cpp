//описання методів класа Тип провопорушення
#include"TypeOfViolation.h"

TypeOfViolation::TypeOfViolation() {
	violation = "";
	sizeFine = 0;
}

TypeOfViolation::TypeOfViolation(string V, int S) {
	violation = V;
	sizeFine = S;
}

TypeOfViolation::~TypeOfViolation() {
	//видаляємо обєкт
}

void TypeOfViolation::SetParametrs(string V, int S) {
	violation = V;
	sizeFine = S;
}

void TypeOfViolation::Print() {
	cout << "Тип правопорушення: " << violation << endl;
	cout << "Розмір штрафа: " << sizeFine << " грн" << endl;
}