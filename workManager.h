#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "boss.h"
#include "manager.h"
#include "employ.h"
#include"worker.h"

#define FILENAME "empFile.txt"


using namespace std;

class WorkManager
{

public:

	WorkManager();

	~WorkManager();

	void Show_Menu();

	void ExitSystem();

	void AddEmp();

	void save();

	int m_EmpNum;

	bool is_FileEmpty;

	int getNum();

	void init_Emp();

	void show_Emp();

	void delete_Emp();

	void change_Emp();

	int is_Exist(int id);

	Worker ** m_EmpArray;

	

};

