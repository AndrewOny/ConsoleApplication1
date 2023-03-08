// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//�������� ����

#include"Function.h"

using namespace std;

int stateM;
void MainMenu() {
	std::cout << "  ����.\n"
		<< "(0) ����� � ��������.\n"
		<< "(1) ���������� ����� ��������������.\n"
		<< "(2) ��������� ��������������.\n"
		<< "(3) ���� ��������� ��������������.\n"
		<< "(4) ���������� ������������ �� ������� �� � �� �.\n"
		<< "(5) ���� ������������ � ����� ������� �������� ���� �������.\n"
		<< "(6) ����� ������ ����������������� ����.\n"
		<< "(7) ���� ���������� ��� ������������.\n"
		<< "(8) ���� ������� �������������.\n"
		<< "(9) ����� ������ ��������������� ����.\n"
		<< "(10) ���������� ������������ �� ������� �� � �� �.\n"
		<< " ��� ����: ";
	std::cin >> stateM;
};

//������� ������� 

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string InputCarOwner = { "InputCarOwner.txt" }, InputViolationLog = { "InputViolationLog.txt" };//��� �������
	string OutputCarOwner = { "OutoutCarOwner.txt" }, OutputViolationLog = { "OutoutViolationLog.txt" };//��� ������

	int kolCarOwner = KolElFromFile(InputCarOwner), kolViolationLog = KolElFromFile(InputViolationLog);

	//�������� ������
	CarOwner* C = new CarOwner[kolCarOwner];
	ViolationLog* V = new ViolationLog[kolViolationLog];

	//������� � �����
	ReadFromFileAboutCarOwner(C, InputCarOwner);
	ReadFromFileAboutViolationLog(V, C, kolCarOwner, InputViolationLog);

	std::system("pause");
	std::system("cls");
	MainMenu();


	while (stateM != 0) {

		if (stateM == 1) {
			system("csl"); //�������� �� ������ � ������

			//��������� ����
			string S, N, P;
			Address A;
			string M;
			int Num;
			int newKolCarOwner = kolCarOwner + 1;
			CarOwner* C1 = new CarOwner[newKolCarOwner];
			ReadFromFileAboutCarOwner(C1, InputCarOwner);
			cout << "������ ϲ�: ";
			cin >> S >> N >> P;
			cout << "������ ������: ";
			cin >> A.street >> A.house >> A.apatment;
			cout << "������ ����� ������: ";
			cin >> M;
			cout << "������ ����� ����: ";
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

			//��������� ����
			string S = "", N = "", P = "";
			Address A; A.apatment = 0; A.house = 0; A.street = "";
			string M = "";
			int Num = 0;

			int indexDel;
			cout << "������� ����� ������������ ����� ������� �������� �� 1 �� " << kolCarOwner << " : ";
			cin >> indexDel;

			C[indexDel - 1].SetParametrs(S, N, P, A, M, Num);
			WriteInFileInputCarOwner(InputCarOwner, C, kolCarOwner);

			//������ ������� �� ��� � ����� � ��������� ������
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

			//��������� ����
			string S, N, P;
			Address AF;
			string M;
			int Num;

			int index;
			cout << "������ ����� ������������ � ����� ������� ������� ��������� �� 1 �� " << kolCarOwner << " : ";
			cin >> index;

			cout << "������ ϲ�:";
			cin >> S >> N >> P;
			cout << "������ �����:";
			cin >> AF.street >> AF.house >> AF.apatment;
			cout << "������ ����� ������: ";
			cin >> M;
			cout << "������ ����� ����: ";
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
					//������ ������
					CarOwner Buf(C[i].Getsurname(), C[i].Getname(), C[i].GetPatronymic(), C[i].GetAddress(), C[i].GetModelCAr(), C[i].GetNum());//��������� �����
					C[i].SetParametrs(C[j].Getsurname(), C[j].Getname(), C[j].GetPatronymic(), C[j].GetAddress(), C[j].GetModelCAr(), C[i].GetNum());
					C[j].SetParametrs(Buf.Getsurname(), Buf.Getname(), Buf.GetPatronymic(), Buf.GetAddress(), Buf.GetModelCAr(), C[i].GetNum());
				}
			}

			WriteInFileInputCarOwner(kolCarOwner, InputCarOwner, C);//����� � ����

			cout << "���������� ��������.\n";
			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 5) {
			system("cls");

			int index, sum = 0;
			bool fS = false, fN = false, fP = false, f = false;//�� ������ ��������� ������������
			cout << "������� ����� ������������ �� 1 �� " << kolCarOwner << " : ";
			cin >> index;

			for (int i = 0; i < kolViolationLog; i++) {
				for (int j = 0; j < kolCarOwner; j++) {
					if ((C[index - 1].Getsurname() == V[i].GetSurname()[j]) && (C[index - 1].Getname() == V[i].Getname()[j]) && C[index - 1].GetPatronymic() == V[i].GetPatronymic()[j])//���� ������ ��������� �� ϲ�
					{
						f = false;//������ ���� � ���� ���������
						sum += V[i].GetType().GetSF();
					}

				}
			}
			if (f)
				cout << "���� ������� �������" << sum << " �������\n";
			else
				cout << "�������� �� ���� �������� ��� ������� ����\n";

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

			bool f = false;//���� �� ������� ���������

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
					cout << "����� ������ ������������� � ����� ������� " << max[index] << " :\n";
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
			cout << "������� � �������/� ���� (1/0): ";
			cin >> w;
			system("cls");

			//�� ���� ������� �� ���� � ����� � �������� ������
			kolCarOwner = KolElFromFile(InputCarOwner);
			CarOwner* C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			if (w) {
				for (int i = 0; i < kolCarOwner; i++) {
					cout << "����������� " << i << " :\n";
					C[i].Print();
					cout << "****************************\n";
				}
			}
			else
			{
				WriteInFileCarOwner(OutputCarOwner, C, kolCarOwner);
				cout << "���������� �������� � ���� \"" << OutputCarOwner << "\"\n";
			}

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == 8) {
			system("cls");
			bool w;
			cout << "������� � �������/� ���� (1/0): ";
			cin >> w;
			system("cls");

			//�� ���� ������� �� ���� � ����� � �������� ������
			kolCarOwner = KolElFromFile(InputCarOwner);
			CarOwner* C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			if (w) {
				for (int i = 0; i < kolViolationLog; i++) {
					cout << "�������������� �" << i + 1 << " :\n";
					V[i].Print(kolCarOwner);
					cout << "*****************\n";
				}
			}
			else
			{
				WriteInFileViolationLog(OutputViolationLog, V, kolViolationLog, kolCarOwner);
				cout << "���������� �������� � ���� \"" << OutputViolationLog << "\"\n";
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

			bool f = false;//���� �� ������� ���������

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
					cout << " ������������� � ��������� ����� ������� " << max[index] << " :\n";
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
					//������ ������
					CarOwner Buf(C[i].Getsurname(), C[i].Getname(), C[i].GetPatronymic(), C[i].GetAddress(), C[i].GetModelCAr(), C[i].GetNum());//��������� �����
					C[i].SetParametrs(C[j].Getsurname(), C[j].Getname(), C[j].GetPatronymic(), C[j].GetAddress(), C[j].GetModelCAr(), C[i].GetNum());
					C[j].SetParametrs(Buf.Getsurname(), Buf.Getname(), Buf.GetPatronymic(), Buf.GetAddress(), Buf.GetModelCAr(), C[i].GetNum());
				}
			}

			WriteInFileInputCarOwner(kolCarOwner, InputCarOwner, C);//����� � ����

			cout << "���������� ��������.\n";
			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		////////////////////////////////////////////////

		system("cls");
		cout << "������ ���������.\n";
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
