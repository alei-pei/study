#include "workManager.h"



WorkManager::WorkManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if(!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->is_FileEmpty = true;
		ifs.close();
		return;
	}


	//文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件存在但为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->is_FileEmpty = true;
		ifs.close();
		return;
	}
	int num = this->getNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];

	this->init_Emp();

	

	
	/*this->m_EmpNum = 0;
	this->m_EmpArray = NULL;*/
}

WorkManager::~WorkManager()
{
	if (this->m_EmpArray!=NULL)
	{
		delete [] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int index=0;
	string dep;	

	while (ifs >> id && ifs >> name && ifs >> dep)
	{
		Worker* worker = NULL;

		if (dep == "老板")
		{
			worker = new Boss(id,name,dep);
		}
		else if (dep == "经理")
		{
			worker = new Manager(id, name, dep);
		}
		else 
		{
			worker = new Employee(id, name, dep);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkManager::show_Emp()
{
	if (this->is_FileEmpty)
	{
		cout << "no data" << endl;
	}

	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::delete_Emp()
{
	int index;
	int id;

	if (this->is_FileEmpty)
	{
		cout << "文件为空" << endl;
		return;
	}
	
	cout << "请输入你要删除的员工编号：";
	cin >> index;
	id = this->is_Exist(index);

	if (id == -1)
	{
		cout << "查无此人" << endl;
		return;
	}

	else
	{
		for (int i = id; id < i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;

		this->save();

		cout << "删除成功" << endl;
	}

}

void WorkManager::change_Emp()
{
	int index;
	int id;

	if (this->is_FileEmpty)
	{
		cout << "文件为空" << endl;
		return;
	}

	cout << "请输入你要修改的员工编号：";

	cin >> index;

	id = this->is_Exist(index);

	if (id == -1)
	{
		cout << "查无此人" << endl;
		return;
	}

	else
	{
		delete this->m_EmpArray[id];

		int newID;

		cout << "请输入新的编号:";

		cin >> newID;

		string newName;

		cout << "请输入新的姓名:" ;

		cin >> newName;


		cout << "请输入新的岗位:";

		string newDep;

		cin >> newDep;

		cout << "请输入职位";
		
		cout << "1、老板" << endl
			<< "2、经理" << endl
			<< "3、普通职工" << endl;

		int dselect = 0;

		Worker* worker = NULL;

		cin >> dselect;

		switch (dselect)
		{
		case1:
			worker = new Boss(newID,newName,newDep);
		case2:
			worker = new Manager(newID, newName, newDep);
		case3:
			worker = new Employee(newID, newName, newDep);
		default:
			break;
		}

		this->m_EmpArray[id] = worker;

		cout << "修改成功" << endl;

		this->save();

		
	}

}

int WorkManager::is_Exist(int id)
{

	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
		
	}
	return index;
}

//获取人数
int WorkManager::getNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;

	string dep;

	int num = 1;

	while (ifs >> id && ifs >> name && ifs >> dep)
	{
		num++;
	}

	return num;
}

void WorkManager::save()
{
	ofstream ofs;

	ofs.open(FILENAME,ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID 
			<< this->m_EmpArray[i]->m_Name
			<< this->m_EmpArray[i]->m_DepName << endl;
	}
}

void WorkManager::Show_Menu()
{
	cout << "*******欢迎使用职工管理系统*******" << endl;
	cout << "********0.退出管理程序***********" << endl;
	cout << "********1.增加职工信息***********" << endl;
	cout << "********2.显示职工信息***********" << endl;
	cout << "********3.删除离职职工***********" << endl;
	cout << "********4.修改职工信息***********" << endl;
	cout << "********5.查找职工信息***********" << endl;
	cout << "********6.按照编号排序***********" << endl;
	cout << "********7.清空所有文档***********" << endl;
	cout << "********************************" << endl;
	cout << endl;
	
}

void WorkManager::ExitSystem()
{
	cout << "欢迎下次再次使用" << endl;
	system("pause");
	exit(0);
}

void WorkManager::AddEmp()
{
	cout << "请输入要添加员工数量：" << endl;

	int addNum = 0;

	cin >> addNum;

	if (addNum<=0)
	{
		cout << "输入错误" << endl;

	}
	else
	{
		int newSize = this->m_EmpNum + addNum;

		Worker** newSpace = new Worker * [newSize];

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id;

			string name;

			string dep;

			int dSelect;

			cout << "请输入要添加的员工编号：";

			cin >> id;


			cout << "请输入要添加的员工姓名：";

			cin >> name;
			

			cout << "请输入要添加的员工部门：";

			cin >> dep;

			cout << "请输入岗位" << endl;
			cout << "1、老板" << endl;
			cout << "2、经理" << endl;
			cout << "3、普通员工" << endl;

			cin >> dSelect;

			Worker * worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Boss(id,name,dep);
				break;
			case 2:
				worker = new Manager(id, name, dep);
				break;
			case 3:
				worker = new Employee(id, name, dep);
				break;
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;
			
		}
		delete[] this->m_EmpArray;

		this->m_EmpArray = newSpace;

		this->m_EmpNum = newSize;

		this->save();

		this->is_FileEmpty = false;

		cout << "添加" << addNum << "名成员成功" << endl;
		
		system("pause");

		system("cls");
	}

}

