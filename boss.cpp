#include "boss.h"

Boss::Boss(int id, string name, string depName)
{

	this->m_ID = id;
	this->m_Name = name;
	this->m_DepName = depName;
}

void Boss::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位:" << this->m_DepName
		<< "\t已经给经理下达任务" << endl;
}

string Boss::getDepName()
{
	return string("老板");
}
