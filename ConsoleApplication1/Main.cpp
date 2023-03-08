// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//головний файл

#include"Function.h"

using namespace std;

int stateM;
void MainMenu() {
	std::cout << "  МЕНЮ.\n"
		<< "(0) Вихід з програми.\n"
		<< "(1) Добавлення нових правопорушників.\n"
		<< "(2) Видалення правопорушників.\n"
		<< "(3) Зміна параметрів правопорушника.\n"
		<< "(4) Сортування автовласників по алфавіту від А до Я.\n"
		<< "(5) Вибір автовласника в якого потрібно дізнатися суму штрафів.\n"
		<< "(6) Найти самого недисциплінованого водія.\n"
		<< "(7) Вивід інформації про автовласників.\n"
		<< "(8) Вивід журналу правопорушень.\n"
		<< "(9) Найти самого дисциплінованого водія.\n"
		<< "(10) Сортування автовласників по алфавіту від Я до А.\n"
		<< " Ваш вибір: ";
	std::cin >> stateM;
};

//головна функція 

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string InputCarOwner = { "InputCarOwner.txt" }, InputViolationLog = { "InputViolationLog.txt" };//для читання
	string OutputCarOwner = { "OutoutCarOwner.txt" }, OutputViolationLog = { "OutoutViolationLog.txt" };//для запису

	int kolCarOwner = KolElFromFile(InputCarOwner), kolViolationLog = KolElFromFile(InputViolationLog);

	//виділяємо память
	CarOwner* C = new CarOwner[kolCarOwner];
	ViolationLog* V = new ViolationLog[kolViolationLog];

	//зчитуємо з файлу
	ReadFromFileAboutCarOwner(C, InputCarOwner);
	ReadFromFileAboutViolationLog(V, C, kolCarOwner, InputViolationLog);

	std::system("pause");
	std::system("cls");
	MainMenu();


	while (stateM != 0) {

		if (stateM == 1) {
			system("csl"); //видаляти всі записи в консолі

			//тимчасови змінні
			string S, N, P;
			Address A;
			string M;
			int Num;
			int newKolCarOwner = kolCarOwner + 1;
			CarOwner* C1 = new CarOwner[newKolCarOwner];
			ReadFromFileAboutCarOwner(C1, InputCarOwner);
			cout << "Введіть ПІБ: ";
			cin >> S >> N >> P;
			cout << "Введіть адресу: ";
			cin >> A.street >> A.house >> A.apatment;
			cout << "Введіть марку машини: ";
			cin >> M;
			cout << "Введіть номер авто: ";
			cin >> Num;

			C1[newKolCarOwner - 1].SetParametrs(S, N, P, A, M, Num);
			WriteInFileInputCarOwner(newKolCarOwner, InputCarOwner, C1);

			kolCarOwner = KolElFromFile(InputCarOwner);
			CarOwner* C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 2) {
			system("cls");
			kolCarOwner = KolElFromFile(InputCarOwner);
			CarOwner* C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			//тимчасови змінні
			string S = "", N = "", P = "";
			Address A; A.apatment = 0; A.house = 0; A.street = "";
			string M = "";
			int Num = 0;

			int indexDel;
			cout << "Виберіть номер автовласника якого потрібно видалити від 1 до " << kolCarOwner << " : ";
			cin >> indexDel;

			C[indexDel - 1].SetParametrs(S, N, P, A, M, Num);
			WriteInFileInputCarOwner(InputCarOwner, C, kolCarOwner);

			//заново зчитуємо всі дані з файлу і видаляємо память
			kolCarOwner = KolElFromFile(InputCarOwner);
			C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 3) {
			system("cls");

			//тимчасови змінні
			string S, N, P;
			Address AF;
			string M;
			int Num;

			int index;
			cout << "Введіть номер автовласника в якого потрібно поміняти параметри від 1 до " << kolCarOwner << " : ";
			cin >> index;

			cout << "Введіть ПІБ:";
			cin >> S >> N >> P;
			cout << "Введіть адрес:";
			cin >> AF.street >> AF.house >> AF.apatment;
			cout << "Введіть марку машини: ";
			cin >> M;
			cout << "Введіть номер авто: ";
			cin >> Num;

			C[index - 1].SetParametrs(S, N, P, AF, M, Num);

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 4) {
			system("cls");

			for (int i = 0; i < kolCarOwner; i++) {
				for (int j = i + 1; j < kolCarOwner; j++) {
					//міняємо місцями
					CarOwner Buf(C[i].Getsurname(), C[i].Getname(), C[i].GetPatronymic(), C[i].GetAddress(), C[i].GetModelCAr(), C[i].GetNum());//тимчасова змінна
					C[i].SetParametrs(C[j].Getsurname(), C[j].Getname(), C[j].GetPatronymic(), C[j].GetAddress(), C[j].GetModelCAr(), C[i].GetNum());
					C[j].SetParametrs(Buf.Getsurname(), Buf.Getname(), Buf.GetPatronymic(), Buf.GetAddress(), Buf.GetModelCAr(), C[i].GetNum());
				}
			}

			WriteInFileInputCarOwner(kolCarOwner, InputCarOwner, C);//запис в файл

			cout << "Сортування закінчено.\n";
			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 5) {
			system("cls");

			int index, sum = 0;
			bool fS = false, fN = false, fP = false, f = false;//чи найшли потрібного автовласника
			cout << "Виберіть номер автовласника від 1 до " << kolCarOwner << " : ";
			cin >> index;

			for (int i = 0; i < kolViolationLog; i++) {
				for (int j = 0; j < kolCarOwner; j++) {
					if ((C[index - 1].Getsurname() == V[i].GetSurname()[j]) && (C[index - 1].Getname() == V[i].Getname()[j]) && C[index - 1].GetPatronymic() == V[i].GetPatronymic()[j])//якщо найшли співпадіння по ПІБ
					{
						f = false;//найшли хоча б одне співпадіння
						sum += V[i].GetType().GetSF();
					}

				}
			}
			if (f)
				cout << "Сума штрафів дорівнює" << sum << " гривень\n";
			else
				cout << "Співпвдінь не було найденно або штрафів немає\n";

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 6) {
			system("cls");
			int* max = new int[kolCarOwner];
			for (int i = 0; i < kolCarOwner; i++)
				max[i] = 0;

			bool f = false;//доки не знайшли співпадіння

			for (int i = 0; i < kolViolationLog; i++) {
				for (int j = 0; j < kolCarOwner; j++) {
					if (V[i].GetSurname()[j] != "")
					{
						max[j] += V[i].GetType().GetSF();
						f = false;
					}
				}
			}

			int maxSF = max[0], index = 0;
			for (int i = 0; i < kolCarOwner; i++) {
				if (maxSF < max[i])
				{
					maxSF = max[i];
					index = i;
				}
				if (f)
					cout << "Самий більший правопорушник з сумою штрафів " << max[index] << " :\n";
				C[index].Print();

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
		}

		if (stateM == 7) {
			system("cls");
			bool w;
			cout << "Вивести в конмоль/в файл (1/0): ";
			cin >> w;
			system("cls");

			//по новій зчитуємо всі данні з файлу і виділяємо память
			kolCarOwner = KolElFromFile(InputCarOwner);
			CarOwner* C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			if (w) {
				for (int i = 0; i < kolCarOwner; i++) {
					cout << "автовласник " << i << " :\n";
					C[i].Print();
					cout << "****************************\n";
				}
			}
			else
			{
				WriteInFileCarOwner(OutputCarOwner, C, kolCarOwner);
				cout << "Інформація записана в файл \"" << OutputCarOwner << "\"\n";
			}

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 8) {
			system("cls");
			bool w;
			cout << "Вивести в конмоль/в файл (1/0): ";
			cin >> w;
			system("cls");

			//по новій зчитуємо всі данні з файлу і виділяємо память
			kolCarOwner = KolElFromFile(InputCarOwner);
			CarOwner* C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			if (w) {
				for (int i = 0; i < kolViolationLog; i++) {
					cout << "Правопорушення №" << i + 1 << " :\n";
					V[i].Print(kolCarOwner);
					cout << "*****************\n";
				}
			}
			else
			{
				WriteInFileViolationLog(OutputViolationLog, V, kolViolationLog, kolCarOwner);
				cout << "Інформація записана в файл \"" << OutputViolationLog << "\"\n";
			}

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 9) {
			system("cls");
			int* max = new int[kolCarOwner];
			for (int i = 0; i < kolCarOwner; i++)
				max[i] = 0;

			bool f = false;//доки не знайшли співпадіння

			for (int i = 0; i < kolViolationLog; i++) {
				for (int j = 0; j < kolCarOwner; j++) {
					if (V[i].GetSurname()[j] != "")
					{
						max[j] += V[i].GetType().GetSF();
						f = false;
					}
				}
			}

			int maxSF = max[0], index = 0;
			for (int i = 0; i < kolCarOwner; i++) {
				if (maxSF > max[i])
				{
					maxSF = max[i];
					index = i;
				}
				if (f)
					cout << " Правопорушник з найменшою сумою штрафів " << max[index] << " :\n";
				C[index].Print();

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
		}
		if (stateM == 10) {
			system("cls");

			for (int i = 0; i < kolCarOwner; i++) {
				for (int j = i + 1; j < kolCarOwner; j++) {
					//міняємо місцями
					CarOwner Buf(C[i].Getsurname(), C[i].Getname(), C[i].GetPatronymic(), C[i].GetAddress(), C[i].GetModelCAr(), C[i].GetNum());//тимчасова змінна
					C[i].SetParametrs(C[j].Getsurname(), C[j].Getname(), C[j].GetPatronymic(), C[j].GetAddress(), C[j].GetModelCAr(), C[i].GetNum());
					C[j].SetParametrs(Buf.Getsurname(), Buf.Getname(), Buf.GetPatronymic(), Buf.GetAddress(), Buf.GetModelCAr(), C[i].GetNum());
				}
			}

			WriteInFileInputCarOwner(kolCarOwner, InputCarOwner, C);//запис в файл

			cout << "Сортування закінчено.\n";
			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		////////////////////////////////////////////////

		system("cls");
		cout << "Робота завершена.\n";
		system("pause");
	}
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
