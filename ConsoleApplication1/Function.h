#pragma once

#include <iostream>
#include <Windows.h>
#include <string>

#include"CarOwner.h"
#include"Function.h"
#include"TypeOfViolation.h"
#include"ViolationLog.h"

using namespace std;

//описання прототипів функції
int KolElFromFile(string nameFile);
void ReadFromFileAboutCarOwner(CarOwner* C, string nameFile);//зчитуємо інфу з файлу
void ReadFromFileAboutViolationLog(ViolationLog* V, CarOwner* C, int n, string nameFile);//зчитуємо інфу з журналу правопорушень
void WriteInFileCarOwner(string nameF, CarOwner *C, int n);//запис в файл
void WriteInFileInputCarOwner(string nameF, CarOwner*C, int n);
void WriteInFileViolationLog(string nameF, ViolationLog* V, int n, int m);
void WriteInFileInputCarOwner(int n, string nameF, CarOwner* C);
