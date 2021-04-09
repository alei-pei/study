#include "employ.h"


Employee::Employee(int id, string name, string depName)
{

	this->m_ID = id;
	this->m_Name = name;
	this->m_DepName = depName;

}

void Employee::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位:" << this->m_DepName
		<< "\t已经完成任务" << endl;
}

string Employee::getDepName()
{
	return string("员工");
}