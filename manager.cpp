#include "manager.h"

Manager::Manager(int id, string name, string depName)
{

	this->m_ID = id;
	this->m_Name = name;
	this->m_DepName = depName;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位:" << this->m_DepName
		<< "\t完成老板下达的任务" << endl;
}

string Manager::getDepName()
{
	return string("经理");
}

